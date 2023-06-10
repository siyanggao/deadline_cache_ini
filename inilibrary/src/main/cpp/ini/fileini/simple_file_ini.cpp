#include "simple_file_ini.h"

SimpleFileIni::SimpleFileIni(const string& filepath) {
    file_path = filepath;
}

string SimpleFileIni::GetStringValue(const string& section,const string& key,const string& default_value){
    lock_guard<mutex> lock(mutex_);
    if(!LoadIniFile()) return default_value;
    const char *value = ini.GetValue(section.c_str(),key.c_str(),default_value.c_str());
    return value;
}

bool SimpleFileIni::SetStringValue(const string& section, const string& key, const string& value) {
    lock_guard<mutex> lock(mutex_);
    if(!CheckAndCreateFile()) return false;
    if(!LoadIniFile()) return false;
    SI_Error ret = ini.SetValue(section.c_str(),key.c_str(),value.c_str());
    if(ret < 0){
//        LOGE("ini set value error")
        return false;
    }
    if(!SaveIniFile()) return false;
    return true;
}
bool SimpleFileIni::EraseValue(const string& section, const string& key) {
    lock_guard<mutex> lock(mutex_);
    if(!CheckAndCreateFile()) return false;
    if(!LoadIniFile()) return false;
    SI_Error ret = ini.Delete(section.c_str(),key.c_str());
    if(ret < 0){
        return false;
    }
    if(!SaveIniFile()) return false;
    return true;
}
int SimpleFileIni::GetIntValue(const string& section, const string& key, const int& default_value) {
    lock_guard<mutex> lock(mutex_);
    if(!LoadIniFile()) return default_value;
    int value = ini.GetLongValue(section.c_str(),key.c_str(),default_value);
    return value;
}
bool SimpleFileIni::SetIntValue(const string& section, const string& key,const int& value) {
    lock_guard<mutex> lock(mutex_);
    if(!CheckAndCreateFile()) return false;
    if(!LoadIniFile()) return false;
    SI_Error ret = ini.SetLongValue(section.c_str(),key.c_str(),value);
    if(ret < 0){
//        LOGE("ini set value error")
        return false;
    }
    if(!SaveIniFile()) return false;
    return true;
}
bool SimpleFileIni::GetBoolValue(const string& section, const string& key, const bool& default_value) {
    lock_guard<mutex> lock(mutex_);
    if(!LoadIniFile()) return default_value;
    bool value = ini.GetBoolValue(section.c_str(),key.c_str(),default_value);
    return value;
}
bool SimpleFileIni::SetBoolValue(const string& section, const string& key, const bool& value) {
    lock_guard<mutex> lock(mutex_);
    if(!CheckAndCreateFile()) return false;
    if(!LoadIniFile()) return false;
    SI_Error ret = ini.SetBoolValue(section.c_str(),key.c_str(),value);
    if(ret < 0){
//        LOGE("ini set value error")
        return false;
    }
    if(!SaveIniFile()) return false;
    return true;
}

bool SimpleFileIni::SaveIniFile() {
    SI_Error ret = ini.SaveFile(file_path.c_str());
    if(ret < 0){
//        LOGE("ini save file %s error",file_path.c_str())
        return false;
    }
    return true;
}

bool SimpleFileIni::LoadIniFile() {
    auto ret = ini.LoadFile(file_path.c_str());
    if(ret < 0){
//        LOGE("ini load file %s failed",file_path.c_str())
        return false;
    }
    return true;
}

double SimpleFileIni::GetDoubleValue(const string& section, const string& key, const double& default_value) {
    lock_guard<mutex> lock(mutex_);
    if(!LoadIniFile()) return default_value;
    double value = ini.GetDoubleValue(section.c_str(),key.c_str(),default_value);
    return value;
}

bool SimpleFileIni::SetDoubleValue(const string& section, const string& key, const double& value) {
    lock_guard<mutex> lock(mutex_);
    if(!CheckAndCreateFile()) return false;
    if(!LoadIniFile()) return false;
    SI_Error ret = ini.SetDoubleValue(section.c_str(),key.c_str(),value);
    if(ret < 0){
//        LOGE("ini set value error")
        return false;
    }
    if(!SaveIniFile()) return false;
    return true;
}

long SimpleFileIni::GetLongValue(const string& section, const string& key, const long& default_value) {
    lock_guard<mutex> lock(mutex_);
    if(!LoadIniFile()) return default_value;
    long value = ini.GetLongValue(section.c_str(),key.c_str(),default_value);
    return value;;
}

bool SimpleFileIni::SetLongValue(const string& section, const string& key, const long& value) {
    lock_guard<mutex> lock(mutex_);
    if(!CheckAndCreateFile()) return false;
    if(!LoadIniFile()) return false;
    SI_Error ret = ini.SetLongValue(section.c_str(),key.c_str(),value);
    if(ret < 0){
//        LOGE("ini set value error")
        return false;
    }
    if(!SaveIniFile()) return false;
    return true;
}

bool SimpleFileIni::CheckFileExist() {
    int ret = access(file_path.c_str(),F_OK);
    if(ret == 0){
        return true;
    }else{
        return false;
    }
}

bool SimpleFileIni::CreateFile() {
    fstream output_fstream;
    output_fstream.open(file_path.c_str(),std::ios_base::out);
    if(output_fstream.is_open()){
        output_fstream.close();
        return true;
    }else{
        return false;
    }
}

bool SimpleFileIni::CheckAndCreateFile() {
    auto file_ret = CheckFileExist();
    if(!file_ret){
        file_ret = CreateFile();
        if(!file_ret){
            return false;
        }
    }
    return true;
}

SimpleFileIni::~SimpleFileIni() {

}


