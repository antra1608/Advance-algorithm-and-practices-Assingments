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
temp->left=temp->right=NULL;
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
void printKDistance(struct node *root,int k)
{
if(k==0)
printf("%d ",root->data);
else
{
if(root->left)
printKDistance(root->left,k-1);
if(root->right)
printKDistance(root->right,k-1);
}

}
int main()
{
int n;
scanf("%d",&n);
int i=0;
struct node *root=NULL;

for(i;i<n;i++)
{
int d;
scanf("%d",&d);
root=insert(root,d);
}
int distance;
scanf("%d",&distance);
printKDistance(root,distance);
return 0;
}
