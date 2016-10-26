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
temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;
temp->right=NULL;
temp->left=NULL;
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

void DFS(struct node *root)
{
printf("%d ",root->data);
if(root->left)
DFS(root->left);
if(root->right)
DFS(root->right);
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
root=insert(root,d);
}
printf("DFS is\n");
DFS(root);
return 0;
}
