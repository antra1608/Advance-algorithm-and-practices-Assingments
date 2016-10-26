#include<stdio.h>
#include<malloc.h>
struct node
{
int data;
struct node * left;
struct node * right;
struct node * parent;
};
void inorder(struct node * root)
{
if(root->left)
inorder(root->left);
printf("%d_",root->data);
if(root->right)
inorder(root->right);
}

int find_identical(struct node *r1,struct node *r2)
{
 if(r1==NULL && r2==NULL)
 return 1;
 if(r1!=NULL && r2!=NULL)
 return (r1->data==r2->data && (find_identical(r1->left,r2->left)) && (find_identical(r1->right,r2->right)));
return 0;
}



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


int main()
{
int t;
int j=0;
scanf("%d",&t);
for(j;j<t;j++)
{
int n;
scanf("%d",&n);
int c=2;
int i=0;
int k=0;
struct node *root1=NULL;
root1=(struct node *)malloc(sizeof(struct node));
scanf("%d",&root1->data);
root1->right=NULL;
root1->parent=NULL;
root1->left=NULL;
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
root1=insert(root1,temp);
}
struct node *root2=NULL;
root2=(struct node *)malloc(sizeof(struct node));
scanf("%d",&root2->data);
root2->right=NULL;
root2->parent=NULL;
root2->left=NULL;
for(i=0;i<n-1;i++)
{
int a;
scanf("%d",&a);
struct node *temp=NULL;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=a;
temp->right=NULL;
temp->left=NULL;
temp->parent=NULL;
root2=insert(root2,temp);
}
inorder(root1);
printf("\n");
inorder(root2);
c=find_identical(root1,root2);
if(c==1)
printf("y\n");
else 
printf("n\n");
}
return 0;
}
