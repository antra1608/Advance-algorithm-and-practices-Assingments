#include<stdio.h>
#include<malloc.h>

struct node 
{
int data;
struct node *left;
struct node *right;
};
struct node* newnode(char data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
void inorder(struct node * root)
{
if(root->left)
inorder(root->left);
printf("%c_",root->data);
if(root->right)
inorder(root->right);
}

int search(char in[],struct node *t,int strt,int end)
{
int i=0;
for(i=strt;i<=end;i++)
{
if(in[i]==t->data)
return i;
}
}
struct node * buildTree(char in[],char pre[],int strt,int end)
{
static int preindex=0;
if(strt>end)
return NULL;
struct node *t=NULL;
t=newnode(pre[preindex++]);

if(strt==end)
return t;

int index=search(in,t,strt,end);
t->left=buildTree(in,pre,strt,index-1);
t->right=buildTree(in,pre,index+1,end);

return t;
}
int main()
{
char in[]={'d','b','e','a','f','c'};
char pre[]={'a','b','d','e','c','f'};
int len=sizeof(in)/sizeof(in[0]);
struct node *root=NULL;
root=buildTree(in,pre,0,len-1);
inorder(root);
return 0;
}
