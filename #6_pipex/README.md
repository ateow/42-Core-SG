# pipex
This project recreates some features of linux's PIPE features
- Handle multiple pipes:
	- Linux Command: `file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`
	- Pipex Project: `./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2`

- Support « and » when the first parameter is "here_doc"
	- Linux Command: `cmd << LIMITER | cmd1 >> file`
	- Pipex Project: `./pipex here_doc LIMITER cmd cmd1 fil`

- Functions allowed: open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid, libft, getnextline


### Project Logic
<pre>
START
error handling
create pipes (depending on number of commands)
|
enter pipe
fork process
|
| ------------------------------
|                     		|
| parent process		| child process (ID = 0)
|				|
|				INFILE > CMD1
|				- get command path				      
|				- check valid command
|				- open Infile / check exist and access
|				- link file FD to STDIN
|				- link Cmd1 STDOUT to pipe write (fd[1])
|				- execve command
|
middle pipe (while loop thru cmds)
fork process
|
| ------------------------------
|                     		|
| parent process		| n child process (ID = 0)
|				|
|				CMD > CMD (midde pipe) 
|				- get command path				      
|				- check valid command
|				- link Cmd STDIN to previous pipe read (prev fd[0])
|				- link Cmd STDOUT to next pipe write (next fd[1])
|				- execve command
|
exit pipe
|
CMD > OUTFILE
- get command path	
- check valid command
- open / create outfile
- link CMD STDOUT to STDIN
- link STDOUT to file FD
- execve command
|
END

</pre>

Piping Logic\
![pipeline_diagram_en drawio](https://github.com/ateow/42-Core-SG/assets/144050579/6453972a-2e19-4111-b27e-8d4143baca14)


### To be improved
Code is unable to handle `awk` & `tr` command flags with quotes well

### Notes

- Command to File `>` redirect output of command to file
- File to Command `<` redirect file text to input of command 
- Command to Command `|` redirect command 1 output to command 2 input

* **EXECVE**
* Initially, both the parent and child processes share the same memory. When one of the processes (either the parent or the child) attempts to modify a shared memory page, the operating system creates a copy of that memory page for the process making the modification. This is the "copy-on-write" mechanism.
* After the copy is made, each process has its own separate copy of the memory page, and modifications in one process do not affect the other.
This COW mechanism is an optimization to reduce the overhead of duplicating all memory when forking a process. It ensures that the memory is only actually duplicated when necessary.
* Now, regarding memory management:
* If you allocate memory dynamically using functions like malloc or calloc before forking, both the parent and child processes will initially share the same memory, and the memory is subject to COW. If one process modifies the dynamically allocated memory, a separate copy is created for that process.
* If one process explicitly frees dynamically allocated memory, it does not directly affect the other process. Each process has its own memory space, so freeing memory in one process only affects that process's view of the memory. The other process may continue to use the memory until it is explicitly freed or until the process exits.
* So, freeing memory in one process does not automatically free it in the other. Each process is responsible for managing its own memory. However, if you're not careful and both processes access the same dynamically allocated memory, you can run into issues like double freeing or memory leaks. Therefore, it's essential to ensure proper memory management in both the parent and child processes to avoid these problems.

