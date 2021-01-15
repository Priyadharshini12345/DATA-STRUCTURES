

#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
}*new,*head,*tail,*temp;
void inspos(){
		int pos,value,i,count=1;
	printf("Enter the position to insert\n");
	scanf("%d",&pos);
	printf("Enter the element to insert\n");
	scanf("%d",&value);
	new=(struct node*)malloc(sizeof(struct node));
	new->data=value;
	temp=head;
	while(temp->next!=head){
		count++;
		temp=temp->next;
	}
	if(pos==1){
		new->next=head;
		tail->next=new;
		head=new;
	}
	else if(pos==count+1){
		tail->next=new;
		new->next=head;
		tail=new;
	}
	else{
		temp=head;
		for(i=1;i<pos-1;i++)
			temp=temp->next;
		new->next=temp->next;
		temp->next=new;
	}
}
void delete(){
		int value,i=1,j,pos,count=1;
	printf("Enter the element to delete\n");
	scanf("%d",&value);
	temp=head;
	while(temp->next!=head){
		count++;
		temp=temp->next;
	}
	temp=head;
	while(temp->next!=head){
		if(temp->data==value){
			pos=i;
			break;
		}
		else{
			i++;
			temp=temp->next;
		}
	}
	if(temp->data==value)
		pos=i;
	if(pos==1){
		temp=head;
		head=head->next;
		tail->next=head;
		temp->next=NULL;
	}
	else if(pos==count){
		temp=head;
		while(temp->next!=tail){
			temp=temp->next;
		}
		tail->next=NULL;
		temp->next=head;
		tail=temp;
	}
	else{
		temp=head;
		for(j=1;j<pos-1;j++)
			temp=temp->next;
		temp->next=temp->next->next;
	}
}
void find(){
		int search,fd=1;
	printf("Enter the element to search\n");
	scanf("%d",&search);
	temp=head;
	while(temp->next!=head){
		if(temp->data==search){
			printf("%d is found\n",temp->data);
			break;
		}
		else{
			fd=0;
			temp=temp->next;
		}
	}
	if(temp->data==search && fd!=1){
		fd=-1;
		printf("%d is found\n",temp->data);
	}
	if(fd==0 && fd!=-1)
		printf("%d is not found\n",search);
}
void modify(){
		int mod,rep;
	printf("Enter the element to modify\n");
	scanf("%d",&mod);
	printf("Enter the element to replace with\n");
	scanf("%d",&rep);
	temp=head;
	while(temp->next!=head){
		if(temp->data==mod){
			temp->data=rep;
			break;
		}
		else{
			temp=temp->next;
		}
	}
	if(temp->data==mod){
		temp->data=rep;
	}
}
void count(){
		int count=1;
	temp=head;
	while(temp->next!=head){
		count++;
		temp=temp->next;
	}
	printf("Total elements are: %d\n",count);
}
void display(){
	temp=head;
	printf("Elements are:\n");
	while(temp->next!=head){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
}
void main(){
		int val,opt;
		char ch;
	do{
		new=(struct node*)malloc(sizeof(struct node));
		printf("Enter element\n");
		scanf("%d",&val);
		new->data=val;
		new->next=NULL;
		if(head==NULL){
			head=new;
			tail=new;
		}
		else{
			tail->next=new;
			tail=new;
			tail->next=head;
		}
		printf("Enter n to exit\n");
		scanf("%s",&ch);
	}while(ch!='n');
	printf("1.INSERTION AT A SPECIFIED POSITION\n");
	printf("2.DELETION OF A SPECIFIC ELEMENT\n");
	printf("3.FIND\n");
	printf("4.PRINT ALL ELEMENTS\n");
	printf("5.MODIFY AN ELEMENT\n");
	printf("6.COUNT\n");
	do{
		printf("Enter your choice\n");
		scanf("%d",&opt);
		switch(opt){
		case 1:
			inspos();
			break;
		case 2:
			delete();
			break;
		case 3:
			find();
			break;
		case 4:
			display();
			break;
		case 5:
			modify();
			break;
		case 6:
			count();
			break;
		case 7:
			printf("Exited\n");
			break;
		default:
		printf("Enter valid option\n");
		}
	}while(opt!=7);
}



