#include <iostream>
#include "stack.h"
	
int main(void)
{
	CStackList<int> iStack;
	for (int i = 0; i < 10; i++)
	{
		iStack.push(i + 1);
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", iStack.pop());
	}

	return 0;
}