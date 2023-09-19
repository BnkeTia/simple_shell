#include "shell.h"

/**
 * print_b- A function that prints or writes to the STDOUT.
 * @string: pointer to a character array
 * Return: void.
 */
void print_b(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}
