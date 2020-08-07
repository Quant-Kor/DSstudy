#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}


int Partition(int arr[], int left, int right)
{
	int pivot, low, high;
	int mid = (left + right) / 2;

	//arr[left], arr[right], arr[mid];

	if (arr[left] >= arr[right])
	{
		if (arr[left] < arr[mid])
		{
			pivot = arr[left];
			low = left + 1;
			high = right;
		}
		else
		{
			pivot = arr[mid];
			low = left;
			high = right;
		}
	}
	else
	{
		if (arr[right] <= arr[mid])
		{
			pivot = arr[right];
			low = left;
			high = right - 1;
		}
		else
		{
			pivot = arr[mid];
			low = left;
			high = right;
		}
	}

	printf("�ǹ� : %d \n", pivot);

	while (low <= high)
	{
		// �ǹ����� ū ���� ã�� ����
		while (pivot >= arr[low] && low <= right)
			low++;

		// �ǹ����� ���� ���� ã�� ����
		while (pivot <= arr[high] && high >= left + 1)
			high--;

		// �������� ���� ���¶�� Swap ����
		if (low <= high)
			Swap(arr, low, high);
	}

	if (pivot == arr[left])
	{
		Swap(arr, left, high);
		return high;
	}
	else if (pivot == arr[right])
	{
		Swap(arr, low, right);
		return low;
	}
	else
		return mid;

	//return high;
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

int main(void)
{
	//int arr[7] = { 3,2,4,1,7,6,5 };
	//int arr[3] = { 3,3,3 };
	int arr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}