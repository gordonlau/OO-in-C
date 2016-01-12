#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "arraylist.h"
#include "linkedlist.h"

void list_insertion_and_retrieval(List *list);
void list_add_fluent_api(List *list);
void print_list(List *list);

int main(){

  List *arrayList = new_array_list();
  List *linkedList = new_linked_list();
  list_insertion_and_retrieval(arrayList);
  list_insertion_and_retrieval(linkedList);
  list_add_fluent_api(arrayList);
  arrayList->delete(arrayList);
  linkedList->delete(linkedList);
}

void list_insertion_and_retrieval(List *list){
    int j;
    for(j=0;j<=15;j++){
        int *value = malloc(sizeof(int));
        *value = j;
        list->add(list,value);
    }
    printf("%s length:%d \n",list->type,list->length(list));
    print_list(list);
}


void list_add_fluent_api(List *list){
  int one=1,two=2,three=3;
  list->add(list,&one)
  ->add(list,&two)
  ->add(list,&three);
  print_list(list);
}
void print_list(List *list){
  int i;
  for(i=0;i<(list->length(list));i++){
    printf("%s Element %d:%d \n",list->type,i,*(int *)list->get(list,i));
  }
}
