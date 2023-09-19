#include "shell.h"

/**
 * exec_prompt - A function that executes a prompt.
 * @user_input: a pointer to a character string
 * Return: void
 */

void exec_prompt(const char *user_input)
{
	pid_t child_pid;
	char *user_coms[MAX_INPUT_SIZE]; /* declaration of an array of commands */
	int aC = 0; /* keep track of number of arguments */
	char *token;

	token = strtok((char *)user_input, " ");
	while (token != NULL)
	{
		user_coms[aC] = token;
		token = strtok(NULL, " ");
		aC++; /* increasing the number of arguments */
	}
	user_coms[aC] = NULL; /* add a null chracter to the end of the array */

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
		if (aC == 0)
		{
			/* execute a single word command*/
			if (execlp(user_coms[0], user_coms[0], NULL) == -1)
			{
				fprintf(stderr, "Error: Failed to execute %s\n", user_coms[0]);
				perror("execlp");
				exit(EXIT_FAILURE);
			}
			else
			{
			/* executing the command with execve */
			if (execvp(user_coms[0], user_coms) == -1)
			{
				fprintf(stderr, "Error: Failed to execute %s\n", user_coms[0]);
				perror("execve");
				exit(EXIT_FAILURE);
			}

			}
		}
		else
		{
			/* parent process waits for child to complete */
			wait(NULL);
		}

	}
}
