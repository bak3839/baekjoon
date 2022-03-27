#include <stdio.h>
#include <string.h>
int main(void) {
	int n[3];
	int num = 1;
	char str[10];
	int stack[10] = { 0, };
	for (int i = 0; i < 3; i++) {
		scanf("%d", &n[i]);
		num *= n[i];
	}
	sprintf(str, "%d", num);
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		for (int j = 0; j <= 9; j++) {
			if ((str[i] - 48) == j) {
				stack[j]++;
				break;
			}
		}
	}
	for (int i = 0; i <= 9; i++) printf("%d\n", stack[i]);

	return 0;
}