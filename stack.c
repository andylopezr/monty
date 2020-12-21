#include "monty.h"
/**
 * pop - deletes the head node
 * @head: pointer to head
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
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	if (!*head)
	{
		fprintf(s, "\033[31mL%u: can't pop an empty stack\033[0m\n", line_number);
		values.retvalue = -1;
		return;
	}
	tmp = *head;
	if (tmp->next)
		tmp->next->prev = NULL;
	*head = tmp->next;
	free(tmp);
	values.retvalue = 0;
}

/**
 * swap - swaps the top two elements of the stack
 * @head: head pointer
 * @line_number: monty file line counter
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	if (list_len(*head) < 2)
	{
		fprintf(s, "\033[31mL%u: can't swap, stack too short\033[0m\n", line_number);
		values.retvalue = -1;
		return;
	}

	tmp = *head;
	*head = tmp->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
	tmp->prev = *head;
	(*head)->prev = NULL;
	if (tmp->next)
		(tmp->next)->prev = tmp;
	values.retvalue = 0;
}

/**
 * nop - does nothing
 * @head: head pointer
 * @line_number: monty file line counter
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

/**
 * rotl - rotates the stack to the top
 * @head: pointer to a pointer
 * @line_number: monty file line counter
 */
void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;

	if (!head || !(*head) || !(*head)->next)
		return;

	tmp = *head;
	*head = tmp->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*head)->prev;
	tmp->next->next = NULL;
	tmp->next->prev = tmp;
	(*head)->prev = NULL;
	values.retvalue = 0;
}

/**
 * rotr - rotates the stack to the bottom
 * @head: pointer to a pointer
 * @line_number: monty file line counter
 */
void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;

	if (!head || !(*head) || !(*head)->next)
		return;
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *head;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	*head = tmp;
	tmp->next->prev = tmp;
	values.retvalue = 0;
}
