#pragma once

#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100

typedef int Data;

typedef struct _Queue
{
	int front;
	int rear;
	Data queue[QUE_LEN];
}CQueue;

typedef CQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
void Dequeue(Queue * pq);

Data QPeek(Queue * pq);
