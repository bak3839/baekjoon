#include <stdio.h>
int main(void) {
	int n, H, W, N;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &H, &W, &N);
		if (N % H == 0) {
			printf("%d\n", H * 100 + (N / H));
			continue;
		}
		if (N <= H) printf("%d\n", N * 100 + 1);
		else if ((W * H) == N) printf("%d\n", H * 100 + W);
		else printf("%d\n", ((N % H) * 100) + (N / H) + 1);
	}
	return 0;
}