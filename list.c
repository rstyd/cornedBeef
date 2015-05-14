#include "list.h"

// Returns a new empty list
list_t *newList() {
    // Store the list at this page address
    list_t *newList = malloc(sizeof(list_t));
    newList->head = NULL;
    newList->tail = NULL;
    newList->size = 0;

    return newList;
}

// Add a node to to the back of the list
node_t *pushNode(list_t *list, void *key, void *value){ 
    node_t *node;

    if (list->head == NULL) {
        // Allocate space for the node
        node = newNode(key, value, NULL, NULL);
        list->head = node;
        // When the list has 1 element, the head and tail are equal
        list->tail = list->head;
        list->size++;
    }
    else if (list->size == 1) {
        node = newNode(key, value,  NULL, list->head);	
        list->tail = node;
        list->head->next = list->tail;
        list->size++;
    }
    else {
        node = newNode(key, value, NULL, list->tail);
        list->tail->next = node;
        // the new node is the new tail
        list->tail = list->tail->next;
        list->size++;
    }
    return node;
}

// Adds a node to to the back of the list without creating a new node first
void insertNode(list_t *list, node_t *newNode){ 
    if (list->head == NULL) {
        // Allocate space for the node
        list->head = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
        // When the list has 1 element, the head and tail are equal
        list->tail = list->head;
        list->size++;
    }
    else if (list->size == 1) {
        list->tail = newNode;	
        newNode->next = NULL;
        newNode->prev = list->head;
        list->head->next = list->tail;
        list->size++;
    }
    else {
        list->tail->next = newNode;
        newNode->next = NULL;
        newNode->prev = list->tail;
        // the new node is the new tail
        list->tail = list->tail->next;
        list->size++;
    }
}

// Removes a node from the back of the list
node_t *popNode(list_t *list) {
    node_t *doomed_node = NULL;
    if (list->size == 0) {
        //printf("Cannot remove an item from an empty list.\n");
        //exit(1);
        return NULL;
    }

    if (list->head == list->tail) {
        doomed_node = list->head;
        // Unlink the tail and head from the list
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        list->tail->prev->next = NULL;
        doomed_node = list->tail;
        list->tail = list->tail->prev;
    }
    list->size--;
    return doomed_node;
}

// Returns a pointer to the first node whose data element matches the argument. If no element matches, return NULL
node_t *findNode(list_t *list, void *key){

    node_t *currentNode = list->head;        
    while (currentNode != NULL && currentNode->key != key) {
        currentNode = currentNode->next;
    }
    return currentNode;
    }

// Returns a pointer to a newly allocated node
node_t *newNode(void *key, void *value, node_t *next, node_t *prev) {
    node_t *newNode = malloc(sizeof(node_t));
    newNode->key = key;
    newNode->value = value;
    newNode->next = next;
    newNode->prev = prev;
    return newNode;
}


// Removes the node that is at the supplied address
void deleteNode(list_t *list, node_t *node) {
    if (node == NULL) {
        return;
    }
    if (node->prev == NULL) {
        list->head = node->next;
    }
    else  {
        if (node->prev->next != NULL) {
            node->prev->next = node->next;
        }
    }
    if (node->next == NULL) {
        list->tail = node->prev;
    }
    else  {
        if (node->next->prev != NULL)
            node->next->prev = node->prev;
    }
    free(node);
    list->size--;
}

// Removes all elements from the list
void clearList(list_t *list) {
    while (list->size != 0) {
        free(popNode(list));
    }

}

// Deletes all of the list memebers with popNode then frees the list
void deleteList(list_t *list) {
    clearList(list);
    free(list);
}

void printList(list_t *list) {
    node_t *current = list->head;

    while (current != NULL) {
        if (current != list->tail)
            printf("(%s, %s), ", current->key, current->value);
        else
            printf("(%s, %s)\n", current->key, current->value);
        current = current->next;
    }
}
