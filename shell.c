#include "shell.h"

/**
 * main - Entry point of the shell functions
 * Return: 0 on success
 */
int main(void)
{
	char user_input[MAX_INPUT_SIZE];
	size_t input_len;

	while (1)
	{
		infinite_prompt();
		if (fgets(user_input, sizeof(user_input), stdin) == NULL)
		{
			perror("fgets");
			exit(EXIT_FAILURE);
		}
		/* Remove trailing newline character */
		input_len = strlen(user_input);
		if ((input_len > 0) && (user_input[input_len - 1]) == '\n')
		{
			user_input[input_len - 1] = '\0';
		}
		/* setting e condition for user to close shell */
		if (strcmp(user_input, "exit") == 0)
		{
			break;
		}

		exec_prompt(user_input);
		myparser_c(user_input, sizeof(user_input));
	}
	return (0);
}

/* Infinite prompt function that displays the prompt as long as shell runs */
#include "shell.h"

/**
 * infinite_prompt - A helper function that continuously displays the prompt.
 * Return: void
 */
void infinite_prompt(void)
{
	print_b("cShell |\n|> ");
}
