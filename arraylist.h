#ifndef ARRAYLIST_INCLUDED
#define ARRAYLIST_INCLUDED
#include "list.h"
#include "randomAccess.h"

typedef struct ArrayList{
  List *asList;
  RandomAccess *asRandomAccess;
  char *type;
  void *data;
  void (*delete)(struct ArrayList *arrayList);
}ArrayList;

ArrayList * new_array_list();
#endif
