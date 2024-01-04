# minishell

The group project is done together with ChristopherOoi. Recreated a bash shell with:
* Environment variables, piping, redirections, history, &&, ||, parenthesis and Wildcards functions. 
* Implemented our own builtins for: echo, cd, pwd, export, unset, env, exit.
* Handle signals for SIGINT and SIGQUIT for ctrl-C, ctrl-D, ctrl-\ in interactive mode.

### minishell code logic

1) check user input is not empty, spaces or tabs
2) inject space if there are no space in <>&| ("ls >hello" -> "ls > hello")
3) split string into 2D arrary by &&, ||, pipe. do not spilt if there are brackets
4) loop thru strings, in each string, check for:
	- || and &&
		- skip strings if exit status fufills ||, && conditions
	- pipes
		- fork and set pipe conditions
			- if pipe exist in prev, set conditions
			- if pipe exist in next, set conditions
		- execute
			- if redirect exist in string, enter redirect function
				- split string up based on redirect symbols
				- set fd conditions based on < > << >>
				- if bracket exist in string, fork, recusre to S/N 3
				- else execute string
					- check and expand env
					- check and expand wildcard
					- check if its builtin
					- execute
				- reset fd conditions
			- if bracket exist in string, fork, recusre to S/N 3
			- else execute string
				- check and expand env
				- check and expand wildcard
				- check if its builtin
				- execute
	- Redirect
		- enter redirect function
			- split string up based on redirect symbols
			- set fd conditions based on < > << >>
			- if bracket exist in string, fork, recusre to S/N 3
			- else execute string
				- check and expand env
				- check and expand wildcard
				- check if its builtin
				- execute
			- reset fd conditions
	- bracket
		- if bracket exist in string, fork, recusre to S/N 3
	- if all 4 conditions dont exist, execute string
		- split string into cmd and arguments arrary. loop thru each string:
		- check and expand env
		- check and expand wildcard
		- check if its builtin
		- execute
