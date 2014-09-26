// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once




#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�:
#include <windows.h>
#include <windows.h>
#include <objbase.h>
#include <vector>
#include <string>
#include <map>
#include <windows.h>
#include <commctrl.h>
#include <tchar.h>
#include <shlwapi.h>
#include <list>


// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


#include "..\..\DuiLib\UIlib.h"

#ifndef NO_USING_DUILIB_NAMESPACE
using namespace DuiLib;
using namespace std;
#endif

#include "debug.h"


#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "..\\..\\Lib\\DuiLib_ud.lib")
#   else
#       pragma comment(lib, "..\\..\\Lib\\DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "..\\..\\Lib\\DuiLib_u.lib")
#   else
#       pragma comment(lib, "..\\..\\Lib\\DuiLib.lib")
#   endif
#endif

#define MESSAGE_RICHEDIT_MAX  1024

