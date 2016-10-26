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
printf("%d ",root->data);
if(root->right)
inorder(root->right);
}
struct node *precedor(struct node *root)
{
while(root->left!=NULL)
root=root->left;
return root;
}
//both of this delete code will work fine
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

struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


struct node * find_max(struct node *x)
{
while(x->right!=NULL)
x=x->right;
return x;

}



char  search (struct node * root, int x)
{
struct node * child=root;
struct node * parent=NULL;

while(child!=NULL)
{
parent=child;
if(child->data<x)
{
child=child->right;
}
else if(child->data>x)
child=child->left;
else 
return 'y';
}

return 'n';

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


struct node * find_precedor(struct node *root,struct node *x)
{
if(x->left!=NULL)
return find_max(x->left);
struct node * y=NULL;

y=x->parent;
while(y!=NULL && (x==y->left))
{
x=y;
y=y->parent;
}
return y;

}

int main()
{
int n;
int del;
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
//printf("value scanned%d \n",a);
root=insert(root,temp);
//printf("value inserted= %d and root is = %d\n",temp->data,root->data);
}
/*
scanf("%d",&k);
for(i=0;i<k;i++)
{
int dat;
scanf("%d",&dat);
char c=search(root,dat);
printf("%c \n",c);
}

*/

//struct node * ans=find_precedor(root,r);

//:wq
//printf("precedor of %d is %d\n\n inorder is\n",r->data,ans->data);


//printf("\n%d\n",root->data);
inorder(root);
printf("\n");
scanf("%d",&del);
root=delete(root,del);
inorder(root);



return 0;
}
