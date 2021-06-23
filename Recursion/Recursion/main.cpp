#include <iostream>
using namespace std;

void hanoi(int n, char start, char to, char end)
{
	if (n == 1) printf("원반 %d 를 %c에서 %c 로 옮긴다.\n", n, start, end);
	else
	{
		hanoi(n - 1, start, end, to);
		printf("원반 %d 를 %c에서 %c 로 옮긴다.\n", n, start, end);
		hanoi(n - 1, to, start, end);
	}
}

int main()
{
	hanoi(3, 'A', 'B', 'C');
}