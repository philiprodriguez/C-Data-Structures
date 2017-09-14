#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

//Return a pointer to a new linked list
LinkedList * initLinkedList()
{
  LinkedList * newLinkedList = (LinkedList*) malloc(sizeof(LinkedList));
  (*newLinkedList).head = NULL;
  (*newLinkedList).tail = NULL;
  (*newLinkedList).size = 0;
  return newLinkedList;
}

LLNode * initLLNode(int value)
{
  LLNode * newNode = (LLNode*) malloc(sizeof(LLNode));
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

//Get node at index... O(index)
LLNode * getNode(LinkedList * ll, int index)
{
  if (ll == NULL)
    return NULL;
  if ((*ll).head == NULL || (*ll).tail == NULL)
    return NULL;

  LLNode * current = (*ll).head;
  while(current != NULL)
  {
    if (index == 0)
      break;

    index--;
    current = (*current).next;
  }
  return current;
}

//Method for adding to the back... O(1)
void addNode(LinkedList * ll, LLNode * newNode)
{
    if (ll == NULL)
      return;

    //Ensure newNode's next is null!
    newNode->next = NULL;

    if ((*ll).tail == NULL)
    {
      //If our list is empty...
      (*ll).head = (*ll).tail = newNode;
      (*ll).size = 1;
    }
    else
    {
      //Not empty!
      (*(*ll).tail).next = newNode;
      (*ll).tail = (*(*ll).tail).next;
      (*ll).size++;
    }
}

//Add to the front of the list... O(1)
void addFront(LinkedList *ll, LLNode * newNode)
{
  if (ll == NULL)
    return;

  if (ll->tail == NULL)
  {
    //Empty list!
    (*ll).head = (*ll).tail = newNode;
    (*ll).size = 1;
  }
  else
  {
    newNode->next = ll->head;
    ll->head = newNode;
    ll->size++;
  }
}

//Returns 1 if it could remove and free iteam at index... O(index)
int removeNode(LinkedList * ll, int index)
{
  if (ll == NULL)
    return 0;
  if (ll->head == NULL)
    return 0;

  LLNode * prev = NULL;
  LLNode * cur = ll->head;
  while(index > 0)
  {
    prev = cur;
    cur = cur->next;
    index--;
    if (cur == NULL)
      return 0;
  }

  if (prev == NULL)
  {
    ll->head = cur->next;
    if (cur == ll->tail)
    {
      ll->tail = NULL;
    }
    free(cur);
    ll->size--;
    return 1;
  }
  else
  {
    prev->next = cur->next;
    free(cur);
    ll->size--;
    return 1;
  }
}

//Get tail node... O(1)
LLNode * getTail(LinkedList * ll)
{
  if (ll == NULL)
    return NULL;
  return ll->tail;
}

//O(ll->size)
void printList(LinkedList * ll)
{
  if (ll == NULL)
  {
    printf("NULL LINKED LIST\n");
  }
  else
  {
    printf("List Size = %d\n", ll->size);
    LLNode * cur = ll->head;
    while(cur != NULL)
    {
      printf("[%d]-->", cur->value);
      cur = cur->next;
    }
    printf("NULL\n");
  }
}
