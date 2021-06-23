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
	// 리스트의 생성 및 초기화 //
	List list;
	//LData data;
	LData ppos;
	Point comp;
	ListInit(&list);

	SetSortRule(&list, Sort);	// 오름차순 정렬

	// 5개의 데이터 저장 //
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

	// 저장된 데이터의 전체 출력 //
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while(LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n\n");

	// 숫자 22을 검색하여 모두 삭제 //
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

	// 삭제 후 남아있는 데이터 전체 출력 //
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n\n");
	return 0;
}