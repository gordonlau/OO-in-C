#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
#include "linkedlist.h"

void list_insertion_and_retrieval(List *list);

int main(){

  List *list = new_array_list();
  List *list2 = new_linked_list();
  list_insertion_and_retrieval(list);
  list_insertion_and_retrieval(list2);
  list->delete(list);
  list2->delete(list2);
}

void list_insertion_and_retrieval(List *list){
    int i;
    for(i=0;i<=15;i++){
        int *value = malloc(sizeof(int));
        *value = i;
        list->add(list,value);
    }
    printf("List length:%d \n",list->length(list));
    for(i=0;i<=15;i++){
        int *result = (int *)list->get(list,i);
        printf("List %dth Element:%d \n",i,*result);
        free(result);
    }
}
