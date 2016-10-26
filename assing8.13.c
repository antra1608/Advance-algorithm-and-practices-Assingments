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
temp=(struct node *)malloc(sizeof(struct node ));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
return temp;
}
struct node *insert(struct node *root,int data)
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

void printAncestor(struct node *root,int data,int **flag)
{
if(root==NULL)
return ;

if(root->data>data && root->left)
{
printAncestor(root->left,data,&(*flag));
if((**flag)==1)
printf("%d ",root->data);
}
else if(root->data<data && root->right)
{
printAncestor(root->right,data,&(*flag));
if((**flag)==1)printf("%d ",root->data);
}
else if(root->data==data) 
{(**flag)=1;
return;}
else
{(**flag)=0;
return;}
}


int main()
{
int n;
int i=0;
scanf("%d",&n);
struct node *root=NULL;
for(i;i<n;i++)
{
int d;
scanf("%d",&d);
root=insert(root,d);
}
int data=0;
scanf("%d",&data);
printf("all ancestor are: \n");
int **f;
int *e;
int a=1;
e=&a;
f=&e;
printAncestor(root,data,f);
}
