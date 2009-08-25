#include <windows.h>
#include <winreg.h>
#include <stdlib.h>
#include <jni.h>

#include "Uploader.h"
#include "zugslist_dll.h"

int wow_install_root(char *buff, DWORD *buff_size) {
	HKEY wow_key;
	DWORD var_type = REG_SZ;
	LONG status;

	RegOpenKeyEx(
		HKEY_LOCAL_MACHINE,
		"Software\\Blizzard Entertainment\\World of Warcraft",
		0,
		KEY_READ,
		&wow_key
	);

	/* 
	   LONG WINAPI RegQueryValueEx(
		__in         HKEY hKey,
		__in_opt     LPCTSTR lpValueName,
		__reserved   LPDWORD lpReserved,
		__out_opt    LPDWORD lpType,
		__out_opt    LPBYTE lpData,
		__inout_opt  LPDWORD lpcbData
	   );
	*/
	
	status = RegQueryValueEx(wow_key, "InstallPath", NULL, &var_type, buff, buff_size);
	RegCloseKey (wow_key);
	
	return status;
}

JNIEXPORT jstring JNICALL Java_Uploader_getWoWPath(JNIEnv *jenv, jobject jobj) {
	DWORD buff_size = 6;
	char *buff = (char *)malloc(buff_size);
	jstring wow_path;
	LONG status;

	memset(buff, '\0',6);
	status = wow_install_root(buff, &buff_size);
	if( status == ERROR_MORE_DATA ) {
		buff = (char *)realloc((void *)buff, buff_size);
		status = wow_install_root(buff, &buff_size);
	}
	wow_path = (*jenv)->NewStringUTF(jenv,buff);
	free((void *)buff);
	return wow_path;
}
