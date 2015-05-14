#include <stdio.h>
#include "hash.h"
#include <string.h>
#include <assert.h>

int main(int argc, char *argv[]) 
{
    hash_t *ht = newHashTable(1);

    add(ht, "Rusty", "Davis");
    char *name = lookup(ht, "Rusty"); 
    assert(strcmp(name, "Davis") == 0);
    assert(ht->keys == 1);
    assert(ht->capacity == 1);
    
    add(ht, "Kanye", "West");
    name = lookup(ht, "Kanye"); 
    assert(strcmp(name, "West") == 0);
    assert(ht->keys == 2);
    assert(ht->capacity == 2);

    add(ht, "Taylor", "Swift");
    name = lookup(ht, "Taylor"); 
    assert(strcmp(name, "Swift") == 0);
    assert(ht->keys == 3);
    assert(ht->capacity == 4);
    

    add(ht, "Kendrick", "Lamar");
    name = lookup(ht, "Kendrick"); 
    assert(strcmp(name, "Lamar") == 0);
    assert(ht->keys == 4);

    add(ht, "John", "Coltrane");
    name = lookup(ht, "John"); 
    assert(strcmp(name, "Coltrane") == 0);
    assert(ht->keys == 5);
    assert(ht->capacity == 8);

    add(ht, "Miles", "Davis");
    name = lookup(ht, "Miles"); 
    assert(strcmp(name, "Davis") == 0);
    assert(ht->keys == 6);

    add(ht, "Stannis", "Baratheon");
    name = lookup(ht, "Stannis"); 
    assert(strcmp(name, "Baratheon") == 0);
    assert(ht->keys == 7);

    printf("Keys: %d Capacity: %d\n", ht->keys, ht->capacity);
    printf("Load %f", (ht->keys*1.0) / ht->capacity);
    destroyHashTable(ht);
    return 0;
}
