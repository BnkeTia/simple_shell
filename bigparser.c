#include "shell.h"

/**
 * myparser_c - A function that receives the user inputs
 * @user_inputs: pointer to the character string.
 * @size: maximum size of the input buffer
 * Return: void
 */
void myparser_c(char *user_inputs, size_t size)
{
	/* initializing the length of the input string */
	size_t input_len;

	if (fgets(user_inputs, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			print_b("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			print_b("Input reading error.\n");
			exit(EXIT_FAILURE);
		}
	}
	input_len = strlen(user_inputs);
	if ((input_len > 0) && (user_inputs[input_len - 1] == '\n'))
	{

		user_inputs[input_len - 1] = '\0';
	}
}
