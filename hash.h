#include <stdio.h>
#include "list.h"

typdef struct hashTable {
    // The buckets in which keys are kept
    list_t *buckets; 
    int size;
    double loadFactor;
} hash_t;

typedef struct entry {
    void *value;
} entry_t;

typedef struct key {
    void *key;
} key_t;

hash_t *newHashTable();
entry_t *lookup(hash_t *hashTable, char *key);
void insert(hash_t *hashTable, char *key, void *value);
entry_t *delete(hash_t *hashTable, void *key);
void resize(hash_t *hashTable);
