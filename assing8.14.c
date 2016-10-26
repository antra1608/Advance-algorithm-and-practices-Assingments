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
temp=(struct node *)malloc(sizeof(struct node));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
return temp;
};


struct node * insert(struct node * root,int data)
{
if(root==NULL)
root=newNode(data);
else
{
if(root->data<=data)
root->right=insert(root->right,data);
else if(root->data>data)
root->left=insert(root->left,data);
}
return root;
}

void inorder(struct node * root)
{
if(root->left)
inorder(root->left);
printf("%d_",root->data);
if(root->right)
inorder(root->right);
}

struct node *precedor(struct node *root)
{
while(root->left!=NULL)
root=root->left;
return root;
}


struct node * delete(struct node *root, int data)
{
if(root==NULL)
return root;
if(root->data==data)
{
	if(!(root->left) && !(root->right))
	{
	struct node * temp=root;
	free(temp);
	return NULL;	
	}
	else if((root->left)==NULL)
	{
	struct node * temp=root->right;
	free(root);
	return temp;
	}
	else if((root->right)==NULL)
	{
	struct node *temp=root->left;
	free(root);
	return temp;
	}
	else
	{
	struct node * temp=precedor(root->right);
	printf("succesor is %d\n",temp->data);
	root->data=temp->data;
	root->right=delete(root->right,temp->data);
	}
	return root;

}
else if(root->data>=data)
{root->left=delete(root->left,data); return root;}
else
{root->right=delete(root->right,data); return root;}
}

delete_leaf(struct node * root,struct node *temp)
{
if(root->left)
{
delete_leaf(root->left,temp);
}

if(root->left==NULL && root->right==NULL)
{
temp=delete(temp,root->data);
}
if(root->right)
{
delete_leaf(root->right,temp);
}
}
int main()
{
struct node *root=NULL;
int n;
scanf("%d",&n);
int i=0;
for(i;i<n;i++)
{
int d=0;
scanf("%d",&d);
root=insert(root,d);
}
inorder(root);
delete_leaf(root,root);
printf("\n");
inorder(root);
return 0;
}




