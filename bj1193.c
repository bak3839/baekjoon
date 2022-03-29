#include <stdio.h>
int main(void) {
	int x;
	scanf("%d", &x);
	int n = 0;
	int up = 1, dn = 1;
	while (n < x) {
		if (up == dn) {
		    n++;
			if (n == x) {
				printf("%d/%d", up, dn);
				return 0;
			}
			dn++;
		}
		else if (up < dn) {
			int D = dn;
			for (int i = 0; i < D; i++) {
				n++;
				if (n == x) {
					printf("%d/%d", up, dn);
					return 0;
				}
				up++; dn--;
			}
			dn = 1;
		}
		else {
			int U = up;
			for (int i = 0; i < U; i++) {
				n++;
				if (n == x) {
					printf("%d/%d", up, dn);
					return 0;
				}
				up--; dn++;
			}
			up = 1;
		}
	}
}