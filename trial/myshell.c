#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/* Define the maximum input size */
#define MAX_INPUT_SIZE 128

extern char **environ;

/* Function prototypes */
void print_b(const char *string);
void infinite_prompt(void);
void exec_prompt(const char *user_input);

/* Main function */
int main(void)
{
    char *user_input = NULL; /* Dynamically allocate memory for user input*/
    size_t input_len;

    while (1)
    {
        infinite_prompt();

        /* Read user input*/
        if (getline(&user_input, &input_len, stdin) == -1)
        {
            perror("getline");
            free(user_input); /* Free dynamically allocated memory*/
            exit(EXIT_FAILURE);
        }

        /* Remove trailing newline character */
        input_len = strlen(user_input);
        if (input_len > 0 && user_input[input_len - 1] == '\n')
        {
            user_input[input_len - 1] = '\0';
        }

        /* Check if the user wants to exit the shell */
        if (strcmp(user_input, "exit") == 0)
        {
            free(user_input); /* Free dynamically allocated memory*/
            break;
        }

        exec_prompt(user_input);

        /* Display prompt after command execution */
        infinite_prompt();
    }

    free(user_input); /* Free dynamically allocated memory*/
    return 0;
}

/* Infinite prompt function */
void infinite_prompt(void)
{
    print_b("Biggyshell$ ");
}

/* Print to STDOUT */
void print_b(const char *string)
{
    write(STDOUT_FILENO, string, strlen(string));
}

/* Execute the command with arguments */
void exec_prompt(const char *user_input)
{
    pid_t child_pid;
    char *token;
    char **user_coms = NULL;
    int aC = 0; /* Number of arguments*/
    int i;

    /* Tokenize the user input*/
    token = strtok((char *)user_input, " ");
    while (token != NULL)
    {
        user_coms = realloc(user_coms, (aC + 1) * sizeof(char *));
        if (user_coms == NULL)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        user_coms[aC] = strdup(token);
        if (user_coms[aC] == NULL)
        {
            perror("strdup");
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, " ");
        aC++; /* Increase the number of arguments*/
    }

    user_coms = realloc(user_coms, (aC + 1) * sizeof(char *));
    if (user_coms == NULL)
    {
        perror("realloc");
        exit(EXIT_FAILURE);
    }
    user_coms[aC] = NULL; /* Add a null character to the end of the array*/

    /* Create a new process*/
    child_pid = fork();

    /* Check fork success*/
    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
        /* Execute the command with arguments using execvp*/
        if (execvp(user_coms[0], user_coms) == -1)
        {
            fprintf(stderr, "Error: Failed to execute %s\n", user_coms[0]);
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Parent process waits for the child to complete*/
        wait(NULL);
    }

    /* Free dynamically allocated memory*/
    for (i = 0; i < aC; i++)
    {
        free(user_coms[i]);
    }
    free(user_coms);
}
