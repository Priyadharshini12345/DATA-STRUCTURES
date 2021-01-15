
#include<stdio.h>
#define size 5
int queue[size];
int front=-1,rear=-1;
void enqueue(){
		int x;
		if((front==0 && rear==size-1) || (rear+1==front))
			printf("Queue overflow\n");
		else{
			printf("Enter element to insert\n");
			scanf("%d",&x);
			if(rear==-1){
				front=0;
				rear=0;
			}
			else {
				if(rear==size-1)
					rear=0;
				else
					rear++;
				}
			queue[rear]=x;
		}
}
void dequeue(){
		int g;
	if(front==-1)
		printf("queue underflow\n");
	else if(front==rear){
		rear=-1;
		front=-1;
	}
	else{
		if(front==size-1)
			front=0;
	else{
		g=queue[front];
		printf("%d is dequeued\n",g);
		front++;
		}
	}
}
void display(){
		int i,j;
	printf("Elements of Circular queue are:\n");
	if(front>rear){
		for(i=front;i<=size-1;i++)
			printf("%d",queue[i]);
		for(j=0;j<=rear;j++)
			printf("%d",queue[j]);
	}
	else{
		for(i=front;i<=rear;i++)
			printf("%d\n",queue[i]);
	}
}
void main(){
		int opt;
	printf("1.Enqueue\n");
	printf("2.Dequeue\n");
	printf("3.Display\n");
	printf("4.Exit\n");
	do{
		printf("Enter option\n");
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
				exit(0);
				break;
			default:
				printf("Enter valid option\n");
		}
	}while(opt!=4);
}

