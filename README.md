# deadline_cache_ini
library ini provide read and write ini file in kotlin and c++,with deadline cache

# feature and dependencies
this library base on other ini library,and wrapper deadline cache  
value are cached,but cache has deadline time  
value are removed from cache when reach deadline time,so value read from real ini file and put into cache again  
this project is android project  
this library suitable for project that write by kotlin and c++，and kotlin and c++ all has a need to operate ini file  
kotlin based on https://ini4j.sourceforge.net  
c++ based on https://github.com/brofield/simpleini  

# install
kotlin  
import ini4j to your project,gradle or maven  
copy com.gsy.ini file to your project.com.gsy.ini location is inilibrary/src/main/java

c++  
copy ini file to your project.ini file location is inilibrary/src/main/cpp  
edit your makefile or cmake script

# usage
kotlin  
val iniDataStore = IniDataStore(iniPath, deadlineTime = 1000)  
val ret = iniDataStore.setValue("test_section", "test_key", 1)  
val value = iniDataStore.getValue("test_section", "test_key", -1)  

c++  
auto ini = new IniDataStore(ini_path, 1000);  
bool ret = ini->SetStringValue("test_section", "test_key", "test_value");  
auto value = ini->GetStringValue("test_section", "test_key", "default_value");  
