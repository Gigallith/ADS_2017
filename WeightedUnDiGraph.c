#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WeightedUnDiGraph.h"

WeightedUnDiGraph initializeGraph(){
  WeightedUnDiGraph graph;
  graph.nbEdges = 0;
  Table  t = malloc(sizeof(t_table));
  (t) = creer_table();
  WeightedEdge we;
  for(int i = 0; i<100;i++){
    graph.adjacencyList[i] = t;
    graph.innersList[i] = t;
    graph.incidentsLength[i] = 0;
    graph.innersLength[i] = 0;
    graph.vertices[i] = 0;
    for(int j = 0; j<100;j++){
      graph.incidents[i][j] = we;
    }
  }
  graph.hashmap = initHashmap();
  return graph;
}

WeightedEdge* incidents(WeightedUnDiGraph* w,int source){
  return ((*w).incidents)[source];
}

void addEdge(int u, int v,double wei, WeightedUnDiGraph * w) {
    ajouter_table((&(*w).adjacencyList[u]),v);
    ajouter_table((&(*w).adjacencyList[v]),u);
		ajouter_table((&(*w).innersList[v]),u);
    ajouter_table((&(*w).innersList[u]),v);
    if((*w).vertices[u] == 0){
      (*w).nbVertices++;
    }
    if((*w).vertices[v] == 0){
      (*w).nbVertices++;
    }
    (*w).vertices[u]++;
    (*w).vertices[v]++;
    WeightedEdge we;
    (we.edge).origin = u;
    (we.edge).destination = v;
    we.weight = wei;
    ((*w).incidents)[u][(*w).incidentsLength[u]] = we;
    ((*w).incidents)[v][(*w).incidentsLength[v]] = we;
    (*w).incidentsLength[u]++;
    (*w).incidentsLength[v]++;
    (*w).innersLength[u]++;
    (*w).innersLength[v]++;
    (*w).nbEdges++;
    addInMap(u,v,wei,(*w).hashmap);
    addInMap(v,u,wei,(*w).hashmap);
}

/*void removeEdge(int u, int v, WeightedUnDiGraph* w) {
  if (supprimer_table((*w).adjacencyList[u],v) != 0) {
    supprimer_table((*w).adjacencyList[v],u);
		(*w).nbEdges--;
    supprimer_table((*w).innersList[u],v);
    supprimer_table((*w).innersList[v],u);
    (*w).incidentsLength[u]--;
    if((*w).vertices[v] == 1){
      (*w).nbVertices--;
    }
    if((*w).vertices[u] == 1){
      (*w).nbVertices--;
    }
    (*w).vertices[u]--;
    (*w).vertices[v]--;
	}
}
*/
double edgeWeight(int origin,int dest, WeightedUnDiGraph* w){
    return(weight(origin,dest,w->hashmap));
}
