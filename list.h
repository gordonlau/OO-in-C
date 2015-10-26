#ifndef LIST_INCLUDED
#define LIST_INCLUDED

typedef struct List {
    int (*length)(struct List *list);
    void (*add)(struct List *list,void *elem);
    void *(*get)(struct List *list,int index);
    char *type;
    void *data;
}List;

#endif
