jni test

===

### build

```bash
$ find ./src -name '*.java' > sources_list.txt
$ javac -d bin @sources_list.txt
$ javah -classpath bin -d jni/include -jni com.linguofeng.jnitest.JNI
$ g++ -c \
    -Ijni/include \
    -I/System/Library/Frameworks/JavaVM.framework/Headers \
    jni/src/com_linguofeng_jnitest_JNI.cpp jni/src/random.cpp
$ g++ \
    -dynamiclib \
    -framework JavaVM \
    -o libs/librandom.dylib \
    com_linguofeng_jnitest_JNI.o random.o 
$ java -classpath bin -Djava.library.path=libs com.linguofeng.jnitest.Main
```
