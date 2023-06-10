#ifndef INI_FILE_INI_INTERFACE_H
#define INI_FILE_INI_INTERFACE_H
#include <string.h>

using std::string;
class FileIniInterface{
public:
    virtual string GetStringValue(const string& section,const string& key,const string& default_value) = 0;
    virtual bool SetStringValue(const string& section,const string& key,const string& default_value) = 0;
    virtual bool EraseValue(const string& section,const string& key) = 0;
    virtual int GetIntValue(const string& section,const string& key,const int& default_value) = 0;
    virtual bool SetIntValue(const string& section,const string& key,const int& value) = 0;
    virtual bool GetBoolValue(const string& section,const string& key,const bool& default_value) = 0;
    virtual bool SetBoolValue(const string& section,const string& key,const bool& value) = 0;
    virtual double GetDoubleValue(const string& section,const string& key,const double& default_value) = 0;
    virtual bool SetDoubleValue(const string& section,const string& key,const double& value) = 0;
    virtual long GetLongValue(const string& section,const string& key,const long& default_value) = 0;
    virtual bool SetLongValue(const string& section,const string& key,const long& value) = 0;
    virtual ~FileIniInterface(){};
};
#endif //INI_FILE_INI_INTERFACE_H
