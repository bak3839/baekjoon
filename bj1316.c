#include <stdio.h>
#include <string.h>
int checker(void) {
	char str[101];
	char* ptr;
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] != str[i + 1]) {
			ptr = strchr(str + i + 1, str[i]);
			if (ptr != NULL) return 0;
		}
	}
	return 1;
}
int main(void) {
	int n;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) cnt += checker();
	printf("%d",cnt);
	return 0;
}