/**
 * is_integer - checks if a string is a valid integer
 * @str: the string to check
 * Return: 1 if valid, 0 otherwise
 */
int is_integer(char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
	return (0);

	if (str[0] == '-' || str[0] == '+')
	i = 1;

	for (; str[i] != '\0'; i++)
	{
	if (str[i] < '0' || str[i] > '9')
	return (0);
	}
	return (1);
}
