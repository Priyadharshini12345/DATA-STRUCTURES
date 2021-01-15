#include<stdio.h>
#include<stdlib.h>
struct tree{
        int data;
        struct tree* left;
        struct tree* right;
};
struct tree* create(int val){
        struct tree* new=(struct tree*)malloc(sizeof(int));
        new->data=val;
        new->left=NULL;
        new->right=NULL;
        return new;
}
int count=0;
int leafcount(struct tree* new){
        if(new!=NULL){
                leafcount(new->left);
                if(new->left==NULL && new->right==NULL)
                        count++;
                        leafcount(new->right);
        }
        return count;
}
void main(){
        struct tree* new=create(10);
        new->left=create(5);
        new->right=create(15);
        new->left->left=create(20);
        new->left->right=create(25);
        new->right->left=create(100);
        new->right->right=create(90);
        printf("%d: no of leaf nodes\n",leafcount(new));
}
