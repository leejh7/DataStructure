#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main()
{
	// �ʱ�ȭ //
	List list;
	ListInit(&list);
	LData pNameCard;

	// ������ �߰� //
	pNameCard = MakeNameCard("������", "010-1111-2222");
	LInsert(&list, pNameCard);

	pNameCard = MakeNameCard("������", "010-2222-5555");
	LInsert(&list, pNameCard);

	pNameCard = MakeNameCard("������", "010-3333-7777");
	LInsert(&list, pNameCard);

	// ������ ��ü ��� //
	if (LFirst(&list, &pNameCard))
	{
		ShowNameCardInfo(pNameCard);
		while(LNext(&list, &pNameCard))
			ShowNameCardInfo(pNameCard);
	}
	printf("\n");

	// ã���� �ϴ� �̸��� �ڵ��� ��ȣ ���� //
	if (LFirst(&list, &pNameCard))
	{
		if (NameCompare(pNameCard, "������"))
		{
			ChangePhoneNum(pNameCard, "010-4444-8888");
		}
		else
		{
			while (LNext(&list, &pNameCard))
				if (NameCompare(pNameCard, "������"))
				{
					ChangePhoneNum(pNameCard, "010-4444-8888");
					break;
				}
		}
	}

	// Ÿ���� �̸��� �˻����� ���� //
	if (LFirst(&list, &pNameCard))
	{
		if (NameCompare(pNameCard, "������"))
		{
			LRemove(&list);
			free(pNameCard);
		}
		else
		{
			while (LNext(&list, &pNameCard))
				if (NameCompare(pNameCard, "������"))
				{
					LRemove(&list);
					free(pNameCard);
					break;
				}
		}
	}

	// ������ ��ü ��� //
	if (LFirst(&list, &pNameCard))
	{
		ShowNameCardInfo(pNameCard);
		while (LNext(&list, &pNameCard))
			ShowNameCardInfo(pNameCard);
	}
	printf("\n\n");

	return 0;
}