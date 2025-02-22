#include<stdio.h>
#include<stdlib.h>

typedef struct graph{ // This is the structure of the graph !!
    int v;
    int e;
    int **Adj;
}*graph;

graph adjMatrixOfGraph(){
    int i , j , u;
    graph g = (graph) malloc (sizeof(struct graph));
    if(g == NULL){
        printf("Memory allocation failed !");
        return NULL;
    }
    printf("Enter no of nodes and edges\n ");
    scanf("%d %d",&g -> v,&g -> e);

    g->Adj = (int **)malloc(g->v * sizeof(int **));
    for (i = 0; i < g->v; i++) {
        g->Adj[i] = (int *)malloc(g->v * sizeof(int *));
    }


    for(i = 0; i < g -> v; i++){ // Initializing wth 0 at first
        for(j = 0; j < g -> v; j++){
            g -> Adj[i][j] = 0;
        }
    }

    printf("Enter node pairs for edges:\n");
    for (u = 0; u < g->e; u++) {
        scanf("%d %d", &i, &j);
        g->Adj[i][j] = 1;
        g->Adj[j][i] = 1;  // For undirected graph
    }

    return g;
}
void printGraph(graph g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->v; i++) {
        for (int j = 0; j < g->v; j++) {
            printf("%d ", g->Adj[i][j]);
        }
        printf("\n");
    }
}

// Free allocated memory
void freeGraph(graph g) {
    for (int i = 0; i < g->v; i++) {
        free(g->Adj[i]);
    }
    free(g->Adj);
    free(g);
}


int main(void){
    graph g = adjMatrixOfGraph();
    if (g != NULL) {
        printGraph(g);
        freeGraph(g);
    }
    return 0;
}