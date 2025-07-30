// Env Virtual Machine
//

#ifndef ENVVM_H
#define ENVVM_H

#include <string>

// Define STACK_SIZE.
// Enough space. (1024 bytes of stack size).
//
#define STACK_SIZE		1024

// The Program Counter, counts where you are in the program.
//
int program_counter =		0;

// The Stack Pointer.
//
int stack_pointer =			0;

// Define OpCodes. But this is just v1.0, so there arent so many OpCodes.
// (im pretty sure you dont NEED that many OpCodes lol)
//
typedef enum {
	OP_PRINT,
	OP_CHANGE,
	OP_STATIC,
	OP_ADD,
	OP_SUB,
	OP_MULTI,
	OP_POWEROF,
	OP_PUSH,
	OP_POP
} OpCode;

// An Instruction, consisting of 2 ints:
// 1. OpCode: the instruction to be ran.
// 2. Operands: the value in the OpCode.
//
typedef struct {
	OpCode opcode;
	int operand;
} Instruction;

void ENV_PUSH(int number);
int ENV_POP();

#endif