#include "UsefulHeap.h"

void HeapInit(Heap* ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
}

int HIsEmpty(Heap* ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIdx(int idx)	// 부모 노드의 인덱스 반환
{
	return idx / 2;
}

int GetLChildIdx(int idx)	// L 자식 노드의 인덱스 반환
{
	return idx * 2;
}

int GetRChildIdx(int idx)	// R 자식 노드의 인덱스 반환
{
	return idx * 2 + 1;
}

int GetHiPriChildIdx(Heap* ph, int idx)		
{
	if (GetLChildIdx(idx) > ph->numOfData)	// 자식 노드가 없는 단말 노드인 경우
		return 0;
	else if (GetLChildIdx(idx) == ph->numOfData)	// 자식 노드가 하나인 경우
		return GetLChildIdx(idx);
	else    // 자식 노드가 두 개인 경우(두 자식 노드의 우선순위를 비교해야 함)
	{
		if (ph->comp(ph->heapArr[GetLChildIdx(idx)], ph->heapArr[GetRChildIdx(idx)]) > 0)	// L 자식 노드의 우선순위가 높은 경우
			return GetLChildIdx(idx);
		else
			return GetRChildIdx(idx);
	}
}

void HInsert(Heap* ph, HData data)
{
	if (ph->numOfData + 1 == HEAP_LEN)
	{
		printf("더 이상 데이터를 추가 할 수 없습니다!\n");
		exit(-1);
	}

	int idx = ph->numOfData + 1;

	while (idx != 1)
	{
		if (ph->comp(data, ph->heapArr[GetParentIdx(idx)]) < 0)	// 추가 할 데이터의 우선순위가 부모 노드의 우선순위보다 낮은 경우
			break;
		else
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
			idx = GetParentIdx(idx);
		}
	}

	ph->heapArr[idx] = data;
	ph->numOfData++;
}

HData HDelete(Heap* ph)
{
	if (HIsEmpty(ph))
	{
		printf("더 이상 데이터를 삭제 할 수 없습니다!\n");
		exit(-1);
	}

	HData rData = ph->heapArr[1];	// Heap 자료구조에서 최상위 루트 노드가 삭제된다.
	HData lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIdx(ph, parentIdx))	//childIdx가 0이 되는 경우 반복문 종료 (=parentIdx가 단말노드 위치에 오면 종료)
	{
		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)	// 마지막 노드의 우선순위가 자식 노드의 우선순위보다 같거나 높은 경우
			break;
		else
		{
			ph->heapArr[parentIdx] = ph->heapArr[childIdx];
			parentIdx = childIdx;
		}
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData--;
	return rData;
}
