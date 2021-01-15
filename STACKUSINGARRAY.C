#include<stdio.h>
#define size 10
int stack[size];
int top=-1;
int isempty(){
	if(top==-1)
		return 1;
	else
		return 0;
}
int isfull(){
	if(top==size-1)
		return 1;
	else
		return 0;
}
void push(){
		int val;
		char ch;
	if(isfull()){
		printf("Stack overflow\n");
	}
	else{
			printf("Enter a number\n");
			scanf("%d",&val);
			top++;
			stack[top]=val;
				}
}
void display(){
		int i;
	if(isempty())
		printf("Stack Underflow\n");

	else {
		printf("Elements of stack\n");
		for(i=top;i>=0;i--)
			printf("%d\n",stack[i]);
	}
}
void pop(){
		int ele;
	if(isempty())
		printf("Stack underflow\n");
	else{
		ele=stack[top];
		printf("%d is popped out\n",ele);
		top--;
	}
}
void main(){
int opt;
do{
printf("1.PUSH\n");
printf("2.Display\n");
printf("3.POP\n");
printf("4.Exit\n");
printf("Enter your choice\n");
scanf("%d",&opt);
switch(opt){
case 1:
	push();
	break;
case 2:
	display();
	break;
case 3:
	pop();
	break;
	
}
}while(opt!=4);
}