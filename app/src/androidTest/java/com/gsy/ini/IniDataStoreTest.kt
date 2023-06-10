package com.gsy.ini

import android.util.Log
import androidx.test.ext.junit.runners.AndroidJUnit4
import androidx.test.platform.app.InstrumentationRegistry
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith
import java.io.File

@RunWith(AndroidJUnit4::class)
class IniDataStoreTest {
    private lateinit var iniDataStore: IniDataStore

    @Test
    fun defaultValueTest(){
        for(i in 0..10000000000){
            val ret = iniDataStore.getValue("test","key_default_value",i)
            Log.i("tag",ret.toString())
//            assert(ret == i)
            Thread.sleep(100)
        }
    }

    @Test
    fun setGetTest(){
        var ret = iniDataStore.setValue("test","key1",1)
        assert(ret)
        val value1 = iniDataStore.getValue("test","key1",2)
        assert(value1 == 1)

        ret = iniDataStore.setValue("test","key2",1.1)
        assert(ret)
        val value2 = iniDataStore.getValue("test","key2",2.2)
        assert(value2 == 1.1)

        ret = iniDataStore.setValue("test","key3","abc")
        assert(ret)
        val value3 = iniDataStore.getValue("test","key3","def")
        assert(value3 == "abc")
    }

    @Test
    fun getTest(){
        val ret = iniDataStore.setValue("test","key1",1)
        assert(ret)
        for(i in 0..100){
            val value = iniDataStore.getValue("test","key1",2)
            assert(value == 1)
            Thread.sleep(100)
        }
    }

    @Test
    fun setTest(){
        for(i in 0..100){
            val ret = iniDataStore.setValue("test","key1",1)
            assert(ret)
            Thread.sleep(100)
        }
    }

    @Before
    fun initIniStore(){
        val appContext = InstrumentationRegistry.getInstrumentation().targetContext
        iniDataStore = IniDataStore(
            appContext.getExternalFilesDir(null)!!.absolutePath + File.separator + "config.ini",
            deadlineTime = 1000
        )
    }
}