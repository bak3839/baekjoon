#include <stdio.h>
int main(void) {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int n[3];
	n[0] = w - x; n[1] = h - y; n[2] = y;
	int res = x;
	for (int i = 0; i < 3; i++) if (res > n[i]) res = n[i];
	printf("%d", res);
	return 0;
}