package com.gsy.ini

import androidx.test.ext.junit.runners.AndroidJUnit4
import com.gsy.ini.cache.DeadlineCache
import com.gsy.ini.cache.SimpleLruCache
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith

@RunWith(AndroidJUnit4::class)
class DeadlineCacheTest {
    private val deadlineTime = 10L
    private val deadlineCache = DeadlineCache(deadlineTime,SimpleLruCache())

    @Test
    fun test(){
        deadlineCache.put("test_key","test_value")
        var value = deadlineCache.get("test_key")
        Assert.assertEquals(value,"test_value")
        Thread.sleep(deadlineTime)
        value = deadlineCache.get("test_key")
        Assert.assertEquals(value,null)
    }
}