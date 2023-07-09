#include <stdio.h>
#include <stdlib.h>

typedef enum {False,True}boolean;
struct Node{
	int Data;
	struct Node *Next;
};

typedef struct _List{
	struct Node *head;
}orderedList;

void initialize(orderedList *l);
boolean isEmpty(orderedList *l);
void addFirst(orderedList *l,int x);
void display(orderedList *l);
int length(orderedList *l);
void add(orderedList *l,int x);
void delete(orderedList *l,int num);

void initialize(orderedList *l){
	l->head = NULL;
}

boolean isEmpty(orderedList *l){
	return l->head == NULL;
}

void addFirst(orderedList *l,int x){
	struct Node *nw = (struct Node *)malloc(sizeof(struct Node));
	nw->Data = x;
	nw->Next = l->head;
	l->head = nw;
}
void display(orderedList *l){
	struct Node *temp;
	temp = l->head;
	printf("LIST : \n");
	while(temp != NULL){
		printf("%d ",temp->Data);
		temp = temp->Next;
	}
	printf("\n");
}
void delete(orderedList *l,int num){
	struct Node *del,*temp;
	if(l->head->Data == num){
		del = l->head;
		l->head = l->head->Next;
		free(del);
	}
	else{
		temp = l->head;
		while(temp->Next != NULL){
			if(temp->Next->Data == num)
			{
				del = temp->Next;
				temp->Next = temp->Next->Next;
				free(del);
			    return ;
			}
			temp = temp->Next;
		}
	}
	printf("Element not Exists in the List\n");
}
void add(orderedList *l,int x){
    if(isEmpty(l) || l->head->Data > x){
		addFirst(l,x);
    }
	else{
		struct Node *nw,*temp;
		nw = (struct Node *)malloc(sizeof(struct Node));
		nw->Data = x;
		temp = l->head;
		while(temp->Next != NULL && temp->Next->Data <= x){
			temp = temp->Next;
		}
		nw->Next = temp->Next;
		temp->Next = nw;
	}
}
