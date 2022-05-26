project(
	'TEMPLATE',
	'c',
	version: '0.0.0',
	license: 'MIT',
	meson_version: '>=0.59.0',
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
		'-DNAME="@0@"'.format(meson.project_name()),
		'-DVERSION="@0@"'.format(meson.project_version()),
		'-DLICENSE="@0@"'.format(meson.project_license()[0]),
	],
	language: 'c'
)

datadir = get_option('datadir')
sysconfdir = get_option('sysconfdir')
prefix = get_option('prefix')
incdir = include_directories('include')

summary({
	'bash-completions': get_option('bash-completions'),
	'fish-completions': get_option('fish-completions'),
	'zsh-completions': get_option('zsh-completions'),
	'man-pages': get_option('man-pages'),
}, bool_yn: true)

subdir('completion')
subdir('doc')
subdir('src')
subdir('test')