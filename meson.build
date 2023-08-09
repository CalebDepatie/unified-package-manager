project('unified-package-manager', 'cpp')

MAJOR_VER = '0'
MINOR_VER = '1'
PATCH_VER = '1'
SEM_VER = '"' + MAJOR_VER + '.' + MINOR_VER + '.' + PATCH_VER + '"'

src_files = [
	'src/Command.cpp',
	'src/PackageManager.cpp',
	'src/config_reader.cpp',
	'src/main.cpp',
]

# is it required to specify it as a dependency to include / download the wrap?
tomlplusplus_dep = dependency(
	'tomlplusplus', 
	default_options: [
		'build_lib=false'
	]
)

executable(
	'upm',
	src_files,
	cpp_args: [
		'-std=c++20', 
		'-DVERSION=' + SEM_VER
	],
	include_directories: include_directories('subprojects/tomlplusplus-3.3.0/include'),
	install: true,
	install_dir: '/usr/local/bin/',
)

install_subdir(
	'configs',
	install_dir: '/usr/local/etc/upm/',
)
