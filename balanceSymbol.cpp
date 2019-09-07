#include "arrayStack.cpp"
#include <iostream>

using namespace std;


bool checkBalancedSymbol(string s)
{
	arrayStack* S = createStack();
	char ch = s[0];
	while(ch!='\0')
	{
		if(ch == '(' || ch == '{' || ch == '[')
		{
			push(S, ch)
		}
	}
}


int main(int argc, char const *argv[])
{
	
	push(S, 1);
	push(S, 2);
	push(S, 3);
	dynPush(S, 4);
	printStack(S);
	
	return 0;
}
