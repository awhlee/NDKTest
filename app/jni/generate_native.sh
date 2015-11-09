echo Starting Native Generation
cd ~/dev/src/NDKTest/app/src/main/java 
javah -d ~/dev/src/NDKTest/app/jni/ com.example.alee.ndktest.NdkTest
cd ~/dev/src/NDKTest/app/jni
mv com_example_alee_ndktest_NdkTest.h NativeObj.h
echo Done Native Generation, now implement placeholders...
