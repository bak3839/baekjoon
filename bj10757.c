#include <stdio.h>
#include <string.h>
void change(char *t,int len) {
	for (int i = 0; i < len / 2; i++) {
		char temp = t[i];
		t[i] = t[len - i - 1];
		t[len - i - 1] = temp;
	}
}
int main(void) {
	char a[10002] = { 0, };
	char b[10002] = { 0, };
	char result[10003] = { 0, };
	scanf("%s", a);
	scanf("%s", b);
	int alen = strlen(a);
	int blen = strlen(b);
	change(a, alen);
	change(b, blen);
	int len = alen > blen ? alen : blen;
	int num = 0;
	for (int i = 0; i < len; i++) {
		int sum = a[i] - '0' + b[i] - '0' + num;
		while (sum < 0) sum += '0';
		if (sum > 9) {
			result[i] = sum - 10 + 48;
			num = 1;
		}
		else {
			result[i] = sum + 48;
			num = 0;
		}
	}
	if (num == 1) result[len] = '1'; 
	int rlen = strlen(result);
	change(result, rlen);
	printf("%s", result);
	return 0;
}