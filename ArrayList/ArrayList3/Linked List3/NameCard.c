#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "NameCard.h"

NameCard * MakeNameCard(char * name, char * phone)
{
	NameCard * pNameCard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(pNameCard->name, name);
	strcpy(pNameCard->phone, phone);
	return pNameCard;
}

void ShowNameCardInfo(NameCard * pcard)
{
	printf("�� ��: %s\n", pcard->name);
	printf("��ȭ��ȣ: %s\n\n", pcard->phone);
}

int NameCompare(NameCard * pcard, char * name)
{
	if (strcmp(pcard->name, name) == 0)
		return 1;
	else return 0;
}

void ChangePhoneNum(NameCard * pcard, char * phone)
{
	strcpy(pcard->phone, phone);
}