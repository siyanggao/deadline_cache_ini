package com.gsy.ini.cache

interface CacheInterface {

    fun get(key: String): Any?

    fun put(key: String, value: Any)

    fun erase(key: String)
}