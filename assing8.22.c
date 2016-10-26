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
temp->right=temp->left=NULL;
return temp;

}

int max(int l,int r)
{
return (l>r?l:r);
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
void inorder(struct node *root)
{
if(root->left)
inorder(root->left);
printf("%d ",root->data);
if(root->right)
inorder(root->right);
}

struct node *pruneUtil(struct node *root,int k,int *sum)
{
if(root==NULL)
return root;
int lsum= (*sum) + (root->data);
int rsum=lsum;
root->left=pruneUtil(root->left,k,&lsum);
root->right=pruneUtil(root->right,k,&rsum);
*sum=max(lsum,rsum);
if(*sum<k)
{
free(root);
root=NULL;

}
return root;

}

struct node *prune(struct node *root,int k)
{
int sum=0;
return pruneUtil(root,k,&sum);
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
int k=0;
scanf("%d",&k);
root=prune(root,k);
inorder(root);
}
