
#include<stdio.h>
#include<stdlib.h>
struct queue{
	int data;
	struct queue*next;
}*front,*rear,*temp,*new;
void enqueue(){
		int val;
		char ch;
	do{
		printf("Enter the number\n");
		scanf("%d",&val);
		new=(struct queue*)malloc(sizeof(struct queue));
		new->data=val;
		new->next=NULL;
		if(rear==NULL){
			front=new;
			rear=new;
		}
		else{
			rear->next=new;
			rear=new;
		}
		printf("Enter n to exit\n");
		scanf("%s",&ch);
	}while(ch!='n');
}
void dequeue(){
	temp=front;
	printf("%d is dequeued\n",temp->data);
	front=front->next;
	temp->next=NULL;
	free(temp);
}
void display(){
	if(front==NULL)
		printf("queue underflow\n");
	else{
		printf("Elements of Queue are:\n");
		temp=front;
		while(temp!=NULL){
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
void main(){
		int opt;
	printf("1.ENQUEUE\n");
	printf("2.DEQUEUE\n");
	printf("3.DISPLAY\n");
	printf("4.EXIT\n");
	do{
		printf("Enter your choice\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exited\n");
				break;
			default:
				printf("Enter valid option\n");
		}
	}while(opt!=4);
}

