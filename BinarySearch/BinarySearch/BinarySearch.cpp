#include <iostream>
using namespace std;

int BSearch(int ar[], int len, int target)
{
	int first = 0;
	int last = len - 1;
	int mid;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (ar[mid] == target)
		{
			return mid;
		}
		else if (ar[mid] < target)
		{
			first = mid + 1;
		}
		else
		{
			last = mid - 1;
		}
	}
	return -1;
}

int BsearchRecur(int ar[], int first, int last, int target)
{
	if (first > last) return -1;
	else
	{
		int mid = (first + last) / 2;
		if (ar[mid] == target) return mid;
		else if (ar[mid] < target) return BsearchRecur(ar, mid + 1, last, target);
		else return BsearchRecur(ar, first, mid - 1, target);
	}
}

int main()
{
	int arr[] = { 1,3,5,7,9 };
	int idx;
	int target;
	cin >> target;
	idx = BSearch(arr, sizeof(arr) / sizeof(int), target);
	if (idx == -1)
	{
		cout << "Å½»ö ½ÇÆÐ" << endl;
	}
	else
	{
		cout << "Å¸°Ù ÀúÀå ÀÎµ¦½º: " << idx << endl;
	}

	cin >> target;
	idx = BSearch(arr, sizeof(arr) / sizeof(int), target);
	if (idx == -1)
	{
		cout << "Å½»ö ½ÇÆÐ" << endl;
	}
	else
	{
		cout << "Å¸°Ù ÀúÀå ÀÎµ¦½º: " << idx << endl;
	}

}