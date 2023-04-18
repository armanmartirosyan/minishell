#ifndef DEFINES_H
#define DEFINES_H

// Main
# define SHELL_NAME "mishell$ "
# define SHELL_NAME_CONSOLE "minishell"
# define WHITE_SPACE " \t\n"
# define HERE_DOC "/tmp/.minishell_here_doc_"
# define METASYMBOLS_ALL "><|&)( \t\n"
# define SEPARATORS_ALL "(&<|>)"
# define SINGLE_SEPARATORS "<|>"
# define DOUBLE_SEPARATORS "<|>&"
# define STRICT_META "|&)"
# define PATH_MAX 1024 
# define REDIRECTS "<>"

// Parse Separators
# define PARSE_SEP_SINGLE "(|)"
# define PARSE_SEP_DOUBLE "&|"

// Env Constants
# define PATH "PATH"

// Custom Errors
# define ERROR_UNX "unexpected error"
# define ERROR_127 "command does not exit in the PATH or wrong command name"
# define ERROR_126 "is a directory"
# define ERROR_130 "syntax error near unexpected token"
# define ERROR_128 "too many arguments"

#endif