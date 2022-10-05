#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void mergeSort(int* arr, int left, int right)
{
	if (left == right)
		return;
	int middle = (right + left) / 2;
	int* buffer = (int*)calloc(right - left + 1, sizeof(int));
	mergeSort(arr, left, middle);
	mergeSort(arr, middle + 1, right);
	int i = left, j = middle + 1, c = 0;
	while (i <= middle && j <= right)
	{
		if (arr[i] < arr[j]) {
			buffer[c] = arr[i];
			++i;
		}
		else {
			buffer[c] = arr[j];
			++j;
		}
		++c;
	}
	while (j <= right) {
		buffer[c] = arr[j];
		++j;
		++c;
	}
	while (i <= middle) {
		buffer[c] = arr[i];
		++i;
		++c;
	}
	for (int i = 0; i < right - left + 1; i++)
		arr[i + left] = buffer[i];
	return;
}
int main()
{
	int n;
	scanf_s("%d", &n);
	srand(time(NULL));
	int* arr = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		arr[i] = 1 + rand() % 100;
	mergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}
