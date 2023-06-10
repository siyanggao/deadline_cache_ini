#include <jni.h>
#include <string>
#include <thread>
#include <android/log.h>
#include "ini/fileini/simple_file_ini.h"
#include "ini/cache/simple_lru_cache.h"
#include "ini/cache/deadline_cache.h"
#include "ini/ini_data_store.h"

using namespace std;

extern "C" JNIEXPORT jstring JNICALL
Java_com_gsy_ini_IniNativeLibrary_stringFromJNI(
        JNIEnv* env,
        jobject /* this */, jstring ini_path) {
    std::string ini = env->GetStringUTFChars(ini_path, nullptr);
    return env->NewStringUTF("hello world");
}