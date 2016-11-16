#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct Node 
{
	int data;
	int rank;
	struct Node * parent;
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

struct Node *newNode(int data)
{
	struct Node*temp=NULL;
	temp=(struct Node *)malloc(sizeof(struct Node)); 
	temp->data=data;
	temp->rank=0;
	temp->parent=NULL;
}

struct Node *makeSet(int data)
{
	struct Node *temp=NULL;
	temp=newNode(data);
	temp->parent=temp;
	return temp;

}

//Find representative
struct Node *findRep(struct Node *temp)
{
	while(temp->parent!=temp)
		temp=temp->parent;
	return temp;
}

//Find index of x
int findIndex(struct Node*head[],int x,int n)
{
	int i=0;
	for(i;i<n;i++)
	{	
		if(head[i]->data==x)
		return i;
	}
	return -1;
}


//To union two disjoint sets
struct Node *unionSet(struct Node*head[],int x,int y,int n)
{
	int index1=findIndex(head,x,n);
	int index2=findIndex(head,y,n);
	struct Node *temp1=findRep(head[index1]);
	struct Node *temp2=findRep(head[index2]);
	if(temp1!=temp2)
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
		temp1->parent=temp2;
	return temp1;
	}
	else
	return NULL;
}


//To create the graph
struct Graph * createGraph(int e,int v)
{
	struct Graph* temp=NULL;
	temp=(struct Graph *)malloc(sizeof(struct Graph));
	temp->e=e;
	temp->v=v;
	temp->edge=(struct Edge *)malloc(sizeof(struct Edge)*e);

	return temp;
}


void display(struct Node *head[],int n)
{	
	int i=0;
	for(i;i<n;i++)
	{
		struct Node *temp=NULL;
		temp=head[i];
		if(temp->parent==temp)
		{
			printf("{ ");
			int j=0;
			for(j;j<n;j++)
			{
				struct Node *t=NULL;
				t=head[j];

				if(temp==findRep(t))
					printf("%d ",t->data);
			}
			printf("}\n");
		}
		else
		{
			printf("{ }\n ");
		}
	}
}

//To sort edge by their weights
struct Edge* sort(struct Edge*edge,int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i;j<n;j++)
		{
			if(edge[i].w>edge[j].w)
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


//Kruskal MST
void kruskal(struct Graph *graph)
{
	int v=graph->v;
	int i;
	//To make disjoint set 
	struct Node *head[v];
	for(i=0;i<v;i++)
	{
		head[i]=makeSet(i);
	}
	display(head,v);

	struct Edge result[v];
	//To sort by edge weight
	graph->edge=sort(graph->edge,graph->e);

	int e=0;

	i=0;
	int c=0;
	//Tr create result_edge
	while(i<v-1)
	{
		int v1=graph->edge[c].v1;
		int v2=graph->edge[c].v2;
		int w=graph->edge[c].w;

		struct Node *temp1=NULL;
		struct Node *temp2=NULL;
		temp1=findRep(head[v1]);
		temp2=findRep(head[v2]);

		struct Node *temp=unionSet(head,v1,v2,v);
	//	display(head,v);
		//Cycle is not their
		if(temp!=NULL)
		{
			result[i]=graph->edge[c];
			i++;
		}	

	c++;
	
	}
	
	for(i=0;i<v-1;i++)
	{
		printf("edge %d %d  weight %d\n",result[i].v1,result[i].v2,result[i].w);
	}
	return ;
}


int main()
{
	int e;
	int v;
	scanf("%d %d",&v,&e);
	int n,i;
	struct Graph *graph=NULL;
	graph=createGraph(e,v);
	printf("graph created\n");
	for(i=0;i<e;i++)
	{
		int v1;
		int v2;
		int w;
		scanf("%d",&v1);
		scanf("%d",&v2);
		scanf("%d",&w);
		graph->edge[i].v1=v1;
		graph->edge[i].v2=v2;
		graph->edge[i].w=w;
	}
	
	kruskal(graph);



return 0;
}


