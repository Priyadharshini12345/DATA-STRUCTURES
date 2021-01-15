#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define size 50
int stack[size];
int top=-1;
int precedence(char symbol){
	if(symbol=='^')
		return 3;
	else if((symbol=='*') || (symbol=='/'))
		return 2;
	else if((symbol=='+') || (symbol=='-'))
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
int is_operator(char symbol){
	if(symbol=='^' || symbol=='*' || symbol=='+' || symbol=='-' ||symbol=='/')
		return 1;
	else
		return 0;
}
void push(char ch){
	if(isfull())
		printf("Stack overflow\n");
	else{
		top++;
		stack[top]=ch;
	}
}

char pop(){
		char ele;
	ele=stack[top];
	top--;
	return ele;
}


void main(){
		int i=0,j=0;
		char item,temp;
		char infix[30];
		char postfix[30];
		printf("Enter the infix expression\n");
	gets(infix);
	while(infix[i]!='\0'){
		item=infix[i];
		if(item=='(')
			push(item);
		else if(item>='A' && item<='Z' || item>='a' && item<='z'){
			postfix[j]=item;
			j++;
		}
		else if(is_operator(item)==1){
			temp=pop();
			while(is_operator(temp)==1 && precedence(temp)>=precedence(item)){
				postfix[j]=temp;
				j++;
				temp=pop();
			}
			push(temp);
			push(item);
		}
		else if(item==')'){
			temp=pop();
			while(temp!='('){
				postfix[j]=temp;
				j++;
				temp=pop();
			}
		}
		else{
			printf("Invalid expression\n");
		}
	i++;
	}
	while(top!=-1){
		postfix[j]=pop();
		j++;
	}
	postfix[j]='\0';
	printf("Postfix expression is ");
	printf("%s",postfix);
}