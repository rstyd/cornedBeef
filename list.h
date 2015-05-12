#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "hash.h"

#ifndef LIST_H
#define LIST_H
// A doubly linked list

typedef struct node_t {
    struct node_t *next;
    struct node_t *prev;
    void *key;
    void *value;
} node_t;

typedef struct list_t {
    node_t *head;
    node_t *tail;
    size_t size;
} list_t;


list_t *newList(size_t size);
// Deletes all of the list memebers with popNode then frees the list
void deleteList(list_t *list);
// Adds a node to the back of the list
node_t *pushNode(list_t *list, entry_t *data);
// Removes node from the back of the list
node_t *popNode(list_t *list);
// Returns a pointer to the first node whose data element matches the argument
// Reqruires a reference to a compare function
node_t *findNode(list_t *list, void *key);
// Removes the node that is at the supplied address
void deleteNode(list_t *list, node_t *node);
// Removes all elements from the list
void clearList(list_t *list);
// Returns a pointer to a node allocated when the data from the supplied node
node_t *newNode(void *data, node_t *next, node_t *prev); 
void printList(list_t *list);
void insertNode(list_t *list, node_t *newNode);

#endif
