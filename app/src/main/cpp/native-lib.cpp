#include <jni.h>
#include <string>

#include "LuaManager.h"
#include "AntManager.h"

LuaManager luaManager;
AntManager antManager;

extern "C"
{
    JNIEXPORT jstring JNICALL Java_productions_moo_ants_MainActivity_getLuaVersion(JNIEnv* env, jobject thiz)
    {
        std::string hello = luaManager.getVersion();
        return env->NewStringUTF(hello.c_str());
    }

    JNIEXPORT jint JNICALL Java_productions_moo_ants_Ant_addAnt(JNIEnv* env, jobject thiz)
    {
        return antManager.addAnt();
    }

    JNIEXPORT jint JNICALL Java_productions_moo_ants_Ant_takeAction(JNIEnv* env, jobject thiz, jint antID)
    {
        return antManager.takeActionWithAnt((int)antID);
    }
}
