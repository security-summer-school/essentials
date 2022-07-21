#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char buffer[30];

	int fd = open("flag", O_RDONLY);

	read(fd, buffer, 30);

	printf("Information accuired\n");

	return 0;
}
