#include<stdio.h>
#include<malloc.h>
struct Node 
{
int data;
struct Node *left;
struct Node *right;
int height;
};

int max(int a,int b)
{
return (a>b)?a:b;
}

struct Node *newNode(int data)
{
struct Node *temp=NULL;
temp=(struct Node *)malloc(sizeof(struct Node));
temp->data=data;
temp->left=temp->right=NULL;
temp->height=1;
return temp;
}

void preorder(struct Node *root)
{
printf("%d ",root->data);
if(root->left)
preorder(root->left);
if(root->right)
preorder(root->right);
}

int height(struct Node *root)
{
if(root==NULL)
return 0;
return root->height;
}

int getBalance(struct Node *root)
{
return height(root->left)-height(root->right);
}

struct Node *leftRotation(struct Node *root)
{
struct Node *x=NULL;
struct Node *y=NULL;
x=root->right;
y=x->left;

x->left=root;
root->right=y;

return x;

}

struct Node *rightRotation(struct Node *root)
{
struct Node *x=NULL;
struct Node *y=NULL;
x=root->left;;
y=x->right;

x->right=root;
root->left=y;

return x;

}



struct Node * insert(struct Node *root,int data)
{
if(root==NULL)
return newNode(data);
if(root->data>data)
root->left=insert(root->left,data);
else 
root->right=insert(root->right,data);

root->height=max(height(root->left),height(root->right))+1;

int balance=getBalance(root);

if(balance>1 && data<root->left->data)
return rightRotation(root);

if(balance>1 && data>root->left->data)
{
root->left=leftRotation(root->left);
return rightRotation(root);
}

if(balance<-1 && data>root->right->data)
{
return leftRotation(root);
}

if(balance<-1 && data<root->right->data)
{
root->right=rightRotation(root->right);
return leftRotation(root);
}

return root;

}

struct Node * successor(struct Node *temp)
{
while(temp->right)
temp=temp->right;
return temp;
}




struct Node *delete(struct Node *root,int data)
{
if(root==NULL)
return NULL;
if(root->data==data)
{
if(root->left==NULL && root->right==NULL)
{
free(root);
return NULL;
}
else if(root->left!=NULL && root->right==NULL)
{
struct Node *temp=NULL;
temp=root->left;
free(root);
return temp;
}
else if(root->right!=NULL && root->left==NULL)
{
struct Node *temp=NULL;
temp=root->right;
free(root);
return temp;
}
else
{
struct Node *temp=NULL;
temp=successor(root->right);
root->data=temp->data;
root->right=delete(root->right,data);

}
}
else if(root->data>data)
root->left=delete(root->left,data);
else
root->right=delete(root->right,data);

if(root==NULL)
return NULL;
root->height=max(height(root->left),height(root->right))+1;
int balance=getBalance(root);

if(balance>1 && data<root->left->data)
return rightRotation(root);
if(balance>1 && data>root->left->data)
{
root->left=leftRotation(root->left);
return rightRotation(root);
}
if(balance<-1 && data>root->right->data)
return leftRotation(root);
if(balance<-1 && data<root->right->data)
{
root->right=rightRotation(root->right);
return leftRotation(root);
}
return root;

}

int main()
{
int n;
scanf("%d",&n);
int i;
struct Node *root=NULL;
for(i=0;i<n;i++)
{
int d;
scanf("%d",&d);
root=insert(root,d);

}
preorder(root);
int k;
scanf("%d",&k);

for(i=0;i<k;i++)
{
int d;
scanf("%d",&d);
root=delete(root,d);
preorder(root);

}
}
