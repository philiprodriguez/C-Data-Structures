#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct LLNode {
  int value;
  struct LLNode * next;
} LLNode;

typedef struct LinkedList {
  LLNode * head;
  LLNode * tail;
  int size;
} LinkedList;

LinkedList * initLinkedList();
LLNode * initLLNode(int value);
LLNode * getNode(LinkedList * ll, int index);
LLNode * getTail(LinkedList * ll);
void addNode(LinkedList * ll, LLNode * newNode);
void addFront(LinkedList *ll, LLNode * newNode);
int removeNode(LinkedList * ll, int index);
void printList(LinkedList * ll);

#endif
