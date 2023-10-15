# pipex

Command to File
> redirect output of command to file

File to Command
< redirect file text to input of command 

Command to Command
|
Redirect command 1 output to command 2 input


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
