package com.gsy.ini.cache

class DeadlineCache(
    private val deadlineTime:Long,
    private val cache:CacheInterface
) : CacheInterface {
    private val insertTime = mutableMapOf<String,Long>()

    override fun get(key: String): Any? {
        if(insertTime[key] == null){
            return null
        }
        if(System.currentTimeMillis() - insertTime[key]!! > deadlineTime){
            insertTime.remove(key)
            return null
        }
        return cache.get(key)
    }

    override fun put(key: String, value: Any) {
        cache.put(key, value)
        insertTime[key] = System.currentTimeMillis()
    }

    override fun erase(key: String){
        cache.erase(key)
        insertTime.remove(key)
    }

    override fun clear() {
        cache.clear()
        insertTime.clear()
    }
}