#include<stdio.h>
#include<malloc.h>
struct node 
{
int data;
struct node *left;
struct node *right;
};
struct node * newNode(int data)
{
struct node *temp=NULL;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
return temp; 

}

int isSumTree(struct node *root)
{
if(root->left==NULL && root->right==NULL)
return root->data;
else if((root->data==isSumTree(root->left)+isSumTree(root->right)) && root->left && root->right)
return root->data;
else
return 0;
}
int main()
{
struct node *root=newNode(5);
struct node *a=newNode(3);
struct node *b=newNode(2);
struct node *c=newNode(1);
struct node *d=newNode(2);
struct node *e=newNode(7);
struct node *f=newNode(1);
root->left=a;
root->right=b;
a->left=c;
a->right=d;
b->right=e;
b->left=f;

int i=0;
i=isSumTree(root);
if(i==0)
printf("is not Sum tree\n");
else
printf("is sum tree\n");
return 0;
}
