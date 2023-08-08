project('unified-package-manager', 'cpp')

src_files = [
	'src/Command.cpp',
	'src/PackageManager.cpp',
	'src/config_reader.cpp',
	'src/main.cpp',
]

tomlplusplus_dep = dependency('tomlplusplus')

executable(
	'upm',
	src_files,
	cpp_args: ['-std=c++20', '-DVERSION="0.1"'],
	dependencies: [tomlplusplus_dep],
)
