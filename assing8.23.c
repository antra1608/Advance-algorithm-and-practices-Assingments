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
temp=(struct node *)malloc(sizeof(struct node *));
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

struct node * succesor(struct node *root)
{
while(root->right)
root=root->right;
return root;
}

struct node * delete(struct node * root, int data)
{
if(root==NULL)
return NULL;
if(root->data==data)
{
if(root->left==NULL && root->right==NULL)
{
struct node *temp=root;
free(root);
return NULL;

}
else if(root->left!=NULL && root->right==NULL)
{
struct node *temp=root->left;
free(root);
return temp;
}
else if(root->right!=NULL && root->left==NULL)
{
struct node *temp=root->right;
free(root);
return temp;
}
else
{
struct node *temp=succesor(root);
root->data=temp->data;
root->right=delete(root->right,temp->data);

}
return root;

}
else if(root->data>data)
root->left=delete(root->left,data);
else
root->right=delete(root->right,data);

}

int * inorderArray(struct node * root,int * a,int *index )
{

if(root->left)
a=inorderArray(root->left,a,index);
a[(*index)++]=root->data;

if(root->right)
a=inorderArray(root->right,a,index);
return a;
}

struct node * deleteDuplicate(struct node *root,int n)
{
int *a=NULL;
int b=1;
int *index=&b;

a=(int *)malloc(sizeof(int)*n);
if(a)
a=inorderArray(root,a,index);
int i=1;
printf("\n");
for(i=1;i<n;i++)
{
if(a[i]==a[i+1])
root=delete(root,a[i]);
}
return root;
}


inorder(struct node *root)
{
if(root->left)
inorder(root->left);
printf("%d ",root->data);
if(root->right)
inorder(root->right);
}
int main()
{
int n;
scanf("%d",&n);
int i=0;
struct node *root=NULL;
for(i;i<n;i++)
{
int data=0;
scanf("%d",&data);
root=insert(root,data);
}
inorder(root);
printf("\n");
root=deleteDuplicate(root,n);
inorder(root);

return 0;
}


