#include <stdio.h>
#include <math.h>
int main(void) {
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	if (n1 == 1) n1++;
	for (int i = n1; i <= n2; i++) {
		int end = (int)sqrt(i);
		if (i == 2 || i == 3 || i == 5 || i == 7) {
			printf("%d\n", i);
			continue;
		}
		for (int j = 2; j <= end; j++) {
			if (i % j == 0) break;
			else if (j == end) printf("%d\n", i);
		}
	}
	return 0;
}