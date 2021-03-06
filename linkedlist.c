#include <stdlib.h>
#include "linkedlist.h"

static int length(List *self);
static List * add(List *self,void  *elem);
static void *get(List *self,int index);

List * new_linked_list();
static void delete(List *self);


typedef struct Node{
  void *elem;
  struct Node *next;
}Node;

typedef struct Data{
  Node *first;
  Node *last;
}Data;

static void *get_linked_list(Node *node,int index);
static int length_linked_list(Node *node);
static void delete_linked_list(Node *node);

char *LINKEDLIST = "LinkedList";


List * new_linked_list(){
  Data *data = malloc(sizeof(Data));
  data->first = NULL;
  data->last = NULL;

  List *list = malloc(sizeof(List));
  list->length = length;
  list->add = add;
  list->get = get;
  list->delete = delete;
  list->type = LINKEDLIST;
  list->data = data;
  return list;
}

static int length(List *self){
  if(!self->data || strcmp(self->type,LINKEDLIST)!=0){
    return 0 ;
  }
  Data *data = self->data;
  if(!data->first){
    return 0;
  }
  return length_linked_list(data->first);
}

static int length_linked_list(Node *node){
  int count = 0;
  if(node->elem){
    count++;
  }
  if(node->next){
      return count+ length_linked_list(node->next);
  }else{
      return count;
  }
}

static List * add(List *self,void  *elem){
  if(!self->data || strcmp(self->type,LINKEDLIST)!=0){
    return self;
  }
  Data *data = self->data;
  Node *newNode = malloc(sizeof(Node));
  newNode->elem = elem;
  if(!data->first){ // The List is currently Empty
    data->first = newNode;
    data->last = newNode;
  }else{
      Node *lastNode = data->last;
      newNode->next = NULL;
      lastNode->next = newNode;
      data->last = newNode;
  }
  return self;
}

static void *get(List *self,int index){
  if(!self->data || strcmp(self->type,LINKEDLIST)!=0){
    return NULL;
  }
  Data *data = self->data;
  if(data->first){
      return get_linked_list(data->first,index);
  }else{
    return NULL;
  }
}

static void *get_linked_list(Node *node,int index){
  if(index == 0){
    return node->elem;
  }else if(node->next){
    return get_linked_list(node->next,index-1);
  }else{
    return NULL;
  }
}

static void delete(List *self){
  if(!self->data || strcmp(self->type,LINKEDLIST)!=0){
    return;
  }
  Data *data = self->data;
  if(data->first){
      delete_linked_list(data->first);
  }
  free(data);
  free(self);
}

static void delete_linked_list(Node *node){
  if(node->next){
    delete_linked_list(node->next);
  }
  free(node);
}
