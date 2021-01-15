
#include<stdio.h>
#include<string.h>
#define size 3
int front=0;
int rear=-1;
int queue[size];
void enqueue(){
		int val;
	if(rear==size-1)
		printf("Queue overflow\n");
	else{
		printf("Enter a number\n");
		scanf("%d",&val);
		rear++;
		queue[rear]=val;
	}

}
void dequeue(){
		int val;
	if(rear==-1 || front>rear)
		printf("Queue underflow\n");
	else{
		val=queue[front];
		printf("%d is dequeued\n",val);
		front++;
	}
}
void display(){
		int i;

	if(rear==-1)
		printf("Queue underflow\n");
	else{
		printf("Elements of Queue are:\n");
		for(i=front;i<=rear;i++)
			printf("%d\n",queue[i]);
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
				printf("Enter valid option");
		}
	}while(opt!=4);
}


