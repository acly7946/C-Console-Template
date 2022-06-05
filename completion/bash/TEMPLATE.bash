# TEMPLATE(1) completion

_TEMPLATE()
{
	local cur short long
	_get_comp_words_by_ref cur

	short=(
		-h
		-V
	)

	long=(
		--help
		--version
	)

	if [[ $cur == --* ]]; then
		COMPREPLY=($(compgen -W "${long[*]}" -- "$cur"))
	elif [[ $cur == -* ]]; then
		COMPREPLY=($(compgen -W "${short[*]}" -- "$cur"))
		COMPREPLY+=($(compgen -W "${long[*]}" -- "$cur"))
	else
		COMPREPLY=($(compgen -W "${short[*]}" -- "$cur"))
		COMPREPLY+=($(compgen -W "${long[*]}" -- "$cur"))
		COMPREPLY+=($(compgen -c -- "$cur"))
	fi

} &&
complete -F _TEMPLATE TEMPLATE