#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int k;
	int index;
}element;
int n;
typedef struct {
	element* data;
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
	s->data = malloc(sizeof(element) * n);
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
element peek(StackType* s) {
	return s->data[(s->top)];
}
int main(void) {
	StackType s;
	scanf("%d", &n);
	init_stack(&s);
	int* num = malloc(sizeof(int) * n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	element tmp;
	for (int i = 0; i < n - 1; i++) {
		if (num[i] < num[i + 1]) {
			num[i] = num[i + 1];
			while (!is_empty(&s)) {
				tmp = peek(&s);
				if (tmp.k < num[i + 1]) {
					tmp = pop(&s);
					num[tmp.index] = num[i + 1];
				}
				else break;
			}
		}
		else {
			tmp.index = i;
			tmp.k = num[i];
			push(&s, tmp);
			num[i] = -1;
		}
	}
	num[n - 1] = -1;
	for (int i = 0; i < n; i++)
		printf("%d ", num[i]);
	free(num);
	free(s.data);
	return 0;
}