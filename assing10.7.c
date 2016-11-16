#include<stdio.h>
#include<malloc.h>
struct Node
{
int data;
struct Node * rep;
struct Node * next;

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
	temp->next=NULL;
	temp->rep=temp;

	return temp;
} 

int findIndex(struct Node *head[],int x,int n)
{
int i;
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
for(i=0;i<n;i++)
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

int size(struct Node *root)
{
int i=0;
while(root)
{
i++;
root=root->next;
}
return i;
}

struct Node *unionSet(struct Node *head[],int x,int y,int n)
{
int index1=0;
index1=findIndex(head,x,n);
int index2=0;
index2=findIndex(head,y,n);
struct Node *temp1=NULL;
struct Node *temp2=NULL;
temp1=findRep(head,x,n);
temp2=findRep(head,y,n);
struct Node *t1=NULL;
t1=temp1;
struct Node *t2=NULL;
t2=temp2;
if(temp1!=temp2)
{
if(size(temp1)>=size(temp2))
{
while(t1->next)
t1=t1->next;
t1->next=t2;
while(t2)
{t2->rep=temp1;
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
{t1->rep=temp2;
t1=t1->next;
}
head[index1]=NULL;
}

}
else
return ;
}

void removeNode(struct Node *head[],int x,int n)
{
	int index=findIndex(head,x,n);
	printf("index of %d is %d\n ",x,index);
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

int setSize(struct Node *head[],int n)
{
int i=0;
int count=0;
for(i=0;i<n;i++)
{
struct Node *temp=NULL;
temp=head[i];
while(temp)
{
count++;
temp=temp->next;
}
}
return count;
}


void move(struct Node *src[],struct Node *des[],int x,int n)
{
removeNode(src,x,n);
printf("removed %d\n",x);
int i=0;
while(des[i]!=NULL)
{
i++;
}
des[i]=makeSet(x);
unionSet(des,des[0]->data,x,n);
}

int contains(struct Node *head[],int x,int n)
{
int i;
for(i=0;i<n;i++)
{
struct Node *temp=NULL;
temp=head[i];
while(temp)
{
if(temp->data==x)
return 1;
temp=temp->next;
}

}
return 0;
}


int dfs(int temp,struct Node *white[],struct Node *gray[],struct Node *black[],struct Graph *graph )
{
//printf("set size of gray : %d\n",setSize(gray,graph->v));
if(setSize(gray,graph->v)==graph->v-1)
{
//printf("gray full\n");
return 1;

}
//printf("gray not full\n");
move(white,gray,temp,graph->v);
//printf("moved %d\n",temp);
struct Edge *adjacent=NULL;
adjacent=(struct Edge *)malloc(sizeof(struct Edge)*(graph->v-1));
struct Edge *edge=NULL;
edge=graph->edge;
int i=0;
int c=0;
while(i<graph->e)
{
if(edge[i].v1==temp)
adjacent[c]=edge[i],c++;
i++;
}
for(i=0;i<c;i++)
printf("adjacent are : %d\n",adjacent[i].v2);
for(i=0;i<c;i++)
{
int temp1=NULL;
temp1=adjacent[i].v2;
if(contains(black,temp1,graph->v))
{//printf("%d is inside black\n ",temp);continue;
}	
if(dfs(temp1,white,gray,black,graph))
return 1;
}
move(gray,black,temp,graph->v);
//printf("%d is moved to black\n",temp);
return 0;
}


int isAbsorbescence(struct Graph *graph)
{
int v=graph->v;
int i;
int k;
//for(k=0;k<v;k++)
{
struct Node *black[graph->v];
struct Node *white[graph->v];
struct Node *gray[graph->v];

for(i=0;i<graph->v;i++)
{
white[i]=makeSet(i);
black[i]=NULL;
gray[i]=NULL;
}
struct Node *temp=NULL;
while(setSize(white,graph->v)>0)
{
int i=0;

while(white[i]==NULL)
i++;
temp=white[i];
//printf("%d vertex added\n",temp->data);
if(dfs(temp->data,white,gray,black,graph))
{
return 1;
break;
}
white[i]=NULL;
}

}
return 0;
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


int main()
{
int e,v;
scanf("%d %d",&v,&e);

int i;
struct Graph *graph=NULL;
graph=createGraph(v,e);
for(i=0;i<e;i++)
{
int c;
int d;
scanf("%d %d",&c,&d);
graph->edge[i].v1=c;
graph->edge[i].v2=d;
}
printf("edges added\n");

if(isAbsorbescence(graph))
printf("yes\n");
else
printf("no\n");

return 0;
}
