#include <iostream>
using namespace std;

void hanoi(int n, char start, char to, char end)
{
	if (n == 1) printf("���� %d �� %c���� %c �� �ű��.\n", n, start, end);
	else
	{
		hanoi(n - 1, start, end, to);
		printf("���� %d �� %c���� %c �� �ű��.\n", n, start, end);
		hanoi(n - 1, to, start, end);
	}
}

int main()
{
	hanoi(3, 'A', 'B', 'C');
}