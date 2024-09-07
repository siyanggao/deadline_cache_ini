package com.gsy.ini.fileini

import com.gsy.ini.firstini.FirstIni
import java.io.File
import java.io.IOException
import kotlin.reflect.KClass

class FirstIniFile(private val filePath:String) : FileIniInterface {

    override fun <T> getValue(section: String, key: String, defaultValue: T): T {
        val ret = checkFileExist()
        if(!ret) return defaultValue
        val ini = FirstIni(File(filePath))
        val iniSection = ini.getNode(section) ?: return defaultValue
        val v = iniSection[key]
        return if(v != null){
            toValue(v as String,defaultValue!!::class)
        }else{
            defaultValue
        }
    }

    override fun <T> setValue(section: String, key: String, value: T): Boolean {
        var ret = checkFileExist()
        if(!ret) {
            ret = createFile()
            if(!ret)
                return false
        }
        val ini = FirstIni(File(filePath))
        var iniSection = ini.getNode(section)
        if(iniSection == null){
            ini.addNode(section)
            iniSection = ini.getNode(section)
        }
        iniSection!![key] = value
        return try {
            ini.commit()
            true
        }catch (e:IOException){
            e.printStackTrace()
            false
        }
    }

    override fun erase(section: String, key: String): Boolean {
        var ret = checkFileExist()
        if(!ret) {
            ret = createFile()
            if(!ret)
                return false
        }
        val ini = FirstIni(File(filePath))
        val iniSection: LinkedHashMap<String, Any?> = ini.getNode(section) ?: return false
        iniSection.remove(key)
        return try {
            ini.commit()
            true
        }catch (e:IOException){
            e.printStackTrace()
            false
        }
    }

    private fun<T : Any> toValue(value:String, clazz:KClass<T>):T{
        return when (clazz) {
            Boolean::class -> value.toBoolean() as T
            Byte::class -> value.toByte() as T
            Char::class -> value.toByte() as T
            Double::class -> value.toDouble() as T
            Float::class -> value.toFloat() as T
            Int::class -> value.toInt() as T
            Long::class -> value.toLong() as T
            Short::class -> value.toShort() as T
            String::class -> value as T
            else -> String::class as T
        }
    }

    private fun checkFileExist():Boolean{
        try {
            val file = File(filePath)
            return file.exists()
        }catch (e:Exception){
            e.printStackTrace()
        }
        return false
    }

    private fun createFile():Boolean{
        try {
            val file = File(filePath)
            return file.createNewFile()
        }catch (e:Exception){
            e.printStackTrace()
        }
        return false
    }
}