#include <jni.h>
#include <string>
#include <thread>
#include <android/log.h>
#include "test.h"
#include "simple_lru_cache_test.h"
#include "deadline_cache_test.h"

using namespace std;

extern "C" JNIEXPORT void JNICALL
Java_com_gsy_ini_IniNativeLibrary_test(
        JNIEnv* env,
        jobject /* this */, jstring ini_path) {
    std::string ini = env->GetStringUTFChars(ini_path, nullptr);
    Test *test = new Test(ini);
    test->test1();
    SimpleLruCacheTest *simple_lru_cache_test = new SimpleLruCacheTest();
    simple_lru_cache_test->test();
    DeadlineCacheTest *deadline_cache_test = new DeadlineCacheTest();
    deadline_cache_test->Test();
}