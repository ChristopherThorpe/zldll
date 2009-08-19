zugslist_dll:
	c:\MinGW\bin\gcc.exe -shared zugslist_dll.c -o zugslist_dll.dll
zugslist_user:
	c:\MinGW\bin\gcc.exe use_zugslist_dll.c zugslist_dll.dll -o use_zugslist_dll
clean:
	if exist zugslist_dll.dll del zugslist_dll.dll
	if exist use_zugslist_dll.exe del use_zugslist_dll.exe
all: clean zugslist_dll zugslist_user