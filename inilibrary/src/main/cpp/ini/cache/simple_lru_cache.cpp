#include "simple_lru_cache.h"

SimpleLruCache::SimpleLruCache(const int& max_size) : max_size(max_size){

}

string SimpleLruCache::GetStringValue(const string& key) {
    map<string,string>::iterator iter = data_str.find(key);
    if(iter != data_str.end()){
        usetime.insert(std::pair<string,int>(key,GetCurrentTime()));
        return iter->second;
    }else{
        throw key;
    }
}

bool SimpleLruCache::SetStringValue(const string& key, const string& value) {
    auto insert_ret = data_str.insert(std::pair<string,string>(key,value));
    if(!insert_ret.second){
        return false;
    }
    usetime.insert(std::pair<string,int>(key,GetCurrentTime()));
    while(data_str.size() > max_size){
        auto min = std::max_element(usetime.begin(),usetime.end(),[](std::pair<string,int> left,std::pair<string,int> right){
            return left.second < right.second;
        });
        data_str.erase(min->first);
        usetime.erase(min->first);
    }
    return true;
}

int SimpleLruCache::GetIntValue(const string& key) {
    map<string,int>::iterator iter = data_int.find(key);
    if(iter != data_int.end()){
        usetime.insert(std::pair<string,int>(key,GetCurrentTime()));
        return iter->second;
    }else{
        throw key;
    }
}

bool SimpleLruCache::SetIntValue(const string& key, const int& value) {
    auto insert_ret = data_int.insert(std::pair<string,int>(key,value));
    if(!insert_ret.second){
        return false;
    }
    usetime.insert(std::pair<string,int>(key,GetCurrentTime()));
    while(data_int.size() > max_size){
        auto min = std::max_element(usetime.begin(),usetime.end(),[](std::pair<string,int> left,std::pair<string,int> right){
            return left.second < right.second;
        });
        data_int.erase(min->first);
        usetime.erase(min->first);
    }
    return true;
}

bool SimpleLruCache::GetBoolValue(const string& key) {
    map<string,bool>::iterator iter = data_bool.find(key);
    if(iter != data_bool.end()){
        usetime.insert(std::pair<string,int>(key,GetCurrentTime()));
        return iter->second;
    }else{
        throw key;
    }
}

bool SimpleLruCache::SetBoolValue(const string& key, const bool& value) {
    auto insert_ret = data_bool.insert(std::pair<string,bool>(key,value));
    if(!insert_ret.second){
        return false;
    }
    usetime.insert(std::pair<string,int>(key,GetCurrentTime()));
    while(data_bool.size() > max_size){
        auto min = std::max_element(usetime.begin(),usetime.end(),[](std::pair<string,int> left,std::pair<string,int> right){
            return left.second < right.second;
        });
        data_bool.erase(min->first);
        usetime.erase(min->first);
    }
    return true;
}

double SimpleLruCache::GetDoubleValue(const string& key) {
    map<string,double>::iterator iter = data_double.find(key);
    if(iter != data_double.end()){
        usetime.insert(std::pair<string,int>(key,GetCurrentTime()));
        return iter->second;
    }else{
        throw key;
    }
}

bool SimpleLruCache::SetDoubleValue(const string& key, const double& value) {
    auto insert_ret = data_double.insert(std::pair<string,double>(key,value));
    if(!insert_ret.second){
        return false;
    }
    usetime.insert(std::pair<string,int>(key,GetCurrentTime()));
    while(data_double.size() > max_size){
        auto min = std::max_element(usetime.begin(),usetime.end(),[](std::pair<string,int> left,std::pair<string,int> right){
            return left.second < right.second;
        });
        data_double.erase(min->first);
        usetime.erase(min->first);
    }
    return true;
}

long SimpleLruCache::GetLongValue(const string& key) {
    map<string,long>::iterator iter = data_long.find(key);
    if(iter != data_long.end()){
        usetime.insert(std::pair<string,int>(key,GetCurrentTime()));
        return iter->second;
    }else{
        throw key;
    }
}

bool SimpleLruCache::SetLongValue(const string& key, const long& value) {
    auto insert_ret = data_long.insert(std::pair<string,long>(key,value));
    if(!insert_ret.second){
        return false;
    }
    usetime.insert(std::pair<string,int>(key,GetCurrentTime()));
    while(data_long.size() > max_size){
        auto min = std::max_element(usetime.begin(),usetime.end(),[](std::pair<string,int> left,std::pair<string,int> right){
            return left.second < right.second;
        });
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

int SimpleLruCache::GetCurrentTime() {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec;
}

SimpleLruCache::~SimpleLruCache() {

}


