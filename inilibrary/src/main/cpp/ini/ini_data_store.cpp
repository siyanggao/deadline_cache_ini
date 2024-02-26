#include "ini_data_store.h"

IniDataStore::IniDataStore(const string& ini_path, const int& deadline_time, CacheInterface *cache, const bool& have_space){
    lru_cache = cache;
    deadline_cache = new DeadlineCache(deadline_time, lru_cache);
    file_ini = new SimpleFileIni(ini_path, have_space);
}

string IniDataStore::GetStringValue(const string& section, const string& key, const string& default_value) {
    try{
        auto cache_value = deadline_cache->GetStringValue(section + "-" + key);
        return cache_value;
    }catch (string){
        string file_value = file_ini->GetStringValue(section,key,default_value);
        deadline_cache->SetStringValue(section + "-" + key, file_value);
        return file_value;
    }
}

bool IniDataStore::SetStringValue(const string& section, const string& key, const string& value) {
    deadline_cache->EraseValue(section + "-" + key);
    return file_ini->SetStringValue(section,key,value);
}


int IniDataStore::GetIntValue(const string& section, const string& key, const int& default_value) {
    try{
        int cache_value = deadline_cache->GetIntValue(section + "-" + key);
        return cache_value;
    }catch (string){
        int file_value = file_ini->GetIntValue(section,key,default_value);
        deadline_cache->SetIntValue(section + "-" + key, file_value);
        return file_value;
    }
}

bool IniDataStore::SetIntValue(const string& section, const string& key, const int& value) {
    deadline_cache->EraseValue(section + "-" + key);
    return file_ini->SetIntValue(section,key,value);
}

bool IniDataStore::GetBoolValue(const string& section, const string& key, const bool& default_value) {
    try{
        bool cache_value = deadline_cache->GetBoolValue(section + "-" + key);
        return cache_value;
    }catch (string){
        bool file_value = file_ini->GetBoolValue(section,key,default_value);
        deadline_cache->SetBoolValue(section + "-" + key, file_value);
        return file_value;
    }
}

bool IniDataStore::SetBoolValue(const string& section, const string& key, const bool& value) {
    deadline_cache->EraseValue(section + "-" + key);
    return file_ini->SetBoolValue(section,key,value);
}

double IniDataStore::GetDoubleValue(const string& section, const string& key, const double& default_value) {
    try{
        double cache_value = deadline_cache->GetDoubleValue(section + "-" + key);
        return cache_value;
    }catch (string){
        double file_value = file_ini->GetDoubleValue(section,key,default_value);
        deadline_cache->SetDoubleValue(section + "-" + key, file_value);
        return file_value;
    }
}

bool IniDataStore::SetDoubleValue(const string& section, const string& key, const double& value) {
    deadline_cache->EraseValue(section + "-" + key);
    return file_ini->SetDoubleValue(section,key,value);
}

long IniDataStore::GetLongValue(const string& section, const string& key, const long& default_value) {
    try{
        long cache_value = deadline_cache->GetLongValue(section + "-" + key);
        return cache_value;
    }catch (string){
        long file_value = file_ini->GetLongValue(section,key,default_value);
        deadline_cache->SetLongValue(section + "-" + key, file_value);
        return file_value;
    }
}

bool IniDataStore::SetLongValue(const string& section, const string& key, const long& value) {
    deadline_cache->EraseValue(section + "-" + key);
    return file_ini->SetLongValue(section,key,value);
}


bool IniDataStore::EraseValue(const string& section, const string& key) {
    deadline_cache->EraseValue(section + "-" + key);
    return file_ini->EraseValue(section,key);
}

bool IniDataStore::ResetCache(const string& section,const string& key){
    deadline_cache->EraseValue(section + "-" + key);
}
bool IniDataStore::ResetCache(){
    deadline_cache->Clear();
}

IniDataStore::~IniDataStore() {
    delete deadline_cache;
    delete file_ini;
}


