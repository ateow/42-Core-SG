#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
  
int main()
{
	char	c[10];
	int fd1 = open("sample.txt", O_RDONLY, 0);
	printf("fd1 = %d\n", fd1);

	int fd2 = open("sample2.txt", O_RDONLY, 0);
	printf("fd2 = %d\n", fd2);
	
	read(fd1, &c, 1);
	read(fd1, &c, 1);
	read(fd1, &c, 1);
	read(fd1, &c, 1);
	read(fd1, &c, 1);
	read(fd1, &c, 1);
	read(fd1, &c, 1);
	printf("c = %s\n", c);
	
	read(fd2, &c, 5);
	printf("c = %s\n", c);
	
	exit(0);
}
