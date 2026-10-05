#pragma once

#include <jni.h>

#ifndef MAIN_H
#define MAIN_H

extern "C" {
    JNIEXPORT jstring JNICALL Java_cicadas_mixtape_supermiss_Native_d(JNIEnv* env, jobject obj);
}

#endif