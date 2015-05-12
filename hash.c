#include "hash.h"

//Returns a pointer to a newly allocated hash table with initialSize buckets
hash_t *newHashTable(int capacity) {
    hash_t *hashTable = malloc(sizeof(hash_t));
    hashTable->buckets = malloc(sizeof(list_t *) * capacity);

    // All the buckets are initialized to NULL
    for (int i = 0; i < capacity; i++) {
       hashTable->buckets[i] = NULL;
    }

    hashTable->capacity = capacity;
    hashTable->size = 0;
    hashTable->loadFactor = 0;

    return hashTable;
}

// Looks up the key in the table
void *lookup(hash_t *hashTable, char *key) {
    // hash the key
    unsigned long hKey = hash(key); 
    // Search for the key in the index into the array
    node_t *entry = findNode(hashTable->buckets[hKey], key);
    if (entry == NULL) {
        errExit("Could not find the value");
    }
    return entry->value; 
}

// Adds a new key, value pair to the table 
void add(hash_t *hashTable, void *key, void *value) {
    // Hash the key
    unsigned long hKey = hash(key); 
    // Add it to the list at that element in the buckets array  
    if (hashTable->keys/hashTable->buckets < MAX_LOAD_FACTOR) {
        find(hashTable->buckets[hKey]); 
    }
}

// Removes the value associated with the key from the table
entry_t *delete(hash_t *hashTable, void *key) {
    
}

// Hashes the key 
unsigned long hash(char *key) {
    unsigned long h = 5381;
    int c;

    while ((c = *key++)) {
        h = ((h << 5) + h) + c;
    }

    return h; 
}

// Doubles the number of buckets and redistributes the keys
void resize(hash_t *hashTable) {
    // Create 
}
