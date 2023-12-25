#ifndef INI_INI_DATA_STORE_H
#define INI_INI_DATA_STORE_H
#include <string>
#include "fileini/simple_file_ini.h"
#include "cache/cache_interface.h"
#include "cache/simple_lru_cache.h"
#include "cache/deadline_cache.h"
using std::string;

class IniDataStore : public FileIniInterface{
public:
    /**
     * construct function
     * @param ini_path ini file path
     * @param deadline_time deadline time in millisecond
     * @param cache cache
     */
    IniDataStore(const string& ini_path, const int& deadline_time = 10 * 1000, CacheInterface *cache = new SimpleLruCache(), const bool& have_space = true);
    ~IniDataStore();
    string GetStringValue(const string& section,const string& key,const string& default_value) override;
    bool SetStringValue(const string& section,const string& key,const string& default_value) override;
    int GetIntValue(const string& section,const string& key,const int& default_value) override;
    bool SetIntValue(const string& section,const string& key,const int& value) override;
    bool GetBoolValue(const string& section,const string& key,const bool& default_value) override;
    bool SetBoolValue(const string& section,const string& key,const bool& value) override;
    double GetDoubleValue(const string& section,const string& key,const double& default_value) override;
    bool SetDoubleValue(const string& section,const string& key,const double& value) override;
    long GetLongValue(const string& section,const string& key,const long& default_value) override;
    bool SetLongValue(const string& section,const string& key,const long& value) override;
    bool EraseValue(const string& section,const string& key) override;

private:
    CacheInterface *lru_cache;
    DeadlineCache *deadline_cache;
    FileIniInterface *file_ini;
};


#endif //INI_INI_DATA_STORE_H
