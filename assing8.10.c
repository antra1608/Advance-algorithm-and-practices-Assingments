#include<stdio.h>
#include<malloc.h>
struct node 
{
int data;
struct node *left;
struct node *right;
};

struct node* newNode(int data)
{
struct node *temp=NULL;
temp=(struct node* )malloc(sizeof(struct node));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
return temp;
}

void inorder(struct node *root)
{
if(root->left)
inorder(root->left);
printf("%d_",root->data);
if(root->right)
inorder(root->right);
}  

struct node * insert(struct node *root, int data)
{
if(root==NULL)
{
root=newNode(data);
return root;
}
else

{
if(root->data<=data)
root->right=insert(root->right,data);
else if(root->data>data)
root->left=insert(root->left,data);
return root;
}
}


 clone(struct node *root)
{
if(root==NULL)
return ;

struct node *temp;
temp=root->left;
root->left=root->right;
root->right=temp;
clone(root->left);
clone(root->right);

}

/*
int [] clone(struct node *root)
{
if(root=NULL)
return NULL;
static int a[];
static int index=0;
if(root->left)
a=clone(root->left);
a[index++]=root->data;
if(root->right)
a=clone(root->right);

return a;
}
*/

int main()
{
int n,i;
scanf("%d",&n);
struct node *root=NULL;
for(i=0;i<n;i++)
{
int d=0;
scanf("%d",&d);
root=insert(root,d);
}
printf("tree created \n ");
inorder(root);
struct node *root1=NULL;
root1=root;
clone(root1);
printf("clone tree created \n ");

inorder(root1);

return 0;
}
