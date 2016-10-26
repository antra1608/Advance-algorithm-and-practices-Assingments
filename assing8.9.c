#include<stdio.h>
#include<malloc.h>
struct node {
int data;
struct node * left;
struct node *  right;
struct node *  parent;

};
void delete_bst(struct node *root)
{
if(root->left)
delete_bst(root->left);
struct node *temp=NULL;
temp=root->right;
printf("deleting %d\n",root->data);
free(root);

if(temp)
delete_bst(temp);
}


struct node * newNode(int data)
{
struct node *temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;
temp->right=NULL;
temp->left=NULL;
temp->parent=NULL;
return temp;

}

/*
struct node * insert(struct node *root, int data)
{
if(root==NULL)
{
root=newNode(data);

return root;
}
if(root->data<=data)
root->right=insert(root->right,data);
else if(root->data>data)
root->left=insert(root->left,data);
return root;
}
*/

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


int main()
{
int n,i;
scanf("%d",&n);
struct node *root=NULL;
for(i=0;i<n;i++)
{
int d;
scanf("%d",&d);
struct node *t=NULL;
t=newNode(d);
root=insert(root,t);

}
printf("tree created\n");
delete_bst(root);
printf("tree deleted\n");
}


