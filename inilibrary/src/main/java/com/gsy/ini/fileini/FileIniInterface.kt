package com.gsy.ini.fileini

interface FileIniInterface {

    fun<T> getValue(section: String, key: String, defaultValue: T): T

    fun<T> setValue(section: String, key: String, value: T):Boolean

    fun erase(section: String, key: String):Boolean
}