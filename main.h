#pragma once

#include <jni.h>

#ifndef ZALUPA_LIBRARY_H
#define ZALUPA_LIBRARY_H

extern "C" {
    JNIEXPORT jstring JNICALL Java_cicadas_mixtape_supermiss_Native_d(JNIEnv* env, jobject obj);
}

#endif