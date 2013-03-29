package com.linguofeng.jnitest;

public class Main {

    static {
        System.loadLibrary("random");
    }

    public static void main(String[] args) {
        System.out.println("Hello World!!");

        JNI jni = new JNI();
        jni.echo("call c++");
    }
}
