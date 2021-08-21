#include <stdio.h>

int ISearch(int ar[], int first, int last, int target)
{
	int mid;
	if(ar[first] > target || ar[last] < target)
		return -1;

	mid = ((double)(target - ar[first]) / (ar[last] - ar[first]) * (last - first)) + first;
	if (ar[mid] == target)
		return mid;
	else if (ar[mid] < target)
		return ISearch(ar, mid+ 1, last, target);
	else
		return ISearch(ar, first, mid - 1, target);
}

int main()
{
	int arr[] = { 1,3,5,7,9 };
	int idx, target = 7;

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, target);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);
	

	target = 10;
	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, target);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);
	

	target = 2;
	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, target);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);

	return 0;
}