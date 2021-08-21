#pragma once

#include <stdio.h>

#define TRUE		1
#define FALSE		0

#define HEAP_LEN	100

typedef char HData;
typedef int PriorityComp(HData d1, HData d2);	// d1�� �켱������ ���� ��� 0���� ū �� ��ȯ
												// d2�� �켱������ ���� ��� 0���� ���� �� ��ȯ
												// d1�� d2�� �켱������ ���� ��� 0 ��ȯ

typedef struct _heap
{
	PriorityComp * comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap* ph, PriorityComp pc);

int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);
