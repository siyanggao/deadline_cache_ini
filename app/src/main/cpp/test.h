#ifndef INI_TEST_H
#define INI_TEST_H
#include <random>
#include <cassert>
#include <unistd.h>
#include <thread>
#include "../../../../inilibrary/src/main/cpp/ini/ini_data_store.h"

using namespace std;

class Test {
public:
    Test(string ini_path);
    void test1();
private:
    IniDataStore *ini;
    thread t;
};


#endif //INI_TEST_H
