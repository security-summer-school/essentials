#include <stdio.h>
#include <unistd.h>	// getpagesize()
#include <sys/mman.h>	// mprotect()
#include <errno.h>

const int read_only_var = 10;

int main()
{
	int page_size = getpagesize();
	void *ro_addr = &read_only_var; // compilation warning
	void *ro_page;
	int ret;

	printf("%d\n", *(int *)ro_addr);

	// read_only_var = 11; - compilation error; can't write to read-only variables
	
	//*ro_addr = 11; - segfault, trying to write in a read-only area

	ro_page = ro_addr - ((size_t)ro_addr % page_size); // align to page-size

	ret = mprotect(ro_page, page_size, PROT_READ | PROT_WRITE); // make the memory zone readable and writeable
	if (ret != 0) {
		printf("mprotect failed: %d\n", errno);
		return 1;
	}

	*(int *)ro_addr = 11;	// write

	printf("%d\n", *(int *)ro_addr);

	return 0;
}