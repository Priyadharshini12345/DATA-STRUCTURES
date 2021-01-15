#include<stdio.h>
#include<ctype.h>
#define size 50
int top=-1;
int stack[50];
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
void push(int x){
	if(isfull())
		printf("Stack overflow\n");
	else{
		top++;
		stack[top]=x;
	}
}
int pop(){
		int ele;
	if(isempty())
		printf("Stack underflow\n");
	else{
		ele=stack[top];
		top--;
	}
return ele;
}
void evaluate(char postfix[]){
		char c;
		int a,b,res,i;
	for(i=0;postfix[i]!='#';i++){
		if(isdigit(postfix[i])){
			c=postfix[i];
			push(c -'0');
		}
		else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/'){
			a=pop();
			b=pop();
			switch(postfix[i]){
				case '+':
					res=a+b;
					break;
				case '-':
					res=a-b;
					break;
				case '*':
					res=a*b;
					break;
				case '/':
					res=a/b;
					break;
			}
			push(res);
		}
	}
	printf("VALUE OF POSTFIX EXPRESSION IS %d",res);
}
void main(){
		int i;
		char postfix[30];
	printf("Enter # to stop input\n");
	printf("Enter a postfix expression\n");
	for(i=0;postfix[i]!='#';i++){
		scanf("%c",&postfix[i]);
		if(postfix[i]=='#')
			break;
	}
	evaluate(postfix);
}