#include "shell.h"

/**
 * exec_prompt - A function that executes a prompt.
 * @user_input: a pointer to a character string
 * Return: void
 */

void exec_prompt(const char *user_input)
{
	pid_t child_pid;
	char **user_coms; /* declaration of an array of commands */

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
		/* allocate memory for the user_coms array */
		user_coms = malloc(sizeof(char *) * 2);
		if (user_coms == NULL)
		{
			perror("malloc but no array");
			exit(EXIT_FAILURE);
		}
		user_coms[0] = (char *)user_input;
		/* adding a null string to the array */
		user_coms[1] = NULL;

		/* executing the command with execve */
		if (execve(user_input, user_coms, environ) == -1)
		{
			fprintf(stderr, "Error: Failed to execute %s\n", user_input);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		free(user_coms); /* free my allocated memory */
	}
	else
	{
		/* parent process waits for child to complete */
		wait(NULL);
	}
}
