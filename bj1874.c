#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100000
typedef int element;
typedef struct {
	element data[MAX];
	int top;
}StackType;
void init_stack(StackType* s) {
	s->top = -1;
}
int is_empty(StackType* s) {
	return (s->top == -1);
}
void push(StackType* s, element item) {
	s->data[++(s->top)] = item;
}
element pop(StackType* s) {
	return s->data[(s->top)--];
}
int main(void) {
	StackType s;
	init_stack(&s);
	int n;
	char p[200001] = { '\0', };
	scanf("%d", &n);
	int* a = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int aindex = 0, pindex = 0, num = 1;
	while (aindex < n) {
		if (a[aindex] == num) {
			push(&s, num++);
			pop(&s);
			p[pindex++] = '+';
			p[pindex++] = '-';
			aindex++;
		}
		else if (a[aindex] > num) {
			push(&s, num++);
			p[pindex++] = '+';
		}
		else if (a[aindex] < num) {
			if (pop(&s) != a[aindex]) {
				printf("NO");
				return 0;
			}
			p[pindex++] = '-';
			aindex++;
		}
	}
	for (int i = 0; i < strlen(p); i++) printf("%c\n", p[i]);
	free(a);
	return 0;
}