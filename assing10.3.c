#include<stdio.h>
#include<malloc.h>
struct Edge
{
int v1;
int v2;
//int w;

};
struct Graph
{
int e;
int v;
struct Edge *edge;

};


struct Graph * createGraph(int e,int v)
{
struct Graph *graph=NULL;
graph=(struct Graph *)malloc(sizeof(struct Graph));
graph->e=e;
graph->v=v;
graph->edge=(struct Edge *)malloc(sizeof(struct Edge)*e);
return graph;
}

int isCyclicUtil(int v,int visited[],int *recStack,struct Graph *graph)
{
if(visited[v]==0)
{
	visited[v]=1;
	recStack[v]=1;
	struct Edge *adjacent=NULL;
	adjacent=(struct Edge *)malloc(sizeof(struct Edge)*v-1);
	//struct Edge *edge=(struct Edge *)malloc(sizeof(struct Edge)*v-1);
	
	int i;
	int c=0;
	for(i=0;i<graph->e;i++)
	{	
		if(graph->edge[i].v1==v )
		{
			adjacent[c]=graph->edge[i];
			c++;
		}	
	}
	for(i=0;i<c;i++)
	printf("adjacent of %d are: %d\n",v,adjacent[i].v2);

	for(i=0;i<c;i++)
	{
		printf("recursive called for %d\n",adjacent[i].v2);
		if(!visited[adjacent[i].v2] && isCyclicUtil(adjacent[i].v2,visited,recStack,graph))
			return 1;
		else if(recStack[(i)])
			return 1;
	}
	
}
recStack[v]=0;
return 0;


}

int isCyclic(struct Graph* graph)
{
int visited[graph->v];
int recStack[graph->v];
int i;
for(i=0;i<graph->v;i++)
{
visited[i]=0;
recStack[i]=0;
}

for(i=1;i<=graph->v;i++)
{
printf("isCyclicutil called for %d\n",i);

if(isCyclicUtil(i,visited,recStack,graph))
return 1;
}
return 0;

}

int main()
{
int e;
int v;
struct Graph *graph=NULL;
scanf("%d",&e);
scanf("%d",&v);
graph=createGraph(e,v);
int i;
for(i=0;i<e;i++)
{
int d;
int c;
int w;

scanf("%d",&c);
scanf("%d",&d);
//scanf("%d",&w);
graph->edge[i].v1=c;
graph->edge[i].v2=d;
//graph->edge[i].w=w;

}
printf("graph created\n");
if(isCyclic(graph))
printf("is cyclic\n");
else
printf("not cyclic\n");

return 0;
}
