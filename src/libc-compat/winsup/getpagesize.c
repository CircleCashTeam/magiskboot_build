/*
 * Look like this maybe only used in boot.cpp at magiskboot
 * So we just use a very simple way to get system pagesize 
 * on windows.
 */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "../include/winsup/getpagesize_compat.h"

/*
 * I hope this will work on windows
 */
int32_t getpagesize() {
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);

    return systemInfo.dwPageSize;
}