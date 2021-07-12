#pragma once

#define TRUE 1
#define FALSE 0

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree2.h"

typedef BTreeNode * Data;

typedef struct _node
{
	Data data;
	struct _node * next;
}Node;

typedef struct _listStack
{
	Node * head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);