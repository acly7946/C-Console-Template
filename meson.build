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
		'-Wundef',
		'-Wvla',
	],
	language: 'c'
)

datadir = get_option('datadir')
sysconfdir = get_option('sysconfdir')
prefix = get_option('prefix')
incdir = include_directories('include')

config = configuration_data()
config.set('datadir', join_paths(prefix, datadir))
config.set('prefix', prefix)
config.set('sysconfdir', join_paths(prefix, sysconfdir))

summary({
	'bash-completions': get_option('bash-completions'),
	'fish-completions': get_option('fish-completions'),
	'zsh-completions': get_option('zsh-completions'),
	'man-pages': get_option('man-pages'),
}, bool_yn: true)

subdir('completion')
subdir('man')
subdir('src')