#ifndef __CACHE_H__
#define __CACHE_H__

#include <stdbool.h>

typedef struct cache_s cache_t;

cache_t *cache_init(int cache_size);
void cache_free(cache_t *cache);

int cache_insert(cache_t *cache, char *key, void *val, int size, void (*evict_cb)(void *), bool evictable);
int cache_get(cache_t *cache, char *key, void **val);
int cache_evict(cache_t *cache, char *key);

// Allow the cache entry to be evicted.  For example, if the entry is a write
// which has not been flushed yet it will be inserted as evictable == false.
// Once the entry has been flushed it can be set evictable == true.
int cache_set_evictable(cache_t *cache, char *key);

#endif // __CACHE_H__
