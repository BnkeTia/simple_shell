#include "shell.h"

/**
 * main - Entry point of the shell functions
 * Return: 0 on success
 */
int main(void)
{
	char *user_input = NULL; /*allocate dynamic memory for user input */
	size_t input_len;
	char **env = environ;

	do {
		infinite_prompt();
		if (getline(&user_input, &input_len, stdin) == -1)
		{
			perror("getline");
			free(user_input);/* free malloc memory*/
			exit(EXIT_FAILURE);
		}
		input_len = strlen(user_input);/*remove trailing whitespaces*/
		if ((input_len > 0) && (user_input[input_len - 1]) == '\n')
		{
			user_input[input_len - 1] = '\0';
		}
		if (strcmp(user_input, "exit") == 0)/* exit condition*/
		{
			free(user_input); /*free memory always */
			break;
		}
		else if (strcmp(user_input, "env") == 0)
		{
			while (*env != NULL)
			{
				print_b(*env);
				print_b("\n");
				env++;
			}
		}
		else
		{
			exec_prompt(user_input);
		}
		infinite_prompt();/* display prompt after execution */
	} while(1);
	free(user_input); /* finall free malloc*/
	exit(EXIT_SUCCESS);
	return (0);
}
