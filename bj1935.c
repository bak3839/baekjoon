#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 102

typedef struct {
	double num[MAX_STACK_SIZE];
	int top;
}StackType;
void init_stack(StackType* s) {
	s->top = -1;
}
int is_empty(StackType* s) {
	return (s->top == -1);
}
void push_num(StackType* s, double item) {
	s->num[++(s->top)] = item;
}
double pop_num(StackType* s) {
	return s->num[(s->top)--];
}
double eval_postfix(char* str, double num[]) {
	StackType s;
	init_stack(&s);
	double ch1, ch2, value;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			value = num[(str[i] - 65)];
			push_num(&s, value);
		}
		else {
			ch1 = pop_num(&s);
			ch2 = pop_num(&s);

			switch (str[i]) {
			case'+': {
				push_num(&s, ch2 + ch1);
				break;
			}
			case'-': {
				push_num(&s, ch2 - ch1);
				break;
			}
			case'*': {
				push_num(&s, ch2 * ch1);
				break;
			}
			case'/': {
				push_num(&s, ch2 / ch1);
				break;
			}
			}
		}
	}
	return pop_num(&s);
}

int main(void) {
	int n;
	scanf("%d", &n);
	char str[102];
	scanf("%s", str);
	StackType d;
	init_stack(&d);

	double tmp[102];
	for (int i = 0; i < n; i++) {
		scanf("%lf", &tmp[i]);
	}
	printf("%0.2f", eval_postfix(str, tmp));
	return 0;
}