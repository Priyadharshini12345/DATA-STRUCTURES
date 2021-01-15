¬#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct bnode{
        int data;
        struct bnode* left;
        struct bnode* right;
}*root;
struct bnode* create(){
        struct bnode* newnode;
        int val;
        newnode=(struct bnode*)malloc(sizeof(struct bnode));
        printf("Enter the value of the node\n");
        scanf("%d",&val);
        if(val==-1)
                return 0;
        newnode->data=val;
        printf("Enter the left child of %d\n",val);
        newnode->left=create();
        printf("Enter the right child of %d\n",val);
        newnode->right=create();
        return newnode;
}

void preorder(struct bnode* root){                                                                                                                                    
if(root!=NULL){
printf("%d\t",root->data);   
preorder(root->left);                                                                                                                                 
                preorder(root->right);
        }
}
void postorder(struct bnode* root){
        if(root!=NULL){
                postorder(root->left);
                postorder(root->right);
                printf("%d\t",root->data);
        }
}
                                                                                                                                            
void inorder(struct bnode* root){
        if(root!=NULL){
                inorder(root->left);
                printf("%d\t",root->data);
                inorder(root->right);
        }
}
bool search(struct bnode* root,int val){
        if(root==NULL)
                return false;
        else if(root->data==val)
                return true;
        bool res1=search(root->left,val);
        if(res1)
                return true;
        bool res2=search(root->right,val);
        if(res2)
                return true;
}
struct bnode* find(struct bnode* root,int x){
        struct bnode* temp;
        if(root!=NULL)
        {
                if(root->data==x)
                        return root;
                else{
                        temp=find(root->left,x);
                        if(temp==NULL)
                                temp=find(root->right,x);
                        return temp;
                }
        }
        else
                return NULL;
}
struct bnode* deep(struct bnode* root){
        if(root->left==NULL && root->right==NULL)
                return root;
       else if(root->right!=NULL)
                return deep(root->right);
        else
                return deep(root->left);
}
struct bnode* deepbefore(struct bnode* root,struct bnode* deep){
        if(root->right==deep || root->left==deep)
                return root;
        if(root->right!=NULL)
                return deepbefore(root->right,deep);
        else
                return deepbefore(root->left,deep);
}
void delete(struct bnode* root,int x){
        struct bnode* temp,*fin,*deepbef;
        temp=deep(root);
        deepbef=deepbefore(root,temp);
        fin=find(root,x);
        fin->data=temp->data;
        if(deepbef->left==temp)
                deepbef->left=NULL;
        else if(deepbef->right==temp)
                deepbef->right=NULL;
}
void main(){
        int opt,h,val;
        bool op;
        struct bnode* root;
        root=create();
        do{
                printf("***Traversals\n");
                printf("1.Preorder traversal\n");
                printf("2.Postorder traversal\n");
                printf("3.Inorder traversal\n");
                printf("4.Deletion\n");
 printf("5.Search\n");
printf("6.Exit\n”);
 printf("Enter your choice\n");                                                                                                                                            
                scanf("%d",&opt);
                switch(opt){
                        case 1:
                                preorder(root);
                                printf("\n");
                                break;
                        case 2:
                                postorder(root);
                                printf("\n");
                                break;
                        case 3:
                                inorder(root);
                                printf("\n");
                                break;
                        case 4:
                                printf("Enter the value of the node to delete\n");
                                scanf("%d",&val);
                                delete(root,val);
                                break;
                        case 5:
                                printf("Enter the element to search\n");
                                scanf("%d",&val);
                                op=search(root,val);
                                if(op)
                                        printf("%d is found\n",val);
                                else
                                        printf("%d is not found\n",val);
                                break;
                        
                        default:
printf(“Enter valid choice\n”);
                break;
                }
        }while(opt!=6);
}                                
      

