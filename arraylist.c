#include "list.h"
#include "arraylist.h"
#include <stdlib.h>
#include <string.h>

static int length(List *self);
static void add(List *self,void  *elem);
static void *get(List *self,int index);


ArrayList * new_array_list();
static void delete(ArrayList *arrayList);

typedef struct Data{
  void **arr;
  int capacity;
  int size;
}Data;

char *ARRAYLIST = "ArrayList";

ArrayList * new_array_list(){

  Data *data = malloc(sizeof(ArrayList));
  data->arr = malloc(10*sizeof(void *));
  data->capacity = 10;
  data->size = 0;

  List *list = (List *)malloc(sizeof(List));
  list->length = length;
  list->add = add;
  list->get = get;
  list->type = ARRAYLIST;
  list->data =  data;

  ArrayList *arrayList = malloc(sizeof(ArrayList));
  arrayList->type = ARRAYLIST;
  arrayList->data = data;
  arrayList->asList = list;
  arrayList->delete = delete;
  return arrayList;
}

static int length(List *self){
  if(!self->data || strcmp(self->type,ARRAYLIST)!=0){
    return 0;
  }
  Data *data = self->data;
  return data->size;
}


static void add(List *self,void  *elem){
  if(!self->data || strcmp(self->type,ARRAYLIST)!=0){
    return ;
  }
  Data *data = self-> data;
  int size = data->size;
  int capacity = data->capacity;

  if(size == capacity){
    void **newArr = malloc((10+capacity)*sizeof(void *));

    memcpy(newArr,data->arr,size*sizeof(void *));
    free(data->arr);
    data->arr = newArr;
    data->capacity += 10;
  }
  data->arr[size] = elem;
  data->size++;
}

static void *get(List *self,int index){
  if(!self->data || strcmp(self->type,ARRAYLIST)!=0){
    return NULL;
  }
  Data *data = self->data;
  if(index < data->size){
    return data->arr[index];
  }else{
    return NULL;
  }
}


static void delete(ArrayList *self){
  if(!self->data || strcmp(self->type,ARRAYLIST)!=0){
    return;
  }
  Data *data = self->data;
  free(data->arr);
  free(data);
  free(self->asList);
  free(self);
}
