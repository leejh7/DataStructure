#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	// ����Ʈ ���� �� �ʱ�ȭ //
	List list;
	int data;
	ListInit(&list);

	// 1 ~ 9���� ����Ʈ�� ���� //
	for (int i = 1; i < 10; i++)
	{
		LInsert(&list, i);
	}

	// ����Ʈ�� ����� ���� ���������� �����Ͽ� �� ���� ��� �� ��� //
	int sum = 0;
	if (LFirst(&list, &data))
	{
		sum += data;
		while (LNext(&list, &data))
		{
			sum += data;
		}
	}
	printf("�� ��: %d\n", sum);

	// ����Ʈ�� ����� ���� �� 2�� ����� 3�� ����� �ش��ϴ� ���� ��� ���� //
	if (LFirst(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0) {
			printf("���� �� ������ ��: %d\n",LRemove(&list));
		}
		while (LNext(&list, &data))
		{
			if (data % 2 == 0 || data % 3 == 0) {
				printf("���� �� ������ ��: %d\n", LRemove(&list));
			}
		}
	}

	// ���� �� ����Ʈ ��ü ��� //
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}
	printf("\n");
	return 0;
}