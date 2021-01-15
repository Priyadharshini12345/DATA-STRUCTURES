#include<stdio.h>
struct stack{
int data;
struct stack*next;
}*top,*new,*temp;
void display(){
	temp=top;
	printf("Elements of stack are\n");
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
void push(){
		char ch;
		int val;
	do{
		printf("Enter a number\n");
		scanf("%d",&val);
		new=(struct stack*)malloc(sizeof(struct stack));
		if(top==NULL){
			new->data=val;
			new->next=NULL;
			top=new;
		}
		else{
			new->data=val;
			new->next=top;
			top=new;
		}
	printf("Enter n to exit\n");
	scanf("%s",&ch);
	}while(ch!='n');
}
void pop(){
	if(!top)
		printf("Stack underflow\n");
	else{
		temp=top;
		printf("%d is popped out\n",temp->data);
		top=top->next;
		temp->next=NULL;
		free(temp);
	}
}

void main(){
	push();
	display();
	pop();
	display();
	}
