#include <iostream>
#include "com_linguofeng_jnitest_JNI.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_com_linguofeng_jnitest_JNI_echo
  (JNIEnv *, jobject, jstring) {
    std::cout << "Java_com_linguofeng_jnitest_JNI_echo()\n";
}

JNIEXPORT void JNICALL Java_com_linguofeng_jnitest_JNI_add
  (JNIEnv *, jobject, jint, jint) {
    std::cout << "Java_com_linguofeng_jnitest_JNI_add()\n";
}

#ifdef __cplusplus
}
#endif
