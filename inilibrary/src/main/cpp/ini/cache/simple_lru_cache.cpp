#include "simple_lru_cache.h"

SimpleLruCache::SimpleLruCache(const int& max_size) : max_size(max_size){

}

string SimpleLruCache::GetStringValue(const string& key) {
    auto iter = data_str.find(key);
    if(iter != data_str.end()){
        usetime[key] = steady_clock::now();
        return iter->second;
    }else{
        throw std::out_of_range(key);
    }
}

bool SimpleLruCache::SetStringValue(const string& key, const string& value) {
    data_str[key] = value;
    usetime[key] = steady_clock::now();
    while(data_str.size() > max_size){
        auto min = std::min_element(
                usetime.begin(),
                usetime.end(),
                [](const std::pair<string,steady_clock::time_point>& left,const std::pair<string,steady_clock::time_point>& right){
                    return left.second < right.second;
                }
        );
        data_str.erase(min->first);
        usetime.erase(min->first);
    }
    return true;
}

int SimpleLruCache::GetIntValue(const string& key) {
    auto iter = data_int.find(key);
    if(iter != data_int.end()){
        usetime[key] = steady_clock::now();
        return iter->second;
    }else{
        throw std::out_of_range(key);
    }
}

bool SimpleLruCache::SetIntValue(const string& key, const int& value) {
    auto insert_ret = data_int.insert(std::pair<string,int>(key,value));
    if(!insert_ret.second){
        return false;
    }
    data_int[key] = value;
    usetime[key] = steady_clock::now();
    while(data_int.size() > max_size){
        auto min = std::min_element(
                usetime.begin(),
                usetime.end(),
                [](const std::pair<string,steady_clock::time_point>& left,const std::pair<string,steady_clock::time_point>& right){
                    return left.second < right.second;
                }
        );
        data_int.erase(min->first);
        usetime.erase(min->first);
    }
    return true;
}

bool SimpleLruCache::GetBoolValue(const string& key) {
    auto iter = data_bool.find(key);
    if(iter != data_bool.end()){
        usetime[key] = steady_clock::now();
        return iter->second;
    }else{
        throw std::out_of_range(key);
    }
}

bool SimpleLruCache::SetBoolValue(const string& key, const bool& value) {
    data_bool[key] = value;
    usetime[key] = steady_clock::now();
    while(data_bool.size() > max_size){
        auto min = std::min_element(
                usetime.begin(),
                usetime.end(),
                [](const std::pair<string,steady_clock::time_point>& left,const std::pair<string,steady_clock::time_point>& right){
                    return left.second < right.second;
                }
        );
        data_bool.erase(min->first);
        usetime.erase(min->first);
    }
    return true;
}

double SimpleLruCache::GetDoubleValue(const string& key) {
    auto iter = data_double.find(key);
    if(iter != data_double.end()){
        usetime[key] = steady_clock::now();
        return iter->second;
    }else{
        throw std::out_of_range(key);
    }
}

bool SimpleLruCache::SetDoubleValue(const string& key, const double& value) {
    data_double[key] = value;
    usetime[key] = steady_clock::now();
    while(data_double.size() > max_size){
        auto min = std::min_element(
                usetime.begin(),
                usetime.end(),
                [](const std::pair<string,steady_clock::time_point>& left,const std::pair<string,steady_clock::time_point>& right){
                    return left.second < right.second;
                }
        );
        data_double.erase(min->first);
        usetime.erase(min->first);
    }
    return true;
}

long SimpleLruCache::GetLongValue(const string& key) {
    auto iter = data_long.find(key);
    if(iter != data_long.end()){
        usetime[key] = steady_clock::now();
        return iter->second;
    }else{
        throw std::out_of_range(key);
    }
}

bool SimpleLruCache::SetLongValue(const string& key, const long& value) {
    data_long[key] = value;
    usetime[key] = steady_clock::now();
    while(data_long.size() > max_size){
        auto min = std::min_element(
                usetime.begin(),
                usetime.end(),
                [](const std::pair<string,steady_clock::time_point>& left,const std::pair<string,steady_clock::time_point>& right){
                    return left.second < right.second;
                }
        );
        data_long.erase(min->first);
        usetime.erase(min->first);
    }
    return true;
}

void SimpleLruCache::EraseValue(const string& key) {
    data_str.erase(key);
    data_int.erase(key);
    data_bool.erase(key);
    data_double.erase(key);
    data_long.erase(key);
    usetime.erase(key);
}

void SimpleLruCache::Clear(){
    data_str.clear();
    data_int.clear();
    data_bool.clear();
    data_double.clear();
    data_long.clear();
    usetime.clear();
}

SimpleLruCache::~SimpleLruCache() = default;


