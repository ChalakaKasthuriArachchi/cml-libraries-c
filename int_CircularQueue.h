#include <stdio.h>
#define SIZE 10

typedef enum { False, True}Boolean;
typedef struct _{
	int arry[SIZE];
	int front;
	int rear;
	int size;
}Queue;

/**/
void initialize(Queue *q);
Boolean isEmpty(Queue *q);
Boolean isFull(Queue *q);
void enqueue(Queue *q,int value);
int dequeue(Queue *q);
int getFront(Queue *q);
void display(Queue *q);
int increment(int x);
/**/

void initialize(Queue *q){
	q->front = 0;
	q->size = 0;
	q->rear = -1;
}

Boolean isEmpty(Queue *q){
	if(q->size == 0)
		return True;
	return False;
}

Boolean isFull(Queue *q){
	if(q->size == SIZE)
		return True;
	return False;
}

void enqueue(Queue *q,int value){
	if(isFull(q))
		printf("Queue is Full\n");
	else
	{
		q->rear = increment(q->rear);
		q->arry[q->rear] = value;
		q->size++;
	}
}

int dequeue(Queue *q){
	if(isEmpty(q))
		printf("Queue is Empty");
	else
	{
		int value = q->arry[q->front];
		q->front = increment(q->front);
		q->size--;
		return value;
	}
	return -1;
}

int getFront(Queue *q){
	if(isEmpty(q))
		printf("Queue is Empty");
	else
		return q->arry[q->front];;
	return -1;

}

void display(Queue *q){
	for(int x = q->front; x < (q->size + q->front); x++){
		if(x >= SIZE)
			printf("%d ",q->arry[x - SIZE]);
		else
			printf("%d ",q->arry[x]);
	}
	printf("\n");
}

int increment(int x){
	if(++x == SIZE)
		return 0;
	return x;
}
