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

start\
error handling\
create pipes (depending on number of commands)\
|\
enter pipe
fork process
|\
|\
| ---------------------------------------\
|^10                                       |\
| _parent process_                       |_ child process (ID = 0)_\
|                                        |\



### To be improved
Code is unable to handle `awk` & `tr` command flags with quotes well

### Notes

- Command to File `>` redirect output of command to file
- File to Command `<` redirect file text to input of command 
- Command to Command `|` redirect command 1 output to command 2 input


//

Functions allowed:

OPEN
#include <fcntl.h>
int open(const char *pathname, int flags);
O_CREATE = create file if file does not exist
O_APPEND = open file in append mode, file offset is positioned at end of file
return vale of open is a FD

CLOSE
#include <unistd.h>
int close(int fd);
close() returns zero on success.  On error, -1 is returned, and

PERROR
#include <stdio.h>
void perror(const char *s);
The perror() function produces a message on standard error describing the last error encountered during a call to a system or library function.


ACCESS
#include <unistd.h>
int access(const char *pathname, int mode);
pathname: This is a pointer to a string containing the path to the file or directory you want to check.
mode: This is an integer representing the type of access you want to check. It can be a combination of several constants:
	R_OK: Check if the file is readable.
	W_OK: Check if the file is writable.
	X_OK: Check if the file is executable.
	F_OK: Check if the file exists.

It returns 0 if the file has the specified access permissions or if it exists (or if no tests are requested using F_OK).
It returns -1 if the file is not accessible as specified or if there is an error (e.g., the file doesn't exist, or the path is invalid).

DUP / DUP2
#include <unistd.h>
int dup(int oldfd);
int dup2(int oldfd, int newfd);

for dup: The new file descriptor number is guaranteed to be the lowest-numbered file descriptor that was unused in the calling process.

	If the file descriptor newfd was previously open, it is closed
	before being reused; the close is performed silently (i.e., any
	errors during the close are not reported by dup2()).

	The steps of closing and reusing the file descriptor newfd are
	performed atomically.  This is important, because trying to
	implement equivalent functionality using close(2) and dup() would
	be subject to race conditions, whereby newfd might be reused
	between the two steps.  

EXECVE
This function is primarily used for replacing the current process image with a new one. In other words, it allows you to start a new program while discarding the current program, effectively replacing the current process with the specified program.


When you use the fork system call in Unix-like operating systems, a new process is created that is a copy of the parent process. However, the memory of the child process is not an exact duplicate of the parent's memory. Instead, the child process initially shares the same memory as the parent through a mechanism known as "copy-on-write" (COW).

Here's how it works:

    Initially, both the parent and child processes share the same memory.

    When one of the processes (either the parent or the child) attempts to modify a shared memory page, the operating system creates a copy of that memory page for the process making the modification. This is the "copy-on-write" mechanism.

    After the copy is made, each process has its own separate copy of the memory page, and modifications in one process do not affect the other.

This COW mechanism is an optimization to reduce the overhead of duplicating all memory when forking a process. It ensures that the memory is only actually duplicated when necessary.

Now, regarding memory management:

    If you allocate memory dynamically using functions like malloc or calloc before forking, both the parent and child processes will initially share the same memory, and the memory is subject to COW. If one process modifies the dynamically allocated memory, a separate copy is created for that process.

    If one process explicitly frees dynamically allocated memory, it does not directly affect the other process. Each process has its own memory space, so freeing memory in one process only affects that process's view of the memory. The other process may continue to use the memory until it is explicitly freed or until the process exits.

So, freeing memory in one process does not automatically free it in the other. Each process is responsible for managing its own memory. However, if you're not careful and both processes access the same dynamically allocated memory, you can run into issues like double freeing or memory leaks. Therefore, it's essential to ensure proper memory management in both the parent and child processes to avoid these problems.

