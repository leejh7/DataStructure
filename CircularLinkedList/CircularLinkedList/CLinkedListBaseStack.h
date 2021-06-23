#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"
#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _ClistStack
{
	List * plist;
}ClistStack;

typedef ClistStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);