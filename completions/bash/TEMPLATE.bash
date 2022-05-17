# TEMPLATE(1) completion

_TEMPLATE()
{
  local cur prev short long
  _get_comp_words_by_ref cur prev

  short=(
    -h
    -V
  )

  long=(
    --help
    --version
  )

  case $prev in
    -c|--config)
      _filedir
      return
      ;;
  esac

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