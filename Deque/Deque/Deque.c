#include "Deque.h"

void DequeInit(Deque * pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Deque * pdeq)
{
	if (pdeq->head == NULL) return TRUE;
	else return FALSE;
}

void DQAddFirst(Deque * pdeq, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = NULL;

	if (DQIsEmpty(pdeq))
	{
		newNode->next = NULL;
		pdeq->tail = newNode;
	}
	else
	{
		newNode->next = pdeq->head;
		pdeq->head->prev = newNode;
	}

	pdeq->head = newNode;
}

void DQAddLast(Deque * pdeq, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (DQIsEmpty(pdeq))
	{
		newNode->prev = NULL;
		pdeq->head = newNode;
	}
	else
	{
		newNode->prev = pdeq->tail;
		pdeq->tail->next = newNode;
	}

	pdeq->tail = newNode;
}

void DQRemoveFirst(Deque * pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque is empty!\n");
		exit(-1);
	}

	Node * rtmp = pdeq->head;
	pdeq->head = pdeq->head->next;
	
	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;

	free(rtmp);
}

void DQRemoveLast(Deque * pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque is empty!\n");
		exit(-1);
	}

	Node * rtmp = pdeq->tail;
	pdeq->tail = pdeq->tail->prev;
	
	if (pdeq->tail == NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;

	free(rtmp);
}

Data DQGetFirst(Deque * pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque is empty!\n");
		exit(-1);
	}
	return pdeq->head->data;
}

Data DQGetLast(Deque * pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque is empty!\n");
		exit(-1);
	}
	return pdeq->tail->data;
}