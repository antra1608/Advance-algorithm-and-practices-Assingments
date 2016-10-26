#include<stdio.h>
#include<malloc.h>
struct node 
{
 	int data;
	struct node *left;
	struct node *right;
	
};
struct node *newNode(int data)
{
	struct node *temp=NULL;
	temp=(struct node *)malloc(sizeof(struct node ));
	temp->data=data;
	temp->right=temp->left=NULL;;
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

struct node * findLca(struct node *root,int data1,int data2)
{
	//printf("findlcs called for %d and %d and root = %d\n",data1,data2,root->data);
	if(root->data>data1 && root->data>data2)
		{return findLca(root->left,data1,data2);}
	else if(root->data<data1 && root->data<data2)
		{return findLca(root->right,data1,data2);}
	else
{
		return root;
}
}
int searchHeight(struct node *root,int data,int *height)
{
 	if(root==NULL)
		return 0;
	if(root->data==data)
		{return *height;}
	else if(root->data>data)
		{++(*height);
	(*height)=searchHeight(root->left,data,height);}
	else if(root->data<data)
	{++(*height);
		(*height)=searchHeight(root->right,data,height);
	}
return *height;
}

int findDistance(struct node *root,int data1,int data2)
{
	struct node *lca=NULL;
	printf("keys are %d and %d\n",data1,data2);
	lca=findLca(root,data1,data2);
	int dh1=0;
	int dh2=0;
	int *p=&dh1;
	int *q=&dh2;
		printf("lca is %d\n",lca->data);
dh1=searchHeight(lca,data1,p);
printf("dh1 = %d",dh1);
lca=findLca(root,data1,data2);
printf("lca is = %d\n",lca->data);	
dh2=searchHeight(lca,data2,q);
printf("dh2 = %d\n",dh2);
	return dh1+dh2;
}

void inorder(struct node * root)
{
	if(root->left)
		inorder(root->left);
		printf("%d ",root->data);
	if(root->right)
		inorder(root->right);

}
int main()
{
	int n;
	int i=0;
	int data1,data2;
	int distance=0;
	scanf("%d",&n);
	struct node *root=NULL;
	for(i;i<n;i++)
	{
		int d=0;
		scanf("%d",&d);
 		root=insert(root,d);
	}
	inorder(root);
	scanf("%d",&data1);
	scanf("%d",&data2);
	distance=findDistance(root,data1,data2);
	printf("%d",distance);
	return 0;	
}

