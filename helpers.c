#include "monty.h"
/**
 * token - toknizes the buffer from monty file
 * @buffer: buffer to tokenize
 */
void token(char *buffer)
{
	char *delim = "\t\n ";

	values.opcode = strtok(buffer, delim);
	values.arg = strtok(NULL, delim);
}

/**
 * free_list - frees a list
 * @head: head of the list
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		if (!head)
			break;
		tmp = head;
		head = tmp->next;
		free(tmp);
	}
}

/**
 * check_int - checks for digits in a string
 * @str: pointer to string
 * Return: 1 if digits, 0 if fails
 */
int check_int(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			i++;
			continue;
		}
		else
			return (0);
		i++;
	}
	return (1);
}

/**
 * check_buffer - checks if buffer line needs to be tokenized
 * @str: pointer to string
 * Return: 1 if needed, 0 if not
 */
int check_buffer(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

/**
 * list_len - returns the number of elements in a linked list
 * @head: head pointer
 * Return: number of elements in a linked list
 */
size_t list_len(stack_t *head)
{
	size_t i;
	stack_t *tmp;

	tmp = head;
	for (i = 0; tmp; i++)
		tmp = tmp->next;
	return (i);
}
