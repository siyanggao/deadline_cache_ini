//
// Created by Administrator on 2023/6/10.
//

#ifndef INI_DEADLINE_CACHE_TEST_H
#define INI_DEADLINE_CACHE_TEST_H
#include <cassert>
#include <unistd.h>
#include "../../../../inilibrary/src/main/cpp/ini/cache/deadline_cache.h"
using namespace std;

class DeadlineCacheTest {
public:
    DeadlineCacheTest();
    ~DeadlineCacheTest();
    void Test();

private:
    int deadline_time;
    DeadlineCache *deadline_cache;
    CacheInterface *cache;
};


#endif //INI_DEADLINE_CACHE_TEST_H
