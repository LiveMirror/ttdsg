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
		return m_pPlugIdentify->Ver();
	}
	long SetPath(LPCTSTR path)
	{
		return m_pPlugIdentify->SetPath(path);
	}
	CString Ocr(long x1, long y1, long x2, long y2, LPCTSTR color, double sim)
	{
		return m_pPlugIdentify->Ocr(x1, y1, x2, y2, color, sim);
	}
	long FindStr(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, long * lx, long * ly)
	{
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->FindStr(x1, y1, x2, y2, str, color, sim, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		return lRet;
	}
	long GetResultCount(LPCTSTR str)
	{
		return m_pPlugIdentify->GetResultCount(str);
	}
	long GetResultPos(LPCTSTR str, long index, long * lx, long * ly)
	{
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->GetResultPos(str, index, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		return lRet;
	}
	long StrStr(LPCTSTR s, LPCTSTR str)
	{
		return m_pPlugIdentify->StrStr(s, str);
	}
	long SendCommand(LPCTSTR cmd)
	{
		return m_pPlugIdentify->SendCommand(cmd);
	}
	long UseDict(long index)
	{
		return m_pPlugIdentify->UseDict(index);
	}
	CString GetBasePath()
	{
		return m_pPlugIdentify->GetBasePath();
	}
	long SetDictPwd(LPCTSTR pwd)
	{
		return m_pPlugIdentify->SetDictPwd(pwd);
	}
	CString OcrInFile(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR color, double sim)
	{
		return m_pPlugIdentify->OcrInFile(x1, y1, x2, y2, pic_name, color, sim);
	}
	long Capture(long x1, long y1, long x2, long y2, LPCTSTR file)
	{
		return m_pPlugIdentify->Capture(x1, y1, x2, y2, file);
	}
	long KeyPress(long vk)
	{
		return m_pPlugIdentify->KeyPress(vk);
	}
	long KeyDown(long vk)
	{
		return m_pPlugIdentify->KeyDown(vk);
	}
	long KeyUp(long vk)
	{
		return m_pPlugIdentify->KeyUp(vk);
	}
	long LeftClick()
	{
		return m_pPlugIdentify->LeftClick();
	}
	long RightClick()
	{
		return m_pPlugIdentify->RightClick();
	}
	long MiddleClick()
	{
		return m_pPlugIdentify->MiddleClick();
	}
	long LeftDoubleClick()
	{
		return m_pPlugIdentify->LeftDoubleClick();
	}
	long LeftDown()
	{
		return m_pPlugIdentify->LeftDown();
	}
	long LeftUp()
	{
		return m_pPlugIdentify->LeftUp();
	}
	long RightDown()
	{
		return m_pPlugIdentify->RightDown();
	}
	long RightUp()
	{
		return m_pPlugIdentify->RightUp();
	}
	long MoveTo(long x, long y)
	{
		return m_pPlugIdentify->MoveTo(x, y);
	}
	long MoveR(long rx, long ry)
	{
		return m_pPlugIdentify->MoveR(rx, ry);
	}
	CString GetColor(long x, long y)
	{
		return m_pPlugIdentify->GetColor(x, y);
	}
	CString GetColorBGR(long x, long y)
	{
		return m_pPlugIdentify->GetColorBGR(x, y);
	}
	CString RGB2BGR(LPCTSTR rgb_color)
	{
		return m_pPlugIdentify->RGB2BGR(rgb_color);
	}
	CString BGR2RGB(LPCTSTR bgr_color)
	{
		return m_pPlugIdentify->BGR2RGB(bgr_color);
	}
	long UnBindWindow()
	{
		API_SetHwnd(0x00);
		return m_pPlugIdentify->UnBindWindow();
	}
	long CmpColor(long x, long y, LPCTSTR color, double sim)
	{
		return m_pPlugIdentify->CmpColor(x, y, color, sim);
	}
	long ClientToScreen(long * lx, long * ly)
	{
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->ClientToScreen(m_hwnd, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		return lRet;
	}
	long ScreenToClient(long * lx, long * ly)
	{
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->ScreenToClient(m_hwnd, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		return lRet;
	}
	long ShowScrMsg(long x1, long y1, long x2, long y2, LPCTSTR msg, LPCTSTR color)
	{
		return m_pPlugIdentify->ShowScrMsg(x1, y1, x2, y2, msg, color);
	}
	long SetMinRowGap(long row_gap)
	{
		return m_pPlugIdentify->SetMinRowGap(row_gap);
	}
	long SetMinColGap(long col_gap)
	{
		return m_pPlugIdentify->SetMinColGap(col_gap);
	}
	long FindColor(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long dir, long * lx, long * ly)
	{
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->FindColor( x1, y1, x2, y2, color, sim, dir, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		return lRet;
	}
	CString FindColorEx(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long dir)
	{
		return m_pPlugIdentify->FindColorEx(x1, y1, x2, y2, color, sim, dir);
	}
	long SetWordLineHeight(long line_height)
	{
		return m_pPlugIdentify->SetWordLineHeight(line_height);
	}
	long SetWordGap(long word_gap)
	{
		return m_pPlugIdentify->SetWordGap(word_gap);
	}
	long SetRowGapNoDict(long row_gap)
	{
		return m_pPlugIdentify->SetRowGapNoDict(row_gap);
	}
	long SetColGapNoDict(long col_gap)
	{
		return m_pPlugIdentify->SetColGapNoDict(col_gap);
	}
	long SetWordLineHeightNoDict(long line_height)
	{
		return m_pPlugIdentify->SetWordLineHeightNoDict(line_height);
	}
	long SetWordGapNoDict(long word_gap)
	{
		return m_pPlugIdentify->SetWordGapNoDict(word_gap);
	}
	long GetWordResultCount(LPCTSTR str)
	{
		return m_pPlugIdentify->GetWordResultCount(str);
	}
	long GetWordResultPos(LPCTSTR str, long index, long * lx, long * ly)
	{
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->GetWordResultPos(str, index, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		return lRet;
	}
	CString GetWordResultStr(LPCTSTR str, long index)
	{
		return m_pPlugIdentify->GetWordResultStr(str, index);
	}
	CString GetWords(long x1, long y1, long x2, long y2, LPCTSTR color, double sim)
	{
		return m_pPlugIdentify->GetWords(x1, y1, x2, y2, color, sim);
	}
	CString GetWordsNoDict(long x1, long y1, long x2, long y2, LPCTSTR color)
	{
		return m_pPlugIdentify->GetWordsNoDict(x1, y1, x2, y2, color);
	}
	long SetShowErrorMsg(long show)
	{
		return m_pPlugIdentify->SetShowErrorMsg(show);
	}
	long GetClientSize(long * lWidth, long * lHeight)
	{
		VARIANT width;
		VARIANT height;
		long lRet = m_pPlugIdentify->GetClientSize(m_hwnd, &width, &height);
		*lWidth = vartol(width);
		*lHeight = vartol(height);
		return lRet;
	}
	long MoveWindow(long x, long y)
	{
		return m_pPlugIdentify->MoveWindow(m_hwnd, x, y);
	}
	CString GetColorHSV(long x, long y)
	{
		return m_pPlugIdentify->GetColorHSV(x, y);
	}
	CString GetAveRGB(long x1, long y1, long x2, long y2)
	{
		return m_pPlugIdentify->GetAveRGB(x1, y1, x2, y2);
	}
	CString GetAveHSV(long x1, long y1, long x2, long y2)
	{
		return m_pPlugIdentify->GetAveHSV(x1, y1, x2, y2);
	}
	long GetForegroundWindow()
	{
		return m_pPlugIdentify->GetForegroundWindow();
	}
	long GetForegroundFocus()
	{
		return m_pPlugIdentify->GetForegroundFocus();
	}
	long GetMousePointWindow()
	{
		return m_pPlugIdentify->GetMousePointWindow();
	}
	long GetPointWindow(long x, long y)
	{
		return m_pPlugIdentify->GetPointWindow(x, y);
	}
	CString EnumWindow(long parent, LPCTSTR title, LPCTSTR class_name, long filter)
	{
		return m_pPlugIdentify->EnumWindow(parent, title, class_name, filter);
	}
	long GetWindowState(long flag)
	{
		return m_pPlugIdentify->GetWindowState(m_hwnd, flag);
	}
	long GetWindow(long flag)
	{
		return m_pPlugIdentify->GetWindow(m_hwnd, flag);
	}
	long GetSpecialWindow(long flag)
	{
		return m_pPlugIdentify->GetSpecialWindow(flag);
	}
	long SetWindowText(LPCTSTR text)
	{
		return m_pPlugIdentify->SetWindowText(m_hwnd, text);
	}
	long SetWindowSize(long width, long height)
	{
		return m_pPlugIdentify->SetWindowSize(m_hwnd, width, height);
	}
	long GetWindowRect(VARIANT * x1, VARIANT * y1, VARIANT * x2, VARIANT * y2)
	{
		return m_pPlugIdentify->GetWindowRect(m_hwnd, x1, y1, x2, y2);
	}
	CString GetWindowTitle()
	{
		return m_pPlugIdentify->GetWindowTitle(m_hwnd);
	}
	CString GetWindowClass()
	{
		return m_pPlugIdentify->GetWindowClass(m_hwnd);
	}
	long SetWindowState(long flag)
	{
		return m_pPlugIdentify->SetWindowState(m_hwnd, flag);
	}
	long CreateFoobarRect(long x, long y, long w, long h)
	{
		return m_pPlugIdentify->CreateFoobarRect(m_hwnd, x, y, w, h);
	}
	long CreateFoobarRoundRect(long x, long y, long w, long h, long rw, long rh)
	{
		return m_pPlugIdentify->CreateFoobarRoundRect(m_hwnd, x, y, w, h, rw, rh);
	}
	long CreateFoobarEllipse(long x, long y, long w, long h)
	{
		return m_pPlugIdentify->CreateFoobarEllipse(m_hwnd, x, y, w, h);
	}
	long CreateFoobarCustom(long x, long y, LPCTSTR pic, LPCTSTR trans_color, double sim)
	{
		return m_pPlugIdentify->CreateFoobarCustom(m_hwnd, x, y, pic, trans_color, sim);
	}
	long FoobarFillRect(long x1, long y1, long x2, long y2, LPCTSTR color)
	{
		return m_pPlugIdentify->FoobarFillRect(m_hwnd, x1, y1, x2, y2, color);
	}
	long FoobarDrawText(long x, long y, long w, long h, LPCTSTR text, LPCTSTR color, long align)
	{
		return m_pPlugIdentify->FoobarDrawText(m_hwnd, x, y, w, h, text, color, align);
	}
	long FoobarDrawPic(long x, long y, LPCTSTR pic, LPCTSTR trans_color)
	{
		return m_pPlugIdentify->FoobarDrawPic(m_hwnd, x, y, pic, trans_color);
	}
	long FoobarUpdate()
	{
		return m_pPlugIdentify->FoobarUpdate(m_hwnd);
	}
	long FoobarLock()
	{
		return m_pPlugIdentify->FoobarLock(m_hwnd);
	}	
	long FoobarUnlock()
	{
		return m_pPlugIdentify->FoobarUnlock(m_hwnd);
	}	
	long FoobarSetFont(LPCTSTR font_name, long size, long flag)
	{ 
		return m_pPlugIdentify->FoobarSetFont(m_hwnd, font_name, size, flag);
	}	
	long FoobarTextRect(long x, long y, long w, long h)
	{
		return m_pPlugIdentify->FoobarTextRect(m_hwnd, x, y, w, h);
	}	
	long FoobarPrintText(LPCTSTR text, LPCTSTR color)
	{
		return m_pPlugIdentify->FoobarPrintText(m_hwnd, text, color);
	}	
	long FoobarClearText()
	{
		return m_pPlugIdentify->FoobarClearText(m_hwnd);
	}	
	long FoobarTextLineGap(long gap)
	{
		return m_pPlugIdentify->FoobarTextLineGap(m_hwnd, gap);
	}	
	long Play(LPCTSTR file)
	{
		return m_pPlugIdentify->Play(file);
	}	
	long FaqCapture(long x1, long y1, long x2, long y2, long quality, long delay, long time)
	{
		return m_pPlugIdentify->FaqCapture(x1, y1, x2, y2, quality, delay, time);
	}	
	long FaqRelease(long handle)
	{
		return m_pPlugIdentify->FaqRelease(handle);
	}	
	CString FaqSend(LPCTSTR server, long handle, long request_type, long time_out)
	{ 
		return m_pPlugIdentify->FaqSend(server, handle, request_type, time_out);
	}	
	long Beep(long fre, long delay)
	{
		return m_pPlugIdentify->Beep(fre, delay);
	}	
	long FoobarClose()
	{
		return m_pPlugIdentify->FoobarClose(m_hwnd);
	}	
	long MoveDD(long dx, long dy)
	{
		return m_pPlugIdentify->MoveDD(dx, dy);
	}	
	long FaqGetSize(long handle)
	{
		return m_pPlugIdentify->FaqGetSize(handle);
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
		return m_pPlugIdentify->GetScreenData(x1, y1, x2, y2);
	}	
	long FreeScreenData(long handle)
	{
		return m_pPlugIdentify->FreeScreenData(handle);
	}	
	long WheelUp()
	{
		return m_pPlugIdentify->WheelUp();
	}	
	long WheelDown()
	{
		return m_pPlugIdentify->WheelDown();
	}	
	long SetMouseDelay(LPCTSTR type, long delay)
	{
		return m_pPlugIdentify->SetMouseDelay(type, delay);
	}	
	long SetKeypadDelay(LPCTSTR type, long delay)
	{
		return m_pPlugIdentify->SetKeypadDelay(type, delay);
	}	
	CString GetEnv(long index, LPCTSTR name)
	{
		return m_pPlugIdentify->GetEnv(index, name);
	}	
	long SetEnv(long index, LPCTSTR name, LPCTSTR value)
	{
		return m_pPlugIdentify->SetEnv(index, name, value);
	}	
	long SendString(LPCTSTR str)
	{
		return m_pPlugIdentify->SendString(m_hwnd, str);
	}	
	long DelEnv(long index, LPCTSTR name)
	{
		return m_pPlugIdentify->DelEnv(index, name);
	}	
	CString GetPath()
	{
		return m_pPlugIdentify->GetPath();
	}	
	long SetDict(long index, LPCTSTR dict_name)
	{
		return m_pPlugIdentify->SetDict(index, dict_name);
	}	
	long FindPic(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir, long * lx, long * ly)
	{
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->FindPic(x1, y1, x2, y2, pic_name, delta_color, sim, dir, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		return lRet;
	}	
	CString FindPicEx(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir)
	{
		return m_pPlugIdentify->FindPicEx(x1, y1, x2, y2, pic_name, delta_color, sim, dir);
	}	
	long SetClientSize(long width, long height)
	{
		return m_pPlugIdentify->SetClientSize(m_hwnd, width, height);
	}	
	long ReadInt(LPCTSTR addr, long type)
	{
		return m_pPlugIdentify->ReadInt(m_hwnd, addr, type);
	}	
	float ReadFloat(LPCTSTR addr)
	{
		return m_pPlugIdentify->ReadFloat(m_hwnd, addr);
	}	
	double ReadDouble(LPCTSTR addr)
	{
		return m_pPlugIdentify->ReadDouble(m_hwnd, addr);
	}	
	CString FindInt(LPCTSTR addr_range, long int_value_min, long int_value_max, long type)
	{  
		return m_pPlugIdentify->FindInt(m_hwnd, addr_range, int_value_min, int_value_max, type);
	}	
	CString FindFloat(LPCTSTR addr_range, float float_value_min, float float_value_max)
	{ 
		return m_pPlugIdentify->FindFloat(m_hwnd, addr_range, float_value_min, float_value_max);
	}	
	CString FindDouble(LPCTSTR addr_range, double double_value_min, double double_value_max)
	{ 
		return m_pPlugIdentify->FindDouble(m_hwnd, addr_range, double_value_min, double_value_max);
	}	
	CString FindString(LPCTSTR addr_range, LPCTSTR string_value, long type)
	{ 
		return m_pPlugIdentify->FindString(m_hwnd, addr_range, string_value, type);
	}	
	long GetModuleBaseAddr(LPCTSTR module_name)
	{
		return m_pPlugIdentify->GetModuleBaseAddr(m_hwnd, module_name);
	}	
	CString MoveToEx(long x, long y, long w, long h)
	{
		return m_pPlugIdentify->MoveToEx(x, y, w, h);
	}	
	CString MatchPicName(LPCTSTR pic_name)
	{
		return m_pPlugIdentify->MatchPicName(pic_name);
	}	
	long AddDict(long index, LPCTSTR dict_info)
	{
		return m_pPlugIdentify->AddDict(index, dict_info);
	}	
	long EnterCri()
	{
		return m_pPlugIdentify->EnterCri();
	}	
	long LeaveCri()
	{
		return m_pPlugIdentify->LeaveCri();
	}	
	long WriteInt(LPCTSTR addr, long type, long v)
	{ 
		return m_pPlugIdentify->WriteInt(m_hwnd, addr, type, v);
	}	
	long WriteFloat(LPCTSTR addr, float v)
	{
		return m_pPlugIdentify->WriteFloat(m_hwnd, addr, v);
	}	
	long WriteDouble(LPCTSTR addr, double v)
	{
		return m_pPlugIdentify->WriteDouble(m_hwnd, addr, v);
	}	
	long WriteString(LPCTSTR addr, long type, LPCTSTR v)
	{ 
		return m_pPlugIdentify->WriteString(m_hwnd, addr, type, v);
	}	
	long AsmAdd(LPCTSTR asm_ins)
	{
		return m_pPlugIdentify->AsmAdd(asm_ins);
	}	
	long AsmClear()
	{
		return m_pPlugIdentify->AsmClear();
	}	
	long AsmCall(long mode)
	{
		return m_pPlugIdentify->AsmCall(m_hwnd, mode);
	}	
	long FindMultiColor(long x1, long y1, long x2, long y2, LPCTSTR first_color, LPCTSTR offset_color, double sim, long dir, long * lx, long * ly)
	{
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->FindMultiColor(x1, y1, x2, y2, first_color, offset_color, sim, dir, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		return lRet;
	}	
	CString FindMultiColorEx(long x1, long y1, long x2, long y2, LPCTSTR first_color, LPCTSTR offset_color, double sim, long dir)
	{
		return m_pPlugIdentify->FindMultiColorEx(x1, y1, x2, y2, first_color, offset_color, sim, dir);
	}	
	CString AsmCode(long base_addr)
	{
		return m_pPlugIdentify->AsmCode(base_addr);
	}	
	CString Assemble(LPCTSTR asm_code, long base_addr, long is_upper)
	{
		return m_pPlugIdentify->Assemble(asm_code, base_addr, is_upper);
	}	
	long SetWindowTransparent(long v)
	{
		return m_pPlugIdentify->SetWindowTransparent(m_hwnd, v);
	}	
	CString ReadData(LPCTSTR addr, long len)
	{
		return m_pPlugIdentify->ReadData(m_hwnd, addr, len);
	}	
	long WriteData(LPCTSTR addr, LPCTSTR data)
	{
		return m_pPlugIdentify->WriteData(m_hwnd, addr, data);
	}	
	CString FindData(LPCTSTR addr_range, LPCTSTR data)
	{
		return m_pPlugIdentify->FindData(m_hwnd, addr_range, data);
	}	
	long SetPicPwd(LPCTSTR pwd)
	{
		return m_pPlugIdentify->SetPicPwd(pwd);
	}	
	long Log(LPCTSTR info)
	{
		return m_pPlugIdentify->Log(info);
	}	
	CString FindStrE(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim)
	{
		return m_pPlugIdentify->FindStrE(x1, y1, x2, y2, str, color, sim);
	}	
	CString FindColorE(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long dir)
	{
		return m_pPlugIdentify->FindColorE(x1, y1, x2, y2, color, sim, dir);
	}	
	CString FindPicE(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir)
	{
		return m_pPlugIdentify->FindPicE(x1, y1, x2, y2, pic_name, delta_color, sim, dir);
	}	
	CString FindMultiColorE(long x1, long y1, long x2, long y2, LPCTSTR first_color, LPCTSTR offset_color, double sim, long dir)
	{
		return m_pPlugIdentify->FindMultiColorE(x1, y1, x2, y2, first_color, offset_color, sim, dir);
	}	
	long SetExactOcr(long exact_ocr)
	{
		return m_pPlugIdentify->SetExactOcr(exact_ocr);
	}	
	CString ReadString(LPCTSTR addr, long type, long len)
	{ 
		return m_pPlugIdentify->ReadString(m_hwnd, addr, type, len);
	}	
	long FoobarTextPrintDir(long dir)
	{
		return m_pPlugIdentify->FoobarTextPrintDir(m_hwnd, dir);
	}	
	CString OcrEx(long x1, long y1, long x2, long y2, LPCTSTR color, double sim)
	{
		return m_pPlugIdentify->OcrEx(x1, y1, x2, y2, color, sim);
	}	
	long SetDisplayInput(LPCTSTR mode)
	{
		return m_pPlugIdentify->SetDisplayInput(mode);
	}	
	long GetTime()
	{
		return m_pPlugIdentify->GetTime();
	}	
	long GetScreenWidth()
	{
		return m_pPlugIdentify->GetScreenWidth();
	}	
	long GetScreenHeight()
	{
		return m_pPlugIdentify->GetScreenHeight();
	}	
	long BindWindowEx(LPCTSTR display, LPCTSTR mouse, LPCTSTR keypad, LPCTSTR public_desc, long mode)
	{   
		return m_pPlugIdentify->BindWindowEx(m_hwnd, display, mouse, keypad, public_desc, mode);
	}	
	CString GetDiskSerial()
	{
		return m_pPlugIdentify->GetDiskSerial();
	}	
	CString Md5(LPCTSTR str)
	{
		return m_pPlugIdentify->Md5(str);
	}	
	CString GetMac()
	{
		return m_pPlugIdentify->GetMac();
	}	
	long ActiveInputMethod(LPCTSTR id)
	{
		return m_pPlugIdentify->ActiveInputMethod(m_hwnd, id);
	}	
	long CheckInputMethod(LPCTSTR id)
	{
		return m_pPlugIdentify->CheckInputMethod(m_hwnd, id);
	}	
	long FindInputMethod(LPCTSTR id)
	{
		return m_pPlugIdentify->FindInputMethod(id);
	}	
	long GetCursorPos(long * lx, long * ly)
	{
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->GetCursorPos(&x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		return lRet;
	}	
	long BindWindow(LPCTSTR display, LPCTSTR mouse, LPCTSTR keypad, long mode)
	{  
		return m_pPlugIdentify->BindWindow(m_hwnd, display, mouse, keypad, mode);
	}	
	long FindWindow(LPCTSTR class_name, LPCTSTR title_name)
	{
		return m_pPlugIdentify->FindWindow(class_name, title_name);
	}	
	long GetScreenDepth()
	{
		return m_pPlugIdentify->GetScreenDepth();
	}	
	long SetScreen(long width, long height, long depth)
	{
		return m_pPlugIdentify->SetScreen(width, height, depth);
	}	
	long ExitOs(long type)
	{
		return m_pPlugIdentify->ExitOs(type);
	}	
	CString GetDir(long type)
	{
		return m_pPlugIdentify->GetDir(type);
	}	
	long GetOsType()
	{
		return m_pPlugIdentify->GetOsType();
	}	
	long FindWindowEx(long parent, LPCTSTR class_name, LPCTSTR title_name)
	{
		return m_pPlugIdentify->FindWindowEx(parent, class_name, title_name);
	}	
	long SetExportDict(long index, LPCTSTR dict_name)
	{
		return m_pPlugIdentify->SetExportDict(index, dict_name);
	}	
	CString GetCursorShape()
	{
		return m_pPlugIdentify->GetCursorShape();
	}	
	long DownCpu(long rate)
	{
		return m_pPlugIdentify->DownCpu(rate);
	}	
	CString GetCursorSpot()
	{
		return m_pPlugIdentify->GetCursorSpot();
	}	
	long SendString2(LPCTSTR str)
	{
		return m_pPlugIdentify->SendString2(m_hwnd, str);
	}	
	long FaqPost(LPCTSTR server, long handle, long request_type, long time_out)
	{ 
		return m_pPlugIdentify->FaqPost(server, handle, request_type, time_out);
	}	
	CString FaqFetch()
	{
		return m_pPlugIdentify->FaqFetch();
	}	
	CString FetchWord(long x1, long y1, long x2, long y2, LPCTSTR color, LPCTSTR word)
	{   
		return m_pPlugIdentify->FetchWord(x1, y1, x2, y2, color, word);
	}	
	long CaptureJpg(long x1, long y1, long x2, long y2, LPCTSTR file, long quality)
	{   
		return m_pPlugIdentify->CaptureJpg(x1, y1, x2, y2, file, quality);
	}	
	long FindStrWithFont(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, LPCTSTR font_name, long font_size, long flag, long * lx, long * ly)
	{
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->FindStrWithFont(x1, y1, x2, y2, str, color, sim, font_name, font_size, flag, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		return lRet;
	}	
	CString FindStrWithFontE(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, LPCTSTR font_name, long font_size, long flag)
	{  
		return m_pPlugIdentify->FindStrWithFontE(x1, y1, x2, y2, str, color, sim, font_name, font_size, flag);
	}	
	CString FindStrWithFontEx(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, LPCTSTR font_name, long font_size, long flag)
	{  
		return m_pPlugIdentify->FindStrWithFontEx(x1, y1, x2, y2, str, color, sim, font_name, font_size, flag);
	}	
	CString GetDictInfo(LPCTSTR str, LPCTSTR font_name, long font_size, long flag)
	{ 
		return m_pPlugIdentify->GetDictInfo(str, font_name, font_size, flag);
	}	
	long SaveDict(long index, LPCTSTR file)
	{
		return m_pPlugIdentify->SaveDict(index, file);
	}	
	long GetWindowProcessId()
	{
		return m_pPlugIdentify->GetWindowProcessId(m_hwnd);
	}	
	CString GetWindowProcessPath()
	{
		return m_pPlugIdentify->GetWindowProcessPath(m_hwnd);
	}	
	long LockInput(long lock)
	{
		return m_pPlugIdentify->LockInput(lock);
	}	
	CString GetPicSize(LPCTSTR pic_name)
	{
		return m_pPlugIdentify->GetPicSize(pic_name);
	}	
	long GetID()
	{
		return m_pPlugIdentify->GetID();
	}	
	long CapturePng(long x1, long y1, long x2, long y2, LPCTSTR file)
	{  
		return m_pPlugIdentify->CapturePng(x1, y1, x2, y2, file);
	}	
	long CaptureGif(long x1, long y1, long x2, long y2, LPCTSTR file, long delay, long time)
	{
		return m_pPlugIdentify->CaptureGif(x1, y1, x2, y2, file, delay, time);
	}	
	long ImageToBmp(LPCTSTR pic_name, LPCTSTR bmp_name)
	{
		return m_pPlugIdentify->ImageToBmp(pic_name, bmp_name);
	}	
	long FindStrFast(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, long * lx, long * ly)
	{
		VARIANT x;
		VARIANT y;
		long lRet = m_pPlugIdentify->FindStrFast(x1, y1, x2, y2, str, color, sim, &x, &y);
		*lx = vartol(x);
		*ly = vartol(y);
		return lRet;
	}	
	CString FindStrFastEx(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim)
	{
		return m_pPlugIdentify->FindStrFastEx(x1, y1, x2, y2, str, color, sim);
	}	
	CString FindStrFastE(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim)
	{
		return m_pPlugIdentify->FindStrFastE(x1, y1, x2, y2, str, color, sim);
	}	
	long EnableDisplayDebug(long enable_debug)
	{
		return m_pPlugIdentify->EnableDisplayDebug(enable_debug);
	}	
	long CapturePre(LPCTSTR file)
	{
		return m_pPlugIdentify->CapturePre(file);
	}	
	long RegEx(LPCTSTR code, LPCTSTR Ver, LPCTSTR ip)
	{
		return m_pPlugIdentify->RegEx(code, Ver, ip);
	}	
	CString GetMachineCode()
	{
		return m_pPlugIdentify->GetMachineCode();
	}	
	long SetClipboard(LPCTSTR data)
	{
		return m_pPlugIdentify->SetClipboard(data);
	}	
	CString GetClipboard()
	{
		return m_pPlugIdentify->GetClipboard();
	}	
	long GetNowDict()
	{
		return m_pPlugIdentify->GetNowDict();
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
