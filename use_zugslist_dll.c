#include <stdlib.h>
#include <windows.h>
#include "zugslist_dll.h"

int STDCALL WinMain (HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nShow) {
  DWORD buff_size = 6;
  char *buff = (char *)malloc(buff_size);
  LONG status = wow_install_root(buff, &buff_size);
  
  if( status == ERROR_MORE_DATA ) {
    buff = (char *)realloc((void *)buff, buff_size);
    status = wow_install_root(buff, &buff_size);
  }
  MessageBox (NULL, buff, "WoW install path", MB_OK);
  free((void *)buff);
}
