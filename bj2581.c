#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int m, n, sum = 0;
	scanf("%d %d", &m, &n);
	int min = n;
	for (int i = m; i <= n ; i++) {
		if (i == 2) {
			sum += i;
			min = i;
		}
		for (int j = 2; j < i; j++) {
			if (i % j == 0) break;
			else if (j == i - 1 && i % j != 0) {
				sum += i;
				if (i < min) min = i;
			}
		}
	}
	if (sum == 0) printf("-1");
	else printf("%d\n%d", sum, min);
	return 0;
}