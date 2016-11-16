#include<stdio.h>
#include<malloc.h>
struct Node
{
int data;
struct Node *left;
struct Node *right;
int height;
};

struct Node* newNode(int data)
{
struct Node *temp=NULL;
temp=(struct Node *)malloc(sizeof(struct Node));
temp->left=temp->right=NULL;
temp->data=data;
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
if(root==NULL)
return 0;
return height(root->left)-height(root->right);

}

int max(int a,int b)
{
return (a>b)?a:b;
}

struct Node *leftRotate(struct Node *);
struct Node *rightRotate(struct Node *);



struct Node *insert(struct Node *root,int data)
{
if(root==NULL)
return newNode(data);

if(root->data>data)
root->left=insert(root->left,data);
else 
root->right=insert(root->right,data);

root->height=max(height(root->left),height(root->right))+1;
int balance=getBalance(root);

if(balance>1 && data<root->left->data )
return rightRotate(root);

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

if(balance<-1 && data>root->right->data)
{
return leftRotate(root);
}

return root;
}

struct Node * leftRotate(struct Node *x)
{

{
struct Node *y=x->right;
struct Node *T2=y->left;
y->left=x;
x->right=T2;

x->height=max(height(x->left),height(x->right))+1;
y->height=max(height(y->left),height(y->right))+1;


return y;

}
}


struct Node * rightRotate(struct Node *root)
{

{
struct Node *x=root->left;
struct Node *T2=x->right;

x->right=root;
root->left=T2;
root->height=max(height(root->left),height(root->right));
x->height=max(height(x->left),height(x->right));

return x;

}
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
int t;
scanf("%d",&t);

struct Node **ans=NULL;
ans=(struct Node **)malloc(sizeof(struct Node *)*t);
int k;
for(k=0;k<t;k++)
{
int n;
scanf("%d",&n);
struct Node *root=NULL;
int i;
for(i=0;i<n;i++)
{
int d;
scanf("%d",&d);
root=insert(root,d);
}

ans[k]=root;
}
for(k=0;k<t;k++)
preorder(ans[k]),printf("\n");
return 0;
}
