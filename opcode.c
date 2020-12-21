#include "monty.h"
/**
 * opfinder - finds the opcode to execute
 * @head: Pointer to linked list
 * @ln: file line counter
 * Return: 0 on success -1 on failure
 */
int opfinder(stack_t **head, unsigned int ln)
{
	int i, c;
	instruction_t opcodes[] = {
		{"push", push_mode}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop},
		{"sub", sub}, {"div", _div}, {"mul", mul}, {"mod", mod},
		{"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl},
		{"rotr", rotr}, {"stack", stack}, {"queue", queue}, {NULL, NULL}
	};

	for (i = 0; opcodes[i].opcode; i++)
	{
		c = strncmp(values.opcode, opcodes[i].opcode, strlen(values.opcode));
		if (c == 0)
		{
			opcodes[i].f(head, ln);
			return (values.retvalue);
		}
	}
	fprintf(s, "L%u: unknown instruction %s\n", ln, values.opcode);
	values.retvalue = -1;
	return (values.retvalue);
}
