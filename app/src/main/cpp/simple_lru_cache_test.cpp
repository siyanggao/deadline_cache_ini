#include "simple_lru_cache_test.h"

void SimpleLruCacheTest::test() {
    for(int i=0;i<11;i++){
        cache->SetStringValue("test_string_"+std::to_string(i), std::to_string(i));
    }
    try {
        auto value = cache->GetStringValue("test_string_0");
        assert(false);
    } catch (...) {
        assert(true);
    }
    try {
        cache->GetStringValue("test_string_1");
        assert(true);
    } catch (...) {
        assert(false);
    }
}

SimpleLruCacheTest::SimpleLruCacheTest() {
    cache = new SimpleLruCache(10);
}
