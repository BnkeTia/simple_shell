#include "shell.h"

/**
 * exec_prompt - A function that executes a prompt.
 * @user_input: a pointer to a character string
 * Return: void
 */
void exec_prompt(const char *user_input)
{
	pid_t child_pid;
	char **user_coms = NULL;
	int aC = 0; /* keep track of number of arguments */
	char *token;
	int i;

	token = strtok((char *)user_input, " ");
	while (token != NULL)
	{
		user_coms = realloc(user_coms, (aC + 1) * sizeof(char *));
		if (user_coms == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		user_coms[aC] = strdup(token);
		if (user_coms[aC] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " ");
		aC++; /* increase the number of arguments */
	}
	user_coms = realloc(user_coms, (aC + 1) * sizeof(char *));
	if (user_coms == NULL)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	user_coms[aC] = NULL; /* Null terminate the array */
	child_pid = fork();/* creating a new child process */
	if (child_pid == -1)/* verifying success of fork */
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char *full_path = "/usr/bin/ls";
		if (execve(full_path, user_coms, environ) == -1)
		{
			fprintf(stderr, "Error: Failed to execute %s\n", user_coms[0]);
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
