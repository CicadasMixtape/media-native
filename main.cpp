#include "main.h"
#include "media.h"

JNIEXPORT jstring JNICALL Java_cicadas_mixtape_supermiss_Native_d(JNIEnv* env, jobject obj) {
    return env->NewStringUTF(media::get_format().c_str());
}