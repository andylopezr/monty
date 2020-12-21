#include "monty.h"
/**
 * add - adds top two elements of the stack
 * @head: head pointer
 * @line_number: monty file line counter
 *                                __
 *                /\             |  |
 *               /  \   _ __   __| |_   _
 *              / /\ \ | '_ \ / _` | | | |
 *             / ____ \| | | | (_| | |_| |
 *            / /_.__\ \_| | |\__, |\__, |
 *            | | _._ \_DEC|_|2020_| __/ |
 *            | |_.__/ _ \| '_ \ / _ \_  /
 *            | |___| (_) | |_) | .__// /_
 *            |______\___/| .__/ \___/___|
 *                        | |
 *                       |__|
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	int result;

	if (list_len(*head) < 2)
	{
		fprintf(s, "L%u: can't add, stack too short\n", line_number);
		values.retvalue = -1;
		return;
	}
	tmp = (*head)->next;
	result = (*head)->n + tmp->n;
	tmp->n = result;
	pop(head, line_number);
	values.retvalue = 0;
}

/**
 * sub - substracts top two elements of the stack
 * @head: head pointer
 * @line_number: monty file line counter
 */
void sub(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	if (list_len(*head) < 2)
	{
		fprintf(s, "L%u: can't sub, stack too short\n", line_number);
		values.retvalue = -1;
		return;
	}
	tmp = (*head)->next;
	tmp->n -= (*head)->n;
	pop(head, line_number);
	values.retvalue = 0;
}

/**
 * _div - divides top two elements of the stack
 * @head: head pointer
 * @line_number: monty file line counter
 */
void _div(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	if (list_len(*head) < 2)
	{
		fprintf(s, "L%u: can't div, stack too short\n", line_number);
		values.retvalue = -1;
		return;
	}
	if ((*head)->n == 0)
	{
		fprintf(s, "L%d: division by zero\n", line_number);
		values.retvalue = -1;
		return;
	}
	tmp = (*head)->next;
	tmp->n /= (*head)->n;
	pop(head, line_number);
	values.retvalue = 0;
}

/**
 * mul - multiplies top two elements of the stack
 * @head: head pointer
 * @line_number: monty file line counter
 */
void mul(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	int result;

	if (list_len(*head) < 2)
	{
		fprintf(s, "L%u: can't mul, stack too short\n", line_number);
		values.retvalue = -1;
		return;
	}
	if ((*head)->n == 0)
	{
		fprintf(s, "L%d: multiplied by zero\n", line_number);
		values.retvalue = -1;
		return;
	}
	tmp = (*head)->next;
	result = (tmp->n * (*head)->n);
	pop(head, line_number);
	tmp->n = result;
	values.retvalue = 0;
}


/**
 * mod - modulus of top two elements of the stack
 * @head: head pointer
 * @line_number: monty file line counter
 */
void mod(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	int result;

	if (list_len(*head) < 2)
	{
		fprintf(s, "L%u: can't mod, stack too short\n", line_number);
		values.retvalue = -1;
		return;
	}
	if ((*head)->n == 0)
	{
		fprintf(s, "L%d: division by zero\n", line_number);
		values.retvalue = -1;
		return;
	}
	tmp = (*head)->next;
	result = (tmp->n % (*head)->n);
	pop(head, line_number);
	tmp->n = result;
	values.retvalue = 0;
}
