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

int GetParentIdx(int idx)	// �θ� ����� �ε��� ��ȯ
{
	return idx / 2;
}

int GetLChildIdx(int idx)	// L �ڽ� ����� �ε��� ��ȯ
{
	return idx * 2;
}

int GetRChildIdx(int idx)	// R �ڽ� ����� �ε��� ��ȯ
{
	return idx * 2 + 1;
}

int GetHiPriChildIdx(Heap* ph, int idx)		
{
	if (GetLChildIdx(idx) > ph->numOfData)	// �ڽ� ��尡 ���� �ܸ� ����� ���
		return 0;
	else if (GetLChildIdx(idx) == ph->numOfData)	// �ڽ� ��尡 �ϳ��� ���
		return GetLChildIdx(idx);
	else    // �ڽ� ��尡 �� ���� ���(�� �ڽ� ����� �켱������ ���ؾ� ��)
	{
		if (ph->comp(ph->heapArr[GetLChildIdx(idx)], ph->heapArr[GetRChildIdx(idx)]) > 0)	// L �ڽ� ����� �켱������ ���� ���
			return GetLChildIdx(idx);
		else
			return GetRChildIdx(idx);
	}
}

void HInsert(Heap* ph, HData data)
{
	if (ph->numOfData + 1 == HEAP_LEN)
	{
		printf("�� �̻� �����͸� �߰� �� �� �����ϴ�!\n");
		exit(-1);
	}

	int idx = ph->numOfData + 1;

	while (idx != 1)
	{
		if (ph->comp(data, ph->heapArr[GetParentIdx(idx)]) < 0)	// �߰� �� �������� �켱������ �θ� ����� �켱�������� ���� ���
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
		printf("�� �̻� �����͸� ���� �� �� �����ϴ�!\n");
		exit(-1);
	}

	HData rData = ph->heapArr[1];	// Heap �ڷᱸ������ �ֻ��� ��Ʈ ��尡 �����ȴ�.
	HData lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIdx(ph, parentIdx))	//childIdx�� 0�� �Ǵ� ��� �ݺ��� ���� (=parentIdx�� �ܸ���� ��ġ�� ���� ����)
	{
		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)	// ������ ����� �켱������ �ڽ� ����� �켱�������� ���ų� ���� ���
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
