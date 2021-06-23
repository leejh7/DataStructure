#include "ListBaseQueue.h"
#include <stdio.h>

int main()
{
	// Init
	Queue q;
	QueueInit(&q);

	// 데이터 추가
	Enqueue(&q, 1); Enqueue(&q, 2);
	Enqueue(&q, 3); Enqueue(&q, 4);
	Enqueue(&q, 5);

	// 데이터 삭제
	while (!QIsEmpty(&q))
	{
		printf("%d ", QPeek(&q));
		Dequeue(&q);
	}

	return 0;
}