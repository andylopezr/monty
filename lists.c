#include "monty.h"

/**
 * push_mode - checks for the stack/queue mode
 * @head: head pointer
 * @line_number: monty file line counter
 */
void push_mode(stack_t **head, unsigned int line_number)
{
	int number;

	if (!values.arg || !check_int(values.arg))
	{
		fprintf(s, "L%u: usage: push integer\n", line_number);
		values.retvalue = -1;
		return;
	}
	number = atoi(values.arg);
	if (values.listmode == 0)
		push_head(head, number);
	else
		push_tail(head, number);
}

/**
 * push_head - adds a new node to the beginning of the linked list
 * @head: head pointer
 * @number: monty file line counter
 */
void push_head(stack_t **head, int number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(s, "Error: malloc failed\n");
		values.retvalue = -1;
		return;
	}
	node->n = number;
	node->prev = NULL;
	node->next = NULL;
	if (*head)
	{
		node->next = *head;
		(*head)->prev = node;
	}
	*head = node;
	values.retvalue = 0;
}

/**
 * push_tail - adds a new node to the end of the linked list
 * @head: head pointer
 * @number: monty file line counter
 */
void push_tail(stack_t **head, int number)
{
	stack_t *node;
	stack_t *tmp;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(s, "Error: malloc failed\n");
		values.retvalue = -1;
		return;
	}
	node->n = number;
	node->next = NULL;
	if (!*head)
	{
		node->prev = NULL;
		*head = node;
		values.retvalue = 0;
		return;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	node->prev = tmp;
	tmp->next = node;
	values.retvalue = 0;
}

/**
 * stack - sets the list mode to a stack [LIFO] default behaviour
 * @head: head pointer
 * @line_number: monty file line counter
 */
void stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	if (values.listmode == 0)
		return;
	values.listmode = 0;
}

/**
 * queue - sets the list mode to a queue [FIFO]
 * @head: head pointer
 * @line_number: monty file line counter
 */
void queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	if (values.listmode == 1)
		return;
	values.listmode = 1;
}
