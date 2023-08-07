#include <argparse/argparse.hpp>
#include <iostream>

int main(int argc, char** argv) {

	// -- Arguments Parsing and Command Dispatch --
	argparse::ArgumentParser program("upm");
	program.add_description("Universal Package Manager - Interact with all your package managers from one place");

	argparse::ArgumentParser add_command("add");
	add_command.add_description("Install a package");
	add_command.add_argument("package")
			.help("package[s] to add")
			.remaining();

	argparse::ArgumentParser del_command("del");
	del_command.add_description("Remove a package");
	del_command.add_argument("package")
			.help("package[s] to remove")
			.remaining();

	program.add_subparser(add_command);
	program.add_subparser(del_command);

	try {
		program.parse_args(argc, argv);
	} catch (const std::runtime_error& err) {
		std::cout << err.what() << std::endl;
		std::cout << program;
		exit(0);
	}

	bool verbose = program.get<bool>("--verbose");

	std::cout << "Verbose: " << std::boolalpha << verbose << std::endl;

	return 0;
}