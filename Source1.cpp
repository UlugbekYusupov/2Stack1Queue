#include"Source.h"

int main() {

	STACK* stack1 = createStack();
	STACK* stack2 = createStack();
	bool p = true;
	while (p) {
		int valueIN;
		scanf_s("%d", &valueIN);
		if (valueIN == 0) {
			p = false;
			break;
		}
		pushStack(stack1, valueIN);
	}
	while (!emptyStack(stack1)) {
		int valueIN = popStack(stack1);
		pushStack(stack2, valueIN);
	}
	destroyStack(stack1);
	while (!emptyStack(stack2)) {
		int data = popStack(stack2);
		cout << data << " ";
	}
	destroyStack(stack2);
	_getch();
	return 0;
}