#include<stdio.h>
#include<malloc.h>
struct node
{
int data;
struct node * left;
struct node * right;
struct node * parent;
};
void inorder(struct node * root)
{
if(root->left)
inorder(root->left);
printf("%d_",root->data);
if(root->right)
inorder(root->right);
}
void preorder(struct node * root)
{
printf("%d_",root->data);

if(root->left)
preorder(root->left);
if(root->right)
preorder(root->right);
}
void postorder(struct node * root)
{
if(root->left)
postorder(root->left);
if(root->right)
postorder(root->right);
printf("%d_",root->data);

}

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
int n;
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




printf("\n%d\n",root->data);
inorder(root);
printf("\n");
preorder(root);
printf("\n");
postorder(root);


return 0;
}
