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
    hashTable->keys = 0;
    hashTable->loadFactor = 0;

    return hashTable;
}

// Looks up the key in the table
void *lookup(hash_t *hashTable, char *key) {
    // hash the key
    unsigned long hKey = hash(hashTable->capacity, key); 
    // Search for the key in the index into the array
    node_t *entry = findNode(hashTable->buckets[hKey], key);
    if (entry == NULL) {
        errExit("Could not find the value");
    }
    return entry->value; 
}

// Adds a new key, value pair to the table 
void add(hash_t *hashTable, void *key, void *value) {
    // Make sure adding the node isn't going to push the hash table over the max load factor
    if ((hashTable->keys + 1) / hashTable->capacity > MAX_LOAD_FACTOR) {
        // Doubles the number of buckets in the table and rehashes all of the keys
        resize(hashTable);
    }

    // Hash the key
    unsigned long hKey = hash(hashTable->capacity, key); 
    list_t *bucket;

    // The buckets are lazy initialized
    if (hashTable->buckets[hKey] == NULL) 
       hashTable->buckets[hKey] = newList(); 

    bucket = hashTable->buckets[hKey];
    pushNode(bucket, key, value); 
}

// Removes the value associated with the key from the table
void delete(hash_t *hashTable, void *key) { 
    unsigned long hKey = hash(hashTable->capacity, key); 
    list_t *bucket = hashTable->buckets[hKey];

    if (bucket == NULL) {
        errExit("Cannot delete a key that does not exist");
    }

    node_t *entry = findNode(bucket, key);
    // TODO Make sure deleteNode actually works the way that I intended
    deleteNode(bucket, entry);
}


// Hashes the key 
unsigned long hash(int n, char *key) {
    unsigned long h = 5381;
    int c;

    while ((c = *key++)) {
        h = ((h << 5) + h) + c;
    }

    return h % n; 
}

// Doubles the number of buckets and redistributes the keys
void resize(hash_t *hashTable) {
    // Double the memory alloted to the buckets array
    realloc(hashTable->buckets, 2 * hashTable->capacity * sizeof(list_t *));
    for (int i = 0; i < hashTable->capacity; i++) {
        list_t *bucket = hashTable->buckets[i];
        if (bucket == NULL) {
            continue;
        }
        // Go through every key in the list and rehash
       for (int j = 0; j < bucket->size; j++) {
            node_t *entry = popNode(bucket);
            // Remove the key from the hashTable
            delete(hashTable, entry->key); 
            // Add it back
            add(hashTable, entry->key, entry->value);
            free(entry);
       }
    }
}

void errExit(char *errMsg) {
    fprintf(stderr, "%s\n", errMsg);
    exit(1);
}
