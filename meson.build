project(
	'unified-package-manager', 
	'cpp',
	license: 'BSD-3-Clause',
)

cpp = meson.get_compiler('cpp')

# Various variables that get passed as defines

MAJOR_VER = '0'
MINOR_VER = '2'
PATCH_VER = '0'
SEM_VER = '"' + MAJOR_VER + '.' + MINOR_VER + '.' + PATCH_VER + '"'
DATA_DIR = get_option('data_dir')
INSTALL_DIR = get_option('install_dir')

additional_cxx_args = [
	'-DVERSION=' + SEM_VER,
	'-DDATA_DIR="' + DATA_DIR + '"',
]

if get_option('debug')
	# I'm not sure how to use meson built-in options via the script, so I have to make due
	additional_cxx_args += [
		'-DDEBUG',
	] + cpp.get_supported_arguments(
		'-ferror-limit=5',
		'-fmax-errors=5',
		'-Weverything',
		'-Wcast-align',
		'-Wcast-qual',
		'-Wctor-dtor-privacy',
		'-Wdisabled-optimization',
		'-Wfloat-equal',
		'-Wimport',
		'-Winit-self',
		'-Wlogical-op',
		'-Wmissing-declarations',
		'-Wmissing-field-initializers',
		'-Wmissing-format-attribute',
		'-Wmissing-include-dirs',
		'-Wmissing-noreturn',
		'-Wold-style-cast',
		'-Woverloaded-virtual',
		'-Wpacked',
		'-Wpointer-arith',
		'-Wredundant-decls',
		'-Wshadow',
		'-Wsign-conversion',
		'-Wsign-promo',
		'-Wstack-protector',
		'-Wstrict-null-sentinel',
		'-Wswitch-default',
		'-Wswitch-enum',
		'-Wundef',
		'-Wunreachable-code',
		'-Wunused',
		'-Wunused-parameter',
		'-Wuseless-cast',
		'-Wvariadic-macros',
		'-Wwrite-strings',
		'-Wmissing-noreturn'
	)
endif

src_files = [
	'src/common.cpp',
	'src/Command.cpp',
	'src/PackageManager.cpp',
	'src/guile/guile_functions.cpp',
	'src/main.cpp',
]

guile_dep = dependency('guile-3.0')

run_command('xxd', '-i', 'src/guile/upm.scm', 'src/guile/upm_script.h')

executable(
	'upm',
	[src_files],
	cpp_args: [
		'-std=c++20', 
		additional_cxx_args,
	],
	dependencies: [
		guile_dep
	],
	install: true,
	install_dir: INSTALL_DIR,
)

install_subdir(
	'configs',
	install_dir: DATA_DIR,
)
