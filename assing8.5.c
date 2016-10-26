#include<stdio.h>
#include<malloc.h>
struct node
{
int data;
struct node * left;
struct node * right;
struct node * parent;
};

struct node * insert (struct node * root, struct node * x)
{
struct node * child=root;
struct node * parent=NULL;

while(child!=NULL)
{
parent=child;
if(child->data<=x->data)
{
child=child->right;
}
else
child=child->left;
}
if(parent==NULL)
root=x;
else
{
if(parent->data>=x->data)
parent->left=x;
else
parent->right=x;
}
x->parent=parent;
return root;

}
int noOfLeaves(struct node * root,int c)
{
if(root->left==NULL && root->right==NULL)
return ++c;
if(root->left)
c=noOfLeaves(root->left,c);
if(root->right)
c=noOfLeaves(root->right,c);
return c;
}
int main()
{
int n;
int c=0;
scanf("%d",&n);
int i=0;
int k=0;
struct node *root=NULL;
root=(struct node *)malloc(sizeof(struct node));
scanf("%d",&root->data);
root->right=NULL;
root->parent=NULL;
root->left=NULL;
for(i;i<n-1;i++)
{
int a;
scanf("%d",&a);
struct node *temp=NULL;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=a;
temp->right=NULL;
temp->left=NULL;
temp->parent=NULL;
root=insert(root,temp);
}


c=noOfLeaves(root,0);
printf("\n%d\n",c);
return 0;
}

