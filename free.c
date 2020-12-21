#include "monty.h"
/**
 * free_all - free helper
 * @buffer: containing file lines
 * @head: head pointer
 * @monty: File descriptor
 */
void free_all(char *buffer, stack_t *head, FILE *monty)
{
	free(buffer);
	free_list(head);
	fclose(monty);
}
