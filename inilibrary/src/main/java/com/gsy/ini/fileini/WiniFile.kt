package com.gsy.ini.fileini

import org.ini4j.Profile
import org.ini4j.Wini
import java.io.File

class WiniFile(private val filePath:String) : FileIniInterface {

    override fun <T> getValue(section: String, key: String, defaultValue: T): T {
        val ret = checkFileExist()
        if(!ret) return defaultValue
        val ini = Wini(File(filePath))
        val iniSection = ini[section] ?: return defaultValue
        val clazz = getClazzByValue(defaultValue)
        return iniSection.get(key,clazz) ?: return defaultValue
    }

    override fun<T> setValue(section: String, key: String, value: T):Boolean{
        var ret = checkFileExist()
        if(!ret) {
            ret = createFile()
            if(!ret)
                return false
        }
        val ini = Wini(File(filePath))
        var iniSection = ini[section]
        if(iniSection == null){
            ini.add(section)
            iniSection = ini[section]
        }
        iniSection!![key] = value.toString()
        ini.store()
        return true
    }

    override fun erase(section: String, key: String): Boolean {
        val ret = checkFileExist()
        if(!ret) return true
        val ini = Wini(File(filePath))
        var iniSection: Profile.Section? = ini[section] ?: return true
        val value = iniSection!!.remove(key)
        return if(value != null){
            ini.store()
            true
        }else{
            false
        }
    }

    private fun<T> getClazzByValue(value:T):Class<T>{
        return when (value) {
            is Boolean -> java.lang.Boolean::class.java as Class<T>
            is Byte -> java.lang.Byte::class.java as Class<T>
            is Char -> java.lang.Character::class.java as Class<T>
            is Double -> java.lang.Double::class.java as Class<T>
            is Float -> java.lang.Float::class.java as Class<T>
            is Int -> java.lang.Integer::class.java as Class<T>
            is Long -> java.lang.Long::class.java as Class<T>
            is Short -> java.lang.Short::class.java as Class<T>
            is String -> String::class.java as Class<T>
            else -> String::class.java as Class<T>
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