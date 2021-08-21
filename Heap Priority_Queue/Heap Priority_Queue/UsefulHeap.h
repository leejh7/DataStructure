#pragma once

#include <stdio.h>

#define TRUE		1
#define FALSE		0

#define HEAP_LEN	100

typedef char HData;
typedef int PriorityComp(HData d1, HData d2);	// d1의 우선순위가 높은 경우 0보다 큰 값 반환
												// d2의 우선순위가 높은 경우 0보다 작은 값 반환
												// d1과 d2의 우선순위가 같은 경우 0 반환

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
