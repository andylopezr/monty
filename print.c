#include "monty.h"
/**
 * pall - prints all the values on the stack from the top of the stack
 * @head: head pointer
 * @ln: monty file line counter
 */
void pall(stack_t **head, unsigned int ln)
{
	stack_t *tmp;

	(void)ln;
	tmp = *head;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	values.retvalue = 0;
}

/**
 * pint - prints the value at the top of the stack
 * @head: head pointer
 * @ln: monty file line counter
 */
void pint(stack_t **head, unsigned int ln)
{
	if (!head || !*head)
	{
		fprintf(s, "L%d: can't pint, stack empty\n", ln);
		values.retvalue = -1;
		return;
	}
	else
		printf("%d\n", (*head)->n);
	values.retvalue = 0;
}

/**
 * pchar - prints the char at the top of the stack
 * @head: head pointer
 * @ln: monty file line counter
 */
void pchar(stack_t **head, unsigned int ln)
{
	if (!head || !*head)
	{
		fprintf(s, "L%d: can't pchar, stack empty\n", ln);
		values.retvalue = -1;
		return;
	}
	if ((*head)->n < 32 || (*head)->n > 126)
	{
		fprintf(s, "L%u: can't pchar, value out of range\n", ln);
		values.retvalue = -1;
		return;
	}
	printf("%c\n", (*head)->n);
	values.retvalue = 0;
}

/**
 * pstr -  prints the string starting at the top of the stack
 * @head: head pointer
 * @ln: monty file line counter
 */
void pstr(stack_t **head, unsigned int ln)
{
	stack_t *tmp;

	(void)ln;
	if (!head || !(*head))
	{
		putchar('\n');
		return;
	}
	tmp = *head;
	while (tmp)
	{
		if ((tmp->n == 0) || (tmp->n < 32) || (tmp->n > 126))
			break;
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
	values.retvalue = 0;
}
