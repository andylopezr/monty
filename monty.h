#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>

#define s stderr

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct values_s - hold global variables
 * @retvalue: return value of functions
 * @listmode: mode of list
 * @opcode: byte code command
 * @arg: argument to push command
 */
typedef struct values_s
{
	int retvalue;
	int listmode;
	char *opcode;
	char *arg;
} values_t;

extern values_t values;
values_t values;

/* find opcodes */
int opfinder(stack_t **head, unsigned int line_number);

/* list manipulation */
void push_mode(stack_t **head, unsigned int line_number);
void push_head(stack_t **head, int number);
void push_tail(stack_t **head, int number);
void stack(stack_t **head, unsigned int line_num);
void queue(stack_t **head, unsigned int line_num);

/* stack manipulation */
void pop(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void rotl(stack_t **head, unsigned int line_number);
void rotr(stack_t **head, unsigned int line_number);

/* prints stack */
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void pchar(stack_t **head, unsigned int line_number);
void pstr(stack_t **head, unsigned int line_number);
/*void prev(stack_t **head, unsigned int line_number);*/

/* math functions */
void add(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void mul(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void mod(stack_t **head, unsigned int line_number);

/* helpers */
void free_all(char *buffer, stack_t *head, FILE *monty);
void token(char *buffer);
void free_list(stack_t *head);
int check_head(char *str);
int check_buffer(char *str);
int check_int(char *str);
size_t list_len(stack_t *head);

#endif /* MONTY */
