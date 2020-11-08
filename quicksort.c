#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>

int findPivot(int *x, int start, int end) {
	int rand1, rand2, rand3;
	if (start - end <= 1) {
		return start;
	}
	srand((unsigned)time(NULL));
	rand1 = (rand() % (start - end)) + start;
	return rand1;
}
int Partition(int *x, int start, int end, int pivot) {
	int left = start, right = end, tmp;

	while (left <= right) { //교차되기 전까지 반복
		while (left <= right && x[left] <= x[pivot]) {
			left++;
		}
		while (right >= left && x[right] >= x[pivot]) {
			right--;
		}
		if (left < right) { //교차되지 않았을때 swap
			tmp = x[left];
			x[left] = x[right];
			x[right] = tmp;
		}
	}
	//pivot과 right가 가리키는 대상 swap
	tmp = x[right];
	x[right] = x[pivot];
	x[pivot] = tmp;

	return right;
}

void QuickSort(int *x, int start, int end) {
	int k;

	if (start <= end) {
		k = Partition(x, start, end, findPivot(x, start, end));
		QuickSort(x, start, k - 1);
		QuickSort(x, k + 1, end);
	}
}
int main() {
	int *x, n;
	scanf("%d", &n);
	x = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);

	}

	QuickSort(x, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf(" %d", x[i]);
	}
	return 0;
}