#include "CircularQueue.h"

int NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void QueueInit(Queue * pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue * pq)
{
	if (pq->front == pq->rear) return TRUE;
	else return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front)
	{
		printf("Queue is full!\n");
		exit(-1);
	}
	pq->rear = NextPosIdx(pq->rear);
	pq->queue[pq->rear] = data;
}

void Dequeue(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue is empty!\n");
		exit(-1);
	}
	pq->front = NextPosIdx(pq->front);
}

Data QPeek(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue is empty!\n");
		exit(-1);
	}
	int ret = pq->queue[NextPosIdx(pq->front)];
	return ret;
}