#pragma once

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _Node
{
	int data;
	struct _Node * next;
}Node;

typedef struct _lQueue
{
	Node * front;
	Node * rear;
}LQueue;

typedef LQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
void Dequeue(Queue * pq);

Data QPeek(Queue * pq);