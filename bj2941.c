#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	char* str = malloc(sizeof(char) * 101);
	scanf("%s", str);
	int len = strlen(str);
	int L = len;
	int i = 0;
	while (i < L) {
		if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=') {
			len -= 2;
			i += 3;
			continue;
		}
		else if (str[i] == 'c' && str[i + 1] == '-') len--;
		else if (str[i] == 'c' && str[i + 1] == '=') len--;
		else if (str[i] == 'd' && str[i + 1] == '-') len--;
		else if (str[i] == 'l' && str[i + 1] == 'j') len--;
		else if (str[i] == 'n' && str[i + 1] == 'j') len--;
		else if (str[i] == 's' && str[i + 1] == '=') len--;
		else if (str[i] == 'z' && str[i + 1] == '=') len--;
		else {
			i++;
			continue;
		}
		i += 2;
	}
	printf("%d", len);
	free(str);
	return 0;
}