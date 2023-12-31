#include <iostream>
#include <argparse/argparse.hpp>
#include <libguile.h>

#include "common.hpp"
#include "PackageManager.hpp"

#include "Guile/guile_functions.hpp"

int main(int argc, char** argv) {

	print_debug("Running in debug mode. Expect verbose output");

	// Initialize Guile
	print_debug("Initializing Guile...");

  scm_init_guile();
  scm_with_guile(guile_main, 0);


	// -- Arguments Parsing --
	print_debug("Parsing arguments...");

	argparse::ArgumentParser program("upm", VERSION);
	program.add_description("Universal Package Manager - Interact with all your package managers from one place");

	argparse::ArgumentParser add_command("add");
	add_command.add_description("Install a package");
	add_command.add_argument("packages")
			.help("package[s] to add")
			.nargs(argparse::nargs_pattern::at_least_one);

	argparse::ArgumentParser del_command("del");
	del_command.add_description("Remove a package");
	del_command.add_argument("packages")
			.help("package[s] to remove")
			.nargs(argparse::nargs_pattern::at_least_one);

	argparse::ArgumentParser update_command("update");
	update_command.add_description("Update the system or specific packages");
	update_command.add_argument("packages")
			.help("package[s] to update. leave blank to update the system")
			.default_value<std::vector<std::string>>({})
			.remaining();

	argparse::ArgumentParser search_command("search");
	search_command.add_description("Search for a package");
	search_command.add_argument("search-term")
			.help("The package you're looking for");

	program.add_subparser(add_command);
	program.add_subparser(del_command);
	program.add_subparser(update_command);
	program.add_subparser(search_command);

	try {
		program.parse_args(argc, argv);
	} catch (const std::runtime_error& err) {
		std::cout << err.what() << std::endl;
		std::cout << program;
		exit(0);
	}

	// -- Command Dispatch --
	// Collect all the managers
	std::vector<PackageManager> managers = GetPackageManagers();// = ReadConfigs(CONFIG_DIR);

	print_debug("Running Command...");

	// todo: Clean this up. hard to visually parse
	if (program.is_subcommand_used(add_command)) {

		std::vector<std::string> args;
		auto pkgs = add_command.get<std::vector<std::string>>("packages");

		// todo: install and uninstall should stop after the first success
		for (auto pkg_mng : managers) {
			auto res = pkg_mng.ExecuteInstall(pkgs, args);
		}
		
	} else if (program.is_subcommand_used(del_command)) {

		std::vector<std::string> args;
		auto pkgs = del_command.get<std::vector<std::string>>("packages");

		for (auto pkg_mng : managers) {
			auto res = pkg_mng.ExecuteRemove(pkgs, args);
		}

	} else if (program.is_subcommand_used(update_command)) {

		// Collect arguments
		std::vector<std::string> args;
		auto pkgs = update_command.get<std::vector<std::string>>("packages");

		for (auto pkg_mng : managers) {
			auto res = pkg_mng.ExecuteUpdate(pkgs, args);
		}

	} else if (program.is_subcommand_used(search_command)) {
		
		// Collect arguments
		std::vector<std::string> args;
		std::string search_term = search_command.get<std::string>("search-term");

		for (auto pkg_mng : managers) {
			auto res = pkg_mng.ExecuteSearch(search_term, args);
		}

	} else {
		std::cout << program;
	}

	return 0;
}
