#include<stdio.h>
#include<malloc.h>
struct Node 
{
int data;
struct Node *rep;
struct Node *next; 

};
struct Edge
{
int v1;
int v2;
int w;
};

struct Graph
{
int e;
int v;
struct Edge *edge;
};

struct Node *makeSet(int data)
{
struct Node *temp=NULL;
temp=(struct Node *)malloc(sizeof(struct Node));
temp->data=data;
temp->rep=temp;
temp->next;
return temp;

}


int findIndex(struct Node *head[],int x,int n)
{
int i=0;
struct Node *temp=NULL;

for(i=0;i<n;i++)
{
temp=head[i];
while(temp)
{
if(temp->data==x)
return i;
temp=temp->next;

}

}
return -1;
}


struct Node * findRep(struct Node *head[],int x,int n)
{
int i=0;
for(i;i<n;i++)
{
struct Node *temp=NULL;
temp=head[i];
while(temp)
{
if(temp->data==x)
return temp->rep;
temp=temp->next;

}

}
return NULL;
} 

int size(struct Node *temp)
{
int c=0;
while(temp)
{
c++;
temp=temp->next;
}
return c;
}

struct Node *unionSet(struct Node *head[],int x,int y,int n)
{
int index1=0;
index1=findIndex(head,x,n);
int index2=0;
index2=findIndex(head,y,n);
struct Node *temp1=NULL;
temp=findRep(head,x,n);
struct Node *temp2=NULL;
temp2=findRep(head,y,n);
struct Node *t1=NULL;
struct Node *t2=NULL;
t1=temp1;
t2=temp2;
if(temp1==temp2)
return NULL;
else
{
if(size(temp1)>=size(temp2))
{
while(t1->next)
t1=t1->next;
t1->next=t2;
while(t2)
t2->rep=temp1,t2=t2->next;
head[index2]=NULL;
}
else
{
while(t2->next)
t2=t2->next;
t2->next=t1;
while(t1)
t1->rep=temp2,t1=t1->next;
head[index1]=NULL;
}
}
}

struct Graph * createGraph(int e,int v)
{
struct Graph *graph=NULL;
graph->e=e;
graph->v=v;
graph->edge=(struct Edge *)malloc(sizeof(struct edge)*e);
return graph;
}


int main()
{
int e;
int v;
scanf("%d",&v);
scanf("%d",&e);
int i=0;
struct Graph *graph=NULL;
graph=createGraph(e,v);
for(i;i<e;i++)
{
int v1;
int v2,w;
scanf("%d",&v1);
scanf("%d",&v2);
scanf("%d",&w);
graph->edge[i].v1=v1;
graph->edge[i].v2=v2;
graph->edge[i].w=w;

}
printf("created\n");


}
