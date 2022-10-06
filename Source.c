#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int random_value(int left, int right)
{
	return left + rand() % (right - left + 1);
}
void swap(int* a1, int* a2)
{
	int tmp;
	tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}
void quicksort(int* arr, int left, int right)
{
	if (left < right)
	{
		int rand = random_value(left, right), pivot = arr[rand], i = left, j = right, id = rand;
		while (i < rand && j >= rand)
		{
			if (arr[i] > pivot && arr[j] < pivot)
				swap(arr + i, arr + j);
			if (arr[i] > pivot)
				--j;
			else
				++i;
		}
		while (i < rand) {
			if (arr[i] > pivot) {
				swap(arr + i, arr + id);
				id = i;
			}
			++i;
		}
		while (j >= rand) {
			if (arr[j] < pivot) {
				swap(arr + i, arr + id);
				id = j;
			}
			--j;
		}
		quicksort(arr, left, id);
		quicksort(arr, id + 1, right);
	}
}

int main()
{
	srand(time(NULL));
	int a[7] = { 1, 7, 6, 5, 10, 11, -1 };
	quicksort(a, 0, 6);
	for (int i = 0; i < 6; i++)
		printf("%d ", a[i]);
}