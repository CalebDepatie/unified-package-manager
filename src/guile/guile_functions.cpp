#include "guile_functions.hpp"

#include <libguile.h>
#include <filesystem>
#include "../PackageManager.hpp"
#include "upm_script.h"
#include "../common.hpp"

std::vector<PackageManager> package_managers;

SCM add_pkg_manager(SCM name, SCM install, SCM remove, SCM update, SCM search) {

		std::string name_str = scm_to_locale_string(name);

		print_debug("Adding a package manager: " << name_str);
    PackageManager new_manager(name_str);

		// Check if array
		// Convert to command struct
		// Add to package manager
		auto get_command = [](SCM obj) -> Command {
			Command cmd;
			
			if (scm_is_string(obj)) {
				std::string cmd_str = scm_to_locale_string(obj);
				print_debug("Adding command: " << cmd_str);

				std::vector<std::string> cmd_vec = {cmd_str};

				cmd.SetName(cmd_vec);

			} else if (scm_list_p(obj)) {
				int list_len = scm_to_int(scm_length(obj));
				std::vector<std::string> cmd_vec;

				for (int i = 0; i < list_len; i++) {
					SCM list_item = scm_list_ref(obj, scm_from_int(i));
					std::string list_item_str = scm_to_locale_string(list_item);
					print_debug("Adding command: " << list_item_str);

					cmd_vec.push_back(list_item_str);
					cmd.SetName(cmd_vec);
				}
			}

			return cmd;
		};

		new_manager.SetInstallCommand(get_command(install));
		new_manager.SetRemoveCommand(get_command(remove));
		new_manager.SetUpdateCommand(get_command(update));
		new_manager.SetSearchCommand(get_command(search));

		package_managers.push_back(new_manager);

    return SCM_UNSPECIFIED;
}

void* guile_main(void *data)
{
	// -- Register the C functions --
	scm_c_define_gsubr("add-pkg-manager", 5, 5, 0, reinterpret_cast<void*>(add_pkg_manager));
  
	// -- Load Global Scripts
	// const char* guile_script = reinterpret_cast<const char*>(src_guile_upm_scm);
	// scm_c_eval_string(guile_script);

	// -- Load the config files --
	for (auto& p : std::filesystem::directory_iterator(CONFIG_DIR)) {

		if (p.path().extension() == ".scm") {
			// Todo: check that the manager exists in the system
			scm_c_primitive_load(p.path().c_str());
		}
	}
}

std::vector<PackageManager> GetPackageManagers() {
	return package_managers;
}