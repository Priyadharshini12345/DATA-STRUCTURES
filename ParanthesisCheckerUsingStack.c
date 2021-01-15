#include<stdio.h>
#include<string.h>
#define size 20
int top=-1;
int stack[size];
void push(char c){
        if(top==size-1)
                printf("Stack Overflow\n");
        else{
                top++;
                stack[top]=c;
        }
}
char pop(){
                char val;
        if(top==-1)
                printf("Stack underflow\n");
        else{
                val=stack[top];
                top--;
        }
        return val;
}
void main(){
        char exp[30];
        char temp;
        int i=0;
        int flag=1;
        printf("Enter the expression\n");
        scanf("%s",exp);
        for(i=0;i<strlen(exp);i++){
                if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
                        push(exp[i]);
                if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
                        if(top==-1)
                                flag=0;
                        else{
                                temp=pop();
                                if(exp[i]==')' && (temp=='{' || temp=='['))
                                        flag=0;
                                if(exp[i]=='}' &&(temp=='(' || temp=='['))
                                        flag=0;
                                if(exp[i]==']' &&(temp=='(' || temp=='{'))
                                        flag=0;
                        }
        }
        if(top>=0)
                flag=0;
        if(flag==1)
                printf("Yes\n");
        else
                printf("No\n");
}