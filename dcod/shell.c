#include "shell.h"

/**
 * main - Entry point of the shell functions
 * Return: 0 on success
 */
int main(void)
{
	char user_input[input_len];
	int input_len = MAX_INPUT_SIZE;/* store the value in input_len*/
	char **env = environ;

	while (1)
	{
		infinite_prompt();/* display prompt */
		fgets(user_input, input_len, stdin);

		if (strcmp(user_input, "exit") == 0)/* exit condition*/
		{

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
	}

	return (0);
}
