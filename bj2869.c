#include <stdio.h>
int main(void) {
	int up, dn, v;
	int sum;
	scanf("%d %d %d", &up, &dn, &v);
	sum = (v - up) / (up - dn);
	if ((v - up) % (up - dn) == 0) printf("%d", sum + 1);
	else printf("%d", sum + 2);
	return 0;
}