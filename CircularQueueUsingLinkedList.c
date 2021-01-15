#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node* next;
}*fro,*rear;
void enqueue(int val){
        struct node* new=(struct node*)malloc(sizeof(struct node));
        new->data=val;
        new->next=NULL;
        if(fro==NULL && rear==NULL){
                fro=new;
                rear=new;
        }
        else{
                rear->next=new;
                rear=new;
                new->next=fro;
                }
}
void dequeue(){
        struct node* temp=fro;
        if(fro==NULL && rear==NULL)
                printf("Queue is empty\n");
        else if(fro==rear){
 fro=NULL;                                                                                                                                                     rear=NULL;                                                                                                                                                    printf("%d is dequeued\n",temp->data);
               free(temp);
        }     
      else{                                                                                                                                                        
fro=fro->next;                                                                                                                                                rear->next=fro;                                                                                                                                               printf("%d is dequeued\n",temp->data);
                free(temp);
        }
}
void print(){
        struct node* temp;
        temp=fro;
        if(fro==NULL && rear==NULL)
                printf("Queue is empty\n");
        else{
                do{
                        printf("%d\n",temp->data);
                        temp=temp->next;
                }while(temp!=fro);
        }
}
void main(){
        int opt,val,n,i=0;
        do{
                printf("1.Enqueue\n");
                printf("2.Dequeue\n");
                printf("3.Display\n");
                printf("4.Exit\n");
                printf("Enter your choice\n");
                scanf("%d",&opt);
                switch(opt){
                        case 1:
                                printf("Enter the number of data to insert\n");
                                scanf("%d",&n);
                                while(i<n){
                                printf("Enter the data to insert\n");
                                scanf("%d",&val);
                                enqueue(val);
                                i++;
                                }
                                break;
                        case 2:
                                dequeue();
                                break;
                        case 3:
                                printf("The elements of circular queue are\n");
                                print();
                                break;
                                             }
        }while(opt!=4);
}


