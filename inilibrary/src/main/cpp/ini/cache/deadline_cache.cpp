#include "deadline_cache.h"

DeadlineCache::DeadlineCache(const int& deadline_time, CacheInterface *cache) : deadline_time(deadline_time), cache(cache){

}

string DeadlineCache::GetStringValue(const string& key) {
    auto iter = insert_time.find(key);
    if(iter == insert_time.end()){
        throw key;
    }
    if(GetCurrentTimeMs() - iter->second > deadline_time){
        insert_time.erase(key);
        throw key;
    }
    return cache->GetStringValue(key);
}

bool DeadlineCache::SetStringValue(const string& key, const string& value) {
    auto ret = cache->SetStringValue(key,value);
    insert_time.insert(std::pair<string,int64_t>(key,GetCurrentTimeMs()));
    return ret;
}

int DeadlineCache::GetIntValue(const string& key) {
    auto iter = insert_time.find(key);
    if(iter == insert_time.end()){
        throw key;
    }
    if(GetCurrentTimeMs() - iter->second > deadline_time){
        insert_time.erase(key);
        throw key;
    }
    return cache->GetIntValue(key);
}

bool DeadlineCache::SetIntValue(const string& key, const int& value) {
    auto ret = cache->SetIntValue(key,value);
    insert_time.insert(std::pair<string,int64_t>(key,GetCurrentTimeMs()));
    return ret;
}

bool DeadlineCache::GetBoolValue(const string& key) {
    auto iter = insert_time.find(key);
    if(iter == insert_time.end()){
        throw key;
    }
    if(GetCurrentTimeMs() - iter->second > deadline_time){
        insert_time.erase(key);
        throw key;
    }
    return cache->GetBoolValue(key);
}

bool DeadlineCache::SetBoolValue(const string& key, const bool& value) {
    auto ret = cache->SetBoolValue(key,value);
    insert_time.insert(std::pair<string,int64_t>(key,GetCurrentTimeMs()));
    return ret;
}

double DeadlineCache::GetDoubleValue(const string& key) {
    auto iter = insert_time.find(key);
    if(iter == insert_time.end()){
        throw key;
    }
    if(GetCurrentTimeMs() - iter->second > deadline_time){
        insert_time.erase(key);
        throw key;
    }
    return cache->GetDoubleValue(key);
}

bool DeadlineCache::SetDoubleValue(const string& key, const double& value) {
    auto ret = cache->SetDoubleValue(key,value);
    insert_time.insert(std::pair<string,int64_t>(key,GetCurrentTimeMs()));
    return ret;
}

long DeadlineCache::GetLongValue(const string& key) {
    auto iter = insert_time.find(key);
    if(iter == insert_time.end()){
        throw key;
    }
    if(GetCurrentTimeMs() - iter->second > deadline_time){
        insert_time.erase(key);
        throw key;
    }
    return cache->GetLongValue(key);
}

bool DeadlineCache::SetLongValue(const string& key, const long& value) {
    auto ret = cache->SetLongValue(key,value);
    insert_time.insert(std::pair<string,int64_t>(key,GetCurrentTimeMs()));
    return ret;
}

void DeadlineCache::EraseValue(const string& key) {
    cache->EraseValue(key);
    insert_time.erase(key);
}

int64_t DeadlineCache::GetCurrentTimeMs() {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

DeadlineCache::~DeadlineCache() {

}
