#include <stdio.h>
int main(void) {
	int n, i = 2;
	scanf("%d", &n);
	if (n == 2) printf("%d", n);
	while (i < n) {
		if (n % i == 0) {
			printf("%d\n", i);
			n /= i;
		}
		else i++;
		if (i == n) {
			printf("%d", i);
			break;
		}
	}
	return 0;
}