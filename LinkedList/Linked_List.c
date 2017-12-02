#include<stdio.h>
#include<stdlib.h>

struct n{	

	int data;
	struct n * next;

};

typedef struct n node;

void show(node * r){
	
	while(r!=NULL){ 
		printf("%d\n",r->data);
		r=r->next;
	}
}
node * insert(node * r,int x){
	if(r==NULL){
		r=(node *)malloc(sizeof(node *));
		r->data=x;
		r->next=NULL;
		return r;
	}

	while(r->next != NULL){
		r=r->next;
	}
		r->next = (node *)malloc(sizeof(node));
		r->next->data=x;
		r->next->next = NULL;
		return r;
}

void appendBetween(node * r,int x,int y){
	
	node * temp;
	while(r->data!=y){
		r=r->next;
	}
        temp = (node *)malloc(sizeof(node));
        temp->next = r->next;
        r->next = temp;
        temp->data=x;




}

node * delete(node * r,int x){

	node *temp;

	if(r->data==x){
		temp=r;
		r=r->next;	
		free(temp);
		return r;
	}
	while(r->next != NULL && r->next->data != x){
		r=r->next;
	}
	if(r->next==NULL){
		printf("Sayi bulunamadi");
		return r;
	}
	
       	temp=r->next;
	r->next=r->next->next;
	free(temp);
	return r;

}
 

int main(){
	node * root;
	root=NULL;
	root=insert(root,5);
	insert(root,6);
	insert(root,7);
	insert(root,8);
	appendBetween(root,3,7);/*3->add number 7->insert after 7 */
	root=delete(root,5);
	show(root);
}
