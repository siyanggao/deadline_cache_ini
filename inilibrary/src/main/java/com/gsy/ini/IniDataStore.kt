package com.gsy.ini

import android.util.Log
import com.gsy.ini.cache.CacheInterface
import com.gsy.ini.cache.DeadlineCache
import com.gsy.ini.cache.SimpleLruCache
import com.gsy.ini.fileini.FileIniInterface
import com.gsy.ini.fileini.WiniFile

class IniDataStore(
    iniPath:String,
    deadlineTime:Long = 10 * 1000L,
    cache:CacheInterface = SimpleLruCache()
) : FileIniInterface {
    private val deadlineCache = DeadlineCache(deadlineTime,cache)
    private val fileIni = WiniFile(iniPath)

    override fun <T> getValue(section: String, key: String, defaultValue: T): T {
        val cachedValue = deadlineCache.get("$section-$key")
        if(cachedValue != null){
//            Log.i("tag","cache hit")
            return cachedValue as T
        }else{
//            Log.i("tag","cache miss")
        }
        val ret = fileIni.getValue(section,key, defaultValue)
        deadlineCache.put("$section-$key",ret as Any)
        return ret
    }

    override fun <T> setValue(section: String, key: String, value: T): Boolean {
        deadlineCache.erase("$section-$key")
        return fileIni.setValue(section, key, value)
    }

    override fun erase(section: String, key: String): Boolean {
        fileIni.erase(section, key)
        deadlineCache.erase(key)
        return true
    }
}