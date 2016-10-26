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
struct node * insert(struct node *root,int data)
{
if(root==NULL)
root=newNode(data);
else
{
if(root->data>=data)
root->left=insert(root->left,data);
else
root->right=insert(root->right,data);
}
return root;

}

int height(struct node * root,int data,int level )
{
if(root==NULL)
return 0;
else
{
if(root->data==data)
return level;
else
{
int d=0;
int h=0;
if(root->left)
d=height(root->left,data,level+1);
if(root->right)
h=height(root->right,data,level+1);
if(d>=h)
return d;
else
return h;
}
}

}

void printData(struct node *root,struct node * r)
{
if(r->left)
printData(root,r->left);
int d=0;
d=height(root,r->data,1);
printf(" data = %d and height = %d \n",r->data,d);

if(r->right)
printData(root,r->right);

}
int main()
{
int n;
scanf("%d",&n);
int i=0;
struct node*root=NULL;
for(i;i<n;i++)
{
int d=0;
scanf("%d",&d);
root=insert(root,d);
}

printData(root,root);

return 0;
}
