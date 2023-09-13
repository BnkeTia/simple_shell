#include "shell.h"

/**
 * main - Entry point of the shell functions
 * Return: 0 on success
 */
int main(void)
{
	char user_inputs[128];

	while (1)
	{
		infinite_prompt();
		exec_prompt(user_inputs);
		myparser_c(user_inputs, sizeof(user_inputs));
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
	print_b("Biggyshell$");
}
