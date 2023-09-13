#include "shell.h"

/**
 * exec_prompt - A function that executes a prompt.
 * @user_input: a pointer to a character string
 * Return: void
 */

void exec_prompt(const char *user_input)
{
	pid_t child_pid;

	/* creating a new process */
	child_pid = fork();

	/* verifying success of fork */
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char *const args[] = {(char *)user_input, NULL};
		char *const env[] = {NULL};

		/* executing the command with execve */
		if (execve(user_input, args, env) == -1)
		{

			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* parent process waits for child to complete */
		wait(NULL);
	}
}
