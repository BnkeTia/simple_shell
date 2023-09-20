#include "shell.h"

/**
 * myparser_c - A function that receives the user inputs
 * @user_input: pointer to the character string.
 * @size: maximum size of the input buffer
 * Return: void
 */
void myparser_c(char *user_input, size_t size)
{
	if (fgets(user_input, size, stdin) == NULL)
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
}
