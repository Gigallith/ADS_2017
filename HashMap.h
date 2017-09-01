#ifndef HASHMAP_H
#define HASHMAP_H
#include "WeightedEdge.h"
#define MAX_SIZE (256)

typedef struct element{
	Edge * key;
	double Weight;
} element;

typedef struct Hashmap{
	int table_size;
	int size;
	element* data[MAX_SIZE];
} Hashmap;

Hashmap * initHashmap();
void addInMap(int origin,int dest, double weigh, Hashmap *h);
double weight(int origin, int dest, Hashmap * h);
#endif
