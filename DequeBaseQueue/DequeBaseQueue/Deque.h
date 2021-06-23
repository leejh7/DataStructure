#pragma once

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _Node
{
	Data data;
	struct _Node * next;
	struct _Node * prev;
}Node;

typedef struct _dlDeque
{
	Node * head;
	Node * tail;
}DLDeque;

typedef DLDeque Deque;

void DequeInit(Deque * pdeq);
int DQIsEmpty(Deque * pdeq);

void DQAddFirst(Deque * pdeq, Data data); // 덱의 머리에 노드 추가
void DQAddLast(Deque * pdeq, Data data); // 덱의 꼬리에 노드 추가
void DQRemoveFirst(Deque * pdeq); // 덱의 머리 노드 삭제
void DQRemoveLast(Deque * pdeq); // 덱의 꼬리 노드 삭제

Data DQGetFirst(Deque * pdeq);
Data DQGetLast(Deque * pdeq);