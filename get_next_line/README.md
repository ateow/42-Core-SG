# get_next_line

This project is about programming a function that returns a line read from a file descriptor.
### Mandatory
Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.
Your function should **return the line** that was read. If there is nothing else to read or if an error occurred, it should return NULL.

### Bonus
Your get_next_line() can manage multiple file descriptors at the same time.
It means that you should be able to call get_next_line() to read from fd 3, then fd 4, then 5, then once again 3, once again 4, and so forth.
