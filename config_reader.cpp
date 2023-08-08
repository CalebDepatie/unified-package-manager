#include "config_reader.hpp"
#include <toml++/toml.h>
#include <iostream>
#include <filesystem>

PackageManager ParseConfig(std::string config_path);
Command ParseCommand(toml::table tbl);

std::vector<PackageManager> ReadConfigs(std::string config_dir) {
	std::vector<PackageManager> managers;
	for (auto& p : std::filesystem::directory_iterator(config_dir)) {

		if (p.path().extension() == ".toml") {
			try {
				managers.emplace_back(ParseConfig(p.path()));

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

	return new_manager;
}

Command ParseCommand(toml::table tbl) {
	Command cmd;

	if (tbl["name"].is_array()) {
		auto names = tbl["name"].as_array();
		auto NameList = std::vector<std::string>(names->size());

		names->for_each([&](auto&& el) noexcept {
			if constexpr (toml::is_string<decltype(el)>)
				NameList.push_back(el.get());
		});

		cmd.SetName(NameList);

	} else {
		auto names = std::vector<std::string>(1);
		
		names.push_back(tbl["name"].value<std::string>().value());

		cmd.SetName(names);
	}

	// cmd.Args = tbl["args"].value<std::vector<std::string>>().value();
	return cmd;
}