#include<stdlib.h>
#include<stdio.h>
#include "Heap.h"

Heap * initHeap(int maxSize)
{
  Heap * newHeap = (Heap*)malloc(sizeof(Heap));
  newHeap->size = 0;

  //maxSize needs to be a power of two, so let's make sure it is!
  int curSize = 1;
  while(curSize < maxSize)
    curSize *= 2;
  newHeap->maxSize = curSize;

  newHeap->items = (int*)malloc(sizeof(int)*maxSize);
  return newHeap;
}


//Return the minimum item in heap.
int peekHeap(Heap * heap)
{
  //Maybe we could check here to make sure there is
  //at least one item in the heap, but let's not for now
  //because then we need some kind of sentinel value...
  return heap->items[0];
}

//Return the minimum item in the heap and remove it from the heap
int popHeap(Heap * heap)
{
  //Memorize the minimum
  int minimum = peekHeap(heap);

  //Remove the minimum...  aka replace it with last item
  heap->items[0] = heap->items[heap->size-1];
  heap->size--;

  //Move it as needed
  percolateDown(heap, 0);

  return minimum;
}

//Insert item into the heap in O(log(n)) time. Return 0 or 1 if we fail or
//succeed, respectively.
int addHeap(Heap * heap, int item)
{
  if (heap->size >= heap->maxSize)
  {
    //We have no space!
    return 0;
  }

  //Insert it at the bottom...
  heap->items[heap->size] = item;
  heap->size++;

  //Move it around as needed!
  percolateUp(heap, heap->size-1);
  return 1;
}

//Move the item in index up as appropriate. Should finish in O(log(n)) time.
void percolateUp(Heap * heap, int index)
{
  //Look to see if I am smaller than my parent. If I am, then switch places!
  int parentIndex = (index-1)/2;
  if (heap->items[index] < heap->items[parentIndex])
  {
    int temp = heap->items[index];
    heap->items[index] = heap->items[parentIndex];
    heap->items[parentIndex] = temp;
    percolateUp(heap, parentIndex);
  }
}

//O(log(n))
void percolateDown(Heap * heap, int index)
{
  //If one of my children is smaller than me, swap the smallest and myself
  int child1Index = index+index+1;
  int child2Index = index+index+2;
  int child1;
  int child2;
  if (child1Index < heap->size)
    child1 = heap->items[child1Index];
  else
    child1 = 2147483647;
  if (child2Index < heap->size)
    child2 = heap->items[child2Index];
  else
    child2 = 2147483647;

  if (child1 < heap->items[index] || child2 < heap->items[index])
  {
    if (child1 < child2)
    {
      //Child 1 smaller!
      int temp = heap->items[child1Index];
      heap->items[child1Index] = heap->items[index];
      heap->items[index]=temp;
      percolateDown(heap, child1Index);
    }
    else
    {
      //Child 2 smaller or equal!
      int temp = heap->items[child2Index];
      heap->items[child2Index] = heap->items[index];
      heap->items[index]=temp;
      percolateDown(heap, child2Index);
    }
  }
}
