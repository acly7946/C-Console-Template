project(
	'TEMPLATE',
	'c',
	version: '0.0.0',
	license: 'MIT',
	default_options:
	[
		'c_std=c11',
		'warning_level=3'
	]
)

add_project_arguments(
	[
		'-Wno-unused-parameter',
		'-Wno-unused-result',
		'-Wno-missing-braces',
		'-Wundef',
		'-Wvla',
	],
	language: 'c'
)

bash_comp = dependency('bash-completion', required: false)
fish_comp = dependency('fish', required: false)

datadir = get_option('datadir')
sysconfdir = get_option('sysconfdir')
prefix = get_option('prefix')

config = configuration_data()
config.set('datadir', join_paths(prefix, datadir))
config.set('prefix', prefix)
config.set('sysconfdir', join_paths(prefix, sysconfdir))


# Install bash completions
if get_option('bash-completions')
	bash_files = files(
		'completions/bash/TEMPLATE.bash',
	)

	if bash_comp.found()
		bash_install_dir = bash_comp.get_variable(
			pkgconfig: 'completionsdir',
			pkgconfig_define: ['datadir', datadir]
		)
	else
		bash_install_dir = join_paths(datadir, 'bash-completion', 'completions')
	endif

	install_data(bash_files, install_dir: bash_install_dir)
endif

# Install fish completions
if get_option('fish-completions')
	fish_files = files(
		'completions/fish/TEMPLATE.fish',
	)

	if fish_comp.found()
		fish_install_dir = fish_comp.get_variable(
			pkgconfig: 'completionsdir',
			pkgconfig_define: ['datadir', datadir]
		)
	else
		fish_install_dir = join_paths(datadir, 'fish', 'vendor_completions.d')
	endif

	install_data(fish_files, install_dir: fish_install_dir)
endif

# Install zsh completions
if get_option('zsh-completions')
	zsh_files = files(
		'completions/zsh/_TEMPLATE',
	)
	zsh_install_dir = join_paths(datadir, 'zsh', 'site-functions')

	install_data(zsh_files, install_dir: zsh_install_dir)
endif

summary({
	'man-pages': get_option('man-pages'),
}, bool_yn: true)

subdir('man')

executable(
	'TEMPLATE',
	'src/main.c',
	#dependencies:,
	install: true
)