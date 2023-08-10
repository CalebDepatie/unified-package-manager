project(
	'unified-package-manager', 
	'cpp',
	license: 'BSD-3-Clause',
)

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

tomlplusplus_dep = dependency(
	'tomlplusplus', 
	default_options: [
		'build_lib=false'
	]
).partial_dependency(includes:true)

tomlplusplus_inc = tomlplusplus_dep

executable(
	'upm',
	src_files,
	cpp_args: [
		'-std=c++20', 
		'-DVERSION=' + SEM_VER
	],
	dependencies: [
		tomlplusplus_dep
	],
	install: true,
	install_dir: '/usr/local/bin/',
)

install_subdir(
	'configs',
	install_dir: '/usr/local/etc/upm/',
)
