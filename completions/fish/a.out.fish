# a.out(1) completion

complete -f -c a.out
complete -c a.out -s h -l help --description "Show help message and quit."
complete -c a.out -s V -l version --description "Show the version number and quit."