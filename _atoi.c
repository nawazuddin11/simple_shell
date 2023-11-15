#include "shell.h"
/**
 * interactive - it returns true if shell is interactive
 * @info: structure address
 *
 * Return: 1 if interactive, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - it checks if character is a delimete
 * @c: char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - it checks for alphabetic char
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - it converts a string to an int
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int j, Sign = 1, Flag = 0, outcome;
	unsigned int Result = 0;

	for (j = 0;  s[j] != '\0' && Flag != 2; j++)
	{
		if (s[j] == '-')
			Sign *= -1;

		if (s[j] >= '0' && s[j] <= '9')
		{
			Flag = 1;
			Result *= 10;
			Result += (s[j] - '0');
		}
		else if (Flag == 1)
			Flag = 2;
	}

	if (Sign == -1)
		outcome = -Result;
	else
		outcome = Result;

	return (outcome);
}
