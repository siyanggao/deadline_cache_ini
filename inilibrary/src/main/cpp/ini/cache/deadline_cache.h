#ifndef INI_DEADLINE_CACHE_H
#define INI_DEADLINE_CACHE_H
#include <string>
#include <map>
#include <chrono>
#include <stdexcept>
#include "cache_interface.h"
#include "simple_lru_cache.h"
using std::string;
using std::map;
using std::chrono::steady_clock;

class DeadlineCache : public CacheInterface {
public:
    DeadlineCache(const int& deadline_time, CacheInterface *cache);
    ~DeadlineCache() override;
    string GetStringValue(const string& key) override;
    bool SetStringValue(const string& key, const string& value) override;
    int GetIntValue(const string& key) override;
    bool SetIntValue(const string& key,const int& value) override;
    bool GetBoolValue(const string& key) override;
    bool SetBoolValue(const string& key,const bool& value) override;
    double GetDoubleValue(const string& key) override;
    bool SetDoubleValue(const string& key,const double& value) override;
    long GetLongValue(const string& key) override;
    bool SetLongValue(const string& key,const long& value) override;
    void EraseValue(const string& key) override;
    void Clear() override;

private:
    int deadline_time;
    CacheInterface *cache;
    map<string,steady_clock::time_point> insert_time;
};


#endif //INI_DEADLINE_CACHE_H
