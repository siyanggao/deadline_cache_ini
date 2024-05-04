package com.gsy.ini

import androidx.test.platform.app.InstrumentationRegistry
import androidx.test.ext.junit.runners.AndroidJUnit4

import org.junit.Test
import org.junit.runner.RunWith

import org.junit.Assert.*
import java.io.File

/**
 * Instrumented test, which will execute on an Android device.
 *
 * See [testing documentation](http://d.android.com/tools/testing).
 */
@RunWith(AndroidJUnit4::class)
class IniTest {
    private lateinit var iniDataStore: IniDataStore
    private val deadlineTime = 10L
    private val deadlineCacheTest = DeadlineCacheTest()

    @Test
    fun test() {
        // Context of the app under test.
        val appContext = InstrumentationRegistry.getInstrumentation().targetContext
        val iniPath = appContext.getExternalFilesDir(null)!!.absolutePath + File.separator + "config.ini"
        iniDataStore = IniDataStore(iniPath,deadlineTime)

        iniDataStore.erase("test","int_test")
        iniDataStore.setValue("test","int_test",2)
        for(i in 0..100){
            val value = iniDataStore.getValue("test","int_test",-1)
            assertEquals(value,2)
        }
        Thread.sleep(deadlineTime)
        for(i in 0..100){
            val value = iniDataStore.getValue("test","int_test",-1)
            assertEquals(value,2)
        }

        iniDataStore.setValue("test","string_test","abc")
        for(i in 0..100){
            val value = iniDataStore.getValue("test","string_test","")
            assertEquals(value,"abc")
            Thread.sleep(1)
        }

        iniDataStore.setValue("test","bool_test",true)
        for(i in 0..100){
            val value = iniDataStore.getValue("test","bool_test",false)
            assertEquals(value,true)
            Thread.sleep(1)
        }

        iniDataStore.setValue("test","long_test",3L)
        for(i in 0..100){
            val value = iniDataStore.getValue("test","long_test",1L)
            assertEquals(value,3L)
            Thread.sleep(1)
        }

        iniDataStore.setValue("test","double_test",0.2)
        for(i in 0..100){
            val value = iniDataStore.getValue("test","double_test",0.1)
            assertEquals(value,0.2,0.0000000001)
            Thread.sleep(1)
        }

        deadlineCacheTest.test()

        nativeTest()
    }

    private fun nativeTest(){
        val appContext = InstrumentationRegistry.getInstrumentation().targetContext
        val iniPath = appContext.getExternalFilesDir(null)!!.absolutePath + File.separator + "config.ini"
        IniNativeLibrary().test(iniPath)
    }
}