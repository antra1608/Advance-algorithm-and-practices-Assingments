#include<stdio.h>
#include<malloc.h>
struct Node 
{
int data;
int rank;
struct Node *parent;
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
temp->rank=1;
temp->parent=temp;
return temp;

}

struct Node *findRep(struct Node *root)
{
while(root->parent!=root)
root=root->parent;
return root;
}

int findIndex(struct Node *head[],int n,int x)
{
int i=0;
for(i=0;i<n;i++)
{
if(head[i]->data==x)
return i;
}

return -1;

}

struct Node *unionSet(struct Node* head[],int x,int y,int n)
{
int index1=0;
index1=findIndex(head,n,x);
int index2=0;
index2=findIndex(head,n,y);
struct Node *t1=NULL;
t1=findRep(head[index1]);
struct Node *t2=NULL;
t2=findRep(head[index2]);
if(t1!=t2)
{
if(t1->rank==t2->rank)
{
t1->rank++;
t2->parent=t1;
}
else if(t1->rank>t2->rank)
t1->parent=t2;
else
t2->parent=t1;
}
}

struct Graph * createGraph(int v,int e)
{
struct Graph *graph=NULL;
graph=(struct Graph *)malloc(sizeof(struct Graph));
graph->e=e;
graph->v=v;
graph->edge=(struct Edge *)malloc(sizeof(struct Edge)*e);
return graph;
}

struct Edge *sort(struct Edge *edge,int e)
{
int i;
int j;
for(i=0;i<e-1;i++)
{
for(j=i+1;j<e;j++)
{
if(edge[i].w<edge[j].w)
{
int temp;
temp=edge[i].w;
edge[i].w=edge[j].w;
edge[j].w=temp;
temp=edge[i].v1;
edge[i].v1=edge[j].v1;
edge[j].v1=temp;
temp=edge[i].v2;
edge[i].v2=edge[j].v2;
edge[j].v2=temp;
}

}

}

return edge;
}

void maxSpanTree(struct Graph *graph)
{
struct Edge *edge=sort(graph->edge,graph->e);
int i,e=0;
e=graph->e;
i=0;
int c=0;
struct Node *head[graph->v];
for(i=0;i<graph->v;i++)
{
head[i]=makeSet(i);
}
struct Edge *result=NULL;
result=(struct Edge *)malloc(sizeof(struct Edge)*((graph->v)-1));
i=0;
while(i<(graph->v)-1)
{
int v1=edge[c].v1;
int v2=edge[c].v2;
if(findRep(head[v1])!=findRep(head[v2]))
{
result[i]=edge[c];
i++;
unionSet(head,v1,v2,graph->v);
}
c++;
}
for(i=0;i<c;i++)
{
printf("%d--%d  %d\n",result[i].v1,result[i].v2,result[i].w);
}



}

int main()
{
int v,e;
scanf("%d %d",&v,&e);
struct Graph *graph=NULL;
graph=createGraph(v,e);
int i;
for(i=0;i<e;i++)
{
int c;
int d;
int w;
scanf("%d %d %d",&c,&d,&w);
graph->edge[i].v1=c;
graph->edge[i].v2=d;
graph->edge[i].w=w;
}
printf("edges added\n");
maxSpanTree(graph);
}
