/******************************************************************************/
/**
@(#)$Id: LogicalDeal.cpp 26 2014-12-26 06:59:32Z arvinchen $
* @(#)
*
* (c)  XIAOTING PRIVATE PERSON  2014
* All Rights Reserved.
*/

/**
@brief  输出日志信息
@Author $Author: arvinchen $
@Date $Date: 2014-12-26 14:59:32 +0800 (鍛ㄤ簲, 26 鍗佷簩鏈?2014) $
@Revision $Revision: 26 $
@URL $URL: http://code.taobao.org/svn/coctest/trunk/LogicalDeal/LogicalDeal.cpp $
@Header $Header: http://code.taobao.org/svn/coctest/trunk/LogicalDeal/LogicalDeal.cpp 26 2014-12-26 06:59:32Z arvinchen $
*/
/******************************************************************************/

/******************************************************************************
1, 使用简单方便.只有一个头文件logfile.h include后,直接调用函数即可
2, VC6,VC7(VS2008) 兼容VC版本
3, 可输出文件名及行号
4, 支持多线程应用

例如:
在cpp源代码文件中只要#include "logfile.h"后，就可以直接调用以下函数输出日志信息

Logout("I am Logout \r\n");
Logflout(AT"I am LogfloutAT \r\n");
Loglevelout(3,"I am Loglevelout");

CString test = " i am  wangxiaoding!";
int n = 8;
Logout("CString = %s \r\n",test);
Logout("Intnumber = %d \r\n",n);


******************************************************************************/

//防止多次include头文件
#if !defined(AFX_LOGFILE_H__EF4BC4B2_3BB6_46E8_B936_0F3A61E20BF0__INCLUDED_)
#define AFX_LOGFILE_H__EF4BC4B2_3BB6_46E8_B936_0F3A61E20BF0__INCLUDED_

#pragma once
#pragma warning (disable:4996)	//取消警告
#include <direct.h>

//-----------------------------------------------------------------------------

// Debug版本宏1
//xiaoting
//#if _DEBUG
#ifndef _FLAG_OUTLOG_ENABLE
#define _FLAG_OUTLOG_ENABLE TRUE
#endif // _FLAG_OUTLOG_ENABLE
//#endif // _DEBUG

// 设置控制台宏2
#ifndef _FLAG_OUTLOG_ENABLE
#define _DEBUGCONSOLE
#endif // _FLAG_OUTLOG_ENABLE

// 设置文件名宏3
//#define  _SETFILENAME
#ifdef _SETFILENAME
#define  FILENAME "log.txt"
#endif //_SETFILENAME

// 设置等级宏4
#define  _LOGLEVEL
#ifdef _LOGLEVEL
#define MIN_LEVEL 1
#define MAX_LEVEL 5
#endif // _LOGLEVEL

//-----------------------------------------------------------------------------

#include <windows.h>
#include <stdio.h> 
#include <stdarg.h>
#include <io.h>

enum LOG_TYPE
{
	LOG_USER,
	LOG_IFTEST,
	LOG_LOGCALTEST,
};

enum OUTPUT_TYPE
{
	OUTPUT_NULL = 0x0000,
	OUTPUT_CONSOLE = 0x0001,
	OUTPUT_TXT = 0x0002,
	OUTPUT_MIXED = 0x0003,
};

enum TXT_COLOR {    
	DARKBLUE = 1, 
	DARKGREEN, 
	DARKTEAL, 
	DARKRED, 
	DARKPINK, 
	DARKYELLOW, 
	GRAY, 
	DARKGRAY, 
	BLUE, 
	GREEN, 
	TEAL, 
	RED, 
	PINK, 
	YELLOW, 
	WHITE 
};

// 日志输出类，静态版
struct CLog
{    

	// 取进程执行文件名称
	static void GetProcessFileName(char* lpName)
	{
		if ( ::GetModuleFileNameA(NULL, lpName, MAX_PATH) > 0)
		{
			char* pBegin = lpName;
			char* pTemp  = lpName;
			while ( *pTemp != 0 )
			{
				if ( *pTemp == '\\' )
				{
					pBegin = pTemp + 1;
				}
				pTemp++;
			}

			memcpy(lpName, pBegin, strlen(pBegin)+1);
		}

	}

	static void ConsoleOutput(char* msg, TXT_COLOR eColor)
	{
		static BOOL bOpenConsole = FALSE;

		if (!bOpenConsole)
		{
			bOpenConsole = ::AllocConsole();
			if (bOpenConsole)
			{
				freopen("CONOUT$","w+t",stdout);  
				freopen("CONIN$","r+t",stdin);
				freopen("CONERR", "w", stderr);

				SetConsoleTitle("DebugCosole");


				HWND hwnd=NULL; 
				while(NULL==hwnd) 
					hwnd=::FindWindow(NULL,(LPCTSTR)"DebugCosole"); 

				HMENU hmenu = ::GetSystemMenu ( hwnd, FALSE ); 
				DeleteMenu ( hmenu, SC_CLOSE, MF_BYCOMMAND );
			}
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), eColor);
		printf("%s", msg);
	}
	static void WriteFiles(char* msg, DWORD dLen)
	{
		FILE *pFile;

		//获取日志文件名
		//当前时间
		SYSTEMTIME st;
		::GetLocalTime(&st);

		char szFileName[MAX_PATH];
		char szExeName[MAX_PATH];
		GetProcessFileName(szExeName);
		sprintf(szFileName, "Log(%s)%d-%d-%d.txt", szExeName, //sprintf_s MAX_PATH
			st.wYear, st.wMonth, st.wDay);

		//创建日志文件. 有文件时追加方式打开,没有时创建.
		if (access(szFileName, 0) != -1)
		{						
			pFile = fopen(szFileName,"at");
		}
		else
		{
			pFile = fopen(szFileName,"wt");
		}	

		if (NULL == pFile)
		{
			printf("::CreateFile Error");
			exit(1);
		}

		//向文件写数据 
		fwrite (msg,            //要输入的文字
			1,              //文字每一项的大小 以为这里是字符型的 就设置为1 如果是汉字就设置为4
			dLen,           //单元个数 我们也可以直接写5
			pFile);         //我们刚刚获得到的地址

		fclose(pFile);
	}
	// 输出到文件
	// lpFile   : 源文件名
	// nLine    : 源文件行号
	// lpFormat : 输出的内容
	static void Logout(OUTPUT_TYPE eType, TXT_COLOR eColor,LPCSTR lpFormat, ...)
	{
		static CRITICAL_SECTION  m_crit;
		if (m_crit.DebugInfo==NULL)
			::InitializeCriticalSection(&m_crit); 
		/*-----------------------进入临界区(输出信息)------------------------------*/   
		::EnterCriticalSection(&m_crit);   

		if ( NULL == lpFormat )
			return;

		//当前时间
		SYSTEMTIME st;
		::GetLocalTime(&st);

		//设置消息头
		const DWORD BufSize = 2048;
		char szMsg[BufSize];

		sprintf(szMsg, "[%02d:%02d:%02d.%03d]", st.wHour, st.wMinute, st.wSecond,st.wMilliseconds);

		//格式化消息,并完善整条消息
		char* pTemp = szMsg;
		pTemp += strlen(szMsg);
		va_list args; 
		va_start(args, lpFormat);    
		wvsprintfA(pTemp,  lpFormat, args);	 //vsprintf_s BufSize - strlen(szMsg),
		va_end(args);  

		DWORD dwMsgLen = (DWORD)strlen(szMsg);

		// 判断文件名称是否相同,句柄是否有效.
		// 如果不同或无效,则关闭当前文件,创建新文件

		switch (eType)
		{
		case OUTPUT_NULL:
			{
				FreeConsole();
			}			
			break;
		case OUTPUT_CONSOLE:
			{
				ConsoleOutput(szMsg, eColor);
			}	
			break;
		case OUTPUT_TXT:
			{
				WriteFiles(szMsg, dwMsgLen);
			}	
			break;
		case OUTPUT_MIXED:
			{
				ConsoleOutput(szMsg, eColor);
				WriteFiles(szMsg, dwMsgLen);
			}
			break;
		default:
			break;
		}
		::LeaveCriticalSection(&m_crit);    
		/*----------------------------退出临界区---------------------------------*/	
	}

	// 输出到文件
	// lpFile   : 源文件名
	// nLine    : 源文件行号
	// lpFormat : 输出的内容
	static void logout(LPCSTR lpFile, int nLine,LPCSTR lpFormat, ...)
	{
		static CRITICAL_SECTION  m_crit;
		if (m_crit.DebugInfo==NULL)
			::InitializeCriticalSection(&m_crit); 
		/*-----------------------进入临界区(输出信息)------------------------------*/   
		::EnterCriticalSection(&m_crit);  

		if ( NULL == lpFormat )
			return;

		//当前时间
		SYSTEMTIME st;
		::GetLocalTime(&st);

		//设置消息头
		const DWORD BufSize = 2048;
		char szMsg[BufSize];

		if (nLine==0)
		{ 
			//当nLine==0 时,即Logout("xxx")只打印信息
			sprintf(szMsg, "[%02d:%02d:%02d.%03d]:", 
				st.wHour, st.wMinute, st.wSecond, 
				st.wMilliseconds);
		}
		else
		{
			//当nLine不等于0 时,即Logflout(AT"xxx")打印文件名行号及信息
			sprintf(szMsg, "[%02d:%02d:%02d.%03d]文件%s第%04d行:", 
				st.wHour, st.wMinute, st.wSecond, 
				st.wMilliseconds, lpFile, nLine);

		}

		//格式化消息,并完善整条消息
		char* pTemp = szMsg;
		pTemp += strlen(szMsg);
		va_list args; 
		va_start(args, lpFormat);    
		wvsprintfA(pTemp,  lpFormat, args);  //vsprintf_s BufSize - strlen(szMsg),
		va_end(args); 

		DWORD dwMsgLen = (DWORD)strlen(szMsg);

		//获取日志文件名
		char szFileName[MAX_PATH];
		char szExeName[MAX_PATH];
		GetProcessFileName(szExeName);  
		_mkdir("日志");
		sprintf(szFileName, "日志\\Log(%s)%d-%d-%d.txt", szExeName, //sprintf_s MAX_PATH
			st.wYear, st.wMonth, st.wDay);

		// 判断文件名称是否相同,句柄是否有效.
		// 如果不同或无效,则关闭当前文件,创建新文件
		static char   s_szFileName[MAX_PATH] = {0};
		static HANDLE s_hFile = INVALID_HANDLE_VALUE;

		//设置自定义日志文件名
#ifdef _SETFILENAME
		strcpy(szFileName,FILENAME);
#endif //_SETFILENAME

		BOOL bNew = ((strcmp(s_szFileName, szFileName) != 0) || (s_hFile == INVALID_HANDLE_VALUE));


//#ifdef _DEBUGCONSOLE //控制台输出
		static BOOL bOpenConsole = FALSE;
		if (!bOpenConsole)
		{
			bOpenConsole = ::AllocConsole();
			if (bOpenConsole)
			{
				freopen("CONOUT$","w+t",stdout);  
				freopen("CONIN$","r+t",stdin);
				freopen("CONERR", "w", stderr);

				HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE); 
				SetConsoleTitle(_T("DebugCosole"));
				SetConsoleTextAttribute((HANDLE)handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

				HWND hwnd=NULL; 
				while(NULL==hwnd) 
					hwnd=::FindWindow(NULL,(LPCTSTR)_T("DebugCosole")); 

				HMENU hmenu = ::GetSystemMenu ( hwnd, FALSE ); 
				DeleteMenu ( hmenu, SC_CLOSE, MF_BYCOMMAND );
			}
		}
// 		if (true == SettingIF::Instance()->GetLogModel()) {
// 			if (!bOpenConsole)
// 			{
// 				bOpenConsole = ::AllocConsole();
// 				if (bOpenConsole)
// 				{
// 					freopen("CONOUT$","w+t",stdout);  
// 					freopen("CONIN$","r+t",stdin);
// 					freopen("CONERR", "w", stderr);
// 
// 					HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE); 
// 					SetConsoleTitle(_T("DebugCosole"));
// 					SetConsoleTextAttribute((HANDLE)handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
// 
// 					HWND hwnd=NULL; 
// 					while(NULL==hwnd) 
// 						hwnd=::FindWindow(NULL,(LPCTSTR)_T("DebugCosole")); 
// 
// 					HMENU hmenu = ::GetSystemMenu ( hwnd, FALSE ); 
// 					DeleteMenu ( hmenu, SC_CLOSE, MF_BYCOMMAND );
// 				}
// 			}
// 		}
// 		else {
// 			bOpenConsole = false;
// 			::FreeConsole();
//		}
//#endif //_DEBUGCONSOLE

		printf("%s", szMsg);

		if ( bNew ) // 关闭旧文件，创建新文件
		{
			if ( s_hFile != INVALID_HANDLE_VALUE)
			{
				::CloseHandle(s_hFile);
				s_hFile = INVALID_HANDLE_VALUE;
			}

			//创建日志文件. 有文件时追加方式打开,没有时创建.
			s_hFile = ::CreateFileA( szFileName, 
				GENERIC_WRITE, 
				FILE_SHARE_WRITE | FILE_SHARE_READ, 
				0, 
				OPEN_ALWAYS, 
				FILE_ATTRIBUTE_NORMAL, 
				0);

			if ( s_hFile == INVALID_HANDLE_VALUE)
			{
				printf("::CreateFile Error: %d", ::GetLastError());
				return;
			}
		}



		//把消息写到文件
		if ( s_hFile != INVALID_HANDLE_VALUE) 
		{
			DWORD dwWrite = 0;
			::SetFilePointer(s_hFile, 0, NULL, FILE_END);
			::WriteFile(s_hFile, szMsg, dwMsgLen, &dwWrite, NULL);

			//备份创建成功的新文件名
			strcpy(s_szFileName,szFileName);
		}

		::LeaveCriticalSection(&m_crit);    
		/*----------------------------退出临界区---------------------------------*/
	}

}; // CLog


//宏定义文件名和行号
#define AT __FILE__, __LINE__,



#if (_FLAG_OUTLOG_ENABLE)
static void SetOutputType(int x=2,int y=4)
{
	CLog::Logout(OUTPUT_CONSOLE, YELLOW,"x+y= %d", x+y);
}

//日志输出接口函数1
static void Logout(LOG_TYPE eLogType, LPCSTR lpFormat, ...)
{
	const DWORD BufSize = 2048;
	char szMsg[BufSize];

	va_list args;  //格式化消息

	va_start(args, lpFormat);    
	wvsprintfA(szMsg,  lpFormat, args);  //vsprintf_s BufSize - strlen(szMsg),
	va_end(args);  

	//输出信息
	CLog::logout("0",0,szMsg);
}

//日志输出接口函数2  使用于logflout(AT"xxxx")形式 
//(LPCSTR lpFile, int nLine)有时适配这个函数名,所以修改函数名 fl = file and line
static void Logflout(LPCSTR lpFile, int nLine,LPCSTR lpFormat, ...)
{
	const DWORD BufSize = 2048;
	char szMsg[BufSize];

	char* pTemp = szMsg;

	va_list args; //格式化消息

	va_start(args, lpFormat);    
	wvsprintfA(szMsg,  lpFormat, args);  //vsprintf_s BufSize - strlen(szMsg),
	va_end(args);  

	//输出有文件名及行号的消息
	CLog::logout(lpFile, nLine,szMsg);
}

#ifdef _LOGLEVEL
//日志输出接口函数3
static void Loglevelout(int nshowlevel,LPCSTR lpFormat, ...)
{

#ifdef _SETFILENAME
	if (MIN_LEVEL<=nshowlevel && nshowlevel<= MAX_LEVEL)
#endif
	{
		const DWORD BufSize = 2048;
		char szMsg[BufSize];

		va_list args;  //格式化消息

		va_start(args, lpFormat);    
		wvsprintfA(szMsg,  lpFormat, args);  //vsprintf_s BufSize - strlen(szMsg),
		va_end(args);  

		char buffer[20];
		_itoa(nshowlevel, buffer, 10 );
		strcat(szMsg,"......Level=");
		strcat(szMsg,buffer);
		strcat(szMsg,"\r\n");

		//输出信息
		CLog::logout("0",0,szMsg);
	}

}
#endif //_LOGLEVEL

#ifdef _DEBUGCONSOLE
//关闭控制台接口函数4 
static void Logconsole_close()
{
	FreeConsole();
}

//隐藏或显示控制台接口函数5
static void Logcconsole_win(BOOL pSHWinConsole = FALSE)
{
	static BOOL bGetWinConsole = FALSE;
	HWND wincmd = NULL;

	if (!bGetWinConsole)
	{
		typedef HWND (WINAPI *PROCGETCONSOLEWINDOW)();
		PROCGETCONSOLEWINDOW GetConsoleWindow;

		HMODULE hKernel32 = GetModuleHandle(_T("kernel32"));
		GetConsoleWindow = (PROCGETCONSOLEWINDOW)GetProcAddress(hKernel32,"GetConsoleWindow");

		wincmd=GetConsoleWindow();
	}
	if (pSHWinConsole)
	{
		ShowWindowAsync(wincmd, SW_SHOWNORMAL);
	}
	else
	{
		ShowWindowAsync(wincmd, SW_HIDE );
	}
}
#endif //_DEBUGCONSOLE

#else  //_FLAG_OUTLOG_ENABLE

//日志输出接口函数1 空 用于Release版本
static void Logout(LOG_TYPE eLogType, LPCSTR lpFormat, ...)
{
}
//日志输出接口函数2 空 用于Release版本
static void Logflout(LPCSTR lpFile, int nLine,LPCSTR lpFormat, ...)
{
}

#ifdef _LOGLEVEL
//日志输出接口函数3 空 用于Release版本
static void Loglevelout(int nshowlevel,LPCSTR lpFormat, ...)
{
}
#endif //_LOGLEVEL

#ifdef _DEBUGCONSOLE
//关闭控制台接口函数4 空 用于Release版本
static void Logconsole_close()
{
}
//隐藏或显示控制台接口函数5 空 用于Release版本
static void Logcconsole_win(BOOL pSHWinConsole = FALSE)
{
}
#endif //_DEBUGCONSOLE

#endif //_FLAG_OUTLOG_ENABLE

#endif //!defined(AFX_LOGFILE_H__EF4BC4B2_3BB6_46E8_B936_0F3A61E20BF0__INCLUDED_)

/******************************************************************************
版本号: 3.
时间: 2013/5/16
为更方便书写，将函数名的首字母C去掉。如CLogout 更改为 Logout等
-----------------------------------------------------------------------------
版本号: 2.
时间: 2013/5/15
由于参数匹配有时混乱问题，所以修改函数名CLogout(LPCSTR lpFile, int nLine,LPCSTR lpFormat, ...)
为CLogflout(LPCSTR lpFile, int nLine,LPCSTR lpFormat, ...)
-----------------------------------------------------------------------------
版本号: 1.
时间: 2013/5/15
正常摘用
******************************************************************************/