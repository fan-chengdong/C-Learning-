#include "bubble_sort.h"
#include "helper.h"

void BubbleSort(int array[], int size)
{
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (array[j] > array[j + 1]) {
				Swap(&array[j], &array[j + 1]);
			}
		}
	}
}
