#include "list.h"
#include "arraylist.h"
#include <stdlib.h>
#include <string.h>

static int length(List *self);
static void delete(List *self);
static void add(List *self,void  *elem);
static void *get(List *self,int index);
List * new_array_list();

typedef struct {
  void **arr;
  int capacity;
  int size;
}ArrayList;


List * new_array_list(){
  List *list = (List *)malloc(sizeof(List));
  ArrayList *arrayList = malloc(sizeof(ArrayList));
  arrayList->arr = malloc(10*sizeof(void *));
  arrayList->capacity = 10;
  arrayList->size = 0;
  list->length = length;
  list->delete = delete;
  list->add = add;
  list->get = get;
  list->data =  arrayList;
  return list;
}

static int length(List *self){
  ArrayList *arrayList = self->data;
  return arrayList->size;
}


static void add(List *self,void  *elem){
  ArrayList *arrayList = self-> data;
  int size = arrayList->size;
  int capacity = arrayList->capacity;

  if(size == capacity){
    void **newArr = malloc((10+capacity)*sizeof(void *));

    memcpy(newArr,arrayList->arr,size*sizeof(void *));
    free(arrayList->arr);
    arrayList->arr = newArr;
    arrayList->capacity += 10;
  }
  arrayList->arr[size] = elem;
  arrayList->size++;
}

static void *get(List *self,int index){
  ArrayList *arrayList = self->data;
  if(index < arrayList->size){
    return arrayList->arr[index];
  }else{
    return NULL;
  }
}


static void delete(List *self){
  ArrayList *arrayList = self->data;
  free(arrayList->arr);
  free(arrayList);
  free(self);
}
