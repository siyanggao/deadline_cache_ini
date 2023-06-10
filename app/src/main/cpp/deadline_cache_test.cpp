//
// Created by Administrator on 2023/6/10.
//
#include "deadline_cache_test.h"

DeadlineCacheTest::DeadlineCacheTest() {
    deadline_time = 10L;
    cache = new SimpleLruCache();
    deadline_cache = new DeadlineCache(deadline_time,cache);
}

DeadlineCacheTest::~DeadlineCacheTest() {
    delete deadline_cache;
    delete cache;
}

void DeadlineCacheTest::Test() {
    deadline_cache->SetIntValue("test_key",1);
    auto value = deadline_cache->GetIntValue("test_key");
    assert(value == 1);
    usleep(deadline_time * 1000);
    try {
        deadline_cache->GetIntValue("test_key");
        assert(false);
    }catch (...){
        assert(true);
    }
}
