/* read flag from a file -> place in write-only zone
 * require the students to use mprotect to make the zone readable
 *
 * require the students to use exec, to get a shell and find a flag inside a file
 * 
 * require the students to open and read some files, to find a flag
 * 
 * hidden flag: some base64 hidden in rodata
 */
#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

#define FOREVER		1
#define MAX_FILE_NAME	20

#define elements(array) (sizeof(array) / sizeof(array[0]))

const char hidden[] = "U1NTe29oX3lvdV9mb3VuZF9tZX0=";

int main(void)
{
	char command[100], real_filename[100], buffer[100];
	char *command_type, *filename, *resource, *binary, *perm;
	int fd, ret;
	char has_open_file = 0;
	const char *files[] = {"important.txt", "to_buy.txt", "checklist.txt", "music.txt"};
	ssize_t bytes;
	size_t pagesize = getpagesize();

	char *wronly = mmap(NULL, pagesize, PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1 , 0);

	if (wronly == (void *)-1) {
		printf("Unexpected error %d! Bye!\n", errno);
		exit(1);
	}
	fd = open("/tmp/wronly_flag", O_RDONLY);

	if (fd != -1) {
		bytes = read(fd, wronly, 50);
		if (bytes == -1) {
			printf("Unexpected error! Bye!\n");
			exit(1);
		}
	}
	close(fd);

	while(FOREVER) {
		fgets(command, 100, stdin);

		command_type = strtok(command, " ");

		if (strncmp(command_type, "open", 4) == 0) {
			memset(real_filename, 0, 100);
			if (has_open_file == 1) {
				printf("You can have only one file open at the same time! Security policy\n");
				continue;
			}

			filename = strtok(NULL, " \n");

			if (filename == NULL) {
				printf("https://bit.ly/3PURyzF\n");
				continue;
			}
			
			for (int i = 0; i < elements(files); i++) {
				if (strncmp(filename, files[i], MAX_FILE_NAME) == 0) {
					strncat(real_filename, "/tmp/", 6);
					strncat(real_filename, filename, MAX_FILE_NAME);
					fd = open(real_filename, O_RDONLY);
					
					if (fd != -1)
						has_open_file = 1;
					else
						printf("open failed\n");
				}
			}
		} else if (strncmp(command_type, "close", 5) == 0) {
			if (has_open_file == 0) {
				printf("https://bit.ly/3PURyzF\n");
				continue;
			}

			close(fd);
			has_open_file = 0;
		} else if (strncmp(command_type, "read", 4) == 0) {
			if (has_open_file == 0) {
				printf("https://bit.ly/3PURyzF\n");
				continue;
			}

			read(fd, buffer, 100);
			printf("%s", buffer);
		} else if (strncmp(command_type, "mprotect", 8) == 0) {
			resource = strtok(NULL, " ");
			if (resource == NULL) {
				printf("https://bit.ly/3PURyzF\n");
				continue;
			}

			perm = strtok(NULL, " ");
			if (perm == NULL) {
				printf("https://bit.ly/3PURyzF\n");
				continue;
			}

			if (strncmp(resource, "wronly", 6) == 0 && strncmp(perm, "RW-", 3) == 0) {
				ret = mprotect(wronly, pagesize, PROT_READ | PROT_WRITE);
				if (ret == 0)
					printf("%s", wronly);
				else
					printf("mprotect failed\n");
			}
		} else if (strncmp(command_type, "exec", 4) == 0) {
			binary = strtok(NULL, " \n");

			if (strncmp(binary, "/bin/bash", 7) != 0) {
				printf("https://bit.ly/3PURyzF\n");
				continue;
			}

			execv(binary, NULL);
		} else if (strncmp(command_type, "help", 4) == 0) {
			printf("help - displays available commands\n");
			printf("list <resource> - print the requested resource\n");
			printf("	available resources: files, memory, ??? lmhhir(4)\n");
			printf("exec <binary> - start the given binary file; path must be absolute\n");
			printf("mprotect <memory_zone_name> <protections> - change protection of a given memory zone;\n");
			printf("	examples of protection format: RW-, ---\n");
			printf("open <file> - open a file; can open only the files diplayed by list\n");
			printf("close - close the last opened file\n");
			printf("read - read the current open file\n");
			printf("exit - exit the program\n");
		} else if (strncmp(command_type, "list", 4) == 0) {
			resource = strtok(NULL, " ");

			if (strncmp(resource, "files", 5) == 0)
				for (int i = 0; i < elements(files); i++)
					printf("%s\n", files[i]);
			else if (strncmp(resource, "memory", 6) == 0) {
				printf("wronly	-W-\n");
				printf("???	R--\n");
			}
			else if (strncmp(resource, "hidden", 6) == 0)
				printf("%s\n", hidden);
			else
				printf("https://bit.ly/3PURyzF\n");
		} else if (strncmp(command_type, "exit", 4) == 0)
			break;
		else
			printf("Unrecognized command; use \"help\" to see available commands\n");
	}

	return 0;
}