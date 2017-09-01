#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "WeightedUnDiGraph.h"
#include "BinaryHeap.h"
#include "DisjointSet.h"
#define max_size 100

void fillHeap(BinaryHeap *minHeap, WeightedUnDiGraph *G) {
    for ( int u = 0; u < G->nbVertices; u++ ) {
        for (int v = 0; v < G->incidentsLength[u];v++ ) {
            int a = (G->adjacencyList[u])->vertice;
            if ( u < a ){
                WeightedEdge * e = malloc(sizeof(WeightedEdge));
                e->edge.origin = u;
                e->edge.destination = a;
                e->weight = edgeWeight(u, a,G);
                addinHeap(e,minHeap);
            }
            G->adjacencyList[u] = G->adjacencyList[u] -> next;
        }
    }
}




WeightedEdge * fcm(WeightedUnDiGraph* G, int verticesSourceList[],int verticesSourceListSize) {

    int fcm_size = 0;

    WeightedEdge * fcmi = malloc(sizeof(WeightedEdge));// les arêtes du MST

    // le tas minimum
    BinaryHeap *minHeap = initializeHeap();
    //  On remplis le tas minimum avec les arêtes du graphe G
    fillHeap(minHeap,G);
    //disjoint sets de tous les sommets du graphe G
    DisjointSet *ds = initDisjointSet(G->nbVertices);
    // tant que tous les noeuds ne sont pas connectés
    while ( ds->numSets > verticesSourceListSize ) {
        WeightedEdge *min = deleteExtreme(minHeap);
        int u = (min->edge).origin;
        int v = (min->edge).destination;
        int ru = find(u,ds);
        int rv = find(v,ds);
        int originAlreadyLinked = 0;
        int destAlreadyLinked = 0;
        for(int i = 0; i < verticesSourceListSize; i++){
            if(rv == find(verticesSourceList[i],ds)){
                destAlreadyLinked = 1;
            }
            if(ru == find(verticesSourceList[i],ds)){
                originAlreadyLinked = 1;
            }
        }
        if ( ru != rv && !(destAlreadyLinked == 1 && originAlreadyLinked == 1) ) {
            *(fcmi + fcm_size) = *min;
            printf("%d %d\n",min -> edge.origin,min->edge.destination );
            printf("%s\n","_______" );
            fcm_size += sizeof(WeightedEdge);
            unioon(ru, rv,ds);
        }
    }

    return fcmi;
}

int main() {
    WeightedUnDiGraph G = initializeGraph();
    addEdge(0,2,2,&G);
    addEdge(0,4,8,&G);
    addEdge(2,4,5,&G);
    addEdge(0,6,5,&G);
    addEdge(0,3,3,&G);
    addEdge(4,6,6,&G);
    addEdge(4,1,2,&G);
    addEdge(6,3,6,&G);
    addEdge(6,1,7,&G);
    addEdge(3,1,4,&G);
    addEdge(3,5,7,&G);
    addEdge(1,5,3,&G);
    int sources[2];
    sources[0] = 2;
    sources[1] = 5;
    WeightedEdge*  result = fcm(&G,sources,2);
    int i = 0;
    while((((*(result+i)).edge.origin) > 0) || ((*(result+i)).edge.destination > 0)){
        printf("%d\t",((*(result+i)).edge.origin));
        printf("%d\n",((*(result+i)).edge.destination));
        i+= sizeof(WeightedEdge);
    }
    return 0;
}
