#include<stdio.h>
#include<malloc.h>
struct Node 
{
int data;
struct Node *left;
struct Node *right;
int height;
};

struct Node *newNode(int data)
{
struct Node *temp=NULL;
temp=(struct Node *)malloc(sizeof(struct Node));
temp->data=data;
temp->left=temp->right=NULL;
temp->height=1;
return temp;
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
int max(int a,int b)
{

return (a>b)?a:b;
}

struct Node * leftRotate(struct Node *root)
{
struct Node *y=NULL;
y=root->right;
struct Node *t2=NULL;
t2=y->left;

y->left=root;
root->right=t2;

root->height=max(height(root->right),height(root->left))+1;
y->height=max(height(y->right),height(y->left))+1;

return y;
}

struct Node *rightRotate(struct Node *root)
{
struct Node *x=NULL;
x=root->left;
struct Node *t2=NULL;
t2=x->right;

x->right=root;
root->left=t2;

root->height=max(height(root->left),height(root->right))+1;
x->height=max(height(x->left),height(x->right))+1;

return x;
}


struct Node *insert(struct Node *root,int data)
{
if(root==NULL)
return newNode(data);
if(root->data>data)
root->left=insert(root->left,data);
else 
root->right=insert(root->right,data);

root->height=max(height(root->left),height(root->right));

int balance=getBalance(root);

if(balance>1 && data<root->left->data)
return rightRotate(root);

if(balance<-1 && data>root->right->data)
return leftRotate(root);

if(balance>1 && data>root->left->data)
{
root->left=leftRotate(root->left);
return rightRotate(root);
}
if(balance<-1 && data<root->right->data)
{
root->right=rightRotate(root->right);
return leftRotate(root);
}

return root;
}
struct Node *successor(struct Node *root)
{
while(root->left)
root=root->left;
return root;

}

struct Node *delete(struct Node *root,int data)
{
if(root==NULL)
return NULL;
if(root->data==data)
{
if(root->left==NULL && root->right==NULL )
{
free(root);
return NULL;

}
else if(root->left==NULL && root->right!=NULL)
{
struct Node *temp=NULL;
temp=root->right;
free(root);
return temp;
}
else if(root->left!=NULL && root->right==NULL)
{
struct Node *temp=NULL;
temp=root->left;
free(root);
return temp;
}
else
{
struct Node *temp=successor(root->right);
root->data=temp->data;
root->right=delete(root->right,temp->data);
}


}
else if(root->data<data)
root->right=delete(root->right,data);
else
root->left=delete(root->left,data);

if(root==NULL)
return root;
root->height=max(height(root->left),height(root->right))+1;
int balance=getBalance(root);

if(balance>1 && getBalance(root->left)>=0 )
return rightRotate(root);

if(balance>1 && getBalance(root->left)<0)
{
root->left=leftRotate(root->left);
return rightRotate(root);
}

if(balance<-1 && getBalance(root->right)<=0)
return leftRotate(root);

if(balance<-1 && getBalance(root->right)>0)
{
root->right=rightRotate(root->right);
return leftRotate(root);
}
return root;
}

void preorder(struct Node *root)
{
printf("%d ",root->data);
if(root->left)
preorder(root->left);
if(root->right)
preorder(root->right);
}

int main()
{
int n;
scanf("%d",&n);
int i=0;
struct Node *root=NULL;
for(i=0;i<n;i++)
{
int d;
scanf("%d",&d);
root=insert(root,d);
}
int m;
scanf("%d",&m);
for(i=0;i<m;i++)
{
int d;
scanf("%d",&d);
root=delete(root,d);
preorder(root);
}

}

