#include <stdio.h>
#include <math.h>
int main(void) {
	int n, st = 0;
	while (1) {
		scanf("%d", &n);
		if (n == 0) return 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			int end = (int)sqrt(i);
			if (i == 2 || i == 3) {
				st++;
				continue;
			}
			for (int j = 2; j <= end; j++) {
				if (i % j == 0) break;
				else if (j == end && i % j != 0) st++;
			}
		}
		printf("%d\n", st);
		st = 0;
	}
	return 0;
}