#ifndef LINKEDLIST_INCLUDED
#define LINKEDLIST_INCLUDED
#include "list.h"

typedef struct LinkedList{
  List *asList;
  char *type;
  void *data;
  void (*delete)(struct LinkedList *linkedList);
}LinkedList;

LinkedList * new_linked_list();
#endif
