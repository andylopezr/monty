#include "monty.h"
/**
 * main - entry point for Monty project
 * @ac: number of arguments
 * @av: array of pointers to those arguments
 * Return: Always 0 on success
 */
int main(int ac, char **av)
{
	unsigned int line_number = 0;
	size_t line_len = 0;
	stack_t *head = NULL;
	int len = 0;
	FILE *monty;
	char *buffer = NULL;

	values.retvalue = 0;
	values.listmode = 0;
	values.opcode = NULL;
	values.arg = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "\033[31mUSAGE: monty file\033[0m\n");
		exit(EXIT_FAILURE);
	}
	monty = fopen(av[1], "r");
	if (!monty)
	{
		fprintf(stderr, "\033[31mError: Can't open file %s\033[0m\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((len = getline(&buffer, &line_len, monty)) != -1)
	{
		line_number++;
		if (!(buffer[0] == '\n') && !(buffer[0] == '#') && !check_buffer(buffer))
		{
			token(buffer);
			if (values.opcode[0] == '#')
				continue;
			values.retvalue = opfinder(&head, line_number);
			if (values.retvalue == -1)
				break;
		}
	}
	free_all(buffer, head, monty);
	if (values.retvalue == -1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
