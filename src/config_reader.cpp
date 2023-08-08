#include "config_reader.hpp"
#include <toml++/toml.h>
#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <string>

PackageManager ParseConfig(std::string config_path);
Command ParseCommand(toml::table tbl);

std::vector<PackageManager> ReadConfigs(std::string config_dir) {
	std::vector<PackageManager> managers;
	for (auto& p : std::filesystem::directory_iterator(config_dir)) {

		if (p.path().extension() == ".toml") {
			// todo: check if the manager exists before bothing to parse it
			
			try {
				auto new_manager = ParseConfig(p.path().string());
				
				int res = std::system(("which "
					+ new_manager.GetName() 
					+ " > /dev/null").c_str());
				
				if (res == 0)
					managers.emplace_back(new_manager);

			} catch (const toml::parse_error& err) {
				// Failed to parse a config file
				std::cerr << "Parsing failed:\n" << err << "\n";
			}
		}
	}
	return managers;
}

PackageManager ParseConfig(std::string config_path) {
	toml::table tbl;
	tbl = toml::parse_file(config_path); // possible error

	auto new_manager = PackageManager(tbl["name"].value<std::string>().value());

	// Parse commands
	new_manager.SetInstallCommand(ParseCommand(*tbl["install"].as_table()));
	new_manager.SetRemoveCommand(ParseCommand(*tbl["remove"].as_table()));
	new_manager.SetUpdateCommand(ParseCommand(*tbl["update"].as_table()));
	new_manager.SetSearchCommand(ParseCommand(*tbl["search"].as_table()));

	return new_manager;
}

Command ParseCommand(toml::table tbl) {
	Command cmd;

	// Strip out specific command mapping
	if (tbl["name"].is_array()) {
		auto names = tbl["name"].as_array();
		auto NameList = std::vector<std::string>();
		NameList.reserve(names->size());

		names->for_each([&](auto&& el) noexcept {
			if constexpr (toml::is_string<decltype(el)>)
				NameList.push_back(el.get());
		});

		cmd.SetName(NameList);

	} else {
		auto names = std::vector<std::string>();
		names.reserve(1);
		
		names.push_back(tbl["name"].value<std::string>().value());

		cmd.SetName(names);
	}

	// Strip out argument mappings
	// cmd.Args = tbl["args"].value<std::vector<std::string>>().value();
	return cmd;
}
