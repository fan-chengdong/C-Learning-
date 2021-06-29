#include <stdio.h>

int count_one_bits(unsigned value)
{
	int ones;
	for (ones = 0; value != 0; value = value >> 1) {
		if (value % 2 != 0) {
			ones += 1;
		}
	}
	return ones;
}

int main()
{
	unsigned value = 3;
	int ones = count_one_bits(value);
	printf("%d\n", ones);
	return 0;
}