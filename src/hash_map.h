#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stdlib.h>

typedef struct hash_node {
    char *key;
    void *value;
    struct hash_node *next;
} hash_node_t;

typedef struct hash_map {
    hash_node_t **buckets;
    size_t bucket_count;
    size_t (*hash_func)(void *key);
    int (*key_cmp)(void *key1, void *key2);
} hash_map_t;

hash_map_t *hash_map_create(size_t bucket_count, size_t (*hash_func)(void *key),
                            int (*key_cmp)(void *key1, void *key2));
void hash_map_insert(hash_map_t *hash_map, void *key, void *value);
void *hash_map_get(hash_map_t *hash_map, void *key);
void hash_map_destroy(hash_map_t *hash_map);

#endif // HASH_MAP_H