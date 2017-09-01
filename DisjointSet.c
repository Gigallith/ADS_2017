#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DisjointSet.h"
/**
* builds a disjoint set system of size n with
* the n initial single-element sets
* {0}, {1}, {2}, ..., {n-1}
*/
DisjointSet * initDisjointSet(int nbVertices) {
  DisjointSet* d = malloc(sizeof(DisjointSet));
  d->numSets = nbVertices;
  for ( int i = 0; i < max_size; i++ ){
    d->faze[i] = -1;
  }
  return d;
}

/**
* returns the current number of
* subsets in the disjoint set system
*/
int numSets(DisjointSet * d) {
  return d->numSets;
}

/**
* returns the root of the
* up-tree containing i doing
* path compression
*/
int find(int i,DisjointSet *d) {
  int root = i;
  while ( d->faze[root] >= 0 )
  root = d->faze[root];
  while ( i != root ) {
    int j = d->faze[i];
    d->faze[i] = root;
    i = j;
  }
  return root;
}

/**
* performs the union of the two subsets
* of roots root1 and root2
*/
void unioon(int root1, int root2,DisjointSet *d) {
  if ( d->faze[root1] < d->faze[root2] ) {   // root1 is the largest
    d->faze[root1] += d->faze[root2];
    d->faze[root2] = root1;
  }
  else {
    // root2 is the largest
    d->faze[root2] += d->faze[root1];
    d->faze[root1] = root2;
  }
  d->numSets--;
}
