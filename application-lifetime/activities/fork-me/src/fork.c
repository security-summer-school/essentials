#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	int pid, ret, wstatus;
	
	pid = fork();
	if (pid == 0) {
		/* Child process */
		printf("Hello from the child\n");

		return 0;
	} else {
		/* Parent process */
		printf("Hello from the parent; pid of the child is %d\n", pid);
		
		/* Wait for the child to finish execution.
		 * The status of the child, at the end of the execution, is stored in wstatus
		 */
		ret = waitpid(pid, &wstatus, 0);

		if (WIFEXITED(wstatus))
			printf("child %d has stopped; exit code: %d\n", ret, WEXITSTATUS(wstatus));

		return 0;
	}
}
