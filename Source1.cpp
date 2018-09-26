#include"Source.h"

int main() {

	STACK* stack1 = createStack();
	STACK* stack2 = createStack();
	bool p = true;
	while (p) {
		char ch;
		cin >> ch;
		switch (ch)
		{
		case 'i':
			int valueIN;
			scanf_s("%d", &valueIN);
			pushStack(stack1, valueIN);
			break;
		case 't':
			while (!emptyStack(stack1)) {
				int valueIN = popStack(stack1);
				pushStack(stack2, valueIN);
			}
			break;
		case 'p':
			while (!emptyStack(stack2)) {
				int data = popStack(stack2);
				cout << data << " ";
			}
			break;
		case 'e':
			exit(0);
			break;
		}
	}
	destroyStack(stack1);
	destroyStack(stack2);
	_getch();
	return 0;
}
