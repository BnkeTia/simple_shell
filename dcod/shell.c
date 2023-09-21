#include "shell.h"

/**
 * main - Entry point of the shell functions
 * Return: 0 on success
 */
int main(void)
{
	int input_len = MAX_INPUT_SIZE;
	char user_input[MAX_INPUT_SIZE];
	char *env[] = {NULL};

	while (1)
	{
		infinite_prompt(); /* display prompt */
		fgets(user_input, input_len, stdin);

		if (strcmp(user_input, "exit") == 0) /* exit condition*/
		{

			break;
		}
		else if (strcmp(user_input, "env") == 0)
		{
			char **cE = env;
			while (*env != NULL)
			{
				print_b(*cE);
				print_b("\n");
				cE++;
			}
		}
		else
		{
			exec_prompt(user_input);
		}
	}

	return (0);
}
