#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node* prev;
	int data;
	struct node* next;
}*new,*head,*tail,*temp;
void inspos(){
		int pos,value,i,count=0;
	temp=head;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	printf("Enter position to insert\n");
	scanf("%d",&pos);
	printf("Enter the element to insert\n");
	scanf("%d",&value);
	new=(struct node*)malloc(sizeof(struct node));
	new->data=value;
	if(pos==1){
		new->prev=NULL;
		new->next=head;
		head->prev=new;
		head=new;
	}
	else if(pos==count+1){
		new->prev=tail;
		tail->next=new;
		new->next=NULL;
		tail=new;
	}
	else{
		temp=head;
		for(i=1;i<pos-1;i++)
			temp=temp->next;
		new->next=temp->next;
		temp->next->prev=new;
		temp->next=new;
		new->prev=temp;
	}

}
void display(){
	printf("Elements are:\n");
	temp=head;
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
void find(){
		int fd=1;
		int search;
	temp=head;
	printf("Enter the element to find\n");
	scanf("%d",&search);
	while(temp!=NULL){
		if(temp->data==search){
		printf("%d is found\n",temp->data);
		break;
		}
		else{
			fd=0;
			temp=temp->next;
		}
	}
	if(fd==0)
		printf("%d is not found\n",search);
}
void delete(){
		int i=1,j,pos,del,count=0;
	printf("Enter the element to delete\n");
	scanf("%d",&del);
	temp=head;
	while(temp!=NULL){
		if(temp->data==del){
			pos=i;
			break;
		}
		else{
			i++;
			temp=temp->next;
		}
	}
	temp=head;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	if(pos==1){
		temp=head;
		head=head->next;
		temp->next=NULL;
		head->prev=NULL;
	}
	else if(pos==count){
		temp=tail;
		tail=tail->prev;
		temp->prev=NULL;
		tail->next=NULL;
	}
	else{
	temp=head;
	for(j=1;j<pos-1;j++)
		temp=temp->next;
	temp->next=temp->next->next;
	temp->next->prev=temp;
	}
}
void count(){
		int count=0;
	temp=head;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	printf("Total elements are %d\n",count);
}
void modify(){
		int mod,rep;
	printf("Enter the element to modify\n");
	scanf("%d",&mod);
	printf("Enter the element to replace\n");
	scanf("%d",&rep);
	temp=head;
	while(temp!=NULL){
		if(temp->data==mod){
			temp->data=rep;
			break;
		}
		temp=temp->next;
	}
}

void main(){
		int value,opt;
		char ch;
	do{
		new=(struct node*)malloc(sizeof(struct node));
		printf("Enter the element\n");
		scanf("%d",&value);
		new->data=value;
		new->next=NULL;
		new->prev=NULL;
		if(head==NULL){
			head=new;
			tail=new;
		}
		else{
			tail->next=new;
			new->prev=tail;
			tail=new;
		}
		printf("Enter n to exit\n");
		scanf("%s",&ch);
	}while(ch!='n');
	printf("1.INSERTION AT SPECIFIED POSITION\n");
	printf("2.DELETION OF A SPECIFIC ELEMENT\n");
	printf("3.FIND\n");
	printf("4.PRINT ALL ELEMENTS\n");
	printf("5.MODIFY\n");
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
				printf("Exited");
				break;
			default:
				printf("Enter valid option\n");
		}
	}while(opt!=7);
}

