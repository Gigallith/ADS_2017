#include <stdlib.h>
#include <stdio.h>
#include "BinaryHeap.h"

/**
*Initializing the BinaryHeap
*
**/
BinaryHeap* initializeHeap() {
  BinaryHeap *heap = malloc(sizeof(BinaryHeap));
  heap->size = 0;
  heap->max_length = 100;
  WeightedEdge *edge;
  for(int i = 0; i<heap->max_length;i++){
    heap->A[i] = edge;
  }
  return heap;
}
///////////// Private methods

/**
* Swap values in the array
* at indexes i and j.
* Complexity: THETA(1)
*/
void swap(int i, int j,BinaryHeap* heap) {
  WeightedEdge* tmp = heap->A[i];
  heap->A[i] = heap->A[j];
  heap->A[j] = tmp;
}

/**
* Return the number of the left
* node of node number n.
* Complexity: THETA(1)
*/
int left(int n) {
  return 2*n + 1;
}

/**
* Return the number of the right
* node of node number n.
* Complexity: THETA(1)
*/
int right(int n) {
  return 2*(n + 1);
}

/**
* Return the number of the parent
* node of node number n.
* Complexity: THETA(1)
*/
int parent(int n) {
  return (n - 1)/2;
}

/**
* Percolate down the element à node number n
* Complexity: O(log(size))
*/
void percolateDown(int n,BinaryHeap* heap) {
  int g = left(n); int d = right(n); int k = n;
  if ( g < heap->size && heap->A[g]->weight < heap->A[n]->weight)
  k = g;
  if ( d < heap->size && heap->A[d]->weight < heap->A[k]->weight)
  k = d;
  if ( k != n ) {
    swap(k,n,heap);
    percolateDown(k,heap);
  }
}

/**
* Percolate up the element à node number n
* Complexity: O(log(size))
*/
void percolateUp(int n,BinaryHeap *heap) {
  WeightedEdge * e = heap->A[n];
  while ( n > 0 && (*e).weight < heap->A[parent(n)] -> weight) {
    heap->A[n] = heap->A[parent(n)];
    n = parent(n);
  }
  heap->A[n] = e;
}

/**
* Arrange the elements in A such
* that it has the heap property.
* Complexity: O(size)
*/
void buildHeap(BinaryHeap *heap) {
  for ( int i = parent(heap->size - 1); i >= 0; i-- ){
    percolateDown(i,heap);
  }

}

///////////// Public methods

/**
* Return the size of the heap
* (the number of elements in the heap).
* Complexity: THETA(1)
*/
int size(BinaryHeap *heap) {
  return heap->size;
}

/**
* Return the extreme element.
* Complexity: THETA(1)
*/
WeightedEdge extreme(BinaryHeap *heap) {
  if ( size != 0 )
    return *(heap->A[0]);
}

/**
* Return and delete the extreme element.
* Complexity: O(log(size))
*/
WeightedEdge* deleteExtreme(BinaryHeap *heap) {
  if ( heap->size != 0 ){
    WeightedEdge *extreme = heap->A[0];
    heap->A[0] = heap->A[--heap->size];
    if ( heap->size > 0 ){
      percolateDown(0,heap);
    }
    return extreme;
  }
}

void imprimerHeap(BinaryHeap *heap){
  for(int i = 0 ; i<(*heap).size;i++){
    printf("%d\t %d %f\n",heap -> A[i] -> edge.origin,heap -> A[i] -> edge.destination,heap -> A[i] -> weight );
  }
}

/**
* Add a new element in the heap
* Complexity: O(log(size))
*/
void addinHeap(WeightedEdge* e,BinaryHeap *heap) {
  if (heap->size != heap->max_length){
    heap->A[heap->size++] = e;
    percolateUp(heap->size-1,heap);
  }
}

///////////// Part 3: deleting in the heap

/**
* Delete the element e from the heap.
* Complexity: O(size)
*/
void delete(WeightedEdge* e,BinaryHeap *heap) {
  for ( int i = 0; i < heap->size; i++ ){
    if ( heap->A[i]->edge.origin == (*e).edge.origin &&  heap->A[i]->edge.destination == (*e).edge.destination) {
      heap->A[i] = heap->A[--heap->size];
      percolateUp(i,heap);
      percolateDown(i,heap);
    }
  }
}

/**
* Delete all the elements e from the heap.
* Complexity: O(size)
*/
void deleteAll(WeightedEdge* e,BinaryHeap *heap) {
  int i = 0;
  while ( i < heap->size ){
    if ( heap->A[i]->edge.origin == (*e).edge.origin &&  heap->A[i]->edge.destination == (*e).edge.destination) {
      swap(i,--heap->size,heap);
    }
  }
  buildHeap(heap);
}
