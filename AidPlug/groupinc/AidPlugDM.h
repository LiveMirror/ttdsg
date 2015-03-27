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
#pragma warning (disable:4927)	//取消警告

#ifndef CXX_AIDPLUGDM_H
#define CXX_AIDPLUGDM_H

#ifndef CXX_AIDPLUG_H
#include "AidPlug.h"
#endif

class AidPlugDM : public AidPlug
{
public:
	AidPlugDM();
	~AidPlugDM();

	// Attributes
public:

	// Operations
public:


	// Idmsoft methods
public:
	CString Ver()
	{
		return m_pIdmsoft->Ver();
	}
	long SetPath(LPCTSTR path)
	{
		return m_pIdmsoft->SetPath(path);
	}
	CString Ocr(long x1, long y1, long x2, long y2, LPCTSTR color, double sim)
	{
		return m_pIdmsoft->Ocr(x1, y1, x2, y2, color, sim);
	}
	long FindStr(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, VARIANT * x, VARIANT * y)
	{
		return m_pIdmsoft->FindStr(x1, y1, x2, y2, str, color, sim, x, y);
	}
	long GetResultCount(LPCTSTR str)
	{
		return m_pIdmsoft->GetResultCount(str);
	}
	long GetResultPos(LPCTSTR str, long index, VARIANT * x, VARIANT * y)
	{
		return m_pIdmsoft->GetResultPos(str, index, x, y);
	}
	long StrStr(LPCTSTR s, LPCTSTR str)
	{
		return m_pIdmsoft->StrStr(s, str);
	}
	long SendCommand(LPCTSTR cmd)
	{
		return m_pIdmsoft->SendCommand(cmd);
	}
	long UseDict(long index)
	{
		return m_pIdmsoft->UseDict(index);
	}
	CString GetBasePath()
	{
		return m_pIdmsoft->GetBasePath();
	}
	long SetDictPwd(LPCTSTR pwd)
	{
		return m_pIdmsoft->SetDictPwd(pwd);
	}
	CString OcrInFile(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR color, double sim)
	{
		return m_pIdmsoft->OcrInFile(x1, y1, x2, y2, pic_name, color, sim);
	}
	long Capture(long x1, long y1, long x2, long y2, LPCTSTR file)
	{
		return m_pIdmsoft->Capture(x1, y1, x2, y2, file);
	}
	long KeyPress(long vk)
	{
		return m_pIdmsoft->KeyPress(vk);
	}
	long KeyDown(long vk)
	{
		return m_pIdmsoft->KeyDown(vk);
	}
	long KeyUp(long vk)
	{
		return m_pIdmsoft->KeyUp(vk);
	}
	long LeftClick()
	{
		return m_pIdmsoft->LeftClick();
	}
	long RightClick()
	{
		return m_pIdmsoft->RightClick();
	}
	long MiddleClick()
	{
		return m_pIdmsoft->MiddleClick();
	}
	long LeftDoubleClick()
	{
		return m_pIdmsoft->LeftDoubleClick();
	}
	long LeftDown()
	{
		return m_pIdmsoft->LeftDown();
	}
	long LeftUp()
	{
		return m_pIdmsoft->LeftUp();
	}
	long RightDown()
	{
		return m_pIdmsoft->RightDown();
	}
	long RightUp()
	{
		return m_pIdmsoft->RightUp();
	}
	long MoveTo(long x, long y)
	{
		return m_pIdmsoft->MoveTo(x, y);
	}
	long MoveR(long rx, long ry)
	{
		return m_pIdmsoft->MoveR(rx, ry);
	}
	CString GetColor(long x, long y)
	{
		return m_pIdmsoft->GetColor(x, y);
	}
	CString GetColorBGR(long x, long y)
	{
		return m_pIdmsoft->GetColorBGR(x, y);
	}
	CString RGB2BGR(LPCTSTR rgb_color)
	{
		return m_pIdmsoft->RGB2BGR(rgb_color);
	}
	CString BGR2RGB(LPCTSTR bgr_color)
	{
		return m_pIdmsoft->BGR2RGB(bgr_color);
	}
	long UnBindWindow()
	{
		return m_pIdmsoft->UnBindWindow();
	}
	long CmpColor(long x, long y, LPCTSTR color, double sim)
	{
		return m_pIdmsoft->CmpColor(x, y, color, sim);
	}
	long ClientToScreen(long hwnd, VARIANT * x, VARIANT * y)
	{
		return m_pIdmsoft->ClientToScreen(hwnd, x, y);
	}
	long ScreenToClient(long hwnd, VARIANT * x, VARIANT * y)
	{
		return m_pIdmsoft->ScreenToClient(hwnd, x, y);
	}
	long ShowScrMsg(long x1, long y1, long x2, long y2, LPCTSTR msg, LPCTSTR color)
	{
		return m_pIdmsoft->ShowScrMsg(x1, y1, x2, y2, msg, color);
	}
	long SetMinRowGap(long row_gap)
	{
		return m_pIdmsoft->SetMinRowGap(row_gap);
	}
	long SetMinColGap(long col_gap)
	{
		return m_pIdmsoft->SetMinColGap(col_gap);
	}
	long FindColor(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long dir, VARIANT * x, VARIANT * y)
	{
		return m_pIdmsoft->FindColor( x1, y1, x2, y2, color, sim, dir, x, y);
	}
	CString FindColorEx(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long dir)
	{
		return m_pIdmsoft->FindColorEx(x1, y1, x2, y2, color, sim, dir);
	}
	long SetWordLineHeight(long line_height)
	{
		return m_pIdmsoft->SetWordLineHeight(line_height);
	}
	long SetWordGap(long word_gap)
	{
		return m_pIdmsoft->SetWordGap(word_gap);
	}
	long SetRowGapNoDict(long row_gap)
	{
		return m_pIdmsoft->SetRowGapNoDict(row_gap);
	}
	long SetColGapNoDict(long col_gap)
	{
		return m_pIdmsoft->SetColGapNoDict(col_gap);
	}
	long SetWordLineHeightNoDict(long line_height)
	{
		return m_pIdmsoft->SetWordLineHeightNoDict(line_height);
	}
	long SetWordGapNoDict(long word_gap)
	{
		return m_pIdmsoft->SetWordGapNoDict(word_gap);
	}
	long GetWordResultCount(LPCTSTR str)
	{
		return m_pIdmsoft->GetWordResultCount(str);
	}
	long GetWordResultPos(LPCTSTR str, long index, VARIANT * x, VARIANT * y)
	{
		return m_pIdmsoft->GetWordResultPos(str, index, x, y);
	}
	CString GetWordResultStr(LPCTSTR str, long index)
	{
		return m_pIdmsoft->GetWordResultStr(str, index);
	}
	CString GetWords(long x1, long y1, long x2, long y2, LPCTSTR color, double sim)
	{
		return m_pIdmsoft->GetWords(x1, y1, x2, y2, color, sim);
	}
	CString GetWordsNoDict(long x1, long y1, long x2, long y2, LPCTSTR color)
	{
		return m_pIdmsoft->GetWordsNoDict(x1, y1, x2, y2, color);
	}
	long SetShowErrorMsg(long show)
	{
		return m_pIdmsoft->SetShowErrorMsg(show);
	}
	long GetClientSize(long hwnd, VARIANT * width, VARIANT * height)
	{
		return m_pIdmsoft->GetClientSize(hwnd, width, height);
	}
	long MoveWindow(long hwnd, long x, long y)
	{
		return m_pIdmsoft->MoveWindow(hwnd, x, y);
	}
	CString GetColorHSV(long x, long y)
	{
		return m_pIdmsoft->GetColorHSV(x, y);
	}
	CString GetAveRGB(long x1, long y1, long x2, long y2)
	{
		return m_pIdmsoft->GetAveRGB(x1, y1, x2, y2);
	}
	CString GetAveHSV(long x1, long y1, long x2, long y2)
	{
		return m_pIdmsoft->GetAveHSV(x1, y1, x2, y2);
	}
	long GetForegroundWindow()
	{
		return m_pIdmsoft->GetForegroundWindow();
	}
	long GetForegroundFocus()
	{
		return m_pIdmsoft->GetForegroundFocus();
	}
	long GetMousePointWindow()
	{
		return m_pIdmsoft->GetMousePointWindow();
	}
	long GetPointWindow(long x, long y)
	{
		return m_pIdmsoft->GetPointWindow(x, y);
	}
	CString EnumWindow(long parent, LPCTSTR title, LPCTSTR class_name, long filter)
	{
		return m_pIdmsoft->EnumWindow(parent, title, class_name, filter);
	}
	long GetWindowState(long hwnd, long flag)
	{
		return m_pIdmsoft->GetWindowState(hwnd, flag);
	}
	long GetWindow(long hwnd, long flag)
	{
		return m_pIdmsoft->GetWindow(hwnd, flag);
	}
	long GetSpecialWindow(long flag)
	{
		return m_pIdmsoft->GetSpecialWindow(flag);
	}
	long SetWindowText(long hwnd, LPCTSTR text)
	{
		return m_pIdmsoft->SetWindowText(hwnd, text);
	}
	long SetWindowSize(long hwnd, long width, long height)
	{
		return m_pIdmsoft->SetWindowSize(hwnd, width, height);
	}
	long GetWindowRect(long hwnd, VARIANT * x1, VARIANT * y1, VARIANT * x2, VARIANT * y2)
	{
		return m_pIdmsoft->GetWindowRect(hwnd, x1, y1, x2, y2);
	}
	CString GetWindowTitle(long hwnd)
	{
		return m_pIdmsoft->GetWindowTitle(hwnd);
	}
	CString GetWindowClass(long hwnd)
	{
		return m_pIdmsoft->GetWindowClass(hwnd);
	}
	long SetWindowState(long hwnd, long flag)
	{
		return m_pIdmsoft->SetWindowState(hwnd, flag);
	}
	long CreateFoobarRect(long hwnd, long x, long y, long w, long h)
	{
		return m_pIdmsoft->CreateFoobarRect(hwnd, x, y, w, h);
	}
	long CreateFoobarRoundRect(long hwnd, long x, long y, long w, long h, long rw, long rh)
	{
		return m_pIdmsoft->CreateFoobarRoundRect(hwnd, x, y, w, h, rw, rh);
	}
	long CreateFoobarEllipse(long hwnd, long x, long y, long w, long h)
	{
		return m_pIdmsoft->CreateFoobarEllipse(hwnd, x, y, w, h);
	}
	long CreateFoobarCustom(long hwnd, long x, long y, LPCTSTR pic, LPCTSTR trans_color, double sim)
	{
		return m_pIdmsoft->CreateFoobarCustom(hwnd, x, y, pic, trans_color, sim);
	}
	long FoobarFillRect(long hwnd, long x1, long y1, long x2, long y2, LPCTSTR color)
	{
		return m_pIdmsoft->FoobarFillRect(hwnd, x1, y1, x2, y2, color);
	}
	long FoobarDrawText(long hwnd, long x, long y, long w, long h, LPCTSTR text, LPCTSTR color, long align)
	{
		return m_pIdmsoft->FoobarDrawText(hwnd, x, y, w, h, text, color, align);
	}
	long FoobarDrawPic(long hwnd, long x, long y, LPCTSTR pic, LPCTSTR trans_color)
	{
		return m_pIdmsoft->FoobarDrawPic(hwnd, x, y, pic, trans_color);
	}
	long FoobarUpdate(long hwnd)
	{
		return m_pIdmsoft->FoobarUpdate(hwnd);
	}
	long FoobarLock(long hwnd)
	{
		return m_pIdmsoft->FoobarLock(hwnd);
	}	
	long FoobarUnlock(long hwnd)
	{
		return m_pIdmsoft->FoobarUnlock(hwnd);
	}	
	long FoobarSetFont(long hwnd, LPCTSTR font_name, long size, long flag)
	{ 
		return m_pIdmsoft->FoobarSetFont(hwnd, font_name, size, flag);
	}	
	long FoobarTextRect(long hwnd, long x, long y, long w, long h)
	{
		return m_pIdmsoft->FoobarTextRect(hwnd, x, y, w, h);
	}	
	long FoobarPrintText(long hwnd, LPCTSTR text, LPCTSTR color)
	{
		return m_pIdmsoft->FoobarPrintText(hwnd, text, color);
	}	
	long FoobarClearText(long hwnd)
	{
		return m_pIdmsoft->FoobarClearText(hwnd);
	}	
	long FoobarTextLineGap(long hwnd, long gap)
	{
		return m_pIdmsoft->FoobarTextLineGap(hwnd, gap);
	}	
	long Play(LPCTSTR file)
	{
		return m_pIdmsoft->Play(file);
	}	
	long FaqCapture(long x1, long y1, long x2, long y2, long quality, long delay, long time)
	{
		return m_pIdmsoft->FaqCapture(x1, y1, x2, y2, quality, delay, time);
	}	
	long FaqRelease(long handle)
	{
		return m_pIdmsoft->FaqRelease(handle);
	}	
	CString FaqSend(LPCTSTR server, long handle, long request_type, long time_out)
	{ 
		return m_pIdmsoft->FaqSend(server, handle, request_type, time_out);
	}	
	long Beep(long fre, long delay)
	{
		return m_pIdmsoft->Beep(fre, delay);
	}	
	long FoobarClose(long hwnd)
	{
		return m_pIdmsoft->FoobarClose(hwnd);
	}	
	long MoveDD(long dx, long dy)
	{
		return m_pIdmsoft->MoveDD(dx, dy);
	}	
	long FaqGetSize(long handle)
	{
		return m_pIdmsoft->FaqGetSize(handle);
	}	
	long LoadPic(LPCTSTR pic_name)
	{
		ASSERT(0);
		return 0;
//		return m_pIdmsoft->(pic_name);
	}	
	long FreePic(LPCTSTR pic_name)
	{
		ASSERT(0);
		return 0;
//		return m_pIdmsoft->FreePic(pic_name);
	}	
	long GetScreenData(long x1, long y1, long x2, long y2)
	{
		return m_pIdmsoft->GetScreenData(x1, y1, x2, y2);
	}	
	long FreeScreenData(long handle)
	{
		return m_pIdmsoft->FreeScreenData(handle);
	}	
	long WheelUp()
	{
		return m_pIdmsoft->WheelUp();
	}	
	long WheelDown()
	{
		return m_pIdmsoft->WheelDown();
	}	
	long SetMouseDelay(LPCTSTR type, long delay)
	{
		return m_pIdmsoft->SetMouseDelay(type, delay);
	}	
	long SetKeypadDelay(LPCTSTR type, long delay)
	{
		return m_pIdmsoft->SetKeypadDelay(type, delay);
	}	
	CString GetEnv(long index, LPCTSTR name)
	{
		return m_pIdmsoft->GetEnv(index, name);
	}	
	long SetEnv(long index, LPCTSTR name, LPCTSTR value)
	{
		return m_pIdmsoft->SetEnv(index, name, value);
	}	
	long SendString(long hwnd, LPCTSTR str)
	{
		return m_pIdmsoft->SendString(hwnd, str);
	}	
	long DelEnv(long index, LPCTSTR name)
	{
		return m_pIdmsoft->DelEnv(index, name);
	}	
	CString GetPath()
	{
		return m_pIdmsoft->GetPath();
	}	
	long SetDict(long index, LPCTSTR dict_name)
	{
		return m_pIdmsoft->SetDict(index, dict_name);
	}	
	long FindPic(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir, VARIANT * x, VARIANT * y)
	{
		return m_pIdmsoft->FindPic(x1, y1, x2, y2, pic_name, delta_color, sim, dir, x, y);
	}	
	CString FindPicEx(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir)
	{
		return m_pIdmsoft->FindPicEx(x1, y1, x2, y2, pic_name, delta_color, sim, dir);
	}	
	long SetClientSize(long hwnd, long width, long height)
	{
		return m_pIdmsoft->SetClientSize(hwnd, width, height);
	}	
	long ReadInt(long hwnd, LPCTSTR addr, long type)
	{
		return m_pIdmsoft->ReadInt(hwnd, addr, type);
	}	
	float ReadFloat(long hwnd, LPCTSTR addr)
	{
		return m_pIdmsoft->ReadFloat(hwnd, addr);
	}	
	double ReadDouble(long hwnd, LPCTSTR addr)
	{
		return m_pIdmsoft->ReadDouble(hwnd, addr);
	}	
	CString FindInt(long hwnd, LPCTSTR addr_range, long int_value_min, long int_value_max, long type)
	{  
		return m_pIdmsoft->FindInt(hwnd, addr_range, int_value_min, int_value_max, type);
	}	
	CString FindFloat(long hwnd, LPCTSTR addr_range, float float_value_min, float float_value_max)
	{ 
		return m_pIdmsoft->FindFloat(hwnd, addr_range, float_value_min, float_value_max);
	}	
	CString FindDouble(long hwnd, LPCTSTR addr_range, double double_value_min, double double_value_max)
	{ 
		return m_pIdmsoft->FindDouble(hwnd, addr_range, double_value_min, double_value_max);
	}	
	CString FindString(long hwnd, LPCTSTR addr_range, LPCTSTR string_value, long type)
	{ 
		return m_pIdmsoft->FindString(hwnd, addr_range, string_value, type);
	}	
	long GetModuleBaseAddr(long hwnd, LPCTSTR module_name)
	{
		return m_pIdmsoft->GetModuleBaseAddr(hwnd, module_name);
	}	
	CString MoveToEx(long x, long y, long w, long h)
	{
		return m_pIdmsoft->MoveToEx(x, y, w, h);
	}	
	CString MatchPicName(LPCTSTR pic_name)
	{
		return m_pIdmsoft->MatchPicName(pic_name);
	}	
	long AddDict(long index, LPCTSTR dict_info)
	{
		return m_pIdmsoft->AddDict(index, dict_info);
	}	
	long EnterCri()
	{
		return m_pIdmsoft->EnterCri();
	}	
	long LeaveCri()
	{
		return m_pIdmsoft->LeaveCri();
	}	
	long WriteInt(long hwnd, LPCTSTR addr, long type, long v)
	{ 
		return m_pIdmsoft->WriteInt(hwnd, addr, type, v);
	}	
	long WriteFloat(long hwnd, LPCTSTR addr, float v)
	{
		return m_pIdmsoft->WriteFloat(hwnd, addr, v);
	}	
	long WriteDouble(long hwnd, LPCTSTR addr, double v)
	{
		return m_pIdmsoft->WriteDouble(hwnd, addr, v);
	}	
	long WriteString(long hwnd, LPCTSTR addr, long type, LPCTSTR v)
	{ 
		return m_pIdmsoft->WriteString(hwnd, addr, type, v);
	}	
	long AsmAdd(LPCTSTR asm_ins)
	{
		return m_pIdmsoft->AsmAdd(asm_ins);
	}	
	long AsmClear()
	{
		return m_pIdmsoft->AsmClear();
	}	
	long AsmCall(long hwnd, long mode)
	{
		return m_pIdmsoft->AsmCall(hwnd, mode);
	}	
	long FindMultiColor(long x1, long y1, long x2, long y2, LPCTSTR first_color, LPCTSTR offset_color, double sim, long dir, VARIANT * x, VARIANT * y)
	{
		return m_pIdmsoft->FindMultiColor(x1, y1, x2, y2, first_color, offset_color, sim, dir, x, y);
	}	
	CString FindMultiColorEx(long x1, long y1, long x2, long y2, LPCTSTR first_color, LPCTSTR offset_color, double sim, long dir)
	{
		return m_pIdmsoft->FindMultiColorEx(x1, y1, x2, y2, first_color, offset_color, sim, dir);
	}	
	CString AsmCode(long base_addr)
	{
		return m_pIdmsoft->AsmCode(base_addr);
	}	
	CString Assemble(LPCTSTR asm_code, long base_addr, long is_upper)
	{
		return m_pIdmsoft->Assemble(asm_code, base_addr, is_upper);
	}	
	long SetWindowTransparent(long hwnd, long v)
	{
		return m_pIdmsoft->SetWindowTransparent(hwnd, v);
	}	
	CString ReadData(long hwnd, LPCTSTR addr, long len)
	{
		return m_pIdmsoft->ReadData(hwnd, addr, len);
	}	
	long WriteData(long hwnd, LPCTSTR addr, LPCTSTR data)
	{
		return m_pIdmsoft->WriteData(hwnd, addr, data);
	}	
	CString FindData(long hwnd, LPCTSTR addr_range, LPCTSTR data)
	{
		return m_pIdmsoft->FindData(hwnd, addr_range, data);
	}	
	long SetPicPwd(LPCTSTR pwd)
	{
		return m_pIdmsoft->SetPicPwd(pwd);
	}	
	long Log(LPCTSTR info)
	{
		return m_pIdmsoft->Log(info);
	}	
	CString FindStrE(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim)
	{
		return m_pIdmsoft->FindStrE(x1, y1, x2, y2, str, color, sim);
	}	
	CString FindColorE(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long dir)
	{
		return m_pIdmsoft->FindColorE(x1, y1, x2, y2, color, sim, dir);
	}	
	CString FindPicE(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir)
	{
		return m_pIdmsoft->FindPicE(x1, y1, x2, y2, pic_name, delta_color, sim, dir);
	}	
	CString FindMultiColorE(long x1, long y1, long x2, long y2, LPCTSTR first_color, LPCTSTR offset_color, double sim, long dir)
	{
		return m_pIdmsoft->FindMultiColorE(x1, y1, x2, y2, first_color, offset_color, sim, dir);
	}	
	long SetExactOcr(long exact_ocr)
	{
		return m_pIdmsoft->SetExactOcr(exact_ocr);
	}	
	CString ReadString(long hwnd, LPCTSTR addr, long type, long len)
	{ 
		return m_pIdmsoft->ReadString(hwnd, addr, type, len);
	}	
	long FoobarTextPrintDir(long hwnd, long dir)
	{
		return m_pIdmsoft->FoobarTextPrintDir(hwnd, dir);
	}	
	CString OcrEx(long x1, long y1, long x2, long y2, LPCTSTR color, double sim)
	{
		return m_pIdmsoft->OcrEx(x1, y1, x2, y2, color, sim);
	}	
	long SetDisplayInput(LPCTSTR mode)
	{
		return m_pIdmsoft->SetDisplayInput(mode);
	}	
	long GetTime()
	{
		return m_pIdmsoft->GetTime();
	}	
	long GetScreenWidth()
	{
		return m_pIdmsoft->GetScreenWidth();
	}	
	long GetScreenHeight()
	{
		return m_pIdmsoft->GetScreenHeight();
	}	
	long BindWindowEx(long hwnd, LPCTSTR display, LPCTSTR mouse, LPCTSTR keypad, LPCTSTR public_desc, long mode)
	{   
		return m_pIdmsoft->BindWindowEx(hwnd, display, mouse, keypad, public_desc, mode);
	}	
	CString GetDiskSerial()
	{
		return m_pIdmsoft->GetDiskSerial();
	}	
	CString Md5(LPCTSTR str)
	{
		return m_pIdmsoft->Md5(str);
	}	
	CString GetMac()
	{
		return m_pIdmsoft->GetMac();
	}	
	long ActiveInputMethod(long hwnd, LPCTSTR id)
	{
		return m_pIdmsoft->ActiveInputMethod(hwnd, id);
	}	
	long CheckInputMethod(long hwnd, LPCTSTR id)
	{
		return m_pIdmsoft->CheckInputMethod(hwnd, id);
	}	
	long FindInputMethod(LPCTSTR id)
	{
		return m_pIdmsoft->FindInputMethod(id);
	}	
	long GetCursorPos(VARIANT * x, VARIANT * y)
	{
		return m_pIdmsoft->GetCursorPos(x, y);
	}	
	long BindWindow(long hwnd, LPCTSTR display, LPCTSTR mouse, LPCTSTR keypad, long mode)
	{  
		return m_pIdmsoft->BindWindow(hwnd, display, mouse, keypad, mode);
	}	
	long FindWindow(LPCTSTR class_name, LPCTSTR title_name)
	{
		return m_pIdmsoft->FindWindow(class_name, title_name);
	}	
	long GetScreenDepth()
	{
		return m_pIdmsoft->GetScreenDepth();
	}	
	long SetScreen(long width, long height, long depth)
	{
		return m_pIdmsoft->SetScreen(width, height, depth);
	}	
	long ExitOs(long type)
	{
		return m_pIdmsoft->ExitOs(type);
	}	
	CString GetDir(long type)
	{
		return m_pIdmsoft->GetDir(type);
	}	
	long GetOsType()
	{
		return m_pIdmsoft->GetOsType();
	}	
	long FindWindowEx(long parent, LPCTSTR class_name, LPCTSTR title_name)
	{
		return m_pIdmsoft->FindWindowEx(parent, class_name, title_name);
	}	
	long SetExportDict(long index, LPCTSTR dict_name)
	{
		return m_pIdmsoft->SetExportDict(index, dict_name);
	}	
	CString GetCursorShape()
	{
		return m_pIdmsoft->GetCursorShape();
	}	
	long DownCpu(long rate)
	{
		return m_pIdmsoft->DownCpu(rate);
	}	
	CString GetCursorSpot()
	{
		return m_pIdmsoft->GetCursorSpot();
	}	
	long SendString2(long hwnd, LPCTSTR str)
	{
		return m_pIdmsoft->SendString2(hwnd, str);
	}	
	long FaqPost(LPCTSTR server, long handle, long request_type, long time_out)
	{ 
		return m_pIdmsoft->FaqPost(server, handle, request_type, time_out);
	}	
	CString FaqFetch()
	{
		return m_pIdmsoft->FaqFetch();
	}	
	CString FetchWord(long x1, long y1, long x2, long y2, LPCTSTR color, LPCTSTR word)
	{   
		return m_pIdmsoft->FetchWord(x1, y1, x2, y2, color, word);
	}	
	long CaptureJpg(long x1, long y1, long x2, long y2, LPCTSTR file, long quality)
	{   
		return m_pIdmsoft->CaptureJpg(x1, y1, x2, y2, file, quality);
	}	
	long FindStrWithFont(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, LPCTSTR font_name, long font_size, long flag, VARIANT * x, VARIANT * y)
	{
		return m_pIdmsoft->FindStrWithFont(x1, y1, x2, y2, str, color, sim, font_name, font_size, flag, x, y);
	}	
	CString FindStrWithFontE(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, LPCTSTR font_name, long font_size, long flag)
	{  
		return m_pIdmsoft->FindStrWithFontE(x1, y1, x2, y2, str, color, sim, font_name, font_size, flag);
	}	
	CString FindStrWithFontEx(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, LPCTSTR font_name, long font_size, long flag)
	{  
		return m_pIdmsoft->FindStrWithFontEx(x1, y1, x2, y2, str, color, sim, font_name, font_size, flag);
	}	
	CString GetDictInfo(LPCTSTR str, LPCTSTR font_name, long font_size, long flag)
	{ 
		return m_pIdmsoft->GetDictInfo(str, font_name, font_size, flag);
	}	
	long SaveDict(long index, LPCTSTR file)
	{
		return m_pIdmsoft->SaveDict(index, file);
	}	
	long GetWindowProcessId(long hwnd)
	{
		return m_pIdmsoft->GetWindowProcessId(hwnd);
	}	
	CString GetWindowProcessPath(long hwnd)
	{
		return m_pIdmsoft->GetWindowProcessPath(hwnd);
	}	
	long LockInput(long lock)
	{
		return m_pIdmsoft->LockInput(lock);
	}	
	CString GetPicSize(LPCTSTR pic_name)
	{
		return m_pIdmsoft->GetPicSize(pic_name);
	}	
	long GetID()
	{
		return m_pIdmsoft->GetID();
	}	
	long CapturePng(long x1, long y1, long x2, long y2, LPCTSTR file)
	{  
		return m_pIdmsoft->CapturePng(x1, y1, x2, y2, file);
	}	
	long CaptureGif(long x1, long y1, long x2, long y2, LPCTSTR file, long delay, long time)
	{
		return m_pIdmsoft->CaptureGif(x1, y1, x2, y2, file, delay, time);
	}	
	long ImageToBmp(LPCTSTR pic_name, LPCTSTR bmp_name)
	{
		return m_pIdmsoft->ImageToBmp(pic_name, bmp_name);
	}	
	long FindStrFast(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, VARIANT * x, VARIANT * y)
	{
		return m_pIdmsoft->FindStrFast(x1, y1, x2, y2, str, color, sim, x, y);
	}	
	CString FindStrFastEx(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim)
	{
		return m_pIdmsoft->FindStrFastEx(x1, y1, x2, y2, str, color, sim);
	}	
	CString FindStrFastE(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim)
	{
		return m_pIdmsoft->FindStrFastE(x1, y1, x2, y2, str, color, sim);
	}	
	long EnableDisplayDebug(long enable_debug)
	{
		return m_pIdmsoft->EnableDisplayDebug(enable_debug);
	}	
	long CapturePre(LPCTSTR file)
	{
		return m_pIdmsoft->CapturePre(file);
	}	
	long RegEx(LPCTSTR code, LPCTSTR Ver, LPCTSTR ip)
	{
		return m_pIdmsoft->RegEx(code, Ver, ip);
	}	
	CString GetMachineCode()
	{
		return m_pIdmsoft->GetMachineCode();
	}	
	long SetClipboard(LPCTSTR data)
	{
		return m_pIdmsoft->SetClipboard(data);
	}	
	CString GetClipboard()
	{
		return m_pIdmsoft->GetClipboard();
	}	
	long GetNowDict()
	{
		return m_pIdmsoft->GetNowDict();
	}	
	long Is64Bit()
	{
		return m_pIdmsoft->Is64Bit();
	}	
	long GetColorNum(long x1, long y1, long x2, long y2, LPCTSTR color, double sim)
	{
		return m_pIdmsoft->GetColorNum(x1, y1, x2, y2, color, sim);
	}	
	CString EnumWindowByProcess(LPCTSTR process_name, LPCTSTR title, LPCTSTR class_name, long filter)
	{ 
		return m_pIdmsoft->EnumWindowByProcess(process_name, title, class_name, filter);
	}	
	long GetDictCount(long index)
	{
		return m_pIdmsoft->GetDictCount(index);
	}	
	long GetLastError()
	{
		return m_pIdmsoft->GetLastError();
	}	
	CString GetNetTime()
	{
		return m_pIdmsoft->GetNetTime();
	}	
	long EnableGetColorByCapture(long en)
	{
		return m_pIdmsoft->EnableGetColorByCapture(en);
	}	
	long CheckUAC()
	{
		return m_pIdmsoft->CheckUAC();
	}	
	long SetUAC(long uac)
	{
		return m_pIdmsoft->SetUAC(uac);
	}	
	long DisableFontSmooth()
	{
		return m_pIdmsoft->DisableFontSmooth();
	}	
	long CheckFontSmooth()
	{
		return m_pIdmsoft->CheckFontSmooth();
	}	
	long SetDisplayAcceler(long level)
	{
		return m_pIdmsoft->SetDisplayAcceler(level);
	}	
	long FindWindowByProcess(LPCTSTR process_name, LPCTSTR class_name, LPCTSTR title_name)
	{
		return m_pIdmsoft->FindWindowByProcess(process_name, class_name, title_name);
	}	
	long FindWindowByProcessId(long process_id, LPCTSTR class_name, LPCTSTR title_name)
	{
		return m_pIdmsoft->FindWindowByProcessId(process_id, class_name, title_name);
	}	
	CString ReadIni(LPCTSTR section, LPCTSTR key, LPCTSTR file)
	{
		return m_pIdmsoft->ReadIni(section, key, file);
	}	
	long WriteIni(LPCTSTR section, LPCTSTR key, LPCTSTR v, LPCTSTR file)
	{ 
		return m_pIdmsoft->WriteIni(section, key, v, file);
	}	
	long RunApp(LPCTSTR path, long mode)
	{
		return m_pIdmsoft->RunApp(path, mode);
	}	
	long delay(long mis)
	{
		return m_pIdmsoft->delay(mis);
	}	
	long FindWindowSuper(LPCTSTR spec1, long flag1, long type1, LPCTSTR spec2, long flag2, long type2)
	{   
		return m_pIdmsoft->FindWindowSuper(spec1, flag1, type1, spec2, flag2, type2);
	}	
	CString ExcludePos(LPCTSTR all_pos, long type, long x1, long y1, long x2, long y2)
	{   
		return m_pIdmsoft->ExcludePos(all_pos, type, x1, y1, x2, y2);
	}	
	CString FindNearestPos(LPCTSTR all_pos, long type, long x, long y)
	{ 
		return m_pIdmsoft->FindNearestPos(all_pos, type, x, y);
	}	
	CString SortPosDistance(LPCTSTR all_pos, long type, long x, long y)
	{ 
		return m_pIdmsoft->SortPosDistance(all_pos, type, x, y);
	}	
	long FindPicMem(long x1, long y1, long x2, long y2, LPCTSTR pic_info, LPCTSTR delta_color, double sim, long dir, VARIANT * x, VARIANT * y)
	{
		return m_pIdmsoft->FindPicMem(x1, y1, x2, y2, pic_info, delta_color, sim, dir, x, y);
	}	
	CString FindPicMemEx(long x1, long y1, long x2, long y2, LPCTSTR pic_info, LPCTSTR delta_color, double sim, long dir)
	{
		return m_pIdmsoft->FindPicMemEx(x1, y1, x2, y2, pic_info, delta_color, sim, dir);
	}	
	CString FindPicMemE(long x1, long y1, long x2, long y2, LPCTSTR pic_info, LPCTSTR delta_color, double sim, long dir)
	{
		return m_pIdmsoft->FindPicMemE(x1, y1, x2, y2, pic_info, delta_color, sim, dir);
	}	
	CString AppendPicAddr(LPCTSTR pic_info, long addr, long size)
	{
		return m_pIdmsoft->AppendPicAddr(pic_info, addr, size);
	}	
	long WriteFile(LPCTSTR file, LPCTSTR content)
	{
		return m_pIdmsoft->WriteFile(file, content);
	}	
	long Stop(long id)
	{
		return m_pIdmsoft->Stop(id);
	}	
	long SetDictMem(long index, long addr, long size)
	{
		return m_pIdmsoft->SetDictMem(index, addr, size);
	}	
	CString GetNetTimeSafe()
	{
		return m_pIdmsoft->GetNetTimeSafe();
	}	
	long ForceUnBindWindow(long hwnd)
	{
		return m_pIdmsoft->ForceUnBindWindow(hwnd);
	}	
	CString ReadIniPwd(LPCTSTR section, LPCTSTR key, LPCTSTR file, LPCTSTR pwd)
	{ 
		return m_pIdmsoft->ReadIniPwd(section, key, file, pwd);
	}	
	long WriteIniPwd(LPCTSTR section, LPCTSTR key, LPCTSTR v, LPCTSTR file, LPCTSTR pwd)
	{  
		return m_pIdmsoft->WriteIniPwd(section, key, v, file, pwd);
	}	
	long DecodeFile(LPCTSTR file, LPCTSTR pwd)
	{
		return m_pIdmsoft->DecodeFile(file, pwd);
	}	
	long KeyDownChar(LPCTSTR key_str)
	{
		return m_pIdmsoft->KeyDownChar(key_str);
	}	
	long KeyUpChar(LPCTSTR key_str)
	{
		return m_pIdmsoft->KeyUpChar(key_str);
	}	
	long KeyPressChar(LPCTSTR key_str)
	{
		return m_pIdmsoft->KeyPressChar(key_str);
	}	
	long KeyPressStr(LPCTSTR key_str, long delay)
	{
		return m_pIdmsoft->KeyPressStr(key_str, delay);
	}	
	long EnableKeypadPatch(long en)
	{
		return m_pIdmsoft->EnableKeypadPatch(en);
	}	
	long EnableKeypadSync(long en, long time_out)
	{
		return m_pIdmsoft->EnableKeypadSync(en, time_out);
	}	
	long EnableMouseSync(long en, long time_out)
	{
		return m_pIdmsoft->EnableMouseSync(en, time_out);
	}	
	long DmGuard(long en, LPCTSTR type)
	{
		return m_pIdmsoft->DmGuard(en, type);
	}	
	long FaqCaptureFromFile(long x1, long y1, long x2, long y2, LPCTSTR file, long quality)
	{   
		return m_pIdmsoft->FaqCaptureFromFile(x1, y1, x2, y2, file, quality);
	}	
	CString FindIntEx(long hwnd, LPCTSTR addr_range, long int_value_min, long int_value_max, long type, long step, long multi_thread, long mode)
	{
		return m_pIdmsoft->FindIntEx(hwnd, addr_range, int_value_min, int_value_max, type, step, multi_thread, mode);
	}	
	CString FindFloatEx(long hwnd, LPCTSTR addr_range, float float_value_min, float float_value_max, long step, long multi_thread, long mode)
	{
		return m_pIdmsoft->FindFloatEx(hwnd, addr_range, float_value_min, float_value_max, step, multi_thread, mode);
	}	
	CString FindDoubleEx(long hwnd, LPCTSTR addr_range, double double_value_min, double double_value_max, long step, long multi_thread, long mode)
	{
		return m_pIdmsoft->FindDoubleEx(hwnd, addr_range, double_value_min, double_value_max, step, multi_thread, mode);
	}	
	CString FindStringEx(long hwnd, LPCTSTR addr_range, LPCTSTR string_value, long type, long step, long multi_thread, long mode)
	{
		return m_pIdmsoft->FindStringEx(hwnd, addr_range, string_value, type, step, multi_thread, mode);
	}	
	CString FindDataEx(long hwnd, LPCTSTR addr_range, LPCTSTR data, long step, long multi_thread, long mode)
	{
		return m_pIdmsoft->FindDataEx(hwnd, addr_range, data, step, multi_thread, mode);
	}	
	long EnableRealMouse(long en, long mousedelay, long mousestep)
	{
		return m_pIdmsoft->EnableRealMouse(en, mousedelay, mousestep);
	}	
	long EnableRealKeypad(long en)
	{
		return m_pIdmsoft->EnableRealKeypad(en);
	}	
	long SendStringIme(LPCTSTR str)
	{
		return m_pIdmsoft->SendStringIme(str);
	}	
	long FoobarDrawLine(long hwnd, long x1, long y1, long x2, long y2, LPCTSTR color, long style, long width)
	{
		return m_pIdmsoft->FoobarDrawLine(hwnd, x1, y1, x2, y2, color, style, width);
	}	
	CString FindStrEx(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim)
	{
		return m_pIdmsoft->FindStrEx(x1, y1, x2, y2, str, color, sim);
	}	
	long IsBind(long hwnd)
	{
		return m_pIdmsoft->IsBind(hwnd);
	}	
	long SetDisplayDelay(long t)
	{
		return m_pIdmsoft->SetDisplayDelay(t);
	}	
	long GetDmCount()
	{
		return m_pIdmsoft->GetDmCount();
	}	
	long DisableScreenSave()
	{
		return m_pIdmsoft->DisableScreenSave();
	}	
	long DisablePowerSave()
	{
		return m_pIdmsoft->DisablePowerSave();
	}	
	long SetMemoryHwndAsProcessId(long en)
	{
		return m_pIdmsoft->SetMemoryHwndAsProcessId(en);
	}	
	long FindShape(long x1, long y1, long x2, long y2, LPCTSTR offset_color, double sim, long dir, VARIANT * x, VARIANT * y)
	{
		return m_pIdmsoft->FindShape(x1, y1, x2, y2, offset_color, sim, dir, x, y);
	}	
	CString FindShapeE(long x1, long y1, long x2, long y2, LPCTSTR offset_color, double sim, long dir)
	{
		return m_pIdmsoft->FindShapeE(x1, y1, x2, y2, offset_color, sim, dir);
	}	
	CString FindShapeEx(long x1, long y1, long x2, long y2, LPCTSTR offset_color, double sim, long dir)
	{
		return m_pIdmsoft->FindShapeEx(x1, y1, x2, y2, offset_color, sim, dir);
	}	
	CString FindStrS(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, VARIANT * x, VARIANT * y)
	{
		return m_pIdmsoft->FindStrS(x1, y1, x2, y2, str, color, sim, x, y);
	}	
	CString FindStrExS(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim)
	{
		return m_pIdmsoft->FindStrExS(x1, y1, x2, y2, str, color, sim);
	}	
	CString FindStrFastS(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, VARIANT * x, VARIANT * y)
	{
		return m_pIdmsoft->FindStrFastS(x1, y1, x2, y2, str, color, sim, x, y);
	}	
	CString FindStrFastExS(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim)
	{
		return m_pIdmsoft->FindStrFastExS(x1, y1, x2, y2, str, color, sim);
	}	
	CString FindPicS(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir, VARIANT * x, VARIANT * y)
	{
		return m_pIdmsoft->FindPicS(x1, y1, x2, y2, pic_name, delta_color, sim, dir, x, y);
	}	
	CString FindPicExS(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir)
	{
		return m_pIdmsoft->FindPicExS(x1, y1, x2, y2, pic_name, delta_color, sim, dir);
	}	
	long ClearDict(long index)
	{
		return m_pIdmsoft->ClearDict(index);
	}	
	CString GetMachineCodeNoMac()
	{
		return m_pIdmsoft->GetMachineCodeNoMac();
	}	
	long GetClientRect(long hwnd, VARIANT * x1, VARIANT * y1, VARIANT * x2, VARIANT * y2)
	{
		return m_pIdmsoft->GetClientRect(hwnd, x1, y1, x2, y2);
	}	
	long EnableFakeActive(long en)
	{
		return m_pIdmsoft->EnableFakeActive(en);
	}	
	long GetScreenDataBmp(long x1, long y1, long x2, long y2, VARIANT * data, VARIANT * size)
	{
		return m_pIdmsoft->GetScreenDataBmp(x1, y1, x2, y2, data, size);
	}	
	long EncodeFile(LPCTSTR file, LPCTSTR pwd)
	{
		return m_pIdmsoft->EncodeFile(file, pwd);
	}	
	CString GetCursorShapeEx(long type)
	{
		return m_pIdmsoft->GetCursorShapeEx(type);
	}	
	long FaqCancel()
	{
		return m_pIdmsoft->FaqCancel();
	}	
	CString IntToData(long int_value, long type)
	{
		return m_pIdmsoft->IntToData(int_value, type);
	}	
	CString FloatToData(float float_value)
	{
		return m_pIdmsoft->FloatToData(float_value);
	}	
	CString DoubleToData(double double_value)
	{
		return m_pIdmsoft->DoubleToData(double_value);
	}	
	CString StringToData(LPCTSTR string_value, long type)
	{
		return m_pIdmsoft->StringToData(string_value, type);
	}	
	long SetMemoryFindResultToFile(LPCTSTR file)
	{
		return m_pIdmsoft->SetMemoryFindResultToFile(file);
	}	
	long EnableBind(long en)
	{
		return m_pIdmsoft->EnableBind(en);
	}	
	long SetSimMode(long mode)
	{
		return m_pIdmsoft->SetSimMode(mode);
	}	
	long LockMouseRect(long x1, long y1, long x2, long y2)
	{
		return m_pIdmsoft->LockMouseRect(x1, y1, x2, y2);
	}	
	long SendPaste(long hwnd)
	{
		return m_pIdmsoft->SendPaste(hwnd);
	}	
	long IsDisplayDead(long x1, long y1, long x2, long y2, long t)
	{
		return m_pIdmsoft->IsDisplayDead(x1, y1, x2, y2, t);
	}	
	long GetKeyState(long vk)
	{
		return m_pIdmsoft->GetKeyState(vk);
	}	
	long CopyFile(LPCTSTR src_file, LPCTSTR dst_file, long over)
	{
		return m_pIdmsoft->CopyFile(src_file, dst_file, over);
	}	
	long IsFileExist(LPCTSTR file)
	{
		return m_pIdmsoft->IsFileExist(file);
	}	
	long DeleteFile(LPCTSTR file)
	{
		return m_pIdmsoft->DeleteFile(file);
	}	
	long MoveFile(LPCTSTR src_file, LPCTSTR dst_file)
	{
		return m_pIdmsoft->MoveFile(src_file, dst_file);
	}	
	long CreateFolder(LPCTSTR folder_name)
	{
		return m_pIdmsoft->CreateFolder(folder_name);
	}	
	long DeleteFolder(LPCTSTR folder_name)
	{
		return m_pIdmsoft->DeleteFolder(folder_name);
	}	
	long GetFileLength(LPCTSTR file)
	{
		return m_pIdmsoft->GetFileLength(file);
	}	
	CString ReadFile(LPCTSTR file)
	{
		return m_pIdmsoft->ReadFile(file);
	}	
	long WaitKey(long key_code, long time_out)
	{
		return m_pIdmsoft->WaitKey(key_code, time_out);
	}	
	long DeleteIni(LPCTSTR section, LPCTSTR key, LPCTSTR file)
	{
		return m_pIdmsoft->DeleteIni(section, key, file);
	}	
	long DeleteIniPwd(LPCTSTR section, LPCTSTR key, LPCTSTR file, LPCTSTR pwd)
	{ 
		return m_pIdmsoft->DeleteIniPwd(section, key, file, pwd);
	}	
	long EnableSpeedDx(long en)
	{
		return m_pIdmsoft->EnableSpeedDx(en);
	}	
	long EnableIme(long en)
	{
		return m_pIdmsoft->EnableIme(en);
	}	
	long Reg(LPCTSTR code, LPCTSTR Ver)
	{
		return m_pIdmsoft->Reg(code, Ver);
	}	
	CString SelectFile()
	{
		return m_pIdmsoft->SelectFile();
	}	
	CString SelectDirectory()
	{
		return m_pIdmsoft->SelectDirectory();
	}	
	long LockDisplay(long lock)
	{
		return m_pIdmsoft->LockDisplay(lock);
	}	
	long FoobarSetSave(long hwnd, LPCTSTR file, long en, LPCTSTR header)
	{ 
		return m_pIdmsoft->FoobarSetSave(hwnd, file, en, header);
	}	
	CString EnumWindowSuper(LPCTSTR spec1, long flag1, long type1, LPCTSTR spec2, long flag2, long type2, long sort)
	{
		return m_pIdmsoft->EnumWindowSuper(spec1, flag1, type1, spec2, flag2, type2, sort);
	}	
	long DownloadFile(LPCTSTR url, LPCTSTR save_file, long timeout)
	{
		return m_pIdmsoft->DownloadFile(url, save_file, timeout);
	}	
	long EnableKeypadMsg(long en)
	{
		return m_pIdmsoft->EnableKeypadMsg(en);
	}	
	long EnableMouseMsg(long en)
	{
		return m_pIdmsoft->EnableMouseMsg(en);
	}	
	long RegNoMac(LPCTSTR code, LPCTSTR Ver)
	{
		return m_pIdmsoft->RegNoMac(code, Ver);
	}	
	long RegExNoMac(LPCTSTR code, LPCTSTR Ver, LPCTSTR ip)
	{
		return m_pIdmsoft->RegExNoMac(code, Ver, ip);
	}	
	long SetEnumWindowDelay(long delay)
	{
		return m_pIdmsoft->SetEnumWindowDelay(delay);
	}	
	long FindMulColor(long x1, long y1, long x2, long y2, LPCTSTR color, double sim)
	{
		return m_pIdmsoft->FindMulColor(x1, y1, x2, y2, color, sim);
	}	
	CString GetDict(long index, long font_index)
	{
		return m_pIdmsoft->GetDict(index, font_index);
	}	
	long GetBindWindow()
	{
		return m_pIdmsoft->GetBindWindow();
	}	
	long FoobarStartGif(long hwnd, long x, long y, LPCTSTR pic_name, long repeat_limit, long delay)
	{
		return m_pIdmsoft->FoobarStartGif(hwnd, x, y, pic_name, repeat_limit, delay);
	}	
	long FoobarStopGif(long hwnd, long x, long y, LPCTSTR pic_name)
	{ 
		return m_pIdmsoft->FoobarStopGif(hwnd, x, y, pic_name);
	}	
	long FreeProcessMemory(long hwnd)
	{
		return m_pIdmsoft->FreeProcessMemory(hwnd);
	}	
	CString ReadFileData(LPCTSTR file, long start_pos, long end_pos)
	{
		return m_pIdmsoft->ReadFileData(file, start_pos, end_pos);
	}	
	long VirtualAllocEx(long hwnd, long addr, long size, long type)
	{
		return m_pIdmsoft->VirtualAllocEx(hwnd, addr, size, type);
	}	
	long VirtualFreeEx(long hwnd, long addr)
	{
		return m_pIdmsoft->VirtualFreeEx(hwnd, addr);
	}	
	CString GetCommandLine(long hwnd)
	{
		return m_pIdmsoft->GetCommandLine(hwnd);
	}	
	long TerminateProcess(long pid)
	{
		return m_pIdmsoft->TerminateProcess(pid);
	}	
	CString GetNetTimeByIp(LPCTSTR ip)
	{
		return m_pIdmsoft->GetNetTimeByIp(ip);
	}	
	CString EnumProcess(LPCTSTR name)
	{
		return m_pIdmsoft->EnumProcess(name);
	}	
	CString GetProcessInfo(long pid)
	{
		return m_pIdmsoft->GetProcessInfo(pid);
	}	
	long ReadIntAddr(long hwnd, long addr, long type)
	{
		return m_pIdmsoft->ReadIntAddr(hwnd, addr, type);
	}	
	CString ReadDataAddr(long hwnd, long addr, long len)
	{
		return m_pIdmsoft->ReadDataAddr(hwnd, addr, len);
	}	
	double ReadDoubleAddr(long hwnd, long addr)
	{
		return m_pIdmsoft->ReadDoubleAddr(hwnd, addr);
	}	
	float ReadFloatAddr(long hwnd, long addr)
	{
		return m_pIdmsoft->ReadFloatAddr(hwnd, addr);
	}	
	CString ReadStringAddr(long hwnd, long addr, long type, long len)
	{
		return m_pIdmsoft->ReadStringAddr(hwnd, addr, type, len);
	}	
	long WriteDataAddr(long hwnd, long addr, LPCTSTR data)
	{
		return m_pIdmsoft->WriteDataAddr(hwnd, addr, data);
	}	
	long WriteDoubleAddr(long hwnd, long addr, double v)
	{
		return m_pIdmsoft->WriteDoubleAddr(hwnd, addr, v);
	}	
	long WriteFloatAddr(long hwnd, long addr, float v)
	{
		return m_pIdmsoft->WriteFloatAddr(hwnd, addr, v);
	}	
	long WriteIntAddr(long hwnd, long addr, long type, long v)
	{
		return m_pIdmsoft->WriteIntAddr(hwnd, addr, type, v);
	}	
	long WriteStringAddr(long hwnd, long addr, long type, LPCTSTR v)
	{ 
		return m_pIdmsoft->WriteStringAddr(hwnd, addr, type, v);
	}	
	long Delays(long min_s, long max_s)
	{
		return m_pIdmsoft->Delays(min_s, max_s);
	}	
	long FindColorBlock(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long count, long width, long height, VARIANT * x, VARIANT * y)
	{
		return m_pIdmsoft->FindColorBlock(x1, y1, x2, y2, color, sim, count, width, height, x, y);
	}	
	CString FindColorBlockEx(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long count, long width, long height)
	{ 
		return m_pIdmsoft->FindColorBlockEx(x1, y1, x2, y2, color, sim, count, width, height);
	}	
	long OpenProcess(long pid)
	{
		return m_pIdmsoft->OpenProcess(pid);
	}	
	CString EnumIniSection(LPCTSTR file)
	{
		return m_pIdmsoft->EnumIniSection(file);
	}	
	CString EnumIniSectionPwd(LPCTSTR file, LPCTSTR pwd)
	{
		return m_pIdmsoft->EnumIniSectionPwd(file, pwd);
	}	
	CString EnumIniKey(LPCTSTR section, LPCTSTR file)
	{
		return m_pIdmsoft->EnumIniKey(section, file);
	}	
	CString EnumIniKeyPwd(LPCTSTR section, LPCTSTR file, LPCTSTR pwd)
	{
		return m_pIdmsoft->EnumIniKeyPwd(section, file, pwd);
	}	
	long SwitchBindWindow(long hwnd)
	{
		return m_pIdmsoft->SwitchBindWindow(hwnd);
	}	
	long InitCri()
	{
		return m_pIdmsoft->InitCri();
	}	
	long SendStringIme2(long hwnd, LPCTSTR str, long mode)
	{
		return m_pIdmsoft->SendStringIme2(hwnd, str, mode);
	}	
	CString EnumWindowByProcessId(long pid, LPCTSTR title, LPCTSTR class_name, long filter)
	{ 
		return m_pIdmsoft->EnumWindowByProcessId(pid, title, class_name, filter);
	}	
	CString GetDisplayInfo()
	{
		return m_pIdmsoft->GetDisplayInfo();
	}	
	long EnableFontSmooth()
	{
		return m_pIdmsoft->EnableFontSmooth();
	}	
	CString OcrExOne(long x1, long y1, long x2, long y2, LPCTSTR color, double sim)
	{
		return m_pIdmsoft->OcrExOne(x1, y1, x2, y2, color, sim);
	}	
	long SetAero(long en)
	{
		return m_pIdmsoft->SetAero(en);
	}	
	long FoobarSetTrans(long hwnd, long trans, LPCTSTR color, double sim)
	{
		return m_pIdmsoft->FoobarSetTrans(hwnd, trans, color, sim);
	}	
	long EnablePicCache(long en)
	{
		return m_pIdmsoft->EnablePicCache(en);
	}	
	CString GetInfo(LPCTSTR cmd, LPCTSTR param)
	{
		return m_pIdmsoft->GetInfo(cmd, param);
	}	
	long FaqIsPosted()
	{
		return m_pIdmsoft->FaqIsPosted();
	}	
	long LoadPicByte(long addr, long size, LPCTSTR name)
	{
		return m_pIdmsoft->LoadPicByte(addr, size, name);
	}	
	long MiddleDown()
	{
		return m_pIdmsoft->MiddleDown();
	}	
	long MiddleUp()
	{
		return m_pIdmsoft->MiddleUp();
	}	

	// Idmsoft properties
public:

//////////////////////////////////////////////////////////////////////////
public:
protected:
private:
	static CString AID_PLUG_DLL;
	static CString AID_PLUG_VERSION;
	Idmsoft* m_pIdmsoft;
};
#endif // CXX_AIDPLUGDM_H
/* EOF */
