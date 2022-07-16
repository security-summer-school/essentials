#include <fcntl.h>	// for open and close
#include <unistd.h>	// for read and write
#include <errno.h>	// for errno
#include <stdio.h>

int main(void)
{
	int fd, read_bytes;
	char buffer[100];

	// open the file as read-write
	fd = open("file.txt", O_RDWR);

	// read the file contents
	read_bytes = read(fd, buffer, sizeof(buffer));
	if (read_bytes == -1) {
		printf("read error: %d\n", errno);
		return 1;
	}

	// write file contents to STDOUT
	write(1, buffer, read_bytes);

	// close the file
	close(fd);
}