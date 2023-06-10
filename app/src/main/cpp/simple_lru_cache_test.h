#ifndef INI_SIMPLE_LRU_CACHE_TEST_H
#define INI_SIMPLE_LRU_CACHE_TEST_H
#include <cassert>
#include <android/log.h>
#include "../../../../inilibrary/src/main/cpp/ini/cache/simple_lru_cache.h"

class SimpleLruCacheTest {
public:
    SimpleLruCacheTest();
    void test();

private:
    SimpleLruCache *cache;
};


#endif //INI_SIMPLE_LRU_CACHE_TEST_H
