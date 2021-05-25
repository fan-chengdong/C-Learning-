#include <stdio.h>
#include "insert_sort.h"
#include "helper.h"
//void Swap(int *a, int *b)
//{
//	if (*a > *b) {
//		int temp = *a;
//		*a = *b;
//		*b = temp;
//	}
//}

void InsertSort(int array[], int size)
{
	for (int i = 1; i < size; i++) {
		int j = i;
		while (j > 0) {
			if (array[j - 1] > array[j]) {
				Swap(&array[j - 1], &array[j]);
				j--;
			} else {
				break;
			}
		}
	}
}

void InsertSort2(int array[], int size)
{
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0; j--) {
			Swap(&array[j - 1], &array[j]);
		}
	}
}
