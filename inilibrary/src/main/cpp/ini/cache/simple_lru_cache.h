#ifndef INI_SIMPLE_LRU_CACHE_H
#define INI_SIMPLE_LRU_CACHE_H
#include <map>
#include <algorithm>
#include <chrono>
#include <stdexcept>
#include "cache_interface.h"
using std::chrono::steady_clock;
using std::map;

class SimpleLruCache : public CacheInterface{
public:
    SimpleLruCache(const int& max_size = 100);
    ~SimpleLruCache();
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
    int max_size;
    map<string,string> data_str;
    map<string,int> data_int;
    map<string,bool> data_bool;
    map<string,double> data_double;
    map<string,long> data_long;

    map<string,steady_clock::time_point> usetime;

};


#endif //INI_SIMPLE_LRU_CACHE_H
