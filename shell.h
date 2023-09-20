#ifndef BIGGY_SHELL_H
#define BIGGY_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


/* define maximum input size */
#define MAX_INPUT_SIZE 128


/* Necessary function prototypes of helper functions */

/* function prototype of print function */
void print_b(const char *string);

/* function prototype of prompt display function */
void infinite_prompt(void);

/* function prototype of prompt execution function */
void exec_prompt(const char *user_input);
extern char **environ; /* external declaration for the environment variable */
char **tok_input(const char *user_input, int *argc);

#endif /* Biggy_SHELL_H *
