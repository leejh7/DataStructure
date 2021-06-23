#pragma once

#include <iostream>
using namespace std;
#define STACK_LEN 100

typedef int Data;

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
}arrayStack;

typedef arrayStack Stack;

void StackInit(Stack * pstack);
bool SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);	// 스택의 peek 연산
