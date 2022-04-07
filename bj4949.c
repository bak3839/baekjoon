#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 101
typedef char element;
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
element pop(StackType* s) {
	return s->data[(s->top)--];
}
int cmp(char* ch) {
	StackType s;
	init_stack(&s);
	int len = strlen(ch);
	char open_ch;
	for (int i = 0; i < len; i++) {
		switch (ch[i]) {
		case'(': case'{': case'[': {
			push(&s, ch[i]);
			break;
		}
		case')': case'}': case']': {
			if (is_empty(&s)) {
				//printf("no\n");
				return 0;
			}
			else {
				open_ch = pop(&s);
				if (open_ch == '(' && ch[i] != ')' ||
					open_ch == '{' && ch[i] != '}' ||
					open_ch == '[' && ch[i] != ']') {
					//printf("no\n");
					return 0;
				}
			}
			break;
		}
		}
	}
	if (!is_empty(&s)) return 0;
	else return 1;
}
int main(void) {
	while (1) {
		char str[MAX_STACK_SIZE] = { 0, };
		gets(str);
		if (strcmp(str, ".") == 0) break;
		if (cmp(str) == 1) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}