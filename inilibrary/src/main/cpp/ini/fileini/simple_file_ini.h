#ifndef INI_SIMPLE_FILE_INI_H
#define INI_SIMPLE_FILE_INI_H
#include <mutex>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include "file_ini_interface.h"
#include "../simpleini/SimpleIni.h"

using std::string;
using std::mutex;
using std::lock_guard;
using std::fstream;

class SimpleFileIni : public FileIniInterface{
public:
    SimpleFileIni(const string& filepath,const bool& have_space);
    ~SimpleFileIni();
    string GetStringValue(const string& section,const string& key,const string& default_value) override;
    bool SetStringValue(const string& section,const string& key,const string& value) override;
    bool EraseValue(const string& section,const string& key) override;
    int GetIntValue(const string& section,const string& key,const int& default_value) override;
    bool SetIntValue(const string& section,const string& key,const int& value) override;
    bool GetBoolValue(const string& section,const string& key,const bool& default_value) override;
    bool SetBoolValue(const string& section,const string& key,const bool& value) override;
    double GetDoubleValue(const string& section,const string& key,const double& default_value) override;
    bool SetDoubleValue(const string& section,const string& key,const double& value) override;
    long GetLongValue(const string& section,const string& key,const long& default_value) override;
    bool SetLongValue(const string& section,const string& key,const long& value) override;

private:
    CSimpleIniA ini;
    mutex mutex_;
    string file_path;
    bool have_space;
    bool LoadIniFile();
    bool SaveIniFile();
    bool CheckFileExist();
    bool CreateFile();
    bool CheckAndCreateFile();
};


#endif //INI_SIMPLE_FILE_INI_H
