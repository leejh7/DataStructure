#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int Sort(LData d1, LData d2)
{
	if (d1->xpos < d2->xpos) return 0;
	else if (d1->xpos == d2->xpos)
	{
		if (d1->ypos < d2->ypos) return 0;
		else return 1;
	}
	else return 1;
}

int main()
{
	// ����Ʈ�� ���� �� �ʱ�ȭ //
	List list;
	//LData data;
	LData ppos;
	Point comp;
	ListInit(&list);

	SetSortRule(&list, Sort);	// �������� ����

	// 5���� ������ ���� //
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 1, 2);
	LInsert(&list, ppos);
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 3);
	LInsert(&list, ppos);
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 1, 3);
	LInsert(&list, ppos);

	// ����� �������� ��ü ��� //
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while(LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n\n");

	// ���� 22�� �˻��Ͽ� ��� ���� //
	comp.xpos = 2;
	comp.ypos = 2;
	if (LFirst(&list, &ppos))
	{
		if (PointComp(&comp, ppos)==0)
		{
			ppos = LRemove(&list);
			free(ppos);
		}
		while (LNext(&list, &ppos))
		{
			if (PointComp(&comp, ppos)==0)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	// ���� �� �����ִ� ������ ��ü ��� //
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n\n");
	return 0;
}