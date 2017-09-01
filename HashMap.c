#include "HashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
 * Initialize the HashMap wich contains an array of Edges and their corresponding weight.
 */
 Hashmap * initHashmap() {
	Hashmap* m = (Hashmap *) malloc(sizeof(Hashmap));
	element* e = malloc(sizeof(element));
	Edge * ed = malloc(sizeof(Edge));
	ed -> origin = -1;
	ed -> destination = -1;
	e -> key = ed;
	for(int i = 0; i<MAX_SIZE; i++){
			m->data[i] = e;
	}
	m->table_size = MAX_SIZE;
	m->size = 0;
	return m;
}

/**
*Returns the weight of the Edge corresponding to origin and dest, 0 if there
*is no Edge corresponding
**/
double weight(int origin,int dest, Hashmap * h){
	for(int i = 0; i < h->size;i++){
		if((h -> data[i] -> key -> origin == origin) && (h -> data[i] -> key -> destination == dest)){
			return (h -> data[i] -> Weight);
		}
	}
	return 0;
}

/**
*Adding an Edge and it's corresponding weight in the map;
*
**/
void addInMap(int origin,int dest, double weigh, Hashmap *h){
	element * el = malloc(sizeof(element));
	Edge * ed = malloc(sizeof(Edge));
	ed -> origin = origin;
	ed -> destination = dest;
	el -> key = ed;
	el -> Weight = weigh;
	h -> data[h -> size] = el;
	h -> size++;
}
