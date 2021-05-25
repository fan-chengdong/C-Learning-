#include "quick_sort.h"

void QuickSort(int array[], int size, int start, int last)
{
	if (start >= last) {
		return;
	}
	int pivot = array[start];
	int low = start;
	int high = last;
	while (low < high) {
		while (low < high && array[high] >= pivot){
			high--;
		}
		array[low] = array[high];
		while (low < high && array[low] < pivot) {
			low++;
		}
		array[high] = array[low];
	}
	array[low] = pivot;
	QuickSort(array, size, start, low - 1);
	QuickSort(array, size, low + 1, last);
}