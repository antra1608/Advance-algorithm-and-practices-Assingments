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
temp=malloc(sizeof(struct node));
temp->data=data;
temp->left=NULL;
temp->right=NULL;
return temp;
}

struct node * insert(struct node* root,int data)
{
if(root==NULL)
{
root=newNode(data);
}
else
{
if(root->data>=data)
root->left=insert(root->left,data);
else
root->right=insert(root->right,data);
}
return root;
}

void inorder(struct node* root)
{
if(root->left)
inorder(root->left);
printf("%d_",root->data);
if(root->right)
inorder(root->right);
}

struct node *predececor(struct node *root)
{
while(root->right)
root=root->right;
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
	struct node * temp=predececor(root->right);
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
/*
struct node * delete(struct node *root,int data)
{
if(root==NULL)
return NULL;
if(root->data>data)
root->left=delete(root->left,data);
else if(root->data<data)
root->right=delete(root->right,data);
else
{
if(root->left==NULL && root->right==NULL)
{
struct node *t=NULL;
t=root;
free(t);
return NULL;
}
else if(root->left==NULL && root->right!=NULL)
{
struct node *temp=root->right;
free(root);
return temp;

}
else if(root->right==NULL && root->left!=NULL)
{
struct node *temp=root->left;
free(root);
return temp;

}
else
{
struct node *temp=predececor(root->left);
root->data=temp->data;
root->left=delete(root->left,temp->data);

}

}
return root;
}
*/
int count_nodes(struct node *root,int k)
{
if(root==NULL)
return k;
if(root->left)
k=count_nodes(root->left,k);
k++;
if(root->right)
k=count_nodes(root->right,k);

return k;
}

void delete_tree(struct node *root,int n)
{
//int k=count_nodes(root,0);
int i=0;
for(i;i<n;i++)
{
root=delete(root,root->data);
printf("\n");
if(i!=n-1)
inorder(root);
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
int d;
scanf("%d",&d);
root=insert(root,d);

}
printf("tree created \n now deleting\n");
inorder(root);
//int k=count_nodes(root,0);
delete_tree(root,n);
printf("%d",k);
return 0;
}

