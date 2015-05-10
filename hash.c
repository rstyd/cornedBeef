#include "hash.h"

//Returns a pointer to a newly allocated hash table with initialSize buckets
hash_t *newHashTable(int initialSize) {
    
}

// Looks up the key in the table
entry_t *lookup(hash_t *hashTable, char *key) {

}

// Inserts a new value into the table with the key
void insert(hash_t *hashTable, char *key, void *value) {

}

// Removes the value associated with the key from the table
entry_t *delete(hash_t *hashTable, void *key) {

}

// Hashes the key 
void hash(char *key) {

}

// Doubles the number of buckets and redistributes the keys
void resize(hash_t *hashTable) {

}
