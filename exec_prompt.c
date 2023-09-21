#include "shell.h"

/**
 * exec_prompt - A function that executes a prompt.
 * @user_input: a pointer to a character string entered by user.
 * Return: void
 */
void exec_prompt(const char *user_input)
{
	pid_t child_pid;
	char **user_coms = NULL;
	int aC = 0; /* keep track of number of arguments */
	int i;

	/* calling the tokenizer */
	user_coms = tok_input(user_input, &aC);

	/* Creating a new child process */
	child_pid = fork();

	if (child_pid == -1)/* verifying success of fork */
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char *full_path = "/usr/bin/ls";

		/* Creating an array of arguments for the execve function */
		char **args = (char **)malloc((aC + 1) * sizeof(char *));
		if (args == NULL)
		{
			perror("malloc failed");
			exit(EXIT_FAILURE);
		}

		for (i = 0; i < aC; i++)
		{
			args[i] = user_coms[i];
		}
		args[aC] = NULL;

		if (execve(full_path, user_coms, environ) == -1)
		{
			fprintf(stderr, "Error: Failed to execute %s\n", args[0]);
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		wait(NULL);/* parent process waits for child to complete */
	}

	for (i = 0; i < aC; i++)/*free dynamically allocated memory */
	{
		free(user_coms[i]);
	}
	free(user_coms);
}
