#include "list.h"
#include "linkedlist.h"
#include <stdlib.h>

static int length(List *self);
static void delete(List *self);
static void add(List *self,void  *elem);
static void *get(List *self,int index);
List * new_linked_list();



typedef struct Node{
  void *elem;
  struct Node *next;
}Node;

typedef struct LinkedList{
  Node *first;
  Node *last;
}LinkedList;

static void *get_linked_list(Node *node,int index);
static int length_linked_list(Node *node);
static void delete_linked_list(Node *node);



List * new_linked_list(){
  List *list = malloc(sizeof(List));
  LinkedList *linkedList = malloc(sizeof(LinkedList));
  linkedList->first = NULL;
  linkedList->last = NULL;
  list->length = length;
  list->delete = delete;
  list->add = add;
  list->get = get;
  list->data = linkedList;
  return list;
}

static int length(List *self){
  LinkedList *linkedList = self->data;
  if(!linkedList->first){
    return 0;
  }
  return length_linked_list(linkedList->first);
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

static void add(List *self,void  *elem){
  LinkedList *linkedList = self->data;
  Node *newNode = malloc(sizeof(Node));
  newNode->elem = elem;
  if(!linkedList->first){ // The List is currently Empty
    linkedList->first = newNode;
    linkedList->last = newNode;
  }else{
      Node *lastNode = linkedList->last;
      newNode->next = NULL;
      lastNode->next = newNode;
      linkedList->last = newNode;
  }
}

static void *get(List *self,int index){
  LinkedList *linkedList = self->data;
  if(linkedList->first){
      return get_linked_list(linkedList->first,index);
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
  LinkedList *linkedList = self->data;
  if(linkedList->first){
      delete_linked_list(linkedList->first);
  }
  free(linkedList);
  free(self);
}

static void delete_linked_list(Node *node){
  if(node->next){
    delete_linked_list(node->next);
  }
  free(node);
}
