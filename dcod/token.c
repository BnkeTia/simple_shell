#include "shell.h"

/**
 * tok_input - A function that tokenizes user input.
 * @user_input: a pointer to a character string
 * @argc: number of commands or arguments, always swap with aC.
 * Return: user commands, user_coms.
 */
char **tok_input(const char *user_input, int *argc)
{
	char **user_coms = NULL;
	char *token;
	int aC = 0;/* initialize number of arguments of zero */

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

	*argc = aC;
	return (user_coms);
}
