#include <stdio.h>
#include <stdio.h>
#include <limits.h>

//defining edge structure
typedef struct edge{
	int src, dest, wt;
}edge_m;

//reverse_del function
void reverse_del(){
	int v, e, i, j, x, s, d, m, n;
	scanf("%d", &v);
	int mat[v][v];
	e = v * v;
	
	edge_m list[e]; //creating array of edge struct named list
	
	//2D array input for adjacency matrix
	for(i=0; i<v; i++){
		for(j=0; j<v; j++){
			scanf("%d", &mat[i][j]);	
		}
	}

	//putting all the edges of graph in list
	x = 0;
	for(i=0; i<v; i++){
		for(j=0; j<v; j++){
			if(mat[i][j] != 0 && mat[i][j] != INT_MAX){
				list[x].src = i;
				list[x].dest = j;
				list[x++].wt = mat[i][j];
				mat[list[x-1].dest][list[x-1].src] = INT_MAX;
			}
		}
	}
	
	e = x; //actual number of edges
	
	//arranging the edges in decreasing order(non increasing)
	edge_m temp;
	for(i=0; i<(e-1); i++){
		for(j=0; j< (e-i-1); j++){
			if(list[j].wt < list[j+1].wt){
				temp.src = list[j].src;
				temp.dest = list[j].dest;
				temp.wt = list[j].wt;
				list[j].src = list[j+1].src;
				list[j].dest = list[j+1].dest;
				list[j].wt = list[j+1].wt;
				list[j+1].src = temp.src;
				list[j+1].dest = temp.dest;
				list[j+1].wt = temp.wt;
			}	
		}
	}
	
	//reverse delete logic
	for(i=0; i<e; i++){
		s = list[i].src;
		d = list[i].dest;
		
		int flag_s = 0;
		int flag_d = 0;
	
		for(n=s; n<v; n++){
			if(mat[s][n] != 0 && mat[s][n] != list[i].wt && mat[s][n] != INT_MAX){
				flag_s = 1;
				break;
			}
		}
		for(m=d; m<v; m++){
			if(mat[d][m] != 0 && mat[d][m] != list[i].wt && mat[d][m] != INT_MAX){
				flag_d = 1;
				break;
			}
		}	
		
		if(flag_s == 1 && flag_d == 1){
			list[i].wt = INT_MAX; //deleting the edge from the list
			mat[s][d] = INT_MAX;  //deleting the edge from matrix
		}			
	}
	
	//printing the mst from list
	printf("Edge\tWeight\n");
	for(i=0; i<e; i++){
		if(list[i].wt != INT_MAX){
			printf("%d-%d\t%d\n", list[i].src, list[i].dest, list[i].wt);
		}
	}
}

//main function
int main(){
	reverse_del();
	return 0;
}

