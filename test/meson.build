valgrind = find_program('valgrind', required: false, disabler: true)
add_test_setup('valgrind',
	exe_wrapper:
	[
		valgrind,
		'--tool=memcheck',
		'--leak-check=full',
		'--gen-suppressions=all',
		'--error-exitcode=1',
	],
	timeout_multiplier: 10,
	is_default: true,
)

test('Valgrind memcheck', TEMPLATE, suite: 'valgrind')