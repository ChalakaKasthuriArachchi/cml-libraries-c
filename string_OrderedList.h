#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 10
typedef enum {False,True}boolean;
struct Node{
	char Data[MAX_LENGTH];
	struct Node *Next;
};

typedef struct _List{
	struct Node *head;
}orderedList;

void initialize(orderedList *l);
boolean isEmpty(orderedList *l);
void addFirst(orderedList *l,char *x);
void display(orderedList *l);
int length(orderedList *l);
void add(orderedList *l,char *x);
void delete(orderedList *l,char *x);
int strCmp(char *s1,char *s2);

void initialize(orderedList *l){
	l->head = NULL;
}

boolean isEmpty(orderedList *l){
	return l->head == NULL;
}

void addFirst(orderedList *l,char *x){
	struct Node *nw = (struct Node *)malloc(sizeof(struct Node));
	strcpy(nw->Data,x);
	nw->Next = l->head;
	l->head = nw;
}
void display(orderedList *l){
	struct Node *temp;
	temp = l->head;
	printf("LIST : \n");
	while(temp != NULL){
		printf("%s ",temp->Data);
		temp = temp->Next;
	}
	printf("\n");
}
void delete(orderedList *l,char *x){
	struct Node *del,*temp;
	if(strCmp(l->head->Data,x) == 0){
		del = l->head;
		l->head = l->head->Next;
		free(del);
	}
	else{
		temp = l->head;
		while(temp->Next != NULL){
			if(strCmp(l->head->Data,x) == 0)
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
void add(orderedList *l,char *x){
    if(isEmpty(l) || strCmp(l->head->Data , x) > 0){
		addFirst(l,x);
    }
	else{
		struct Node *nw,*temp;
		nw = (struct Node *)malloc(sizeof(struct Node));
		strcpy(nw->Data,x);
		temp = l->head;
		while(temp->Next != NULL && strCmp(temp->Next->Data , x) <= 0){
			temp = temp->Next;
		}
		nw->Next = temp->Next;
		temp->Next = nw;
	}
}
int strCmp(char *s1,char *s2){
    int x = 0;
    char c1,c2;
    do{
        c1 = s1[x];
        c2 = s2[x++];
    }while(c1 == c2);
    printf("Comparing : %s | %s : %d\n",s1,s2,c1 - c2);
    return c1 - c2;
}
