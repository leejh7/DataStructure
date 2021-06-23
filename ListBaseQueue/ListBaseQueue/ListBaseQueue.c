#include "ListBaseQueue.h"

void QueueInit(Queue * pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue * pq)
{
	if (pq->front == NULL) return TRUE;
	else return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	
	if (QIsEmpty(pq))	// ù �߰��� ���
	{
		pq->front = newNode;
	}
	else    // ù �߰��� �ƴ� ���
	{
		pq->rear->next = newNode;
	}
	pq->rear = newNode;
}

void Dequeue(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue is empty!\n");
		exit(0);
	}

	Node * tmp = pq->front;
	pq->front = pq->front->next;
	free(tmp);
}

Data QPeek(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue is empty!\n");
		exit(0);
	}

	Data ret = pq->front->data;
	return ret;
}