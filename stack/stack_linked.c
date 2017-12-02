#include <stdio.h>
#include <stdlib.h>

struct n {

	int data;
	struct n * next;

};

typedef struct n node;

node * push(node * r,int a){
	if(r==NULL){
		
		r = (node *)malloc(sizeof(node));
		r -> data = a;
		r -> next = NULL;
		return r;
	}
	while(r->next!=NULL){
		r=r->next;
	}
	r -> next = (node *)malloc(sizeof(node *));
	r -> next -> data = a;
	r -> next -> next = NULL;
	return r;
}

int pop (node * r){

	if(r==NULL){
		printf("Stack Bos");
		return -1;
	}
	if(r->next==NULL){
                int rvalue = r->data;
                free(r);
                return rvalue;
        }

	while(r->next->next!=NULL){
		r=r->next;
	}
	node * temp;
	temp = r->next;
	int rvalue = temp -> data;
	r->next=NULL;
	free(temp);
	return  rvalue;

}


void show(node * r){

	while(r!=NULL){
		printf("%d\n",r->data);
		r=r->next;	
	}

}

int main(){

	
	node * stack;
	stack=NULL;
	stack=push(stack,20);
	push(stack,30);
	push(stack,40);
	show(stack);
	printf(" %d\n",pop(stack));
	printf(" %d\n",pop(stack));
}
