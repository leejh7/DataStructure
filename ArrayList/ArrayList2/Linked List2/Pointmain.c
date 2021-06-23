#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int main()
{
	// �ʱ�ȭ //
	List list;
	Point compPos;
	Point *ppos;

	ListInit(&list);

	// 4���� ������ ���� //
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	// ����� �������� ��� //
	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");
	// ���ϴ� �������� ���� // ex) x = 2, y = 1 �� ������ ����
	compPos.xpos = 2;
	compPos.ypos = 1;
	if (LFirst(&list, &ppos))
	{
		if (!PointComp(ppos, &compPos))
		{
			LRemove(&list);
		}
		while (LNext(&list, &ppos))
		{
			if (!PointComp(ppos, &compPos))
			{
				LRemove(&list);
				free(ppos);
			}
		}
	}

	// ���� �� ���� �������� ��� //
	printf("���� �������� ��: %d\n", LCount(&list));
	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");
}