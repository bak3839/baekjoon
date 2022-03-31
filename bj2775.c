#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int t, N, K;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &K);
		scanf("%d", &N);
		int* a = malloc(sizeof(int) * N);
		for (int i = 0; i < N; i++) a[i] = i + 1;
		for (int j = 0; j < K; j++)
			for (int i = 1; i < N; i++) {
				a[i] = a[i - 1] + a[i];
			}
		printf("%d\n", a[N - 1]);
	}
	return 0;
}