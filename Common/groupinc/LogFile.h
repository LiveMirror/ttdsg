/******************************************************************************/
/**
@(#)$Id: LogicalDeal.cpp 26 2014-12-26 06:59:32Z arvinchen $
* @(#)
*
* (c)  XIAOTING PRIVATE PERSON  2014
* All Rights Reserved.
*/

/**
@brief  �����־��Ϣ
@Author $Author: arvinchen $
@Date $Date: 2014-12-26 14:59:32 +0800 (周五, 26 十二�?2014) $
@Revision $Revision: 26 $
@URL $URL: http://code.taobao.org/svn/coctest/trunk/LogicalDeal/LogicalDeal.cpp $
@Header $Header: http://code.taobao.org/svn/coctest/trunk/LogicalDeal/LogicalDeal.cpp 26 2014-12-26 06:59:32Z arvinchen $
*/
/******************************************************************************/

/******************************************************************************
1, ʹ�ü򵥷���.ֻ��һ��ͷ�ļ�logfile.h include��,ֱ�ӵ��ú�������
2, VC6,VC7(VS2008) ����VC�汾
3, ������ļ������к�
4, ֧�ֶ��߳�Ӧ��

����:
��cppԴ�����ļ���ֻҪ#include "logfile.h"�󣬾Ϳ���ֱ�ӵ������º��������־��Ϣ

Logout("I am Logout \r\n");
Logflout(AT"I am LogfloutAT \r\n");
Loglevelout(3,"I am Loglevelout");

CString test = " i am  wangxiaoding!";
int n = 8;
Logout("CString = %s \r\n",test);
Logout("Intnumber = %d \r\n",n);


******************************************************************************/

//��ֹ���includeͷ�ļ�
#if !defined(AFX_LOGFILE_H__EF4BC4B2_3BB6_46E8_B936_0F3A61E20BF0__INCLUDED_)
#define AFX_LOGFILE_H__EF4BC4B2_3BB6_46E8_B936_0F3A61E20BF0__INCLUDED_

#pragma once
#pragma warning (disable:4996)	//ȡ������
#include <direct.h>

//-----------------------------------------------------------------------------

// Debug�汾��1
//xiaoting
//#if _DEBUG
#ifndef _FLAG_OUTLOG_ENABLE
#define _FLAG_OUTLOG_ENABLE TRUE
#endif // _FLAG_OUTLOG_ENABLE
//#endif // _DEBUG

// ���ÿ���̨��2
#ifndef _FLAG_OUTLOG_ENABLE
#define _DEBUGCONSOLE
#endif // _FLAG_OUTLOG_ENABLE

// �����ļ�����3
//#define  _SETFILENAME
#ifdef _SETFILENAME
#define  FILENAME "log.txt"
#endif //_SETFILENAME

// ���õȼ���4
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

// ��־����࣬��̬��
struct CLog
{    

	// ȡ����ִ���ļ�����
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

		//��ȡ��־�ļ���
		//��ǰʱ��
		SYSTEMTIME st;
		::GetLocalTime(&st);

		char szFileName[MAX_PATH];
		char szExeName[MAX_PATH];
		GetProcessFileName(szExeName);
		sprintf(szFileName, "Log(%s)%d-%d-%d.txt", szExeName, //sprintf_s MAX_PATH
			st.wYear, st.wMonth, st.wDay);

		//������־�ļ�. ���ļ�ʱ׷�ӷ�ʽ��,û��ʱ����.
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

		//���ļ�д���� 
		fwrite (msg,            //Ҫ���������
			1,              //����ÿһ��Ĵ�С ��Ϊ�������ַ��͵� ������Ϊ1 ����Ǻ��־�����Ϊ4
			dLen,           //��Ԫ���� ����Ҳ����ֱ��д5
			pFile);         //���Ǹոջ�õ��ĵ�ַ

		fclose(pFile);
	}
	// ������ļ�
	// lpFile   : Դ�ļ���
	// nLine    : Դ�ļ��к�
	// lpFormat : ���������
	static void Logout(OUTPUT_TYPE eType, TXT_COLOR eColor,LPCSTR lpFormat, ...)
	{
		static CRITICAL_SECTION  m_crit;
		if (m_crit.DebugInfo==NULL)
			::InitializeCriticalSection(&m_crit); 
		/*-----------------------�����ٽ���(�����Ϣ)------------------------------*/   
		::EnterCriticalSection(&m_crit);   

		if ( NULL == lpFormat )
			return;

		//��ǰʱ��
		SYSTEMTIME st;
		::GetLocalTime(&st);

		//������Ϣͷ
		const DWORD BufSize = 2048;
		char szMsg[BufSize];

		sprintf(szMsg, "[%02d:%02d:%02d.%03d]", st.wHour, st.wMinute, st.wSecond,st.wMilliseconds);

		//��ʽ����Ϣ,������������Ϣ
		char* pTemp = szMsg;
		pTemp += strlen(szMsg);
		va_list args; 
		va_start(args, lpFormat);    
		wvsprintfA(pTemp,  lpFormat, args);	 //vsprintf_s BufSize - strlen(szMsg),
		va_end(args);  

		DWORD dwMsgLen = (DWORD)strlen(szMsg);

		// �ж��ļ������Ƿ���ͬ,����Ƿ���Ч.
		// �����ͬ����Ч,��رյ�ǰ�ļ�,�������ļ�

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
		/*----------------------------�˳��ٽ���---------------------------------*/	
	}

	// ������ļ�
	// lpFile   : Դ�ļ���
	// nLine    : Դ�ļ��к�
	// lpFormat : ���������
	static void logout(LPCSTR lpFile, int nLine,LPCSTR lpFormat, ...)
	{
		static CRITICAL_SECTION  m_crit;
		if (m_crit.DebugInfo==NULL)
			::InitializeCriticalSection(&m_crit); 
		/*-----------------------�����ٽ���(�����Ϣ)------------------------------*/   
		::EnterCriticalSection(&m_crit);  

		if ( NULL == lpFormat )
			return;

		//��ǰʱ��
		SYSTEMTIME st;
		::GetLocalTime(&st);

		//������Ϣͷ
		const DWORD BufSize = 2048;
		char szMsg[BufSize];

		if (nLine==0)
		{ 
			//��nLine==0 ʱ,��Logout("xxx")ֻ��ӡ��Ϣ
			sprintf(szMsg, "[%02d:%02d:%02d.%03d]:", 
				st.wHour, st.wMinute, st.wSecond, 
				st.wMilliseconds);
		}
		else
		{
			//��nLine������0 ʱ,��Logflout(AT"xxx")��ӡ�ļ����кż���Ϣ
			sprintf(szMsg, "[%02d:%02d:%02d.%03d]�ļ�%s��%04d��:", 
				st.wHour, st.wMinute, st.wSecond, 
				st.wMilliseconds, lpFile, nLine);

		}

		//��ʽ����Ϣ,������������Ϣ
		char* pTemp = szMsg;
		pTemp += strlen(szMsg);
		va_list args; 
		va_start(args, lpFormat);    
		wvsprintfA(pTemp,  lpFormat, args);  //vsprintf_s BufSize - strlen(szMsg),
		va_end(args); 

		DWORD dwMsgLen = (DWORD)strlen(szMsg);

		//��ȡ��־�ļ���
		char szFileName[MAX_PATH];
		char szExeName[MAX_PATH];
		GetProcessFileName(szExeName);  
		_mkdir("��־");
		sprintf(szFileName, "��־\\Log(%s)%d-%d-%d.txt", szExeName, //sprintf_s MAX_PATH
			st.wYear, st.wMonth, st.wDay);

		// �ж��ļ������Ƿ���ͬ,����Ƿ���Ч.
		// �����ͬ����Ч,��رյ�ǰ�ļ�,�������ļ�
		static char   s_szFileName[MAX_PATH] = {0};
		static HANDLE s_hFile = INVALID_HANDLE_VALUE;

		//�����Զ�����־�ļ���
#ifdef _SETFILENAME
		strcpy(szFileName,FILENAME);
#endif //_SETFILENAME

		BOOL bNew = ((strcmp(s_szFileName, szFileName) != 0) || (s_hFile == INVALID_HANDLE_VALUE));


//#ifdef _DEBUGCONSOLE //����̨���
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

		if ( bNew ) // �رվ��ļ����������ļ�
		{
			if ( s_hFile != INVALID_HANDLE_VALUE)
			{
				::CloseHandle(s_hFile);
				s_hFile = INVALID_HANDLE_VALUE;
			}

			//������־�ļ�. ���ļ�ʱ׷�ӷ�ʽ��,û��ʱ����.
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



		//����Ϣд���ļ�
		if ( s_hFile != INVALID_HANDLE_VALUE) 
		{
			DWORD dwWrite = 0;
			::SetFilePointer(s_hFile, 0, NULL, FILE_END);
			::WriteFile(s_hFile, szMsg, dwMsgLen, &dwWrite, NULL);

			//���ݴ����ɹ������ļ���
			strcpy(s_szFileName,szFileName);
		}

		::LeaveCriticalSection(&m_crit);    
		/*----------------------------�˳��ٽ���---------------------------------*/
	}

}; // CLog


//�궨���ļ������к�
#define AT __FILE__, __LINE__,



#if (_FLAG_OUTLOG_ENABLE)
static void SetOutputType(int x=2,int y=4)
{
	CLog::Logout(OUTPUT_CONSOLE, YELLOW,"x+y= %d", x+y);
}

//��־����ӿں���1
static void Logout(LOG_TYPE eLogType, LPCSTR lpFormat, ...)
{
	const DWORD BufSize = 2048;
	char szMsg[BufSize];

	va_list args;  //��ʽ����Ϣ

	va_start(args, lpFormat);    
	wvsprintfA(szMsg,  lpFormat, args);  //vsprintf_s BufSize - strlen(szMsg),
	va_end(args);  

	//�����Ϣ
	CLog::logout("0",0,szMsg);
}

//��־����ӿں���2  ʹ����logflout(AT"xxxx")��ʽ 
//(LPCSTR lpFile, int nLine)��ʱ�������������,�����޸ĺ����� fl = file and line
static void Logflout(LPCSTR lpFile, int nLine,LPCSTR lpFormat, ...)
{
	const DWORD BufSize = 2048;
	char szMsg[BufSize];

	char* pTemp = szMsg;

	va_list args; //��ʽ����Ϣ

	va_start(args, lpFormat);    
	wvsprintfA(szMsg,  lpFormat, args);  //vsprintf_s BufSize - strlen(szMsg),
	va_end(args);  

	//������ļ������кŵ���Ϣ
	CLog::logout(lpFile, nLine,szMsg);
}

#ifdef _LOGLEVEL
//��־����ӿں���3
static void Loglevelout(int nshowlevel,LPCSTR lpFormat, ...)
{

#ifdef _SETFILENAME
	if (MIN_LEVEL<=nshowlevel && nshowlevel<= MAX_LEVEL)
#endif
	{
		const DWORD BufSize = 2048;
		char szMsg[BufSize];

		va_list args;  //��ʽ����Ϣ

		va_start(args, lpFormat);    
		wvsprintfA(szMsg,  lpFormat, args);  //vsprintf_s BufSize - strlen(szMsg),
		va_end(args);  

		char buffer[20];
		_itoa(nshowlevel, buffer, 10 );
		strcat(szMsg,"......Level=");
		strcat(szMsg,buffer);
		strcat(szMsg,"\r\n");

		//�����Ϣ
		CLog::logout("0",0,szMsg);
	}

}
#endif //_LOGLEVEL

#ifdef _DEBUGCONSOLE
//�رտ���̨�ӿں���4 
static void Logconsole_close()
{
	FreeConsole();
}

//���ػ���ʾ����̨�ӿں���5
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

//��־����ӿں���1 �� ����Release�汾
static void Logout(LOG_TYPE eLogType, LPCSTR lpFormat, ...)
{
}
//��־����ӿں���2 �� ����Release�汾
static void Logflout(LPCSTR lpFile, int nLine,LPCSTR lpFormat, ...)
{
}

#ifdef _LOGLEVEL
//��־����ӿں���3 �� ����Release�汾
static void Loglevelout(int nshowlevel,LPCSTR lpFormat, ...)
{
}
#endif //_LOGLEVEL

#ifdef _DEBUGCONSOLE
//�رտ���̨�ӿں���4 �� ����Release�汾
static void Logconsole_close()
{
}
//���ػ���ʾ����̨�ӿں���5 �� ����Release�汾
static void Logcconsole_win(BOOL pSHWinConsole = FALSE)
{
}
#endif //_DEBUGCONSOLE

#endif //_FLAG_OUTLOG_ENABLE

#endif //!defined(AFX_LOGFILE_H__EF4BC4B2_3BB6_46E8_B936_0F3A61E20BF0__INCLUDED_)

/******************************************************************************
�汾��: 3.
ʱ��: 2013/5/16
Ϊ��������д����������������ĸCȥ������CLogout ����Ϊ Logout��
-----------------------------------------------------------------------------
�汾��: 2.
ʱ��: 2013/5/15
���ڲ���ƥ����ʱ�������⣬�����޸ĺ�����CLogout(LPCSTR lpFile, int nLine,LPCSTR lpFormat, ...)
ΪCLogflout(LPCSTR lpFile, int nLine,LPCSTR lpFormat, ...)
-----------------------------------------------------------------------------
�汾��: 1.
ʱ��: 2013/5/15
����ժ��
******************************************************************************/