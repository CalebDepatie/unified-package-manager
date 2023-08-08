project('unified-package-manager', 'cpp')

src_files = [
	'Command.cpp',
	'PackageManager.cpp',
	'config_reader.cpp',
	'main.cpp',
]

tomlplusplus_dep = dependency('tomlplusplus')

executable(
	'upm',
	src_files,
	cpp_args: ['-std=c++2b', '-DVERSION="0.1"'],
	dependencies: [tomlplusplus_dep],
)
