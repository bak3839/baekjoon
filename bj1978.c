#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int n, st = 0;
	scanf("%d", &n);
	int* a = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		if (a[i] == 2) st++;
		for (int j = 2; j < a[i]; j++) {
			if (a[i] % j == 0) break;
			else if (j == a[i]-1 && a[i] % j != 0) st++;
		}
	}
	printf("%d", st);
	return 0;
}