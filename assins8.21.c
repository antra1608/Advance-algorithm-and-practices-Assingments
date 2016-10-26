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
struct node * temp=NULL;
temp=(struct node *)malloc(sizeof(struct node ));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
return temp;

}

struct node * insert(struct node *root, int data)
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
int height(struct node* root)
{
if(root==NULL)
return 0;
int lh=height(root->left);
int rh=height(root->right);
if(lh>=rh)
return (1+lh);
else
return (1+rh);

}
void printLevel(struct node *root,int level)
{
if(level==1)
printf("%d ",root->data);
if(root->left)
printLevel(root->left,level-1);
if(root->right)
printLevel(root->right,level-1);
}
void levelOrder(struct node *root)
{
int d=0;
d=height(root);
printf("height is %d\n",d);
int i=0;
for(i=1;i<=d;i++)
printLevel(root,i);


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
printf("level order is\n");
levelOrder(root);


}
