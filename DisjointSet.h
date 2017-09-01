#ifndef DISJOINTSET_H
#define DISJOINTSET_H
#define max_size 100

typedef struct DisjointSet{
  int faze[max_size];
  int numSets;
} DisjointSet;


DisjointSet * initDisjointSet(int nbVertices);

int numSets(DisjointSet * d);

int find(int i,DisjointSet *d);

void unioon(int root1, int root2, DisjointSet *d);

#endif
