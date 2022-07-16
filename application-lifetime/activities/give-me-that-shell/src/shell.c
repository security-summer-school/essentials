#include <unistd.h>

int main(void)
{
	// the second paramenter contains an array of arguments for the command
	execv("/bin/sh", NULL);
}
