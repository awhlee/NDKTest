package com.example.alee.ndktest;

import android.util.Log;

/**
 * Created by alee on 11/9/15.
 */
public class TestClass {
    private static final String LOG_TAG = "NDK_TEST";


    private int mInt = 0;
    private String mString = "default string";
    private InnerTestClass mInner = new InnerTestClass();

    public int getInteger() { return mInt; }
    public void setInteger(int incoming) { mInt = incoming; }
    public String getString() { return mString; }
    public void setString(String incoming) { mString = incoming; }

    public InnerTestClass getInner() { return mInner; }
    public void setInnerInteger(int incoming) { mInner.setInteger2(incoming); }
    public void setInnerString(String incoming) { mInner.setString2(incoming); }

    public void callback(String theString) {
        Log.i(LOG_TAG, "We are in the callback function: " + theString);
    }


    public static class InnerTestClass {
        private int mInt2 = 0;
        private String mString2 = "default string2";

        public int getInteger2() { return mInt2; }
        public void setInteger2(int incoming) { mInt2 = incoming; }
        public String getString2() { return mString2; }
        public void setString2(String incoming) { mString2 = incoming; }

        public void callback(String theString) {
            Log.i(LOG_TAG, "We are in the inner callback function: " + theString);
        }
    }

}
