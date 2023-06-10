package com.gsy.ini

class IniNativeLibrary {
    external fun stringFromJNI(iniPath : String): String
    external fun test(iniPath : String)

    companion object {
        // Used to load the 'ini' library on application startup.
        init {
            System.loadLibrary("ini")
            System.loadLibrary("ini_app")
        }
    }
}