#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "LinkedList.h"
#include "Heap.h"

void testLinkedList()
{
  printf("Running...\n");
  LinkedList * list = initLinkedList();

  printList(list);

  addNode(list, initLLNode(16));
  addNode(list, initLLNode(1));
  addNode(list, initLLNode(12));
  addNode(list, initLLNode(65));
  addNode(list, initLLNode(13));

  printList(list);

  removeNode(list, 4);

  printList(list);

  removeNode(list, 0);
  removeNode(list, 0);
  removeNode(list, 0);
  removeNode(list, 0);
  removeNode(list, 0);
  removeNode(list, 0);

  printList(list);
}

void testHeap()
{
  Heap * heap = initHeap(512);

  addHeap(heap, 15);
  addHeap(heap, 325);
  addHeap(heap, 12);
  addHeap(heap, 532);
  addHeap(heap, 21);
  addHeap(heap, 19);
  addHeap(heap, 1129);
  addHeap(heap, 190);
  addHeap(heap, 10);
  addHeap(heap, 102);
  addHeap(heap, 375);
  addHeap(heap, 123);
  addHeap(heap, 198);
  addHeap(heap, 153);
  addHeap(heap, 422);
  addHeap(heap, 190);

  while(heap->size > 0)
  {
    printf("Popped %d\n", popHeap(heap));
  }

  printf("Ok!\n");

  int values[512];
  for(int i = 0; i < 512; i++)
  {
    values[i] = i+1;
  }
  srand(time(NULL));
  for(int i = 0; i < 512; i++)
  {
    //Swap item i with item r
    int r = rand() % 512;
    int temp = values[i];
    values[i] = values[r];
    values[r] = temp;
  }
  for(int i = 0; i < 512; i++)
  {
    printf("Inserting %d\n", values[i]);
    addHeap(heap, values[i]);
  }

  while(heap->size > 0)
  {
    printf("Popped %d\n", popHeap(heap));
  }
}

int main()
{
  testHeap();
  return 0;
}
