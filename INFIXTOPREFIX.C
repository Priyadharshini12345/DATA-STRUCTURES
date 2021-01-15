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
		int k,l,i=0,j=0;
		char item,temp;
		char infix[30],inf[30];
		char prefix[30];
	printf("Enter the infix expression\n");
	scanf("%s",infix);
	for(k=strlen(infix)-1,l=0;k>=0,l<strlen(infix);k--,l++)
		inf[l]=infix[k];
	while(inf[i]!='\0'){
		item=inf[i];
		if(item==')')
			push(item);
		else if(item>='A' && item<='Z' || item>='a' && item<='z'){
			prefix[j]=item;
			j++;
		}
		else if(is_operator(item)==1){
			temp=pop();
			while(is_operator(temp)==1 && precedence(temp)>=precedence(item)){
				prefix[j]=temp;
				j++;
				temp=pop();
			}
			push(temp);
			push(item);
		}
		else if(item=='('){
		temp=pop();
		while(temp!=')'){
			prefix[j]=temp;
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
		prefix[j]=pop();
		j++;
	}
	prefix[j]='\0';
	printf("Prefix expression is\n");
	for(i=strlen(prefix)-1;i>=0;i--)
		printf("%c",prefix[i]);

	}