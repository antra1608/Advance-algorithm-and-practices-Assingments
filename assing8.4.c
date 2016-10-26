#include<stdio.h>
#include<malloc.h>
struct node
{
int data;
struct node * left;
struct node * right;
struct node * parent;
};

struct node * insert (struct node * root, struct node * x)
{
struct node * child=root;
struct node * parent=NULL;

while(child!=NULL)
{
parent=child;
if(child->data<=x->data)
{
child=child->right;
}
else
child=child->left;
}
if(parent==NULL)
root=x;
else
{
if(parent->data>=x->data)
parent->left=x;
else
parent->right=x;
}
x->parent=parent;
return root;

}
void printpaths(struct node *root)
{
int path[1000];
print_recur(root,path,0);
}
 print_recur(struct node *root,int path[],int len)
{
if(root==NULL)
return;
path[len]=root->data;
len++;
if(root->left==NULL && root->right==NULL)
print_array(path,len);
else
{
print_recur(root->left,path,len);
print_recur(root->right,path,len);
}

}
print_array(int path[],int len)
{
int i=0;
for(i;i<len;i++)
printf("%d ",path[i]);
printf("\n");
}
int main()
{
int n;
scanf("%d",&n);
int i=0;
int k=0;
struct node *root=NULL;
root=(struct node *)malloc(sizeof(struct node));
scanf("%d",&root->data);
root->right=NULL;
root->parent=NULL;
root->left=NULL;
for(i;i<n-1;i++)
{
int a;
scanf("%d",&a);
struct node *temp=NULL;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=a;
temp->right=NULL;
temp->left=NULL;
temp->parent=NULL;
root=insert(root,temp);
}


printpaths(root);
return 0;
}

