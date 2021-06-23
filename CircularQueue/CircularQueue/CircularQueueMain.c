#include "CircularQueue.h"
#include <stdio.h>

int main()
{
	// Init
	Queue q;
	QueueInit(&q);

	// ������ �ֱ�
	Enqueue(&q, 1); Enqueue(&q, 2);
	Enqueue(&q, 3); Enqueue(&q, 4);

	// ������ ������
	while (!QIsEmpty(&q))
	{
		printf("%d ", QPeek(&q));
		Dequeue(&q);
	}

	Enqueue(&q, 1); Enqueue(&q, 2);
	Enqueue(&q, 3); 
	Enqueue(&q, 4);

	return 0;
}