#include "shell.h"

/**
 * main - Entry point of the shell functions
 * Return: 0 on success
 */
int main(void)
{
	char *user_input = NULL; /*allocate dynamic memory for user input */
	size_t input_len;

	while (1)
	{
		infinite_prompt();
		/* reads user inputs */
		if (getline(&user_input, &input_len, stdin) == -1)
		{
			perror("getline");
			free(user_input);/* free malloc memory*/
			exit(EXIT_FAILURE);
		}
		/* Remove trailing newline character */
		input_len = strlen(user_input);
		if ((input_len > 0) && (user_input[input_len - 1]) == '\n')
		{
			user_input[input_len - 1] = '\0';
		}
		/* setting a condition for user to exit shell */
		if (strcmp(user_input, "exit") == 0)
		{
			free(user_input); /*free memory always */
			break;
		}

		exec_prompt(user_input);
		/* display prompt after command execution */
		infinite_prompt();
	}
	free(user_input); /* finall free malloc*/
	return (0);
}

/**
 * infinite_prompt - A helper function that continuously displays the prompt.
 * Return: void
 */
void infinite_prompt(void)
{
	print_b("Biggyshell$ ");
}
