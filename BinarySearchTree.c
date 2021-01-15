¬¬¬#include<stdio.h>
#include<stdlib.h>
struct bnode{
        int data;
        struct bnode *left;
        struct bnode *right;
}*root;
struct bnode* insert(struct bnode* root,int val){
if(root==NULL){      
	root=(struct bnode*)malloc(sizeof(struct bnode));
root->data=val;                                                                                                                                               
root->left=NULL;
root->right=NULL;                                                                                                                                            
        }
        else if(val>root->data)
                root->right=insert(root->right,val);
        else
                root->left=insert(root->left,val);
        return root;
}
void preorder(struct bnode* root){
        if(root!=NULL){
                printf("%d \t",root->data);
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
struct bnode* search(struct bnode* root,int val){
        if(root==NULL)
                printf("%d is not found\n",val);
        else if(val==root->data)
                printf("%d is found\n",val);
        else if(val>root->data)
                return search(root->right,val);
        else
                return search(root->left,val);
        return root;
}
struct bnode* find_min(struct bnode* root){
        if(root==NULL)
                return NULL;
        else if(root->left==NULL)
                return root;
        else
                return find_min(root->left);
}
struct bnode* delete(struct bnode* root,int val){
        struct bnode* temp;
        if(root==NULL)
                return NULL;
        else if(val<root->data)
                root->left=delete(root->left,val);
        else if(val>root->data)
                root->right=delete(root->right,val);
        else{
                if(root->left==NULL && root->right==NULL)
                {
           root=NULL;
                          free(root);
                }
                else if(root->left==NULL){
                        temp=root;
                        root=root->right;
                        free(temp);
                }
                else if(root->right==NULL){
                        temp=root;
                        root=root->left;
                        free(temp);
                }
                else{
                        temp=find_min(root->right);
                        root->data=temp->data;
                        root->right=delete(root->right,temp->data);
                }
        }
        return root;
}

 void main(){
        int opt,val;
        do{
        printf("1.Insertion\n");
        printf("2.Deletion\n");
        printf("3.Search\n");
        printf("*****Traversals*****\n");
        printf("4.Preorder\n");
        printf("5.Postorder\n");
        printf("6.Inorder\n");
        printf(“7.Exit\n”);
        printf("Enter your choice\n");
        scanf("%d",&opt);
                switch(opt){
                        case 1:
                                printf("Enter the element to insert\n");
                                scanf("%d",&val);
                                root=insert(root,val);
                                break;
                        case 2:
                                printf("Enter the element to delete\n");
                                scanf("%d",&val);
                                root=delete(root,val);
                                break;
                        case 3:
                                printf("Enter the element to search\n");
                                scanf("%d",&val);
                                search(root,val);
                                break;
                        case 4:
                                printf("The elements of tree in preorder traversal are:\n");
                                preorder(root);
                                printf("\n");
                                break;
                        case 5:
                                 printf("The elements of tree in postorder traversal are:\n");
                                 postorder(root);
                                 printf("\n");
                                  break;
                        case 6:
                                printf("The elements of tree in inorder traversal are:\n");
                                inorder(root);
                                printf("\n");
                                break;
                        case 7:
                                printf("Exited!\n");
                                exit(0);
                                break;
                        default:
                                printf("Enter valid choice\n");
                        }
        }while(opt!=7);

}                                     
                                                  
           

