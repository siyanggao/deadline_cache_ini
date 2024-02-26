package com.gsy.ini.cache

class SimpleLruCache(private val maxSize:Int = 100) : CacheInterface {
    private val data = mutableMapOf<String,Any>()
    private val useTime = mutableMapOf<String,Long>()

    override fun get(key: String): Any? {
        val ret = data[key]
        return if(ret != null){
            useTime[key] = System.currentTimeMillis()
            ret
        }else{
            null
        }
    }

    override fun put(key: String, value: Any) {
        data[key] = value
        useTime[key] = System.currentTimeMillis()
        while(data.size > maxSize){
            val min = useTime.minWithOrNull { o1, o2 ->
                when {
                    o1.value < o2.value -> -1
                    o1.value == o2.value -> 0
                    else -> 1
                }
            }
            data.remove(min?.key)
            useTime.remove(min?.key)
        }
    }

    override fun erase(key: String) {
        data.remove(key)
        useTime.remove(key)
    }

    override fun clear() {
        data.clear()
        useTime.clear()
    }

    fun size():Int{
        return data.size
    }
}