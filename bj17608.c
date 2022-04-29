#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100000
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
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
void pop(StackType* s) {
	s->data[(s->top)--];
}
element peek(StackType* s) {
	return s->data[(s->top)];
}
int main(void) {
	StackType s;
	init_stack(&s);
	int n, tmp[MAX_STACK_SIZE];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp[i]);
	}
	for (int i = 0; i < n; i++) {
		if (is_empty(&s)) push(&s, tmp[i]);
		else if (peek(&s) > tmp[i]) push(&s, tmp[i]);
		else if (peek(&s) <= tmp[i]) {
			while (peek(&s) <= tmp[i]) {
				pop(&s);
				if (is_empty(&s)) break;
			}
			push(&s, tmp[i]);
		}
	}
	printf("%d", s.top + 1);
	return 0;
}