#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 1000000
typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int count;
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
	s->count = 0;
}
int is_empty(StackType* s) {
	return (s->top == -1);
}
void push(StackType* s, element item) {
	s->data[++(s->top)] = item;
	s->count++;
}
void pop(StackType* s) {
	s->data[(s->top)--];
	s->count--;
}
element peek(StackType* s) {
	return s->data[(s->top)];
}
int main(void) {
	StackType s;
	init_stack(&s);
	char* str = malloc(sizeof(char) * 1000000);
	int lazer = 0, sum = 0;
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		char ch = str[i];
		if (ch == '(') {
			if (is_empty(&s)) lazer = 0;
			push(&s, ch);
			if (str[i - 1] == ')' && i > 0) {
				sum += lazer + 1;
				lazer = 0;
			}
			continue;
		}
		
		else {
			if (str[i - 1] == '(') {
				lazer++;
				pop(&s);
			}
			else {
				sum += lazer + 1;
			}
		}

	}
	printf("%d", sum);
	return 0;
}