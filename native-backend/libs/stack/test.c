#include <stdio.h>

#include "stack.h"

int main(void)
{
	struct stack stk = {};
	double tmp = 0;

	stack_init(&stk);

	stack_push(&stk, 45.f);
	stack_push(&stk, 54.f);

	stack_top(&stk, &tmp);
	printf("%lg\n", tmp);
	stack_pop(&stk);
	stack_top(&stk, &tmp);
	printf("%lg\n", tmp);

	stack_deinit(&stk);

	return 0;
}
