#include"Source.h"
/*createStack*/
STACK* createStack(void) {

	//Local Definitions
	STACK* stack;

	//Statements
	stack = (STACK*)malloc(sizeof(STACK));
	if (stack) {
		stack->count = 0;
		stack->top = NULL;
	}
	return stack;
}
/*pushStack*/
bool pushStack(STACK* stack, int dataInPtr) {
	//Local Definitions
	STACK_NODE* newPtr;

	//Statements
	newPtr = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if (!newPtr)
		return false;
	newPtr->dataPtr = dataInPtr;
	newPtr->link = stack->top;
	stack->top = newPtr;

	(stack->count)++;
	return true;
}
int popStack(STACK* stack) {
	//Local Definitions
	int dataOutPtr;
	STACK_NODE* temp;

	//Statements
	if (stack->count == 0)
		dataOutPtr = NULL;
	else {
		temp = stack->top;
		dataOutPtr = stack->top->dataPtr;
		stack->top = stack->top->link;
		free(temp);
		(stack->count)--;
	}
	return dataOutPtr;
}
/*stackTop*/
int stackTop(STACK* stack) {
	//Statements
	if (stack->count == 0)
		return NULL;
	else
		return stack->top->dataPtr;
}
bool emptyStack(STACK* stack) {
	//Statements
	return (stack->count == 0);
}
bool fullStack(STACK* stack) {
	//Local Definitions
	STACK_NODE* temp;

	//Statements
	if ((temp = (STACK_NODE*)malloc(sizeof(*(stack->top))))) {
		free(temp);
		return false;
	}
	return true;
}
int stackCount(STACK* stack) {
	return stack->count;
}
STACK* destroyStack(STACK* stack) {
	//Local Definitions
	STACK_NODE* temp;

	//Statements
	if (stack) {
		while (stack->top != NULL) {
			free(&stack->top->dataPtr);

			temp = stack->top;
			stack->top = stack->top->link;
			free(temp);
		}
		free(stack);
	}
	return NULL;
}
void printStack(STACK* stack) {
	if (emptyStack(stack)) {
		cout << "empty stack";
	}
	else {
		while (!emptyStack(stack)) {
			cout << *(int*)popStack(stack) << " ";
		}
	}
}