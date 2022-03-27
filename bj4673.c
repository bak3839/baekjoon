#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int selfNum(int a) {
	char str[5];
	sprintf(str, "%d", a);
	int len = strlen(str);
	for (int i = 0; i < len; i++) a += (str[i] - 48);
	return a;
}
int main(void) {
	int* num = malloc(sizeof(int) * 10000);
	memset(num, 0, 10000 * sizeof(int));
	for (int i = 1; i < 10000; i++) {
		if (selfNum(i) <= 10000) num[selfNum(i) - 1] = 1;
	}
	for (int i = 0; i < 10000; i++) if (num[i] == 0) printf("%d\n", i + 1);
	free(num);
	return 0;
}