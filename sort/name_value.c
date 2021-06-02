#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char *name;
	size_t value;
} NameValue;

NameValue *ConvertName(const NameValue inputData[], size_t numSize, size_t *nRet)
{
	int *equalIndex = malloc(numSize * sizeof(size_t));
	memset(equalIndex, 0, numSize * sizeof(size_t));
	//int index = 0;
	for (int i = numSize - 1; i >= 0; i--) {
		if (equalIndex[i] == 1) {
			continue;
		}
		for (int j = i - 1; j >= 0; j--) {
			if (strcmp(inputData[i].name, inputData[j].name) == 0) {
				equalIndex[j] = 1;
				//index++;
			}
		}
	}
	int retCount = 0;
	for (int i = 0; i < numSize; i++) {
		if (equalIndex[i] == 0) {
			retCount++;
		}
	}
	*nRet = retCount;
	NameValue *temp = (NameValue *)malloc(retCount * sizeof(NameValue));
	memset(temp, 0, retCount * sizeof(NameValue));
	int count = 0;
	for (int i = 0; i < numSize; i++) {
		if (equalIndex[i] == 0) {
			temp[count++] = inputData[i];
		}
	}
	free(equalIndex);
	equalIndex = NULL;
	return temp;
}

int main()
{
	NameValue *input = (NameValue *)malloc(5 * sizeof(NameValue));

	input[0].name = "a";
	input[0].value = 1;
	input[1].name = "b";
	input[1].value = 2;
	input[2].name = "b";
	input[2].value = 3;
	input[3].name = "a";
	input[3].value = 5;
	input[4].name = "d";
	input[4].value = 6;
	//for (int i = 0; i < 5; i++) {
	//	printf("%s %d", input[i].name, input[i].value);
	//}
	size_t nRet = 0;
	NameValue *res = ConvertName(input, 5, &nRet);

	for (int i = 0; i < nRet; i++) {
		printf("%s %d\n", res[i].name, res[i].value);
	}
	free(res);
	res = NULL;
	return 0;
}