#include <iostream>
#include "arrayStack.h"
using namespace std;

arrayStack* createStack()
{
	arrayStack* S = (arrayStack*) malloc(sizeof(arrayStack));

	S -> capacity = 3;
	S -> top = -1;
	S -> array = (int*) malloc(sizeof(int)*S->capacity);
	if(!S->array) return NULL;
	return S;
}

bool isEmpty(arrayStack* S)
{
	return (S->top == -1);
}

bool isFull(arrayStack* S)
{
	return (S->capacity == S->top + 1);
}

void push(arrayStack* S, int data)
{
	if(isFull(S)) 
	{

		printf("stack overflow\n");
		return;
	}

	S->array[++(S->top)] = data;
	return;
}

void doubleStack(arrayStack* S)
{
	S->capacity *= 2;
	S->array = (int*) realloc(S->array, S->capacity*sizeof(int));
}

void dynPush(arrayStack* S, int data)
{
	if(isFull(S)) 
		doubleStack(S);

	S->array[++(S->top)] = data;
	return;
}

int pop(arrayStack* S)
{
	if(isEmpty(S))
	{
		printf("stack underflow\n");
		return -1;
	}

	int data = S-> array[S->top--];
	return data;
}

int top(arrayStack* S)
{
	if(isEmpty(S))
		return -1;
	return S->array[S->top];
}

void deleteStack(arrayStack* S)
{
	if(S)
	{
		if(S->array)
			free(S->array);

		free(S);
	}
	return;
}

int stackSize(arrayStack* S)
{
	return (S->top + 1);
}

void printStack(arrayStack* S)
{
	for (int i = S->top; i > -1; --i)
	{
		/* code */
		printf("%d\n", S->array[i]);
	}
}



