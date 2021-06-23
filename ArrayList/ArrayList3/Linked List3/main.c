#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main()
{
	// 초기화 //
	List list;
	ListInit(&list);
	LData pNameCard;

	// 데이터 추가 //
	pNameCard = MakeNameCard("이진수", "010-1111-2222");
	LInsert(&list, pNameCard);

	pNameCard = MakeNameCard("한지영", "010-2222-5555");
	LInsert(&list, pNameCard);

	pNameCard = MakeNameCard("조수진", "010-3333-7777");
	LInsert(&list, pNameCard);

	// 데이터 전체 출력 //
	if (LFirst(&list, &pNameCard))
	{
		ShowNameCardInfo(pNameCard);
		while(LNext(&list, &pNameCard))
			ShowNameCardInfo(pNameCard);
	}
	printf("\n");

	// 찾고자 하는 이름의 핸드폰 번호 변경 //
	if (LFirst(&list, &pNameCard))
	{
		if (NameCompare(pNameCard, "조수진"))
		{
			ChangePhoneNum(pNameCard, "010-4444-8888");
		}
		else
		{
			while (LNext(&list, &pNameCard))
				if (NameCompare(pNameCard, "조수진"))
				{
					ChangePhoneNum(pNameCard, "010-4444-8888");
					break;
				}
		}
	}

	// 타겟의 이름을 검색으로 삭제 //
	if (LFirst(&list, &pNameCard))
	{
		if (NameCompare(pNameCard, "한지영"))
		{
			LRemove(&list);
			free(pNameCard);
		}
		else
		{
			while (LNext(&list, &pNameCard))
				if (NameCompare(pNameCard, "한지영"))
				{
					LRemove(&list);
					free(pNameCard);
					break;
				}
		}
	}

	// 데이터 전체 출력 //
	if (LFirst(&list, &pNameCard))
	{
		ShowNameCardInfo(pNameCard);
		while (LNext(&list, &pNameCard))
			ShowNameCardInfo(pNameCard);
	}
	printf("\n\n");

	return 0;
}