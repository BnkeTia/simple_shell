#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


/* Necessary function prototypes of helper functions */

/* function prototype of print function */
void print_b(const char *string);

/* function prototype of prompt display function */
void infinite_prompt(void);

/* function prototype of prompt execution function */
void exec_prompt(const char *user_inputs);

/* function prototype of parser function */ 
void myparser_c(char *user_inputs, size_t size);

#endif /* SHELL_H */
