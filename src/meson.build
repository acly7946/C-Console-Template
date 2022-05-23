TEMPLATE = executable(
	'TEMPLATE',
	'main.c',
	#dependencies:,
	include_directories: incdir,
	install: true
)

valgrind = find_program('valgrind', required: false, disabler: true)
add_test_setup('valgrind',
	exe_wrapper:
	[
		valgrind,
		'--leak-check=full',
		'--gen-suppressions=all',
		'--error-exitcode=3',
	],
	timeout_multiplier: 100,
	is_default: true,
)

test('Valgrind Leak Check', TEMPLATE, suite: 'valgrind')