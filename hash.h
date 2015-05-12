#include <stdio.h>
#include "list.h"

#ifndef HASH_H
#define HASH_H

#define MAX_LOAD_FACTOR 1.075

// The hash table structure
typedef struct hashTable {
    // The buckets in which keys are kept
    list_t **buckets; 
    // The number of buckets
    int capacity;
    int keys;
    // Number of entries / number of buckets 
    double loadFactor;
} hash_t;

hash_t *newHashTable();
entry_t *lookup(hash_t *hashTable, char *key);
void add(hash_t *hashTable, void *key, void *value);
entry_t *delete(hash_t *hashTable, void *key);
void resize(hash_t *hashTable);sunsigned long hash(char *key);
unsigned long hash(char *key);
void errExit(char *errMsg);
#endif
