#include <fcntl.h>	/* For open and close */
#include <unistd.h>	/* For read and write */
#include <errno.h>	/* For errno */
#include <stdio.h>

int main(void)
{
	int fd, read_bytes;
	char buffer[100];

	/* Open the file as read-write */
	fd = open("file.txt", O_RDWR);

	/* Read the file contents */
	read_bytes = read(fd, buffer, sizeof(buffer));
	if (read_bytes == -1) {
		printf("read error: %d\n", errno);
		return 1;
	}

	/* Write file contents to STDOUT */
	write(1, buffer, read_bytes);

	/* Close the file */
	close(fd);
}
