#include <stddef.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

#define check_stk(st, func) \
{ \
	if (!st) { \
		prerr("%s(): invalid stack pointer", \
		      func); \
	} \
}

#define prerr(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__);

int stack_init(struct stack *stk)
{
	check_stk(stk, "stack_init");

	
	stk->mem = NULL;
	stk->sz = 0;

	return STACK_OPERATION_OK;
}

int stack_push(struct stack *stk, double value)
{
	check_stk(stk, "stack_push");

	stk->mem = (double *)realloc(stk->mem, (stk->sz++) * sizeof(double));
	if (!(stk->mem)) {
		prerr("stack_push(): failed to reallocate memory: %s",
		      strerror(errno));
		return STACK_OPERATION_FAILED;
	}

	stk->mem[stk->sz - 1] = value;

	return STACK_OPERATION_OK;
}

int stack_pop(struct stack *stk)
{
	check_stk(stk, "stack_pop");

	if (!(stk->mem) || !(stk->sz)) {
		prerr("stack_pop(): stack is empty or invalid memory pointer");
		return STACK_OPERATION_FAILED;
	}

	stk->mem = (double *)realloc(stk->mem, (stk->sz--) * sizeof(double));

	return STACK_OPERATION_OK;
}

int stack_top(struct stack *stk, double *value)
{
	check_stk(stk, "stack_top");

	if (!(stk->mem) || !(stk->sz)) {
		prerr("stack_top(): stack is empty or invalid memory pointer");
		return STACK_OPERATION_FAILED;
	}

	*value = stk->mem [stk->sz - 1];
	
	return STACK_OPERATION_OK;
}

int stack_deinit(struct stack *stk)
{
	check_stk(stk, "stack_deinit");

	if (stk->mem) {
		free((void *)(stk->mem));
		stk->mem = NULL;
	}

	stk->sz = 0;

	return STACK_OPERATION_OK;
}

#undef check_stk
#undef prerr
