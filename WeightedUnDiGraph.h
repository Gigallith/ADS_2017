#ifndef WEIGHTEDUNDIGRAPH_H
#define WEIGHTEDUNDIGRAPH_H
#define max_size 100
#include "table.h"
#include "WeightedEdge.h"
#include "HashMap.h"

typedef struct weightedUnDiGraph{
  int nbEdges;
  Table adjacencyList[100];
  Table innersList[100];
  WeightedEdge incidents[100][100];
  int incidentsLength[100];
  int innersLength[100];
  int vertices[100];
  int nbVertices;
  Hashmap *hashmap;

} WeightedUnDiGraph;

WeightedUnDiGraph initializeGraph();

WeightedEdge* incidents(WeightedUnDiGraph* w,int source);

void addEdge(int u, int v,double wei, WeightedUnDiGraph * w);

void removeEdge(int u, int v, WeightedUnDiGraph* w);

double edgeWeight(int origin,int dest, WeightedUnDiGraph* w);
#endif
