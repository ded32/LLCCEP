#ifndef LLCCEP_NATIVE_BACKEND_STACK_H
#define LLCCEP_NATIVE_BACKEND_STACK_H

#include <stddef.h>

struct stack {
	double *mem;
	size_t sz;
};

#define STACK_OPERATION_FAILED 1
#define STACK_OPERATION_OK     0

int stack_init(struct stack *stk);
int stack_push(struct stack *stk, double value);
int stack_pop(struct stack *stk);
int stack_top(struct stack *stk, double *value);
int stack_deinit(struct stack *stk);

#endif /* LLCCEP_NATIVE_BACKEND_STACK_H */
