#include <stdio.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	int *sortArr = (int*)malloc(sizeof(int) * (right + 1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] > arr[rIdx])
		{
			sortArr[sIdx] = arr[fIdx++];
		}
		else
			sortArr[sIdx] = arr[rIdx++];
		
		sIdx++;
	}

	while (fIdx <= mid)
	{
		sortArr[sIdx++] = arr[fIdx++];
	}

	while (rIdx <= right)
	{
		sortArr[sIdx++] = arr[rIdx++];
	}
	
	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}

int main()
{
	int arr[8] = { 8,2,3,7,1,5,4,6 };
	MergeSort(arr, 0, 7);
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		printf("%d ", arr[i]);
}