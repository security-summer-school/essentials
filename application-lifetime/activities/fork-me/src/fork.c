#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int pid, ret, wstatus;
	
	pid = fork();
	if (pid == 0) {
		// child process
		printf("Hello from the child\n");

		return 0;
	} else {
		// parent process
		printf("Hello from the parent; pid of the child is %d\n", pid);
		
		/* wait for the child to finish execution;
		 * the status of the child, at the end of the execution, is stored in wstatus
		 */
		ret = waitpid(pid, &wstatus, 0);

		if (WIFEXITED(wstatus))
			printf("child %d has stopped; exit code: %d\n", ret, WEXITSTATUS(wstatus));

		return 0;
	}
}