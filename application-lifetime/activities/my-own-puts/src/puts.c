#include <unistd.h>
#include <stdio.h>

int puts(const char *s)
{
	write(1, "I do what I want\n", 18);

	return 0;
}
