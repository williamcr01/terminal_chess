#include <stdlib.h>
#include "hash_map.h"

hash_map_t *hash_map_create(size_t bucket_count, size_t (*hash_func)(void *key),
                            int (*key_cmp)(void *key1, void *key2)) {
    hash_map_t *hash_map = malloc(sizeof(hash_map_t));
    hash_map->buckets = calloc(bucket_count, sizeof(hash_node_t *));
    hash_map->bucket_count = bucket_count;
    hash_map->hash_func = hash_func;
    hash_map->key_cmp = key_cmp;
    return hash_map;
}

void hash_map_insert(hash_map_t *hash_map, void *key, void *value) {
    size_t index = hash_map->hash_func(key) % hash_map->bucket_count;
    hash_node_t *node = hash_map->buckets[index];
    while (node) {
        if (hash_map->key_cmp(node->key, key) == 0) {
            node->value = value;
            return;
        }
        node = node->next;
    }
    node = malloc(sizeof(hash_node_t));
    node->key = key;
    node->value = value;
    node->next = hash_map->buckets[index];
    hash_map->buckets[index] = node;
}

void *hash_map_get(hash_map_t *hash_map, void *key) {
    size_t index = hash_map->hash_func(key) % hash_map->bucket_count;
    hash_node_t *node = hash_map->buckets[index];
    while (node) {
        if (hash_map->key_cmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

void hash_map_destroy(hash_map_t *hash_map) {
    for (size_t i = 0; i < hash_map->bucket_count; i++) {
        hash_node_t *node = hash_map->buckets[i];
        while (node) {
            hash_node_t *next = node->next;
            free(node);
            node = next;
        }
    }
    free(hash_map->buckets);
    free(hash_map);
}