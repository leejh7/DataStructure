#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int main()
{
	// 초기화 //
	List list;
	Point compPos;
	Point *ppos;

	ListInit(&list);

	// 4개의 데이터 저장 //
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

	// 저장된 데이터의 출력 //
	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");
	// 원하는 데이터의 삭제 // ex) x = 2, y = 1 인 데이터 삭제
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

	// 삭제 후 남은 데이터의 출력 //
	printf("남은 데이터의 수: %d\n", LCount(&list));
	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");
}