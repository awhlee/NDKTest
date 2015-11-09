#include "NativeObj.h"
#include <stdio.h>
#include <stdlib.h>

#define _T(A) (unsigned short)L##A

char *global_string;

/** 
 * Create and return a Java string back to caller
 */

JNIEXPORT jstring JNICALL Java_com_example_alee_ndktest_NdkTest_getNativeString(
        JNIEnv *pEnv, jobject pThis)
{
    if (!global_string) {
        return (*pEnv)->NewStringUTF(pEnv, "Hello from native code!");
    }
    return (*pEnv)->NewStringUTF(pEnv, global_string);
}

/**
 * Create and return a Java string back to caller
 */
JNIEXPORT jstring JNICALL Java_com_example_alee_ndktest_NdkTest_getAnotherNativeString(
        JNIEnv *pEnv, jobject pThis)
{
    return (*pEnv)->NewStringUTF(pEnv, "Booyah! from native code!");
}

JNIEXPORT void JNICALL Java_com_example_alee_ndktest_NdkTest_setNativeString
(JNIEnv *pEnv, jobject pThis, jstring theString) {
    if (global_string) {
        free(global_string);
    }

    const char *tempString = (*pEnv)->GetStringUTFChars(pEnv, theString, 0);
    int numChars = strlen(tempString);
    global_string = malloc(numChars + 1);
    strcpy(global_string, tempString);

    // Cleanup some references
    (*pEnv)->ReleaseStringUTFChars(pEnv, theString, tempString);

    return;
}

/*
 * Class:     com_example_alee_ndktest_NdkTest
 * Method:    getString
 * Signature: (Lcom/example/alee/ndktest/TestClass;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_alee_ndktest_NdkTest_getString
        (JNIEnv *pEnv, jobject pThis, jobject testClass) {

    // In this function we want to invoke getString on the testClass object.

    // Get a reference to the class for TestClass
    jclass cls = (*pEnv)->GetObjectClass(pEnv, testClass);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return (*pEnv)->NewStringUTF(pEnv, "Could not find TestClass");;
    }

    // Find the getString method.
    jmethodID getStringMethod = (*pEnv)->GetMethodID(pEnv, cls, "getString",
             "()Ljava/lang/String;");
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return (*pEnv)->NewStringUTF(pEnv, "Could not find TestClass.getString()");;
    }

    // Invoke the method on our [in] object.
    jstring jstr = (jstring)(*pEnv)->CallObjectMethod(pEnv, testClass, getStringMethod);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return (*pEnv)->NewStringUTF(pEnv, "Could not call the method");
    }

    if (jstr == NULL) {
        return (*pEnv)->NewStringUTF(pEnv, "getString() returned NULL");
    }

    // Grab the string and return a new string to the caller.
    // TODO: Can we just return the one that we got from CallObjectMethod?
    const char* cstr = (*pEnv)->GetStringUTFChars(pEnv, jstr, 0);
    jstring returnValue = (*pEnv)->NewStringUTF(pEnv, cstr);

    // Cleanup some references
    (*pEnv)->ReleaseStringUTFChars(pEnv, jstr, cstr);
    (*pEnv)->DeleteLocalRef(pEnv, jstr);

    return returnValue;
}

/*
 * Class:     com_example_alee_ndktest_NdkTest
 * Method:    setString
 * Signature: (Lcom/example/alee/ndktest/TestClass;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_example_alee_ndktest_NdkTest_setString
        (JNIEnv *pEnv, jobject pThis, jobject testClass, jstring theString) {
    // In this function we want to call the setString() method on the test class
    // With the string that was passed in.

    // Get a reference to the class for TestClass
    jclass cls = (*pEnv)->GetObjectClass(pEnv, testClass);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return;
    }

    // Find the setString method.
    jmethodID setStringMethod = (*pEnv)->GetMethodID(pEnv, cls, "setString",
             "(Ljava/lang/String;)V");
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return;
    }

    // Invoke the method
    (*pEnv)->CallVoidMethod(pEnv, testClass, setStringMethod, theString);
    return;
}

/*
 * Class:     com_example_alee_ndktest_NdkTest
 * Method:    getInteger
 * Signature: (Lcom/example/alee/ndktest/TestClass;)I
 */
JNIEXPORT jint JNICALL Java_com_example_alee_ndktest_NdkTest_getInteger
        (JNIEnv *pEnv, jobject pThis, jobject testClass) {

    // In this function we want to invoke getInteger on the testClass object.

    // Get a reference to the class for TestClass
    jclass cls = (*pEnv)->GetObjectClass(pEnv, testClass);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return -1;
    }

    // Find the setInteger method.
    jmethodID getIntegerMethod = (*pEnv)->GetMethodID(pEnv, cls, "getInteger", "()I");
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return -1;
    }

    // Invoke the method on our [in] object.
    jint returnInteger = (jint)(*pEnv)->CallIntMethod(pEnv, testClass, getIntegerMethod);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return -1;
    }

    return returnInteger;
}

/*
 * Class:     com_example_alee_ndktest_NdkTest
 * Method:    setInteger
 * Signature: (Lcom/example/alee/ndktest/TestClass;I)V
 */
JNIEXPORT void JNICALL Java_com_example_alee_ndktest_NdkTest_setInteger
        (JNIEnv *pEnv, jobject pThis, jobject testClass, jint theInt) {
    // In this function we want to call the setString() method on the test class
    // With the string that was passed in.

    // Get a reference to the class for TestClass
    jclass cls = (*pEnv)->GetObjectClass(pEnv, testClass);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return;
    }

    // Find the setString method.
    jmethodID setIntegerMethod = (*pEnv)->GetMethodID(pEnv, cls, "setInteger", "(I)V");
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return;
    }

    // Invoke the method
    (*pEnv)->CallVoidMethod(pEnv, testClass, setIntegerMethod, theInt);
    return;
}

/*
 * Class:     com_example_alee_ndktest_NdkTest
 * Method:    getString2
 * Signature: (Lcom/example/alee/ndktest/TestClass;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_alee_ndktest_NdkTest_getString2
        (JNIEnv *pEnv, jobject pThis, jobject testClass) {

    // In this function we want to invoke getString on the testClass's mInner object.

    // Get a reference to the class for TestClass
    jclass outerClass = (*pEnv)->GetObjectClass(pEnv, testClass);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return (*pEnv)->NewStringUTF(pEnv, "Could not find TestClass");
    }

    jfieldID fid = (*pEnv)->GetFieldID(pEnv, outerClass, "mInner",
          "Lcom/example/alee/ndktest/TestClass$InnerTestClass;");
    if (fid == NULL) {
        return (*pEnv)->NewStringUTF(pEnv, "Could not find TestClass$InnerTestClass");
    }

    jobject innerObj = (*pEnv)->GetObjectField(pEnv, testClass, fid);
    if (innerObj == NULL) {
        return (*pEnv)->NewStringUTF(pEnv, "Could not get TestClass$InnerTestClass instance");
    }

    // Now get the class object for the inner class
    jclass innerCls = (*pEnv)->GetObjectClass(pEnv, innerObj);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return (*pEnv)->NewStringUTF(pEnv, "Could not find InnerTestClass");
    }

    // Find the getString method.
    jmethodID getStringMethod = (*pEnv)->GetMethodID(pEnv, innerCls, "getString2",
                                                     "()Ljava/lang/String;");
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return (*pEnv)->NewStringUTF(pEnv, "Could not find InnerTestClass.getString2()");
    }

    // Invoke the method on our [in] object.
    jstring jstr = (jstring)(*pEnv)->CallObjectMethod(pEnv, innerObj, getStringMethod);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return (*pEnv)->NewStringUTF(pEnv, "Could not call the method");
    }

    if (jstr == NULL) {
        return (*pEnv)->NewStringUTF(pEnv, "getString2() returned NULL");
    }

    // Grab the string and return a new string to the caller.
    // TODO: Can we just return the one that we got from CallObjectMethod?
    const char* cstr = (*pEnv)->GetStringUTFChars(pEnv, jstr, 0);
    jstring returnValue = (*pEnv)->NewStringUTF(pEnv, cstr);

    // Cleanup some references
    (*pEnv)->ReleaseStringUTFChars(pEnv, jstr, cstr);
    (*pEnv)->DeleteLocalRef(pEnv, jstr);

    return returnValue;
}

/*
 * Class:     com_example_alee_ndktest_NdkTest
 * Method:    setString2
 * Signature: (Lcom/example/alee/ndktest/TestClass;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_example_alee_ndktest_NdkTest_setString2
        (JNIEnv *pEnv, jobject pThis, jobject testClass, jstring theString) {

// In this function we want to invoke setString on the testClass's mInner object.

    // Get a reference to the class for TestClass
    jclass outerClass = (*pEnv)->GetObjectClass(pEnv, testClass);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return;
    }

    jfieldID fid = (*pEnv)->GetFieldID(pEnv, outerClass, "mInner",
                                       "Lcom/example/alee/ndktest/TestClass$InnerTestClass;");
    if (fid == NULL) {
        return;
    }

    jobject innerObj = (*pEnv)->GetObjectField(pEnv, testClass, fid);
    if (innerObj == NULL) {
        return;
    }

    // Now get the class object for the inner class
    jclass innerCls = (*pEnv)->GetObjectClass(pEnv, innerObj);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return;
    }

    // Find the setString method.
    jmethodID setStringMethod = (*pEnv)->GetMethodID(pEnv, innerCls, "setString2",
                                                     "(Ljava/lang/String;)V");
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return;
    }

    // Invoke the method
    (*pEnv)->CallVoidMethod(pEnv, innerObj, setStringMethod, theString);
    return;
}

/*
 * Class:     com_example_alee_ndktest_NdkTest
 * Method:    getInteger2
 * Signature: (Lcom/example/alee/ndktest/TestClass;)I
 */
JNIEXPORT jint JNICALL Java_com_example_alee_ndktest_NdkTest_getInteger2
        (JNIEnv *pEnv, jobject pThis, jobject testClass) {

    // In this function we want to invoke getInteger on the testClass object.

    // Get a reference to the class for TestClass
    jclass outerClass = (*pEnv)->GetObjectClass(pEnv, testClass);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return -1;
    }

    jfieldID fid = (*pEnv)->GetFieldID(pEnv, outerClass, "mInner",
                                       "Lcom/example/alee/ndktest/TestClass$InnerTestClass;");
    if (fid == NULL) {
        return -1;
    }

    jobject innerObj = (*pEnv)->GetObjectField(pEnv, testClass, fid);
    if (innerObj == NULL) {
        return -1;
    }

    // Now get the class object for the inner class
    jclass innerCls = (*pEnv)->GetObjectClass(pEnv, innerObj);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return -1;
    }

    // Find the setInteger method.
    jmethodID getIntegerMethod = (*pEnv)->GetMethodID(pEnv, innerCls, "getInteger2", "()I");
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return -1;
    }

    // Invoke the method on our [in] object.
    jint returnInteger = (jint)(*pEnv)->CallIntMethod(pEnv, innerObj, getIntegerMethod);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return -1;
    }

    return returnInteger;
}

/*
 * Class:     com_example_alee_ndktest_NdkTest
 * Method:    setInteger2
 * Signature: (Lcom/example/alee/ndktest/TestClass;I)V
 */
JNIEXPORT void JNICALL Java_com_example_alee_ndktest_NdkTest_setInteger2
        (JNIEnv *pEnv, jobject pThis, jobject testClass, jint theInt) {

    // In this function we want to invoke getInteger on the testClass object.

    // Get a reference to the class for TestClass
    jclass outerClass = (*pEnv)->GetObjectClass(pEnv, testClass);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return;
    }

    jfieldID fid = (*pEnv)->GetFieldID(pEnv, outerClass, "mInner",
                                       "Lcom/example/alee/ndktest/TestClass$InnerTestClass;");
    if (fid == NULL) {
        return;
    }

    jobject innerObj = (*pEnv)->GetObjectField(pEnv, testClass, fid);
    if (innerObj == NULL) {
        return;
    }

    // Now get the class object for the inner class
    jclass innerCls = (*pEnv)->GetObjectClass(pEnv, innerObj);
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return;
    }

    // Find the setString method.
    jmethodID setIntegerMethod = (*pEnv)->GetMethodID(pEnv, innerCls, "setInteger2", "(I)V");
    if ((*pEnv)->ExceptionCheck(pEnv)) {
        return;
    }

    // Invoke the method
    (*pEnv)->CallVoidMethod(pEnv, innerObj, setIntegerMethod, theInt);
    return;
}
