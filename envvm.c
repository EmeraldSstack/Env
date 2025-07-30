#include <stdio.h>
#include "envvm.h"
#include "enverrorcodes.h"

int stack[STACK_SIZE];

void ENV_PUSH(int number) {
	if (stack_pointer >= STACK_SIZE) {
		printf(STACK_ERROR_NAME STACK_OVERFLOW"\n");
		return;
	}
	stack[stack_pointer++] = number;
}

int ENV_POP() {
	if (stack_pointer <= 0) {
		printf(STACK_ERROR_NAME STACK_UNDERFLOW"\n");
		return -1;
	}
	return stack[--stack_pointer];
}
