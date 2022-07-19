#include <stdio.h>
#include <unistd.h>	/* For getpagesize() */
#include <sys/mman.h>	/* For mprotect() */
#include <errno.h>

const int read_only_var = 10;

int main()
{
	int page_size = getpagesize();
	void *ro_addr = &read_only_var; /* Compilation warning */
	void *ro_page;
	int ret;

	printf("%d\n", *(int *)ro_addr);

	// read_only_var = 11; - compilation error; can't write to read-only variables
	
	// *ro_addr = 11; - segfault, trying to write in a read-only area

	/* Align to page-size */
	ro_page = ro_addr - ((size_t)ro_addr % page_size);

	/* Make the memory zone readable and writeable */
	ret = mprotect(ro_page, page_size, PROT_READ | PROT_WRITE);
	if (ret != 0) {
		printf("mprotect failed: %d\n", errno);
		return 1;
	}

	/* Write to ex-read-only zone */
	*(int *)ro_addr = 11;

	printf("%d\n", *(int *)ro_addr);

	return 0;
}