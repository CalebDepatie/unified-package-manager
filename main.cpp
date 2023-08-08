#include <iostream>
#include <argparse/argparse.hpp>

#include "config_reader.hpp"

int main(int argc, char** argv) {

	// -- Arguments Parsing SS--
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

	argparse::ArgumentParser upgrade_command("upgrade");
	upgrade_command.add_description("Upgrade the system or specific packages");
	upgrade_command.add_argument("packages")
			.help("package[s] to upgrade. leave blank to upgrade the system")
			.remaining();

	argparse::ArgumentParser search_command("search");
	search_command.add_description("Search for a package");
	search_command.add_argument("search-term")
			.help("The package you're looking for");

	program.add_subparser(add_command);
	program.add_subparser(del_command);
	program.add_subparser(upgrade_command);
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
	std::vector<PackageManager> managers = ReadConfigs("../configs"); // todo: this should be a /etc/ location

	if (program.is_subcommand_used(add_command)) {
		std::cout << "add command used" << std::endl;
		
	} else if (program.is_subcommand_used(del_command)) {
		std::cout << "del command used" << std::endl;

	} else if (program.is_subcommand_used(upgrade_command)) {
		std::cout << "upgrade command used" << std::endl;

	} else if (program.is_subcommand_used(search_command)) {
		std::cout << "search command used" << std::endl;

	} else {
		std::cout << program;
	}

	return 0;
}