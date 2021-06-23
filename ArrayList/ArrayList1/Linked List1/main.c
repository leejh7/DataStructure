#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	// 리스트 생성 및 초기화 //
	List list;
	int data;
	ListInit(&list);

	// 1 ~ 9까지 리스트에 저장 //
	for (int i = 1; i < 10; i++)
	{
		LInsert(&list, i);
	}

	// 리스트에 저장된 값을 순차적으로 참조하여 그 합을 계산 후 출력 //
	int sum = 0;
	if (LFirst(&list, &data))
	{
		sum += data;
		while (LNext(&list, &data))
		{
			sum += data;
		}
	}
	printf("총 합: %d\n", sum);

	// 리스트에 저장된 값들 중 2의 배수와 3의 배수에 해당하는 값을 모두 삭제 //
	if (LFirst(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0) {
			printf("삭제 된 데이터 값: %d\n",LRemove(&list));
		}
		while (LNext(&list, &data))
		{
			if (data % 2 == 0 || data % 3 == 0) {
				printf("삭제 된 데이터 값: %d\n", LRemove(&list));
			}
		}
	}

	// 수정 된 리스트 전체 출력 //
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