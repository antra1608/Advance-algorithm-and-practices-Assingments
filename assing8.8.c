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
struct node *new=NULL;
new=(struct node *)malloc(sizeof(struct node));
new->data=data;
new->left=NULL;
new->right=NULL;
return new;
}

void inorder(struct node *root)
{
if(root->left)
inorder(root->left);
printf("%d_",root->data);
if(root->right)
inorder(root->right);
}


struct node * bin_tree(int pre[],int post[],int *preindex,int l,int h,int size)
{
if(*preindex>=size || l>h )
return NULL;

struct node *root=NULL;
root=newNode(pre[*preindex]);
++(*preindex);

if(l==h)
return root;

int i=l;
for(i;i<=h;i++)
{
if(post[i]==pre[*preindex])
break;
}
if(i<=h)
{
root->left=bin_tree(pre,post,preindex,l,i,size);
root->right=bin_tree(pre,post,preindex,i+1,h,size);
}
return root;

}

int main()
{
int pre[]={1,2,4,8,9,5,3,6,7};
int post[]={8,9,4,5,2,6,7,3,1};
int size=sizeof(pre)/sizeof(pre[0]);
struct node *root=NULL;
int preindex=0;
root=bin_tree(pre,post,&preindex,0,size-1,size);
printf("\ninorder is:\n");
inorder(root);
return 0;
}


