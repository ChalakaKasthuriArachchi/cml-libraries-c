#include <stdio.h>
#include <stdlib.h>
struct Node{
	int Data;
	struct Node *Next;
};

typedef struct _stack{
	struct Node *Top;
}stack;

/**/
void initialize(stack *s);
void push(stack *s,int d);
int top(stack *s);
int isEmpty(stack *s);
int pop(stack *s);
void display(stack *s);
/**/
void initialize(stack *s){
	s->Top = NULL;
}

void push(stack *s,int d){
  	struct Node *nw = 
		(struct Node*)malloc(sizeof(struct Node *));
	nw->Data = d;
	nw->Next = s->Top;
	s->Top = nw;
}

int isEmpty(stack *s){
	return s->Top == NULL;	
}

int pop(stack *s){
	if(isEmpty(s)){
		printf("Stack is Empty\n");				
		return -1;
	}
	struct Node *tmp = s->Top;
	int val = tmp->Data;
	s->Top = tmp->Next;
	free(tmp);
	return val;
}

void display(stack *s){
	if(isEmpty(s)){
		printf("Stack is Empty\n");	
	}
	else{
		printf("Stack : ");
		struct Node *tmp = s->Top;
		while(tmp != NULL){
			printf("%d ",tmp->Data);
			tmp = tmp->Next;
		}
		printf("\n");
	}
}

