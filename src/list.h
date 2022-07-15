#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    void *data;
    struct node_t *next;
} NODE;

typedef struct {
    NODE *head;
    NODE *tail;
    int size;
} LIST;

LIST *list_create();

void list_add(LIST *list, void *data);

void *list_get(LIST *list, int index);

int list_index(LIST *list, NODE *node);

int list_size(LIST *list);

void list_free(LIST *list);

#endif //LIST_H