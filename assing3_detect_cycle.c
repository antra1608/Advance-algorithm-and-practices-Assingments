#include<stdio.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node * next;
	struct Node *rep;

};
struct Edge
{
	int v1;
	int v2;
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
	temp->next=NULL;
	temp->rep=temp;

	return temp;
} 

int findIndex(struct Node *head[],int x,int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		struct Node *temp=NULL;
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


struct Node *findRep(struct Node *head[],int x,int n)
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
	int i=0;
	while(temp)
	{
		i++;
		temp=temp->next;
	}
	return i;
}

//To remove Node from set
void removeNode(struct Node *head[],int x,int n)
{
	int index=findIndex(head,x,n);
	printf("index is %d\n",index);
	struct Node *prev=NULL;
	struct Node *temp=head[index];
	//if first element(representative is x)
	if(temp->data==x)
	{
		
		head[index]=temp->next;
		struct Node* node=temp; 
		temp=temp->next;
		//make next element as representative
		while(temp)
		{
			temp->rep=head[index];
			temp=temp->next;
		}
		free(node);
	}
	else
	//if x is in middle of llinkedlist	
	{
		while(temp)
		{
			if(temp->data==x)
			{
				prev->next=temp->next;
				free(temp);
	
			}
			prev=temp;
			temp=temp->next;
		}
	}
}

struct Node *unionSet(struct Node *head[],int x,int y,int n)
{
	int index1=0;
	index1=findIndex(head,x,n);
	int index2=0;
	index2=findIndex(head,y,n);
	struct Node *temp1=findRep(head,x,n);
	struct Node *temp2=findRep(head,y,n);
	struct Node *t1=temp1;
	struct Node *t2=temp2;
	if(temp1==temp2)
		return ;
	if(size(temp1)>=size(temp2))
	{
		while(t1->next)
		t1=t1->next;
		t1->next=t2;
		while(t2)
		{
		t2->rep=temp1;
		t2=t2->next;
		}
		head[index2]=NULL;

	}
	else
	{
		while(t2->next)
		t2=t2->next;
		t2->next=t1;
		while(t1)
		{
			t1->rep=temp2;
			t1=t1->next;
		}
		head[index1]=NULL;
	}
}
//Size of whole disjoint set
int setSize(struct Node * head[],int v)
{
	int i;
	int size=0;
	for(i=0;i<v;i++)
	{
		struct Node *temp=NULL;
		temp=head[i];
		while(temp)
		{
			size++;
			temp=temp->next;
		}

	}

	return size;
}

//Move x from disjoint set src to disjoint set des
void move(struct Node *src[],struct Node *des[],int n1,int n2,int x)
{
	removeNode(src,x,n1);
	int i=0;
	while(des[i]!=NULL)
		i++;
	des[i]=makeSet(x);
	unionSet(des,x,des[0]->data,n2);
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

//whether disjoint set contains temp or not
int contains(struct Node * head[],int temp,int v)
{
	int i=0;
	for(i;i<v;i++)
	{
		struct Node *temp1=NULL;
		temp1=head[i];
		while(temp1)
		{
			if(temp1->data==temp)
			return 1;
			temp1=temp1->next;
		}

	}
	return 0;


}

int dfs(int temp,struct Node *white[],struct Node *black[],struct Node *gray[],int v,struct Graph *graph)
{
	move(white,gray,graph->v,graph->v,temp);
	printf("moved %d to gray\n",temp);
	struct Edge *adjacent=NULL;
	adjacent=(struct Edge *)malloc(sizeof(struct Edge)*(graph->v-1));
	int i=0;
	int c=0;
	//find adjacent edges to temp
	for(i=0;i<graph->e;i++)
	{
		if(graph->edge[i].v1==temp)
		adjacent[c]=graph->edge[i],c++;
	}
	
	//for each adjacent vertices check whether it is in gray set if yes than cycle exits otherwise do dfs traversal for adjacent vertices
	for(i=0;i<c;i++)
	{
		int temp=NULL;
		temp=(adjacent[i].v2);
		if(contains(black,temp,v))
		continue;
		if(contains(gray,temp,v))
		return 1;
		if(dfs(temp,white,black,gray,v,graph))
		return 1;
	}
	//move temp from gray to black disjoint set
	move(gray,black,graph->v,graph->v,temp);
	return 0;
}
//Main function to find cycle
int findCycle(struct Graph * graph)
{
	struct Node *black[graph->v];
	struct Node *white[graph->v];
	struct Node *gray[graph->v];

	int i;
	//add vertices to white set
	for(i=0;i<graph->v;i++)
	{
	white[i]=makeSet(i);
	black[i]=NULL;
	gray[i]=NULL;
	}
	struct Node *temp=NULL;
	//till white set is not empty
	while(setSize(white,graph->v)>0)
	{
		int i=0;
		//find next non empty node
		while(white[i]==NULL)
		i++;
		temp=white[i];
		// do dfs traversal for that
		if(dfs(temp->data,white,black,gray,graph->v,graph))
			return 1;
		white[i]=NULL;
	
	}
	return 0;
}



int main()
{
	int e,v;
	scanf("%d",&v);
	scanf("%d",&e);
	struct Graph*graph=NULL;
	graph=createGraph(v,e);
	int i;
	for(i=0;i<e;i++)
	{
		int c;
		int d;
		scanf("%d",&c);
		scanf("%d",&d);
		graph->edge[i].v1=c;
		graph->edge[i].v2=d;
	}

	if(findCycle(graph))
		printf("Cycle exits\n");
	else
		printf("Cycle not exits\n");

	return 0;
}
