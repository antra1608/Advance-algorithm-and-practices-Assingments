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

struct Node* makeSet(int data)
{
	struct Node *temp=NULL;
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	temp->rank=0;
	temp->parent=temp;
}

int findIndex(struct Node *head[],int x,int n)
{
	int i=0;
	for(i;i<n;i++)
		{
			if(head[i]->data==x)
				return i;	
		}	
	return -1;
}

struct Node * findRep(struct Node *temp )
{
	while(temp->parent!=temp)
	temp=temp->parent;
	return temp;
}

struct Node * unionSet(struct Node *head[],int x,int y,int n)
{
	int index1=findIndex(head,x,n);
	int index2=findIndex(head,y,n);
	struct Node *temp1=findRep(head[index1]);
	struct Node *temp2=findRep(head[index2]);
	
	if(temp1==temp2)
		return NULL;
	else
	{
		if(temp1->rank==temp2->rank)
		{
			temp1->rank++;
			temp2->parent=temp1;
		}
		else if(temp1->rank>temp2->rank)
		{
			temp2->parent=temp1;
		}
		else
		{
			temp1->parent=temp2;	
		}

	}
	return temp1;
}

void display(struct Node *head[],int n)
{
int i;
for(i=0;i<n;i++)
{
struct Node *temp=NULL;
temp=head[i];
if(temp->parent==temp)
{
int j;
printf("{");
for(j=0;j<n;j++)
{
if(temp==findRep(head[j]))
printf("%d ",head[j]->data);
}
printf("}\n");
}
else
{
printf("{ }\n");
}


}

}

struct Graph * createGraph(int v,int e)
{
	struct Graph *graph=NULL;
	graph=(struct Graph*)malloc(sizeof(struct Graph));
	graph->v=v;
	graph->e=e;
	graph->edge=(struct Edge *)malloc(sizeof(struct Edge)*e);
	return graph;

}

struct Graph * prim(struct Graph *graph)
{
	int v=graph->v;
	int e=graph->e;
	struct Edge *adjacent=NULL;
	adjacent=(struct Edge *)malloc(sizeof(struct Edge)*(v-1));
	struct Edge result[v-1];
	struct Node *head[v];
	int i=0;
	
	int j,k,c;
	struct Edge x=graph->edge[0];
	int src=x.v1;
	for(k=0;k<v;k++)
	{
		head[k]=makeSet(k);	
	}
	display(head,v);
	while(i<v-1)	
	{
c=0;
		for(j=0;j<e;j++)
		{
				
			if(graph->edge[j].v1==src || graph->edge[j].v2==src)
			{
				adjacent[c]=graph->edge[j];
		printf("added edge %d--%d in %d\n",adjacent[c].v1,adjacent[c].v2,c);	
c=c+1;
				
			}
				
		}
		int min=adjacent[0].w;
		int index_min=0;
		for(j=0;j<c;j++)
		printf("edge %d--%d\n",adjacent[j].v1,adjacent[j].v2);
		for(j=1;j<c;j++)
		{
			if(findRep(head[adjacent[0].v1])==findRep(head[adjacent[0].v2]) && j==1)
			{min=adjacent[1].w;
			index_min=1;}
			if(adjacent[j].w<min && findRep(head[adjacent[j].v1])!=findRep(head[adjacent[j].v2]))
			{
				min=adjacent[j].w;
				index_min=j;
			}
		}
		c=0;
		result[i++]=adjacent[index_min];
		unionSet(head,adjacent[index_min].v1,adjacent[index_min].v2,v);
		display(head,v);
		if(adjacent[index_min].v1==src)
			src=adjacent[index_min].v2;
		else
			src=adjacent[index_min].v1;
		
		printf("new src is = %d\n",src);	
}
	for(j=0;j<v-1;j++)
		printf("edge = %d--%d weight = %d\n",result[j].v1,result[j].v2,result[j].w);


}

int main()
{
	int v,e;
	scanf("%d",&v);
	scanf("%d",&e);
	int i;
	struct Graph *graph=NULL;
	graph=createGraph(v,e);

	for(i=0;i<e;i++)
	{
		int v1,v2,w;
		scanf("%d %d %d",&v1,&v2,&w);
		graph->edge[i].v1=v1;
		graph->edge[i].v2=v2;
		graph->edge[i].w=w;		
	}
	for(i=0;i<e;i++)
	{
		printf("%d--%d   %d\n",graph->edge[i].v1,graph->edge[i].v2,graph->edge[i].w);	
	}
		
	printf("created\n");
	prim(graph);
}
