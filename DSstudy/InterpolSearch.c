#include <stdio.h>

// 보간 탐색이며 기존 이진 탐색과 다른점이 mid에서 이진 탐색의 경우 중앙에서 찾기를 시작하지만
// 보간 탐색의 찾는 기준을 찾는 위치와 비례하며 찾기 떄문에 이진 탐색보다 효율적으로 찾을 수 있음
// double형ㅇ르 사용한 이유는 모든 연산들이 실수형으로 진행되어 오차가 최소화 되도록!

int ISearch(int ar[], int first, int last, int target)
{
	int mid;

	if (ar[first] > target || ar[last]< target) // 값이 넘어 갈때를 기준으로 판단을 해야함!
		return -1;

	mid = ((double)(target - ar[first]) / (ar[last] - ar[first]) * (last - first)) + first;

	if (ar[first] == target)
		return mid;
	else if (target < ar[mid])
		return ISearch(ar, first, mid - 1, target);
	else
		return ISearch(ar, mid + 1, last, target);
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 2);
	if (idx == -1)
		printf("탐색실패 \n");
	else
		printf("타겟 저장 인덱스: %d \n", idx);


	return 0;
}