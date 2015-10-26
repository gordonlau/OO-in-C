#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
#include "linkedlist.h"

void list_insertion_and_retrieval(List *list);
void print_random_access_type(RandomAccess *randomAccess);

int main(){

  ArrayList *arrayList = new_array_list();
  LinkedList *linkedList = new_linked_list();
  list_insertion_and_retrieval(arrayList->asList);
  list_insertion_and_retrieval(linkedList->asList);
  print_random_access_type(arrayList->asRandomAccess);
  arrayList->delete(arrayList);
  linkedList->delete(linkedList);
}

void list_insertion_and_retrieval(List *list){
    int i;
    for(i=0;i<=15;i++){
        int *value = malloc(sizeof(int));
        *value = i;
        list->add(list,value);
    }
    printf("%s length:%d \n",list->type,list->length(list));
    for(i=0;i<=15;i++){
        int *result = (int *)list->get(list,i);
        printf("%s %dth Element:%d \n",list->type,i,*result);
        free(result);
    }
}

void print_random_access_type(RandomAccess *randomAccess){
  printf("%s is a subtype of RandomAccess\n",randomAccess->type);
}
