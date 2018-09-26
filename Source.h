#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;

/*Stack ADT Type Initialization
	Written by: Yusupov Mirzoulugbek
	Data: 2018.09.27
*/

typedef struct node {
	int dataPtr;
	struct node* link;
}STACK_NODE;

typedef struct {
	int count;
	STACK_NODE* top;
}STACK;


STACK* createStack(void);
STACK* destroyStack(STACK* stack);

int popStack(STACK* stack);
int stackTop(STACK* stack);
bool pushStack(STACK* stack, int dataInPtr);

bool emptyStack(STACK* stack);
bool fullStack(STACK* stack);
int stackCount(STACK* stack);
void printStack(STACK* stack);