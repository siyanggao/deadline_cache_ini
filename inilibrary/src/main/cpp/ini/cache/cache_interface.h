#ifndef INI_CACHE_INTERFACE_H
#define INI_CACHE_INTERFACE_H
#include <string>
using std::string;

class CacheInterface{
public:
    virtual string GetStringValue(const string& key) = 0;
    virtual bool SetStringValue(const string& key,const string& value) = 0;
    virtual int GetIntValue(const string& key) = 0;
    virtual bool SetIntValue(const string& key,const int& value) = 0;
    virtual bool GetBoolValue(const string& key) = 0;
    virtual bool SetBoolValue(const string& key,const bool& value) = 0;
    virtual double GetDoubleValue(const string& key) = 0;
    virtual bool SetDoubleValue(const string& key,const double& value) = 0;
    virtual long GetLongValue(const string& key) = 0;
    virtual bool SetLongValue(const string& key,const long& value) = 0;
    virtual void EraseValue(const string& key) = 0;
    virtual ~CacheInterface() {};
    virtual void Clear() = 0;
};
#endif //INI_CACHE_INTERFACE_H
