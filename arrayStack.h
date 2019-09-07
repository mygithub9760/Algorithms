
struct arrayStack
{
	int capacity;
	int* array;
	int top;
};
arrayStack* createStack();
bool isEmpty(arrayStack* );
bool isFull(arrayStack* );
void push(arrayStack* , int );
void doubleStack(arrayStack* );
void dynPush(arrayStack* , int);
int pop(arrayStack*);
int top(arrayStack*);
void deleteStack(arrayStack* );
int stackSize(arrayStack* );
void printStack(arrayStack* );
