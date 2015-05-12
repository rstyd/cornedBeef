#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include "list.h"
#define MAX_LOAD_FACTOR 1.075

enum type {
    INT_TYPE,
    DOUBLE_TYPE,
    STRING_TYPE 
} hashTypes;

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

hash_t *newHashTable(int capacity);
void *lookup(hash_t *hashTable, char *key);
void add(hash_t *hashTable, void *key, void *value);
void delete(hash_t *hashTable, void *key);
void resize(hash_t *hashTable);
unsigned long hash(int n, char *key);
void errExit(char *errMsg);
#endif
