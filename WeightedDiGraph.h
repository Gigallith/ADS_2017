#ifndef WEIGHTEDDIGRAPH_H
#define WEIGHTEDDIGRAPH_H
#include "table.h"
#include "WeightedEdge.h"
#include "HashMap.h"


typedef struct WeightedDiGraph{
  int nbEdges;
  Table adjacencyList[100];
  Table innersList[100];
  WeightedEdge incidents[100][100];
  int incidentsLength[100];
  int innersLength[100];
  int vertices[100];
  int nbVertices;
  Hashmap *hashmap;
} WeightedDiGraph;

WeightedDiGraph initializeGraph();

WeightedEdge* incidents(WeightedDiGraph* w,int source);

void addEdge(int u, int v,double wei, WeightedDiGraph * w);

void removeEdge(int u, int v, WeightedDiGraph* w);

double edgeWeight(int origin,int dest, WeightedDiGraph* w);
#endif
