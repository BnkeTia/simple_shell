#include "shell.h"

/**
 * main - Entry point to the code
 * Description: responsible for the user interface of biggyshell
 * Return: 0 on succes
 */
int main(void)
{
	int input_len = MAX_INPUT_SIZE;
	char user_coms[MAX_INPUT_SIZE];
	int exit_status;

	while (1)
	{
		printf("Biggyshell$ ");
		fgets(user_coms, input_len, stdin);

		user_coms[strlen(user_coms) - 1] = '\0';

		/* creating an exit condition for the user*/
		if (strcmp(user_coms, "exit") == 0)
		{
			print_b("\n");
			break;
		}
		else if (strncmp(user_coms, "exit ", 5) == 0)
		{
			exit_status = atoi(user_coms + 5);
			
			exit(exit_status);
		}

		exec_prompt(user_coms);
	}
	return (0);
}
