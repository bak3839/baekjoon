#include <stdio.h>
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
	int k, n, sum = 0;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &n);
		if (n != 0) push(&s, n);
		else pop(&s);
	}
	while (!is_empty(&s)) {
		sum += pop(&s);
	}
	printf("%d", sum);
	return 0;
}