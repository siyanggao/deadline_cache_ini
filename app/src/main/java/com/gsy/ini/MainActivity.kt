package com.gsy.ini

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import com.gsy.ini.databinding.ActivityMainBinding
import java.io.File

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    private lateinit var iniDataStore: IniDataStore

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        iniStoreTest()
        IniNativeLibrary().test(getExternalFilesDir(null)!!.absolutePath + File.separator + "config.ini")
    }

    private fun iniStoreTest(){
        iniDataStore = IniDataStore(
            getExternalFilesDir(null)!!.absolutePath + File.separator + "config.ini"
        )
        iniDataStore.setValue("test","key_default_value",3)
        val ret = iniDataStore.getValue("test","key_default_value",4)
        Log.i("tag",ret.toString())
    }

}