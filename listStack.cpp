#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* next;
};

node* createStack()
{
	return NULL;
}

node* createNode(int data)
{
	node* temp = (node*) malloc(sizeof(node*));

	temp -> data = data;
	temp -> next = NULL;

	return temp;
}

bool isEmpty(node* S)
{
	return (S==NULL) ;
}

void push(node** S, int data)
{
	node* temp = *S;

	node* newnode = createNode(data);
	newnode->next = temp;
	temp = newnode;

	*S = temp;
}

int pop(node** S)
{
	if(isEmpty(*S))
	{
		printf("stack underflow\n");
		return -1;
	}

	node* temp = *S;
	int data = temp -> data;

	*S = temp -> next;
	free(temp);
	return data;
}

int stackSize(node* S)
{
	int count = 0;
	while(S)
	{
		count++;
		S = S-> next;
	}

	return count;
}

int main(int argc, char const *argv[])
{
	node* S = createStack();

	push(&S, 1);
	push(&S, 2);

	printf("%d\n", pop(&S));
	printf("%d\n", stackSize(S));
	return 0;
}