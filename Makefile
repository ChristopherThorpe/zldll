zugslist_jni_dll:
	c:\MinGW\bin\gcc.exe -o zugslist_jni.dll -shared -Wall -D_JNI_IMPLEMENTATION_ -Wl,--kill-at -I"c:\Program Files\Java\jdk1.5.0_20\include" -I"c:\Program Files\Java\jdk1.5.0_20\include\win32" zugslist_jni_dll.c -static
zugslist_dll:
	c:\MinGW\bin\gcc.exe -shared zugslist_dll.c -o zugslist_dll.dll
zugslist_user:
	c:\MinGW\bin\gcc.exe use_zugslist_dll.c zugslist_dll.dll -o use_zugslist_dll
clean:
	if exist zugslist_dll.dll del zugslist_dll.dll
	if exist zugslist_jni.dll del zugslist_jni.dll
	if exist use_zugslist_dll.exe del use_zugslist_dll.exe
all: clean zugslist_dll zugslist_user
jni: clean zugslist_jni_dll