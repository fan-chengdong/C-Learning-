#include <stdio.h>

void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void Swap(int *a, int *b)
{
	if (*a > *b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}