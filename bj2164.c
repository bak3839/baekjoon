#include <stdio.h>
#include <stdlib.h>
#define MAX 250002
typedef int element;
typedef struct {
	element data[MAX];
	int rear, front;
}QueueType;

void init_queue(QueueType* q) { // 큐 초기화
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) { // 큐가 비어있는지 확인
	return (q->front == q->rear);
}

int is_full(QueueType* q) { // 큐가 포화 상태인지 확인
	return ((q->rear + 1) % MAX == q->front);
}

void enqueue(QueueType* q, element item) { // 큐 삽입
	q->rear = (q->rear + 1) % MAX;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) { // 큐 삭제
	q->front = (q->front + 1) % MAX;
	return q->data[q->front];
}

int main(void) {
	QueueType q;
	init_queue(&q);
	int n;
	scanf("%d", &n);
	if (n % 2 == 1) enqueue(&q, n);
	for (int i = 2; i <= n; i = i + 2) enqueue(&q, i);
	while (!(q.front + 1 == q.rear)) {
		dequeue(&q);
		enqueue(&q, dequeue(&q));
	}
	printf("%d", dequeue(&q));
}