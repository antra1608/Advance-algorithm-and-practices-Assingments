
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

int find_bst(struct node *root)
{
if(root==NULL)
return 0;
if((root->data>=root->left->data) && (root->data<=root->right->data) && (find_bst(root->left)) &&(find_bst(root->right)))
return 1;
else
return 0;
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

int main()
{
int n,i;
int k=0;
scanf("%d",&n);
struct node *root=NULL;
for(i=0;i<n;i++)
{
int d=0;
scanf("%d",&d);
root=insert(root,d);
}
printf("tree created \n ");
//inorder(root);
k=find_bst(root);
if(k==1)
printf("y\n");
else
printf("n\n");
return 0;
}
