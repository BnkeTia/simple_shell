#include "shell.h"

/**
 * exec_prompt - A function that executes a prompt.
 * @user_input: a pointer to a character string entered by user.
 * Return: void
 */
void exec_prompt(const char *user_input)
{
	pid_t child_pid;
	char **user_comA, *exec, *com_path;
	int i, aC;
	char *env[] = {NULL};
	char *token;

	/* Creating a new child process */
	child_pid = fork();

	if (child_pid == -1)/* verifying success of fork */
	{
		perror("forking error");
	}

	else if (child_pid == 0)
	{
		user_comA = malloc(128 * sizeof(char *));
		if (user_comA == NULL)
		{
			perror("malloc failed");
			exit(EXIT_FAILURE);
		}
		token = strtok((char *)user_input, " ");
		while (token != NULL)
		{
			user_comA[i++] = token;
			token = strtok(NULL, " ");
		}
		user_comA[i] = NULL;
		/* indicate the path to the executable */
		exec = user_comA[0];
		com_path = "/bin/";
		com_path = malloc(strlen(com_path) + strlen(exec) + 1);
		if (com_path == NULL)
		{
			perror("malloc failed");
			exit(EXIT_FAILURE);
		}
		strcpy(com_path, "/usr/bin/");
		strcat(com_path, exec);

		if (execve(com_path, user_comA, env) == -1)
		{
			perror("failed to execute");
			exit(EXIT_FAILURE);
		}
		free(com_path);
		free(user_comA);
	}

	else
	{
		/* parent process wait for chile to finish */
		waitpid(child_pid, &aC, 0);
	}
}
