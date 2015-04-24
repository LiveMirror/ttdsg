/**
  @(#)$Id$
  * @(#)
  *
  * (c)  XIAOTING PRIVATE PERSON  2014
  * All Rights Reserved.
  */

/**
  @brief   Plug-in (Plug-in, also known as addin, add-in, addon or add-on, also translated plug) is a follow certain standardized 
  application program interface to write out the procedure.

  @Author $Author$
  @Date $Date$
  @Revision $Revision$
  @URL $URL$
  @Header $Header$
 */

#ifndef CXX_AIDPLUGIDENTIFYIF_H
#define CXX_AIDPLUGIDENTIFYIF_H
#include "LogFile.h"
#include <vector>
using namespace std;

#ifndef CXX_AIDPLUG_H
#include "AidPlug.h"
#endif

#ifndef AIDPLUGLOGINIF_H
#include "AidPlugLoginIF.h"
#endif

class AidPlugIdentifyIF
{
public:
	__forceinline static AidPlugIdentifyIF* Instance(void) 
	{
		if (false == AidPlugLoginIF::Instance()->API_AntiCrack()) {
			//防破解，使用内联函数使验证代码随机多处进行验证，验证失败返回NULL，使程序崩溃
			return NULL;
		}
		if (NULL == s_pcInstance) {
			s_pcInstance = new AidPlugIdentifyIF;
		}
		return s_pcInstance;
	}
	static void Destroy();
private:
	AidPlugIdentifyIF();
	~AidPlugIdentifyIF();
private:

	// Attributes
public:

	// Operations
public:


	// Idmsoft methods
public:
	CString Ver()
	{
	    unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->Ver();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, cstrRet);
		return cstrRet;
	}
	long SetPath(LPCTSTR path)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetPath(path);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数:%s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, path, lRet);
		return lRet;
	}
	CString Ocr(long x1, long y1, long x2, long y2, LPCTSTR color, double sim)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->Ocr(x1, y1, x2, y2, color, sim);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %lf, 返回值:%s"),
			               __FUNCTION__, 
						   GetTickCount()-ulTickCount, 
						   x1, y1, x2, y2, color, sim,
						   cstrRet);
		return cstrRet;
	}
	long FindStr(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, long * lx, long * ly)
	{
		unsigned long ulTickCount = GetTickCount();		
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->FindStr(x1, y1, x2, y2, str, color, sim, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %s %lf %p %p, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, str, color, sim, lx,ly,
                           lRet);
		return lRet;
	}
	long GetResultCount(LPCTSTR str)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetResultCount(str);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数:%s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, str, lRet);
		return lRet;
	}
	long GetResultPos(LPCTSTR str, long index, long * lx, long * ly)
	{
		unsigned long ulTickCount = GetTickCount();		
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->GetResultPos(str, index, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%s %ld %p %p, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           str, index, lx,ly,
                           lRet);
		return lRet;
	}
	long StrStr(LPCTSTR s, LPCTSTR str)
	{
		unsigned long ulTickCount = GetTickCount();	
		long lRet = m_pPlugIdentify->StrStr(s, str); 
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数:%s %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, s, str, lRet);
		return lRet;
	}
	long SendCommand(LPCTSTR cmd)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SendCommand(cmd);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, cmd, lRet);
		return lRet;
	}
	long UseDict(long index)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->UseDict(index);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, index, lRet);
		return lRet;
	}
	CString GetBasePath()
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetBasePath();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, cstrRet);
		return cstrRet;
	}
	long SetDictPwd(LPCTSTR pwd)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetDictPwd(pwd);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, pwd, lRet);
		return lRet;
	}
	CString OcrInFile(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR color, double sim)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->OcrInFile(x1, y1, x2, y2, pic_name, color, sim);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %s %lf, 返回值:%s"),
			               __FUNCTION__, 
			               GetTickCount()-ulTickCount, 
			               x1, y1, x2, y2, pic_name, color, sim,
			               cstrRet);
		return cstrRet;
	}
	long Capture(long x1, long y1, long x2, long y2, LPCTSTR file)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->Capture(x1, y1, x2, y2, file);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, file,
                           lRet);
		return lRet;
	}
	long KeyPress(long vk)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->KeyPress(vk);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, vk, lRet);
		return lRet;
	}
	long KeyDown(long vk)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->KeyDown(vk);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, vk, lRet);
		return lRet;
	}
	long KeyUp(long vk)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->KeyUp(vk);
        Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, vk, lRet);
		return lRet;
	}
	long LeftClick()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->LeftClick();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}
	long RightClick()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->RightClick();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}
	long MiddleClick()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->MiddleClick();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}
	long LeftDoubleClick()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->LeftDoubleClick();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}
	long LeftDown()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->LeftDown();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}
	long LeftUp()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->LeftUp();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}
	long RightDown()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->RightDown();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}
	long RightUp()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->RightUp();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}
	long MoveTo(long x, long y)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->MoveTo(x, y);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, x, y, lRet);
		return lRet;
	}
	long MoveR(long rx, long ry)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->MoveR(rx, ry);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, rx, ry, lRet);
		return lRet;
	}
	CString GetColor(long x, long y)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetColor(x, y);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld %ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, x, y, cstrRet);
		return cstrRet;
	}
	CString GetColorBGR(long x, long y)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetColorBGR(x, y);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld %ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, x, y, cstrRet);
		return cstrRet;
	}
	CString RGB2BGR(LPCTSTR rgb_color)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->RGB2BGR(rgb_color);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, rgb_color, cstrRet);
		return cstrRet;
	}
	CString BGR2RGB(LPCTSTR bgr_color)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->BGR2RGB(bgr_color);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, bgr_color, cstrRet);
		return cstrRet;
	}
	long UnBindWindow()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->UnBindWindow();
		API_SetHwnd(0x00);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}
	long CmpColor(long x, long y, LPCTSTR color, double sim)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->CmpColor(x, y, color, sim);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %s %lf, 返回值:%ld"),
			               __FUNCTION__, 
			               GetTickCount()-ulTickCount, 
			               x, y, color, sim,
			               lRet);
		return lRet;
	}
	long ClientToScreen(long * lx, long * ly)
	{
		unsigned long ulTickCount = GetTickCount();	
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->ClientToScreen(m_hwnd, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %p %p, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, lx, ly, lRet);	
		return lRet;
	}
	long ScreenToClient(long * lx, long * ly)
	{
		unsigned long ulTickCount = GetTickCount();
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->ScreenToClient(m_hwnd, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %p %p, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, lx, ly, lRet);	
		return lRet;
	}
	long ShowScrMsg(long x1, long y1, long x2, long y2, LPCTSTR msg, LPCTSTR color)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->ShowScrMsg(x1, y1, x2, y2, msg, color);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %s, 返回值:%ld"),
			               __FUNCTION__, 
			               GetTickCount()-ulTickCount, 
			               x1, y1, x2, y2, msg, color,
			               lRet);
		return lRet;
	}
	long SetMinRowGap(long row_gap)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetMinRowGap(row_gap);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, row_gap, lRet);	
		return lRet;
	}
	long SetMinColGap(long col_gap)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetMinColGap(col_gap);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, col_gap, lRet);	
		return lRet;
	}
	long FindColor(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long dir, long * lx, long * ly)
	{
		unsigned long ulTickCount = GetTickCount();
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->FindColor( x1, y1, x2, y2, color, sim, dir, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %lf %ld %p %p, 返回值:%ld"),
			               __FUNCTION__, 
			               GetTickCount()-ulTickCount, 
			               x1, y1, x2, y2, color, sim, dir, lx, ly,
			               lRet);
		return lRet;
	}
	CString FindColorEx(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long dir)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FindColorEx(x1, y1, x2, y2, color, sim, dir);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %lf %ld, 返回值:%s"),
			               __FUNCTION__, 
			               GetTickCount()-ulTickCount, 
			               x1, y1, x2, y2, color, sim, dir,
			               cstrRet);
		return cstrRet;
	}
	long SetWordLineHeight(long line_height)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetWordLineHeight(line_height);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, line_height, lRet);
		return lRet;
	}
	long SetWordGap(long word_gap)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetWordGap(word_gap);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, word_gap, lRet);
		return lRet;
	}
	long SetRowGapNoDict(long row_gap)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetRowGapNoDict(row_gap);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, row_gap, lRet);
		return lRet;
	}
	long SetColGapNoDict(long col_gap)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetColGapNoDict(col_gap);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, col_gap, lRet);
		return lRet;
	}
	long SetWordLineHeightNoDict(long line_height)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetWordLineHeightNoDict(line_height);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, line_height, lRet);
		return lRet;
	}
	long SetWordGapNoDict(long word_gap)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetWordGapNoDict(word_gap);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, word_gap, lRet);
		return lRet;
	}
	long GetWordResultCount(LPCTSTR str)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetWordResultCount(str);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, str, lRet);
		return lRet;
	}
	long GetWordResultPos(LPCTSTR str, long index, long * lx, long * ly)
	{
		unsigned long ulTickCount = GetTickCount();
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->GetWordResultPos(str, index, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %lf %ld %p %p, 返回值:%ld"),
			               __FUNCTION__, 
			               GetTickCount()-ulTickCount, 
			               str, index, lx, ly,
			               lRet);
		return lRet;
	}
	CString GetWordResultStr(LPCTSTR str, long index)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetWordResultStr(str, index);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s %ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, str, index, cstrRet);
		return cstrRet;
	}
	CString GetWords(long x1, long y1, long x2, long y2, LPCTSTR color, double sim)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetWords(x1, y1, x2, y2, color, sim);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %lf, 返回值:%s"),
			               __FUNCTION__, 
			               GetTickCount()-ulTickCount, 
			               x1, y1, x2, y2, color, sim,
			               cstrRet);
		return cstrRet;
	}
	CString GetWordsNoDict(long x1, long y1, long x2, long y2, LPCTSTR color)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetWordsNoDict(x1, y1, x2, y2, color);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s, 返回值:%s"),
			               __FUNCTION__, 
			               GetTickCount()-ulTickCount, 
			                x1, y1, x2, y2, color,
			               cstrRet);
		return cstrRet;
	}
	long SetShowErrorMsg(long show)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetShowErrorMsg(show);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, show, lRet);
		return lRet;
	}
	long GetClientSize(long * lWidth, long * lHeight)
	{
		unsigned long ulTickCount = GetTickCount();
		VARIANT width;
		VARIANT height;
		long lRet = m_pPlugIdentify->GetClientSize(m_hwnd, &width, &height);
		*lWidth = vartol(width);
		*lHeight = vartol(height);
    	Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %p %p, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lWidth, lHeight, lRet);
		return lRet;
	}
	long MoveWindow(long x, long y)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->MoveWindow(m_hwnd, x, y);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, x, y, lRet);
		return lRet;
	}
	CString GetColorHSV(long x, long y)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetColorHSV(x, y);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld %ld, 参数: %s, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, x, y, cstrRet);
		return cstrRet;
	}
	CString GetAveRGB(long x1, long y1, long x2, long y2)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetAveRGB(x1, y1, x2, y2);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld, 返回值:%s"),
			               __FUNCTION__, 
			               GetTickCount()-ulTickCount, 
			               x1, y1, x2, y2,
			               cstrRet);
		return cstrRet;
	}
	CString GetAveHSV(long x1, long y1, long x2, long y2)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetAveHSV(x1, y1, x2, y2);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld, 返回值:%s"),
			               __FUNCTION__, 
			               GetTickCount()-ulTickCount, 
			               x1, y1, x2, y2,
			               cstrRet);
		return cstrRet;
	}
	long GetForegroundWindow()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetForegroundWindow();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}
	long GetForegroundFocus()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetForegroundFocus();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}
	long GetMousePointWindow()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetMousePointWindow();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}
	long GetPointWindow(long x, long y)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetPointWindow(x, y);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数:%ld %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, x, y, lRet);
		return lRet;
	}
	CString EnumWindow(long parent, LPCTSTR title, LPCTSTR class_name, long filter)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->EnumWindow(parent, title, class_name, filter);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %s %s %ld, 返回值:%s"),
			               __FUNCTION__, 
			               GetTickCount()-ulTickCount, 
			               parent, title, class_name, filter,
			               cstrRet);
		return cstrRet;
	}
	long GetWindowState(long flag)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetWindowState(m_hwnd, flag);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, flag, lRet);	
		return lRet;
	}
	long GetWindow(long flag)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetWindow(m_hwnd, flag);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, flag, lRet);	
		return lRet;
	}
	long GetSpecialWindow(long flag)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetSpecialWindow(flag);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, flag, lRet);	
		return lRet;
	}
	long SetWindowText(LPCTSTR text)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetWindowText(m_hwnd, text);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, text, lRet);	
		return lRet;
	}
	long SetWindowSize(long width, long height)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetWindowSize(m_hwnd, width, height);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, width, height, lRet);	
		return lRet;
	}
	long GetWindowRect(VARIANT * x1, VARIANT * y1, VARIANT * x2, VARIANT * y2)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetWindowRect(m_hwnd, x1, y1, x2, y2);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%p %p %p %p, 返回值:%ld"),
			               __FUNCTION__, 
			               GetTickCount()-ulTickCount, 
			               x1, y1, x2, y2,
			               lRet);
		return lRet;
	}
	CString GetWindowTitle()
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetWindowTitle(m_hwnd);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, cstrRet);
		return cstrRet;
	}
	CString GetWindowClass()
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetWindowClass(m_hwnd);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, cstrRet);
		return cstrRet;
	}
	long SetWindowState(long flag)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetWindowState(m_hwnd, flag);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, flag, lRet);	
		return lRet;
	}
	long CreateFoobarRect(long x, long y, long w, long h)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->CreateFoobarRect(m_hwnd, x, y, w, h);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld, 返回值:%ld"),
			               __FUNCTION__, 
			               GetTickCount()-ulTickCount, 
			               x, y, w, h,
			               lRet);
		return lRet;
	}
	long CreateFoobarRoundRect(long x, long y, long w, long h, long rw, long rh)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->CreateFoobarRoundRect(m_hwnd, x, y, w, h, rw, rh);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %ld %ld, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x, y, w, h, rw, rh,
                           lRet);
		return lRet;
	}
	long CreateFoobarEllipse(long x, long y, long w, long h)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->CreateFoobarEllipse(m_hwnd, x, y, w, h);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x, y, w, h,
                           lRet);
		return lRet;
	}
	long CreateFoobarCustom(long x, long y, LPCTSTR pic, LPCTSTR trans_color, double sim)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->CreateFoobarCustom(m_hwnd, x, y, pic, trans_color, sim);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %s %s %lf , 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x, y, pic, trans_color, sim,
                           lRet);
		return lRet;
	}
	long FoobarFillRect(long x1, long y1, long x2, long y2, LPCTSTR color)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FoobarFillRect(m_hwnd, x1, y1, x2, y2, color);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, color,
                           lRet); 
		return lRet;
	}
	long FoobarDrawText(long x, long y, long w, long h, LPCTSTR text, LPCTSTR color, long align)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FoobarDrawText(m_hwnd, x, y, w, h, text, color, align);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %s %ld, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x, y, w, h, text, color, align,
                           lRet);
		return lRet;
	}
	long FoobarDrawPic(long x, long y, LPCTSTR pic, LPCTSTR trans_color)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FoobarDrawPic(m_hwnd, x, y, pic, trans_color);
        Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %lf %ld %p %p, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x, y, pic, trans_color,
                           lRet);
		return lRet;
	}
	long FoobarUpdate()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FoobarUpdate(m_hwnd);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}
	long FoobarLock()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FoobarLock(m_hwnd);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}	
	long FoobarUnlock()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FoobarUnlock(m_hwnd);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}	
	long FoobarSetFont(LPCTSTR font_name, long size, long flag)
	{ 
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FoobarSetFont(m_hwnd, font_name, size, flag);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %lf %ld %p %p, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           font_name, size, flag,
                           lRet);
		return lRet;
	}	
	long FoobarTextRect(long x, long y, long w, long h)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FoobarTextRect(m_hwnd, x, y, w, h);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x, y, w, h,
                           lRet);
		return lRet;
	}	
	long FoobarPrintText(LPCTSTR text, LPCTSTR color)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FoobarPrintText(m_hwnd, text, color);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, text, color, lRet);
		return lRet;
	}	
	long FoobarClearText()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FoobarClearText(m_hwnd);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}	
	long FoobarTextLineGap(long gap)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FoobarTextLineGap(m_hwnd, gap);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, gap, lRet);
		return lRet;
	}	
	long Play(LPCTSTR file)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->Play(file);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, file, lRet);
		return lRet;
	}	
	long FaqCapture(long x1, long y1, long x2, long y2, long quality, long delay, long time)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FaqCapture(x1, y1, x2, y2, quality, delay, time);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %lf %ld %p %p, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, quality, delay, time,
                           lRet);
		return lRet;
	}	
	long FaqRelease(long handle)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FaqRelease(handle);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, handle, lRet);
		return lRet;
	}	
	CString FaqSend(LPCTSTR server, long handle, long request_type, long time_out)
	{ 
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FaqSend(server, handle, request_type, time_out);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %lf %ld, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           server, handle, request_type, time_out,
                           cstrRet);
		return cstrRet;
	}	
	long Beep(long fre, long delay)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->Beep(fre, delay);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, fre, delay, lRet);
		return lRet;
	}	
	long FoobarClose()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FoobarClose(m_hwnd);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}	
	long MoveDD(long dx, long dy)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->Beep(dx, dy);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, dx, dy, lRet);
		return lRet;
	}	
	long FaqGetSize(long handle)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FaqGetSize(handle);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, handle, lRet);
		return lRet;
	}	
	long LoadPic(LPCTSTR pic_name)
	{
//xiaoting		return m_pPlugIdentify->(pic_name);
	}	
	long FreePic(LPCTSTR pic_name)
	{
//xiaoting		return m_pPlugIdentify->FreePic(pic_name);
	}	
	long GetScreenData(long x1, long y1, long x2, long y2)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetScreenData(x1, y1, x2, y2);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %lf %ld %p %p, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2,
                           lRet);
		return lRet;
	}	
	long FreeScreenData(long handle)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FreeScreenData(handle);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, handle, lRet);
		return lRet;
	}	
	long WheelUp()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->WheelUp();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}	
	long WheelDown()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->WheelDown();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}	
	long SetMouseDelay(LPCTSTR type, long delay)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetMouseDelay(type, delay);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, type, delay, lRet);
		return lRet;
	}	
	long SetKeypadDelay(LPCTSTR type, long delay)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetKeypadDelay(type, delay);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, type, delay, lRet);
		return lRet;
	}	
	CString GetEnv(long index, LPCTSTR name)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetEnv(index, name);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, index, name, cstrRet);
		return cstrRet;
	}	
	long SetEnv(long index, LPCTSTR name, LPCTSTR value)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetEnv(index, name, value);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %s %s, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           index, name, value,
                           lRet);
		return lRet;
	}	
	long SendString(LPCTSTR str)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SendString(m_hwnd, str);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, str, lRet);
		return lRet;
	}	
	long DelEnv(long index, LPCTSTR name)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->DelEnv(index, name);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, index, name, lRet);	
		return lRet;
	}	
	CString GetPath()
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetPath();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, cstrRet);
		return cstrRet;
	}	
	long SetDict(long index, LPCTSTR dict_name)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetDict(index, dict_name);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, index, dict_name, lRet);	
		return lRet;
	}	
	long FindPic(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir, long * lx, long * ly)
	{
		unsigned long ulTickCount = GetTickCount();
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->FindPic(x1, y1, x2, y2, pic_name, delta_color, sim, dir, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %s %lf %ld %p %p, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, pic_name, delta_color, sim, dir, lx, ly,
                           lRet);
		return lRet;
	}	
	CString FindPicEx(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FindPicEx(x1, y1, x2, y2, pic_name, delta_color, sim, dir);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %lf %ld, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, pic_name, delta_color, sim, dir,
                           cstrRet);
		return cstrRet;
	}	
	long SetClientSize(long width, long height)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetClientSize(m_hwnd, width, height);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数:%ld %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, width, height, lRet);	
		return lRet;
	}	
	long ReadInt(LPCTSTR addr, long type)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->ReadInt(m_hwnd, addr, type);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数:%s %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, addr, type, lRet);
		return lRet;
	}	
	float ReadFloat(LPCTSTR addr)
	{
		unsigned long ulTickCount = GetTickCount();
		float fRet = m_pPlugIdentify->ReadFloat(m_hwnd, addr);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数:%s, 返回值:%f"), __FUNCTION__, GetTickCount()-ulTickCount, addr, fRet);
		return fRet;
	}	
	double ReadDouble(LPCTSTR addr)
	{
		unsigned long ulTickCount = GetTickCount();
		double dRet = m_pPlugIdentify->ReadDouble(m_hwnd, addr);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数:%s, 返回值:%f"), __FUNCTION__, GetTickCount()-ulTickCount, addr, dRet);
		return dRet;
	}	
	CString FindInt(LPCTSTR addr_range, long int_value_min, long int_value_max, long type)
	{  
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FindInt(m_hwnd, addr_range, int_value_min, int_value_max, type);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%s %ld %ld %ld, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           addr_range, int_value_min, int_value_max, type,
                           cstrRet);
		return cstrRet;
	}	
	CString FindFloat(LPCTSTR addr_range, float float_value_min, float float_value_max)
	{ 
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FindFloat(m_hwnd, addr_range, float_value_min, float_value_max);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%s %f %f, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           addr_range, float_value_min, float_value_max,
                           cstrRet);
		return cstrRet;
	}	
	CString FindDouble(LPCTSTR addr_range, double double_value_min, double double_value_max)
	{ 
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FindDouble(m_hwnd, addr_range, double_value_min, double_value_max);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%s %f %f, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           addr_range, double_value_min, double_value_max,
                           cstrRet);
		return cstrRet;
	}	
	CString FindString(LPCTSTR addr_range, LPCTSTR string_value, long type)
	{ 
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FindString(m_hwnd, addr_range, string_value, type);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%s %s %ld, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           addr_range, string_value, type,
                           cstrRet);
		return cstrRet;
	}	
	long GetModuleBaseAddr(LPCTSTR module_name)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetModuleBaseAddr(m_hwnd, module_name);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, module_name, lRet);
		return lRet;
	}	
	CString MoveToEx(long x, long y, long w, long h)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->MoveToEx(x, y, w, h);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %lf %ld, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x, y, w, h,
                           cstrRet);
		return cstrRet;
	}	
	CString MatchPicName(LPCTSTR pic_name)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->MatchPicName(pic_name);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, pic_name, cstrRet);
		return cstrRet;
	}	
	long AddDict(long index, LPCTSTR dict_info)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->AddDict(index, dict_info);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, index, dict_info, lRet);
		return lRet; 
	}	
	long EnterCri()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->EnterCri();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}	
	long LeaveCri()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->LeaveCri();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}	
	long WriteInt(LPCTSTR addr, long type, long v)
	{ 
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->WriteInt(m_hwnd, addr, type, v);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%s %ld %ld, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           addr, type, v,
                           lRet);
		return lRet;
	}	
	long WriteFloat(LPCTSTR addr, float v)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->WriteFloat(m_hwnd, addr, v);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s %f, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, addr, v, lRet);
		return lRet;
	}	
	long WriteDouble(LPCTSTR addr, double v)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->WriteDouble(m_hwnd, addr, v);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s %lf, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, addr, v, lRet);
		return lRet;
	}	
	long WriteString(LPCTSTR addr, long type, LPCTSTR v)
	{ 
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->WriteString(m_hwnd, addr, type, v);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%s %ld %s, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           addr, type, v,
                           lRet);	
		return lRet;
	}	
	long AsmAdd(LPCTSTR asm_ins)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->AsmAdd(asm_ins);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, asm_ins, lRet);
		return lRet;
	}	
	long AsmClear()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->AsmClear();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}	
	long AsmCall(long mode)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->AsmCall(m_hwnd, mode);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, mode, lRet);
		return lRet;
	}	
	long FindMultiColor(long x1, long y1, long x2, long y2, LPCTSTR first_color, LPCTSTR offset_color, double sim, long dir, long * lx, long * ly)
	{
		unsigned long ulTickCount = GetTickCount();
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->FindMultiColor(x1, y1, x2, y2, first_color, offset_color, sim, dir, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %s %lf %ld %p %p, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, first_color, offset_color, sim, dir, lx, ly,
                           lRet);
		return lRet;
	}	
	CString FindMultiColorEx(long x1, long y1, long x2, long y2, LPCTSTR first_color, LPCTSTR offset_color, double sim, long dir)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FindMultiColorEx(x1, y1, x2, y2, first_color, offset_color, sim, dir);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %s %lf %ld, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, first_color, offset_color, sim, dir,
                           cstrRet);
		return cstrRet;
	}	
	CString AsmCode(long base_addr)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->AsmCode(base_addr);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, base_addr, cstrRet);
		return cstrRet;
	}	
	CString Assemble(LPCTSTR asm_code, long base_addr, long is_upper)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->Assemble(asm_code, base_addr, is_upper);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %lf %ld, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           asm_code, base_addr, is_upper,
                           cstrRet);
		return cstrRet;
	}	
	long SetWindowTransparent(long v)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetWindowTransparent(m_hwnd, v);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, v, lRet);
		return lRet;
	}	
	CString ReadData(LPCTSTR addr, long len)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->ReadData(m_hwnd, addr, len);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s %ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, addr, len, cstrRet);
		return cstrRet;
	}	
	long WriteData(LPCTSTR addr, LPCTSTR data)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->WriteData(m_hwnd, addr, data);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, addr, data, lRet);
		return lRet;
	}	
	CString FindData(LPCTSTR addr_range, LPCTSTR data)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FindData(m_hwnd, addr_range, data);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s %s, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, addr_range, data, cstrRet);
		return cstrRet;
	}	
	long SetPicPwd(LPCTSTR pwd)
	{
		return m_pPlugIdentify->SetPicPwd(pwd);
	}	
	long Log(LPCTSTR info)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->Log(info);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, info, lRet);
		return lRet;
	}	
	CString FindStrE(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FindStrE(x1, y1, x2, y2, str, color, sim);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %s %lf, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, str, color, sim,
                           cstrRet);
		return cstrRet;
	}	
	CString FindColorE(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long dir)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FindColorE(x1, y1, x2, y2, color, sim, dir);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %lf %ld, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, color, sim, dir,
                           cstrRet);
		return cstrRet;
	}	
	CString FindPicE(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FindPicE(x1, y1, x2, y2, pic_name, delta_color, sim, dir);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %s %lf %ld, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, pic_name, delta_color, sim, dir,
                           cstrRet);
		return cstrRet;
	}	
	CString FindMultiColorE(long x1, long y1, long x2, long y2, LPCTSTR first_color, LPCTSTR offset_color, double sim, long dir)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FindMultiColorE(x1, y1, x2, y2, first_color, offset_color, sim, dir);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %s %lf %ld, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, first_color, offset_color, sim, dir,
                           cstrRet);
		return cstrRet;
	}	
	long SetExactOcr(long exact_ocr)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetExactOcr(exact_ocr);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, exact_ocr, lRet);
		return lRet;
	}	
	CString ReadString(LPCTSTR addr, long type, long len)
	{ 
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->ReadString(m_hwnd, addr, type, len);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%s %ld %ld, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           addr, type, len,
                           cstrRet);
		return cstrRet;
	}	
	long FoobarTextPrintDir(long dir)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FoobarTextPrintDir(m_hwnd, dir);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, dir, lRet);	
		return lRet;
	}	
	CString OcrEx(long x1, long y1, long x2, long y2, LPCTSTR color, double sim)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->OcrEx(x1, y1, x2, y2, color, sim);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %lf, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, color, sim,
                           cstrRet);
		return cstrRet;
	}	
	long SetDisplayInput(LPCTSTR mode)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetDisplayInput(mode);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, mode, lRet);
		return lRet;
	}	
	long GetTime()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetTime();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}	
	long GetScreenWidth()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetScreenWidth();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}	
	long GetScreenHeight()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetScreenHeight();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}	
	long BindWindowEx(LPCTSTR display, LPCTSTR mouse, LPCTSTR keypad, LPCTSTR public_desc, long mode)
	{   
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->BindWindowEx(m_hwnd, display, mouse, keypad, public_desc, mode);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数: %s %s %s %s %ld, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           display, mouse, keypad, public_desc, mode,
                           lRet);
		return lRet;
	}	
	CString GetDiskSerial()
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetDiskSerial();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, cstrRet);
		return cstrRet;
	}	
	CString Md5(LPCTSTR str)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->Md5(str);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, str, cstrRet);
		return cstrRet;
	}	
	CString GetMac()
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetMac();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, cstrRet);
		return cstrRet;
	}	
	long ActiveInputMethod(LPCTSTR id)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->ActiveInputMethod(m_hwnd, id);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, id, lRet);
		return lRet;
	}	
	long CheckInputMethod(LPCTSTR id)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->CheckInputMethod(m_hwnd, id);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, id, lRet);
		return lRet;
	}	
	long FindInputMethod(LPCTSTR id)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FindInputMethod(id);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, id, lRet);
		return lRet;
	}	
	long GetCursorPos(long * lx, long * ly)
	{
		unsigned long ulTickCount = GetTickCount();		
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->GetCursorPos(&x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %p %p, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lx, ly, lRet);
		return lRet;
	}	
	long BindWindow(LPCTSTR display, LPCTSTR mouse, LPCTSTR keypad, long mode)
	{  
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->BindWindow(m_hwnd, display, mouse, keypad, mode);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%s %s %s %ld, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           display, mouse, keypad, mode,
                           lRet);
		return lRet;
	}	
	long FindWindow(LPCTSTR class_name, LPCTSTR title_name)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FindWindow(class_name, title_name);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, class_name, title_name, lRet);
		return lRet;
	}	
	long GetScreenDepth()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetScreenDepth();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}	
	long SetScreen(long width, long height, long depth)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetScreen(width, height, depth);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           width, height, depth,
                           lRet);
		return lRet;
	}	
	long ExitOs(long type)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->ExitOs(type);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, type, lRet);
		return lRet;
	}	
	CString GetDir(long type)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetDir(type);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, type, cstrRet);
		return cstrRet;
	}	
	long GetOsType()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetOsType();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}	
	long FindWindowEx(long parent, LPCTSTR class_name, LPCTSTR title_name)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FindWindowEx(parent, class_name, title_name);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %s %s, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           parent, class_name, title_name,
                           lRet);	
		return lRet;
	}	
	long SetExportDict(long index, LPCTSTR dict_name)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetExportDict(index, dict_name);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数:%ld %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, index, dict_name, lRet);	
		return lRet;
	}	
	CString GetCursorShape()
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetCursorShape();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, cstrRet);
		return cstrRet;
	}	
	long DownCpu(long rate)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->DownCpu(rate);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, rate, lRet);
		return lRet;
	}	
	CString GetCursorSpot()
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetCursorSpot();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, cstrRet);
		return cstrRet;
	}	
	long SendString2(LPCTSTR str)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SendString2(m_hwnd, str);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, str, lRet);
		return lRet;
	}	
	long FaqPost(LPCTSTR server, long handle, long request_type, long time_out)
	{ 
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->FaqPost(server, handle, request_type, time_out);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%s %ld %ld %ld, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           server, handle, request_type, time_out,
                           lRet);
		return lRet;
	}	
	CString FaqFetch()
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FaqFetch();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, cstrRet);
		return cstrRet;
	}	
	CString FetchWord(long x1, long y1, long x2, long y2, LPCTSTR color, LPCTSTR word)
	{   
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FetchWord(x1, y1, x2, y2, color, word);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %s, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, color, word,
                           cstrRet);
		return cstrRet;
	}	
	long CaptureJpg(long x1, long y1, long x2, long y2, LPCTSTR file, long quality)
	{   
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->CaptureJpg(x1, y1, x2, y2, file, quality);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %ld, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, file, quality,
                           lRet);
		return lRet;
	}	
	long FindStrWithFont(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, LPCTSTR font_name, long font_size, long flag, long * lx, long * ly)
	{
		unsigned long ulTickCount = GetTickCount();
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->FindStrWithFont(x1, y1, x2, y2, str, color, sim, font_name, font_size, flag, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %s %lf %s %ld %ld %p %p, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, str, color, sim, font_name, font_size, flag, lx, ly,
                           lRet);
		return lRet;
	}	
	CString FindStrWithFontE(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, LPCTSTR font_name, long font_size, long flag)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FindStrWithFontE(x1, y1, x2, y2, str, color, sim, font_name, font_size, flag);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %s %lf %s %ld %ld, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, str, color, sim, font_name, font_size, flag,
                           cstrRet);
		return cstrRet;
	}	
	CString FindStrWithFontEx(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, LPCTSTR font_name, long font_size, long flag)
	{  
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FindStrWithFontEx(x1, y1, x2, y2, str, color, sim, font_name, font_size, flag);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %s %lf %s %ld %ld, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, str, color, sim, font_name, font_size, flag,
                           cstrRet);
		return cstrRet;
	}	
	CString GetDictInfo(LPCTSTR str, LPCTSTR font_name, long font_size, long flag)
	{ 
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetDictInfo(str, font_name, font_size, flag);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%s %s %ld %ld, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           str, font_name, font_size, flag,
                           cstrRet);
		return cstrRet;
	}	
	long SaveDict(long index, LPCTSTR file)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SaveDict(index, file);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, index, file, lRet);
		return lRet;
	}	
	long GetWindowProcessId()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetWindowProcessId(m_hwnd);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}	
	CString GetWindowProcessPath()
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetWindowProcessPath(m_hwnd);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, cstrRet);
		return cstrRet;
	}	
	long LockInput(long lock)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->LockInput(lock);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lock, lRet);
		return lRet;
	}	
	CString GetPicSize(LPCTSTR pic_name)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetPicSize(pic_name);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, pic_name, cstrRet);
		return cstrRet;
	}	
	long GetID()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetID();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}	
	long CapturePng(long x1, long y1, long x2, long y2, LPCTSTR file)
	{  
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->CapturePng(x1, y1, x2, y2, file);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, file,
                           lRet);
		return lRet;
	}	
	long CaptureGif(long x1, long y1, long x2, long y2, LPCTSTR file, long delay, long time)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->CaptureGif(x1, y1, x2, y2, file, delay, time);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %ld %ld, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, file, delay, time,
                           lRet);
		return lRet;
	}	
	long ImageToBmp(LPCTSTR pic_name, LPCTSTR bmp_name)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->ImageToBmp(pic_name, bmp_name);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, pic_name, bmp_name, lRet);
		return lRet;
	}	
	long FindStrFast(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, long * lx, long * ly)
	{
		unsigned long ulTickCount = GetTickCount();
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->FindStrFast(x1, y1, x2, y2, str, color, sim, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %s %lf %p %p, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, str, color, sim, lx, ly,
                           lRet);
		return lRet;
	}	
	CString FindStrFastEx(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FindStrFastEx(x1, y1, x2, y2, str, color, sim);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %s %lf, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, str, color, sim,
                           cstrRet);
		return cstrRet;
	}	
	CString FindStrFastE(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim)
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->FindStrFastE(x1, y1, x2, y2, str, color, sim);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%ld %ld %ld %ld %s %s %lf, 返回值:%s"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           x1, y1, x2, y2, str, color, sim,
                           cstrRet);
		return cstrRet;
	}	
	long EnableDisplayDebug(long enable_debug)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->EnableDisplayDebug(enable_debug);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, enable_debug, lRet);
		return lRet;
	}	
	long CapturePre(LPCTSTR file)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->CapturePre(file);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, file, lRet);
		return lRet;
	}	
	long RegEx(LPCTSTR code, LPCTSTR Ver, LPCTSTR ip)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->RegEx(code, Ver, ip);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld,  参数:%s %s %s, 返回值:%ld"),
                           __FUNCTION__, 
                           GetTickCount()-ulTickCount, 
                           code, Ver, ip,
                           lRet);
		return lRet;
	}	
	CString GetMachineCode()
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetMachineCode();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, cstrRet);
		return cstrRet;
	}	
	long SetClipboard(LPCTSTR data)
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->SetClipboard(data);
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 参数: %s, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, data, lRet);
		return lRet;
	}	
	CString GetClipboard()
	{
		unsigned long ulTickCount = GetTickCount();
		CString cstrRet = m_pPlugIdentify->GetClipboard();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%s"), __FUNCTION__, GetTickCount()-ulTickCount, cstrRet);
		return cstrRet;
	}	
	long GetNowDict()
	{
		unsigned long ulTickCount = GetTickCount();
		long lRet = m_pPlugIdentify->GetNowDict();
		Logout(LOG_IFTEST, _T("函数名:%s, 时间:%ld, 返回值:%ld"), __FUNCTION__, GetTickCount()-ulTickCount, lRet);
		return lRet;
	}	
	long Is64Bit()
	{
		return m_pPlugIdentify->Is64Bit();
	}	
	long GetColorNum(long x1, long y1, long x2, long y2, LPCTSTR color, double sim)
	{
		return m_pPlugIdentify->GetColorNum(x1, y1, x2, y2, color, sim);
	}	
	CString EnumWindowByProcess(LPCTSTR process_name, LPCTSTR title, LPCTSTR class_name, long filter)
	{ 
		return m_pPlugIdentify->EnumWindowByProcess(process_name, title, class_name, filter);
	}	
	long GetDictCount(long index)
	{
		return m_pPlugIdentify->GetDictCount(index);
	}	
	long GetLastError()
	{
		return m_pPlugIdentify->GetLastError();
	}	
	CString GetNetTime()
	{
		return m_pPlugIdentify->GetNetTime();
	}	
	long EnableGetColorByCapture(long en)
	{
		return m_pPlugIdentify->EnableGetColorByCapture(en);
	}	
	long CheckUAC()
	{
		return m_pPlugIdentify->CheckUAC();
	}	
	long SetUAC(long uac)
	{
		return m_pPlugIdentify->SetUAC(uac);
	}	
	long DisableFontSmooth()
	{
		return m_pPlugIdentify->DisableFontSmooth();
	}	
	long CheckFontSmooth()
	{
		return m_pPlugIdentify->CheckFontSmooth();
	}	
	long SetDisplayAcceler(long level)
	{
		return m_pPlugIdentify->SetDisplayAcceler(level);
	}	
	long FindWindowByProcess(LPCTSTR process_name, LPCTSTR class_name, LPCTSTR title_name)
	{
		return m_pPlugIdentify->FindWindowByProcess(process_name, class_name, title_name);
	}	
	long FindWindowByProcessId(long process_id, LPCTSTR class_name, LPCTSTR title_name)
	{
		return m_pPlugIdentify->FindWindowByProcessId(process_id, class_name, title_name);
	}	
	CString ReadIni(LPCTSTR section, LPCTSTR key, LPCTSTR file)
	{
		return m_pPlugIdentify->ReadIni(section, key, file);
	}	
	long WriteIni(LPCTSTR section, LPCTSTR key, LPCTSTR v, LPCTSTR file)
	{ 
		return m_pPlugIdentify->WriteIni(section, key, v, file);
	}	
	long RunApp(LPCTSTR path, long mode)
	{
		return m_pPlugIdentify->RunApp(path, mode);
	}	
	long delay(long mis)
	{
		return m_pPlugIdentify->delay(mis);
	}	
	long FindWindowSuper(LPCTSTR spec1, long flag1, long type1, LPCTSTR spec2, long flag2, long type2)
	{   
		return m_pPlugIdentify->FindWindowSuper(spec1, flag1, type1, spec2, flag2, type2);
	}	
	CString ExcludePos(LPCTSTR all_pos, long type, long x1, long y1, long x2, long y2)
	{   
		return m_pPlugIdentify->ExcludePos(all_pos, type, x1, y1, x2, y2);
	}	
	CString FindNearestPos(LPCTSTR all_pos, long type, long x, long y)
	{ 
		return m_pPlugIdentify->FindNearestPos(all_pos, type, x, y);
	}	
	CString SortPosDistance(LPCTSTR all_pos, long type, long x, long y)
	{ 
		return m_pPlugIdentify->SortPosDistance(all_pos, type, x, y);
	}	
	long FindPicMem(long x1, long y1, long x2, long y2, LPCTSTR pic_info, LPCTSTR delta_color, double sim, long dir, long * lx, long * ly)
	{
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->FindPicMem(x1, y1, x2, y2, pic_info, delta_color, sim, dir, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		return lRet;
	}	
	CString FindPicMemEx(long x1, long y1, long x2, long y2, LPCTSTR pic_info, LPCTSTR delta_color, double sim, long dir)
	{
		return m_pPlugIdentify->FindPicMemEx(x1, y1, x2, y2, pic_info, delta_color, sim, dir);
	}	
	CString FindPicMemE(long x1, long y1, long x2, long y2, LPCTSTR pic_info, LPCTSTR delta_color, double sim, long dir)
	{
		return m_pPlugIdentify->FindPicMemE(x1, y1, x2, y2, pic_info, delta_color, sim, dir);
	}	
	CString AppendPicAddr(LPCTSTR pic_info, long addr, long size)
	{
		return m_pPlugIdentify->AppendPicAddr(pic_info, addr, size);
	}	
	long WriteFile(LPCTSTR file, LPCTSTR content)
	{
		return m_pPlugIdentify->WriteFile(file, content);
	}	
	long Stop(long id)
	{
		return m_pPlugIdentify->Stop(id);
	}	
	long SetDictMem(long index, long addr, long size)
	{
		return m_pPlugIdentify->SetDictMem(index, addr, size);
	}	
	CString GetNetTimeSafe()
	{
		return m_pPlugIdentify->GetNetTimeSafe();
	}	
	long ForceUnBindWindow()
	{
		return m_pPlugIdentify->ForceUnBindWindow(m_hwnd);
	}	
	CString ReadIniPwd(LPCTSTR section, LPCTSTR key, LPCTSTR file, LPCTSTR pwd)
	{ 
		return m_pPlugIdentify->ReadIniPwd(section, key, file, pwd);
	}	
	long WriteIniPwd(LPCTSTR section, LPCTSTR key, LPCTSTR v, LPCTSTR file, LPCTSTR pwd)
	{  
		return m_pPlugIdentify->WriteIniPwd(section, key, v, file, pwd);
	}	
	long DecodeFile(LPCTSTR file, LPCTSTR pwd)
	{
		return m_pPlugIdentify->DecodeFile(file, pwd);
	}	
	long KeyDownChar(LPCTSTR key_str)
	{
		return m_pPlugIdentify->KeyDownChar(key_str);
	}	
	long KeyUpChar(LPCTSTR key_str)
	{
		return m_pPlugIdentify->KeyUpChar(key_str);
	}	
	long KeyPressChar(LPCTSTR key_str)
	{
		return m_pPlugIdentify->KeyPressChar(key_str);
	}	
	long KeyPressStr(LPCTSTR key_str, long delay)
	{
		return m_pPlugIdentify->KeyPressStr(key_str, delay);
	}	
	long EnableKeypadPatch(long en)
	{
		return m_pPlugIdentify->EnableKeypadPatch(en);
	}	
	long EnableKeypadSync(long en, long time_out)
	{
		return m_pPlugIdentify->EnableKeypadSync(en, time_out);
	}	
	long EnableMouseSync(long en, long time_out)
	{
		return m_pPlugIdentify->EnableMouseSync(en, time_out);
	}	
	long DmGuard(long en, LPCTSTR type)
	{
		return m_pPlugIdentify->DmGuard(en, type);
	}	
	long FaqCaptureFromFile(long x1, long y1, long x2, long y2, LPCTSTR file, long quality)
	{   
		return m_pPlugIdentify->FaqCaptureFromFile(x1, y1, x2, y2, file, quality);
	}	
	CString FindIntEx(LPCTSTR addr_range, long int_value_min, long int_value_max, long type, long step, long multi_thread, long mode)
	{
		return m_pPlugIdentify->FindIntEx(m_hwnd, addr_range, int_value_min, int_value_max, type, step, multi_thread, mode);
	}	
	CString FindFloatEx(LPCTSTR addr_range, float float_value_min, float float_value_max, long step, long multi_thread, long mode)
	{
		return m_pPlugIdentify->FindFloatEx(m_hwnd, addr_range, float_value_min, float_value_max, step, multi_thread, mode);
	}	
	CString FindDoubleEx(LPCTSTR addr_range, double double_value_min, double double_value_max, long step, long multi_thread, long mode)
	{
		return m_pPlugIdentify->FindDoubleEx(m_hwnd, addr_range, double_value_min, double_value_max, step, multi_thread, mode);
	}	
	CString FindStringEx(LPCTSTR addr_range, LPCTSTR string_value, long type, long step, long multi_thread, long mode)
	{
		return m_pPlugIdentify->FindStringEx(m_hwnd, addr_range, string_value, type, step, multi_thread, mode);
	}	
	CString FindDataEx(LPCTSTR addr_range, LPCTSTR data, long step, long multi_thread, long mode)
	{
		return m_pPlugIdentify->FindDataEx(m_hwnd, addr_range, data, step, multi_thread, mode);
	}	
	long EnableRealMouse(long en, long mousedelay, long mousestep)
	{
		return m_pPlugIdentify->EnableRealMouse(en, mousedelay, mousestep);
	}	
	long EnableRealKeypad(long en)
	{
		return m_pPlugIdentify->EnableRealKeypad(en);
	}	
	long SendStringIme(LPCTSTR str)
	{
		return m_pPlugIdentify->SendStringIme(str);
	}	
	long FoobarDrawLine(long x1, long y1, long x2, long y2, LPCTSTR color, long style, long width)
	{
		return m_pPlugIdentify->FoobarDrawLine(m_hwnd, x1, y1, x2, y2, color, style, width);
	}	
	CString FindStrEx(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim)
	{
		return m_pPlugIdentify->FindStrEx(x1, y1, x2, y2, str, color, sim);
	}	
	long IsBind()
	{
		return m_pPlugIdentify->IsBind(m_hwnd);
	}	
	long SetDisplayDelay(long t)
	{
		return m_pPlugIdentify->SetDisplayDelay(t);
	}	
	long GetDmCount()
	{
		return m_pPlugIdentify->GetDmCount();
	}	
	long DisableScreenSave()
	{
		return m_pPlugIdentify->DisableScreenSave();
	}	
	long DisablePowerSave()
	{
		return m_pPlugIdentify->DisablePowerSave();
	}	
	long SetMemoryHwndAsProcessId(long en)
	{
		return m_pPlugIdentify->SetMemoryHwndAsProcessId(en);
	}	
	long FindShape(long x1, long y1, long x2, long y2, LPCTSTR offset_color, double sim, long dir, long * lx, long * ly)
	{
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->FindShape(x1, y1, x2, y2, offset_color, sim, dir, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		return lRet;
	}	
	CString FindShapeE(long x1, long y1, long x2, long y2, LPCTSTR offset_color, double sim, long dir)
	{
		return m_pPlugIdentify->FindShapeE(x1, y1, x2, y2, offset_color, sim, dir);
	}	
	CString FindShapeEx(long x1, long y1, long x2, long y2, LPCTSTR offset_color, double sim, long dir)
	{
		return m_pPlugIdentify->FindShapeEx(x1, y1, x2, y2, offset_color, sim, dir);
	}	
	CString FindStrS(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, long * lx, long * ly)
	{
		VARIANT x;
		VARIANT y;
		CString cstrRet = m_pPlugIdentify->FindStrS(x1, y1, x2, y2, str, color, sim, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		return cstrRet;
	}	
	CString FindStrExS(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim)
	{
		return m_pPlugIdentify->FindStrExS(x1, y1, x2, y2, str, color, sim);
	}	
	CString FindStrFastS(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, long * lx, long * ly)
	{
		VARIANT x;
		VARIANT y;
		CString cstrRet = m_pPlugIdentify->FindStrFastS(x1, y1, x2, y2, str, color, sim, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		return cstrRet;
	}	
	CString FindStrFastExS(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim)
	{
		return m_pPlugIdentify->FindStrFastExS(x1, y1, x2, y2, str, color, sim);
	}	
	CString FindPicS(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir, long * lx, long * ly)
	{
		VARIANT x;
		VARIANT y;
		CString cstrRet = m_pPlugIdentify->FindPicS(x1, y1, x2, y2, pic_name, delta_color, sim, dir, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		return cstrRet;
	}	
	CString FindPicExS(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir)
	{
		return m_pPlugIdentify->FindPicExS(x1, y1, x2, y2, pic_name, delta_color, sim, dir);
	}	
	long ClearDict(long index)
	{
		return m_pPlugIdentify->ClearDict(index);
	}	
	CString GetMachineCodeNoMac()
	{
		return m_pPlugIdentify->GetMachineCodeNoMac();
	}	
	long GetClientRect(VARIANT * x1, VARIANT * y1, VARIANT * x2, VARIANT * y2)
	{
		return m_pPlugIdentify->GetClientRect(m_hwnd, x1, y1, x2, y2);
	}	
	long EnableFakeActive(long en)
	{
		return m_pPlugIdentify->EnableFakeActive(en);
	}	
	long GetScreenDataBmp(long x1, long y1, long x2, long y2, VARIANT * data, VARIANT * size)
	{
		return m_pPlugIdentify->GetScreenDataBmp(x1, y1, x2, y2, data, size);
	}	
	long EncodeFile(LPCTSTR file, LPCTSTR pwd)
	{
		return m_pPlugIdentify->EncodeFile(file, pwd);
	}	
	CString GetCursorShapeEx(long type)
	{
		return m_pPlugIdentify->GetCursorShapeEx(type);
	}	
	long FaqCancel()
	{
		return m_pPlugIdentify->FaqCancel();
	}	
	CString IntToData(long int_value, long type)
	{
		return m_pPlugIdentify->IntToData(int_value, type);
	}	
	CString FloatToData(float float_value)
	{
		return m_pPlugIdentify->FloatToData(float_value);
	}	
	CString DoubleToData(double double_value)
	{
		return m_pPlugIdentify->DoubleToData(double_value);
	}	
	CString StringToData(LPCTSTR string_value, long type)
	{
		return m_pPlugIdentify->StringToData(string_value, type);
	}	
	long SetMemoryFindResultToFile(LPCTSTR file)
	{
		return m_pPlugIdentify->SetMemoryFindResultToFile(file);
	}	
	long EnableBind(long en)
	{
		return m_pPlugIdentify->EnableBind(en);
	}	
	long SetSimMode(long mode)
	{
		return m_pPlugIdentify->SetSimMode(mode);
	}	
	long LockMouseRect(long x1, long y1, long x2, long y2)
	{
		return m_pPlugIdentify->LockMouseRect(x1, y1, x2, y2);
	}	
	long SendPaste()
	{
		return m_pPlugIdentify->SendPaste(m_hwnd);
	}	
	long IsDisplayDead(long x1, long y1, long x2, long y2, long t)
	{
		return m_pPlugIdentify->IsDisplayDead(x1, y1, x2, y2, t);
	}	
	long GetKeyState(long vk)
	{
		return m_pPlugIdentify->GetKeyState(vk);
	}	
	long CopyFile(LPCTSTR src_file, LPCTSTR dst_file, long over)
	{
		return m_pPlugIdentify->CopyFile(src_file, dst_file, over);
	}	
	long IsFileExist(LPCTSTR file)
	{
		return m_pPlugIdentify->IsFileExist(file);
	}	
	long DeleteFile(LPCTSTR file)
	{
		return m_pPlugIdentify->DeleteFile(file);
	}	
	long MoveFile(LPCTSTR src_file, LPCTSTR dst_file)
	{
		return m_pPlugIdentify->MoveFile(src_file, dst_file);
	}	
	long CreateFolder(LPCTSTR folder_name)
	{
		return m_pPlugIdentify->CreateFolder(folder_name);
	}	
	long DeleteFolder(LPCTSTR folder_name)
	{
		return m_pPlugIdentify->DeleteFolder(folder_name);
	}	
	long GetFileLength(LPCTSTR file)
	{
		return m_pPlugIdentify->GetFileLength(file);
	}	
	CString ReadFile(LPCTSTR file)
	{
		return m_pPlugIdentify->ReadFile(file);
	}	
	long WaitKey(long key_code, long time_out)
	{
		return m_pPlugIdentify->WaitKey(key_code, time_out);
	}	
	long DeleteIni(LPCTSTR section, LPCTSTR key, LPCTSTR file)
	{
		return m_pPlugIdentify->DeleteIni(section, key, file);
	}	
	long DeleteIniPwd(LPCTSTR section, LPCTSTR key, LPCTSTR file, LPCTSTR pwd)
	{ 
		return m_pPlugIdentify->DeleteIniPwd(section, key, file, pwd);
	}	
	long EnableSpeedDx(long en)
	{
		return m_pPlugIdentify->EnableSpeedDx(en);
	}	
	long EnableIme(long en)
	{
		return m_pPlugIdentify->EnableIme(en);
	}	
	long Reg(LPCTSTR code, LPCTSTR Ver)
	{
		return m_pPlugIdentify->Reg(code, Ver);
	}	
	CString SelectFile()
	{
		return m_pPlugIdentify->SelectFile();
	}	
	CString SelectDirectory()
	{
		return m_pPlugIdentify->SelectDirectory();
	}	
	long LockDisplay(long lock)
	{
		return m_pPlugIdentify->LockDisplay(lock);
	}	
	long FoobarSetSave(LPCTSTR file, long en, LPCTSTR header)
	{ 
		return m_pPlugIdentify->FoobarSetSave(m_hwnd, file, en, header);
	}	
	CString EnumWindowSuper(LPCTSTR spec1, long flag1, long type1, LPCTSTR spec2, long flag2, long type2, long sort)
	{
		return m_pPlugIdentify->EnumWindowSuper(spec1, flag1, type1, spec2, flag2, type2, sort);
	}	
	long DownloadFile(LPCTSTR url, LPCTSTR save_file, long timeout)
	{
		return m_pPlugIdentify->DownloadFile(url, save_file, timeout);
	}	
	long EnableKeypadMsg(long en)
	{
		return m_pPlugIdentify->EnableKeypadMsg(en);
	}	
	long EnableMouseMsg(long en)
	{
		return m_pPlugIdentify->EnableMouseMsg(en);
	}	
	long RegNoMac(LPCTSTR code, LPCTSTR Ver)
	{
		return m_pPlugIdentify->RegNoMac(code, Ver);
	}	
	long RegExNoMac(LPCTSTR code, LPCTSTR Ver, LPCTSTR ip)
	{
		return m_pPlugIdentify->RegExNoMac(code, Ver, ip);
	}	
	long SetEnumWindowDelay(long delay)
	{
		return m_pPlugIdentify->SetEnumWindowDelay(delay);
	}	
	long FindMulColor(long x1, long y1, long x2, long y2, LPCTSTR color, double sim)
	{
		return m_pPlugIdentify->FindMulColor(x1, y1, x2, y2, color, sim);
	}	
	CString GetDict(long index, long font_index)
	{
		return m_pPlugIdentify->GetDict(index, font_index);
	}	
	long GetBindWindow()
	{
		return m_pPlugIdentify->GetBindWindow();
	}	
	long FoobarStartGif(long x, long y, LPCTSTR pic_name, long repeat_limit, long delay)
	{
		return m_pPlugIdentify->FoobarStartGif(m_hwnd, x, y, pic_name, repeat_limit, delay);
	}	
	long FoobarStopGif(long x, long y, LPCTSTR pic_name)
	{ 
		return m_pPlugIdentify->FoobarStopGif(m_hwnd, x, y, pic_name);
	}	
	long FreeProcessMemory()
	{
		return m_pPlugIdentify->FreeProcessMemory(m_hwnd);
	}	
	CString ReadFileData(LPCTSTR file, long start_pos, long end_pos)
	{
		return m_pPlugIdentify->ReadFileData(file, start_pos, end_pos);
	}	
	long VirtualAllocEx(long addr, long size, long type)
	{
		return m_pPlugIdentify->VirtualAllocEx(m_hwnd, addr, size, type);
	}	
	long VirtualFreeEx(long addr)
	{
		return m_pPlugIdentify->VirtualFreeEx(m_hwnd, addr);
	}	
	CString GetCommandLine()
	{
		return m_pPlugIdentify->GetCommandLine(m_hwnd);
	}	
	long TerminateProcess(long pid)
	{
		return m_pPlugIdentify->TerminateProcess(pid);
	}	
	CString GetNetTimeByIp(LPCTSTR ip)
	{
		return m_pPlugIdentify->GetNetTimeByIp(ip);
	}	
	CString EnumProcess(LPCTSTR name)
	{
		return m_pPlugIdentify->EnumProcess(name);
	}	
	CString GetProcessInfo(long pid)
	{
		return m_pPlugIdentify->GetProcessInfo(pid);
	}	
	long ReadIntAddr(long addr, long type)
	{
		return m_pPlugIdentify->ReadIntAddr(m_hwnd, addr, type);
	}	
	CString ReadDataAddr(long addr, long len)
	{
		return m_pPlugIdentify->ReadDataAddr(m_hwnd, addr, len);
	}	
	double ReadDoubleAddr(long addr)
	{
		return m_pPlugIdentify->ReadDoubleAddr(m_hwnd, addr);
	}	
	float ReadFloatAddr(long addr)
	{
		return m_pPlugIdentify->ReadFloatAddr(m_hwnd, addr);
	}	
	CString ReadStringAddr(long addr, long type, long len)
	{
		return m_pPlugIdentify->ReadStringAddr(m_hwnd, addr, type, len);
	}	
	long WriteDataAddr(long addr, LPCTSTR data)
	{
		return m_pPlugIdentify->WriteDataAddr(m_hwnd, addr, data);
	}	
	long WriteDoubleAddr(long addr, double v)
	{
		return m_pPlugIdentify->WriteDoubleAddr(m_hwnd, addr, v);
	}	
	long WriteFloatAddr(long addr, float v)
	{
		return m_pPlugIdentify->WriteFloatAddr(m_hwnd, addr, v);
	}	
	long WriteIntAddr(long addr, long type, long v)
	{
		return m_pPlugIdentify->WriteIntAddr(m_hwnd, addr, type, v);
	}	
	long WriteStringAddr(long addr, long type, LPCTSTR v)
	{ 
		return m_pPlugIdentify->WriteStringAddr(m_hwnd, addr, type, v);
	}	
	long Delays(long min_s, long max_s)
	{
		return m_pPlugIdentify->Delays(min_s, max_s);
	}	
	long FindColorBlock(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long count, long width, long height, long * lx, long * ly)
	{
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->FindColorBlock(x1, y1, x2, y2, color, sim, count, width, height, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		return lRet;
	}	
	CString FindColorBlockEx(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long count, long width, long height)
	{ 
		return m_pPlugIdentify->FindColorBlockEx(x1, y1, x2, y2, color, sim, count, width, height);
	}	
	long OpenProcess(long pid)
	{
		return m_pPlugIdentify->OpenProcess(pid);
	}	
	CString EnumIniSection(LPCTSTR file)
	{
		return m_pPlugIdentify->EnumIniSection(file);
	}	
	CString EnumIniSectionPwd(LPCTSTR file, LPCTSTR pwd)
	{
		return m_pPlugIdentify->EnumIniSectionPwd(file, pwd);
	}	
	CString EnumIniKey(LPCTSTR section, LPCTSTR file)
	{
		return m_pPlugIdentify->EnumIniKey(section, file);
	}	
	CString EnumIniKeyPwd(LPCTSTR section, LPCTSTR file, LPCTSTR pwd)
	{
		return m_pPlugIdentify->EnumIniKeyPwd(section, file, pwd);
	}	
	long SwitchBindWindow()
	{
		return m_pPlugIdentify->SwitchBindWindow(m_hwnd);
	}	
	long InitCri()
	{
		return m_pPlugIdentify->InitCri();
	}	
	long SendStringIme2(LPCTSTR str, long mode)
	{
		return m_pPlugIdentify->SendStringIme2(m_hwnd, str, mode);
	}	
	CString EnumWindowByProcessId(long pid, LPCTSTR title, LPCTSTR class_name, long filter)
	{ 
		return m_pPlugIdentify->EnumWindowByProcessId(pid, title, class_name, filter);
	}	
	CString GetDisplayInfo()
	{
		return m_pPlugIdentify->GetDisplayInfo();
	}	
	long EnableFontSmooth()
	{
		return m_pPlugIdentify->EnableFontSmooth();
	}	
	CString OcrExOne(long x1, long y1, long x2, long y2, LPCTSTR color, double sim)
	{
		return m_pPlugIdentify->OcrExOne(x1, y1, x2, y2, color, sim);
	}	
	long SetAero(long en)
	{
		return m_pPlugIdentify->SetAero(en);
	}	
	long FoobarSetTrans(long trans, LPCTSTR color, double sim)
	{
		return m_pPlugIdentify->FoobarSetTrans(m_hwnd, trans, color, sim);
	}	
	long EnablePicCache(long en)
	{
		return m_pPlugIdentify->EnablePicCache(en);
	}	
	CString GetInfo(LPCTSTR cmd, LPCTSTR param)
	{
		return m_pPlugIdentify->GetInfo(cmd, param);
	}	
	long FaqIsPosted()
	{
		return m_pPlugIdentify->FaqIsPosted();
	}	
	long LoadPicByte(long addr, long size, LPCTSTR name)
	{
		return m_pPlugIdentify->LoadPicByte(addr, size, name);
	}	
	long MiddleDown()
	{
		return m_pPlugIdentify->MiddleDown();
	}	
	long MiddleUp()
	{
		return m_pPlugIdentify->MiddleUp();
	}	

	// Idmsoft properties
public:

//////////////////////////////////////////////////////////////////////////
public:
	enum AIDPLUG_TYPE
	{
		AIDPLUG_NON = 0,
		AIDPLUG_PAY_DM,
		AIDPLUG_FREE_DM,

		AIDPLUG_ALL,
		AIDPLUG_INVALID = -1,
	};

	struct WidthHeight
	{
		long lWidth;
		long lHeight;
	};
	struct Coordinate
	{
		long lx;
		long ly;
	};
	long API_FindWindow();
	long API_BindWindow();
	long API_BindWindowNormal();
	long API_LeftClick(long x, long y, long lSleep);
	long API_CapturePreFromTime(CString strFolderPath);
	long API_CaptureFromTime(long x1, long y1, long x2, long y2, CString strFolderPath);

	WidthHeight API_GetPicSize(LPCTSTR pic_name);
	vector<Coordinate> API_FindMultiPic(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir);
	//模糊查找，用于找到多个相似图片不需要精确数据的情况，用于提高查找效率 0以中心点切分，1以四周切分
	vector<Coordinate> API_FindMultiPicBlur(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir, long lFindType);
	void API_SetHwnd(long hwnd) {m_hwnd = hwnd;}

	AIDPLUG_TYPE API_GetAidPlugType();
private:
	void InitResource();
	void API_FindMultiPicRecursion(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir, WidthHeight sMaxWidthHeight, vector<Coordinate>* vCoord);
	void API_FindMultiPicBlurRecursion(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir, long lFindType, vector<Coordinate>* vCoord);

	short vartoi(const _variant_t& var);
	long vartol(const _variant_t& var);
	double vartof(const _variant_t& var);
	CString vartocstring(_variant_t var);
public:
		
protected:
private:
	static AidPlugIdentifyIF* s_pcInstance;
	static const CString CSTRING_PASSWORD;
	static const CString CSTRING_CAPTURE_FOLDER;
	AidPlug* m_pPlugIdentify;
	long m_hwnd;
};
#endif // CXX_AIDPLUGIDENTIFYIF_H
/* EOF */
