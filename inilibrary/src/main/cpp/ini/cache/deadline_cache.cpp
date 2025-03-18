#include "deadline_cache.h"

DeadlineCache::DeadlineCache(const int& deadline_time, CacheInterface *cache) : deadline_time(deadline_time), cache(cache){

}

string DeadlineCache::GetStringValue(const string& key) {
    auto iter = insert_time.find(key);
    if(iter == insert_time.end()){
        throw std::out_of_range(key);
    }
    if(steady_clock::now() - iter->second > std::chrono::microseconds(deadline_time)){
        insert_time.erase(key);
        throw std::out_of_range(key);
    }
    return cache->GetStringValue(key);
}

bool DeadlineCache::SetStringValue(const string& key, const string& value) {
    auto ret = cache->SetStringValue(key,value);
    insert_time[key] = steady_clock::now();
    return ret;
}

int DeadlineCache::GetIntValue(const string& key) {
    auto iter = insert_time.find(key);
    if(iter == insert_time.end()){
        throw std::out_of_range(key);
    }
    if(steady_clock::now() - iter->second > std::chrono::microseconds(deadline_time)){
        insert_time.erase(key);
        throw std::out_of_range(key);
    }
    return cache->GetIntValue(key);
}

bool DeadlineCache::SetIntValue(const string& key, const int& value) {
    auto ret = cache->SetIntValue(key,value);
    insert_time[key] = steady_clock::now();
    return ret;
}

bool DeadlineCache::GetBoolValue(const string& key) {
    auto iter = insert_time.find(key);
    if(iter == insert_time.end()){
        throw std::out_of_range(key);
    }
    if(steady_clock::now() - iter->second > std::chrono::microseconds(deadline_time)){
        insert_time.erase(key);
        throw std::out_of_range(key);
    }
    return cache->GetBoolValue(key);
}

bool DeadlineCache::SetBoolValue(const string& key, const bool& value) {
    auto ret = cache->SetBoolValue(key,value);
    insert_time[key] = steady_clock::now();
    return ret;
}

double DeadlineCache::GetDoubleValue(const string& key) {
    auto iter = insert_time.find(key);
    if(iter == insert_time.end()){
        throw std::out_of_range(key);
    }
    if(steady_clock::now() - iter->second > std::chrono::microseconds(deadline_time)){
        insert_time.erase(key);
        throw std::out_of_range(key);
    }
    return cache->GetDoubleValue(key);
}

bool DeadlineCache::SetDoubleValue(const string& key, const double& value) {
    auto ret = cache->SetDoubleValue(key,value);
    insert_time[key] = steady_clock::now();
    return ret;
}

long DeadlineCache::GetLongValue(const string& key) {
    auto iter = insert_time.find(key);
    if(iter == insert_time.end()){
        throw std::out_of_range(key);
    }
    if(steady_clock::now() - iter->second > std::chrono::microseconds(deadline_time)){
        insert_time.erase(key);
        throw std::out_of_range(key);
    }
    return cache->GetLongValue(key);
}

bool DeadlineCache::SetLongValue(const string& key, const long& value) {
    auto ret = cache->SetLongValue(key,value);
    insert_time[key] = steady_clock::now();
    return ret;
}

void DeadlineCache::EraseValue(const string& key) {
    cache->EraseValue(key);
    insert_time.erase(key);
}

void DeadlineCache::Clear() {
    cache->Clear();
    insert_time.clear();
}

DeadlineCache::~DeadlineCache() = default;
