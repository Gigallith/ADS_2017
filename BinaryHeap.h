#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include "WeightedEdge.h"
typedef struct BinaryHeap {
  int size;
  int max_length;
  WeightedEdge* A[100];
} BinaryHeap;

BinaryHeap* initializeHeap();
///////////// Private methods

/**
* Swap values in the array
* at indexes i and j.
* Complexity: THETA(1)
*/
void swap(int i, int j,BinaryHeap *heap);
void imprimerHeap(BinaryHeap *heap);
/**
* Return the number of the left
* node of node number n.
* Complexity: THETA(1)
*/
int left(int n);

/**
* Return the number of the right
* node of node number n.
* Complexity: THETA(1)
*/
int right(int n);

/**
* Return the number of the parent
* node of node number n.
* Complexity: THETA(1)
*/
int parent(int n);

/**
* Percolate down the element à node number n
* Complexity: O(log(size))
*/
void percolateDown(int n,BinaryHeap *heap);

/**
* Percolate up the element à node number n
* Complexity: O(log(size))
*/
void percolateUp(int n,BinaryHeap *heap);

/**
* Arrange the elements in A such
* that it has the heap property.
* Complexity: O(size)
*/
void buildHeap(BinaryHeap *heap);

///////////// Public methods

/**
* Return the size of the heap
* (the number of elements in the heap).
* Complexity: THETA(1)
*/
int size(BinaryHeap *heap);

/**
* Return the extreme element.
* Complexity: THETA(1)
*/
WeightedEdge extreme(BinaryHeap *heap);

/**
* Return and delete the extreme element.
* Complexity: O(log(size))
*/
WeightedEdge* deleteExtreme(BinaryHeap *heap);

/**
* Add a new element in the heap
* Complexity: O(log(size))
*/
void addinHeap(WeightedEdge* e,BinaryHeap *heap);

///////////// Part 3: deleting in the heap

/**
* Delete the element e from the heap.
* Complexity: O(size)
*/
void delete(WeightedEdge* e,BinaryHeap *heap);

/**
* Delete all the elements e from the heap.
* Complexity: O(size)
*/
void deleteAll(WeightedEdge* e,BinaryHeap *heap);
#endif
