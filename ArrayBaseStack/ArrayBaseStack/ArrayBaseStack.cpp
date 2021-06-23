#include "ArrayBaseStack.h"

void StackInit(Stack * pstack)
{
	pstack->topIndex = -1;
}

bool SIsEmpty(Stack * pstack)
{
	if (pstack->topIndex == -1) return true;
	else return false;
}

void SPush(Stack * pstack, Data data)
{
	if (pstack->topIndex == 99)
	{
		printf("Stack Memory Full\n");
		exit(-1);
	}
	pstack->stackArr[++(pstack->topIndex)] = data;
}

Data SPop(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	return pstack->stackArr[(pstack->topIndex)--];
}

Data SPeek(Stack *pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	return pstack->stackArr[(pstack->topIndex)];
}