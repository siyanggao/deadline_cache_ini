#include "test.h"

Test::Test(string ini_path) {
    ini = new IniDataStore(ini_path,10);
}

void Test::test1() {
    ini->SetStringValue("test","string_test","fdsdfsf");
    for(int i = 0; i < 100; i++){
        auto value = ini->GetStringValue("test","string_test","gjsjfldsfdls");
        assert(value == "fdsdfsf");
        int rand_num = rand() % 15;
        usleep(rand_num*1000);
    }

    ini->SetIntValue("test","int_test",2);
    for(int i = 0; i < 100; i++){
        auto value = ini->GetIntValue("test","int_test",3);
        assert(value == 2);
        int rand_num = rand() % 15;
        usleep(rand_num*1000);
    }



    ini->SetBoolValue("test","bool_test",true);
    for(int i = 0; i < 100; i++){
        auto value = ini->GetBoolValue("test","bool_test",false);
        assert(value == true);
        int rand_num = rand() % 15;
        usleep(rand_num*1000);
    }

    ini->SetLongValue("test","long_test",2L);
    for(int i = 0; i < 100; i++){
        auto value = ini->GetLongValue("test","long_test",1L);
        assert(value == 2L);
        int rand_num = rand() % 15;
        usleep(rand_num*1000);
    }

    ini->SetDoubleValue("test","double_test",0.2);
    for(int i = 0; i < 100; i++){
        auto value = ini->GetDoubleValue("test","double_test",0.1);
        assert(value == 0.2);
        int rand_num = rand() % 15;
        usleep(rand_num*1000);
    }

}



