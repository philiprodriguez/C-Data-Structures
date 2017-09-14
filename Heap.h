#ifndef HEAP
#define HEAP

typedef struct Heap {
  int size;
  int maxSize;
  int * items;
} Heap;

Heap * initHeap(int maxSize);
int peekHeap(Heap * heap);
int popHeap(Heap * heap);
int addHeap(Heap * heap, int item);
void percolateUp(Heap * heap, int index);
void percolateDown(Heap * heap, int index);

#endif
