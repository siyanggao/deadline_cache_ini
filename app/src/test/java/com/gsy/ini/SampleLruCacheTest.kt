package com.gsy.ini

import com.gsy.ini.cache.SimpleLruCache
import org.junit.Test

class SampleLruCacheTest {
    private val cache = SimpleLruCache()

    @Test
    fun putTest(){
        for(i in 0..1000){
            cache.put("test${i}","ds")
            assert(cache.size() <= 100)
            println(i.toString())
            Thread.sleep(100)
        }
    }

    @Test
    fun getTest(){
        for(i in 0..100){
            cache.put("key",i)
            val ret = cache.get("key")
            assert(ret == i)
            Thread.sleep(100)
        }
    }
}