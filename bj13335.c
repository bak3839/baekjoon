#include <stdio.h>
#include <stdlib.h>
#define MAX 4000
typedef int element;
typedef struct {
	element data[MAX];
	int rear, front;
}QueueType;
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}
int is_empty(QueueType* q) {
	if (q->front == q->rear) {
		return 1;
	}
	else return 0;
}
void enqueue(QueueType* q, element item) {
	q->rear = (q->rear + 1) % MAX;
	q->data[q->rear] = item;
}
element peek(QueueType* q) {
	return q->data[q->front + 1];
}
element dequeue(QueueType* q) {
	q->front = (q->front + 1) % MAX;
	return q->data[q->front];
}
int main(void) {
	QueueType q;
	init_queue(&q);
	QueueType q2;
	init_queue(&q2);

	int n, w, l;
	int result = 0, sum = 0, tmp;
	scanf("%d %d %d", &n, &w, &l);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		enqueue(&q, tmp);
	}
	int cn = 0; // 차량수
	int count = 0; // 단위시간 | sum은 다리위 차량무게합
	do {
		result++;
		if (w == cn) {
			sum -= dequeue(&q2);
			cn--;
		}
		if (!is_empty(&q)) {
			if (sum + peek(&q) <= l && cn < w) { // 차량무게합+다음차량이 다리중량보다 작거나 같으면 통과
				enqueue(&q2, peek(&q));
				sum += dequeue(&q);
				cn++;
				continue;
			}
			else {
				enqueue(&q2, 0);
				cn++;
				continue;
			}
		}
		else {
			cn++;
		}
	} while (!is_empty(&q2) || !is_empty(&q));
	printf("%d", result);
	return 0;
}