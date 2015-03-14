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

#ifndef CXX_AIDPLUG_H
#define CXX_AIDPLUG_H

#include "Cdmsoft.h"

class AidPlug
{
public:
	AidPlug() {};
	virtual ~AidPlug() {};
private:
	virtual Idmsoft* InitNewDll() = 0;

	// Attributes
public:

	// Operations
public:


	// Idmsoft methods
public:
	virtual CString Ver() = 0;
	virtual long SetPath(LPCTSTR path) = 0;
	virtual CString Ocr(long x1, long y1, long x2, long y2, LPCTSTR color, double sim) = 0;
	virtual long FindStr(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, VARIANT * x, VARIANT * y) = 0;
	virtual long GetResultCount(LPCTSTR str) = 0;
	virtual long GetResultPos(LPCTSTR str, long index, VARIANT * x, VARIANT * y) = 0;
	virtual long StrStr(LPCTSTR s, LPCTSTR str) = 0;
	virtual long SendCommand(LPCTSTR cmd) = 0;
	virtual long UseDict(long index) = 0;
	virtual CString GetBasePath() = 0;
	virtual long SetDictPwd(LPCTSTR pwd) = 0;
	virtual CString OcrInFile(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR color, double sim) = 0;
	virtual long Capture(long x1, long y1, long x2, long y2, LPCTSTR file) = 0;
	virtual long KeyPress(long vk) = 0;
	virtual long KeyDown(long vk) = 0;
	virtual long KeyUp(long vk) = 0;
	virtual long LeftClick() = 0;
	virtual long RightClick() = 0;
	virtual long MiddleClick() = 0;
	virtual long LeftDoubleClick() = 0;
	virtual long LeftDown() = 0;
	virtual long LeftUp() = 0;
	virtual long RightDown() = 0;
	virtual long RightUp() = 0;
	virtual long MoveTo(long x, long y) = 0;
	virtual long MoveR(long rx, long ry) = 0;
	virtual CString GetColor(long x, long y) = 0;
	virtual CString GetColorBGR(long x, long y) = 0;
	virtual CString RGB2BGR(LPCTSTR rgb_color) = 0;
	virtual CString BGR2RGB(LPCTSTR bgr_color) = 0;
	virtual long UnBindWindow() = 0;
	virtual long CmpColor(long x, long y, LPCTSTR color, double sim) = 0;
	virtual long ClientToScreen(long hwnd, VARIANT * x, VARIANT * y) = 0;
	virtual long ScreenToClient(long hwnd, VARIANT * x, VARIANT * y) = 0;
	virtual long ShowScrMsg(long x1, long y1, long x2, long y2, LPCTSTR msg, LPCTSTR color) = 0;
	virtual long SetMinRowGap(long row_gap) = 0;
	virtual long SetMinColGap(long col_gap) = 0;
	virtual long FindColor(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long dir, VARIANT * x, VARIANT * y) = 0;
	virtual CString FindColorEx(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long dir) = 0;
	virtual long SetWordLineHeight(long line_height) = 0;
	virtual long SetWordGap(long word_gap) = 0;
	virtual long SetRowGapNoDict(long row_gap) = 0;
	virtual long SetColGapNoDict(long col_gap) = 0;
	virtual long SetWordLineHeightNoDict(long line_height) = 0;
	virtual long SetWordGapNoDict(long word_gap) = 0;
	virtual long GetWordResultCount(LPCTSTR str) = 0;
	virtual long GetWordResultPos(LPCTSTR str, long index, VARIANT * x, VARIANT * y) = 0;
	virtual CString GetWordResultStr(LPCTSTR str, long index) = 0;
	virtual CString GetWords(long x1, long y1, long x2, long y2, LPCTSTR color, double sim) = 0;
	virtual CString GetWordsNoDict(long x1, long y1, long x2, long y2, LPCTSTR color) = 0;
	virtual long SetShowErrorMsg(long show) = 0;
	virtual long GetClientSize(long hwnd, VARIANT * width, VARIANT * height) = 0;
	virtual long MoveWindow(long hwnd, long x, long y) = 0;
	virtual CString GetColorHSV(long x, long y) = 0;
	virtual CString GetAveRGB(long x1, long y1, long x2, long y2) = 0;
	virtual CString GetAveHSV(long x1, long y1, long x2, long y2) = 0;
	virtual long GetForegroundWindow() = 0;
	virtual long GetForegroundFocus() = 0;
	virtual long GetMousePointWindow() = 0;
	virtual long GetPointWindow(long x, long y) = 0;
	virtual CString EnumWindow(long parent, LPCTSTR title, LPCTSTR class_name, long filter) = 0;
	virtual long GetWindowState(long hwnd, long flag) = 0;
	virtual long GetWindow(long hwnd, long flag) = 0;
	virtual long GetSpecialWindow(long flag) = 0;
	virtual long SetWindowText(long hwnd, LPCTSTR text) = 0;
	virtual long SetWindowSize(long hwnd, long width, long height) = 0;
	virtual long GetWindowRect(long hwnd, VARIANT * x1, VARIANT * y1, VARIANT * x2, VARIANT * y2) = 0;
	virtual CString GetWindowTitle(long hwnd) = 0;
	virtual CString GetWindowClass(long hwnd) = 0;
	virtual long SetWindowState(long hwnd, long flag) = 0;
	virtual long CreateFoobarRect(long hwnd, long x, long y, long w, long h) = 0;
	virtual long CreateFoobarRoundRect(long hwnd, long x, long y, long w, long h, long rw, long rh) = 0;
	virtual long CreateFoobarEllipse(long hwnd, long x, long y, long w, long h) = 0;
	virtual long CreateFoobarCustom(long hwnd, long x, long y, LPCTSTR pic, LPCTSTR trans_color, double sim) = 0;
	virtual long FoobarFillRect(long hwnd, long x1, long y1, long x2, long y2, LPCTSTR color) = 0;
	virtual long FoobarDrawText(long hwnd, long x, long y, long w, long h, LPCTSTR text, LPCTSTR color, long align) = 0;
	virtual long FoobarDrawPic(long hwnd, long x, long y, LPCTSTR pic, LPCTSTR trans_color) = 0;
	virtual long FoobarUpdate(long hwnd) = 0;
	virtual long FoobarLock(long hwnd) = 0;
	virtual long FoobarUnlock(long hwnd) = 0;
	virtual long FoobarSetFont(long hwnd, LPCTSTR font_name, long size, long flag) = 0;
	virtual long FoobarTextRect(long hwnd, long x, long y, long w, long h) = 0;
	virtual long FoobarPrintText(long hwnd, LPCTSTR text, LPCTSTR color) = 0;
	virtual long FoobarClearText(long hwnd) = 0;	
	virtual long FoobarTextLineGap(long hwnd, long gap) = 0;
	virtual long Play(LPCTSTR file) = 0;
	virtual long FaqCapture(long x1, long y1, long x2, long y2, long quality, long delay, long time) = 0;
	virtual long FaqRelease(long handle) = 0;
	virtual CString FaqSend(LPCTSTR server, long handle, long request_type, long time_out) = 0;
	virtual long Beep(long fre, long delay) = 0;
	virtual long FoobarClose(long hwnd) = 0;
	virtual long MoveDD(long dx, long dy) = 0;	
	virtual long FaqGetSize(long handle) = 0;
	virtual long LoadPic(LPCTSTR pic_name) = 0;
	virtual long FreePic(LPCTSTR pic_name) = 0;	
	virtual long GetScreenData(long x1, long y1, long x2, long y2) = 0;
	virtual long FreeScreenData(long handle) = 0;
	virtual long WheelUp() = 0;	
	virtual long WheelDown() = 0;
	virtual long SetMouseDelay(LPCTSTR type, long delay) = 0;
	virtual long SetKeypadDelay(LPCTSTR type, long delay) = 0;
	virtual CString GetEnv(long index, LPCTSTR name) = 0;
	virtual long SetEnv(long index, LPCTSTR name, LPCTSTR value) = 0;	
	virtual long SendString(long hwnd, LPCTSTR str) = 0;
	virtual long DelEnv(long index, LPCTSTR name) = 0;
	virtual CString GetPath() = 0;
	virtual long SetDict(long index, LPCTSTR dict_name) = 0;
	virtual long FindPic(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir, VARIANT * x, VARIANT * y) = 0;	
	virtual CString FindPicEx(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir) = 0;
	virtual long SetClientSize(long hwnd, long width, long height) = 0;
	virtual long ReadInt(long hwnd, LPCTSTR addr, long type) = 0;	
	virtual float ReadFloat(long hwnd, LPCTSTR addr) = 0;
	virtual double ReadDouble(long hwnd, LPCTSTR addr) = 0;
	virtual CString FindInt(long hwnd, LPCTSTR addr_range, long int_value_min, long int_value_max, long type) = 0;
	virtual CString FindFloat(long hwnd, LPCTSTR addr_range, float float_value_min, float float_value_max) = 0;
	virtual CString FindDouble(long hwnd, LPCTSTR addr_range, double double_value_min, double double_value_max) = 0;
	virtual CString FindString(long hwnd, LPCTSTR addr_range, LPCTSTR string_value, long type) = 0;
	virtual long GetModuleBaseAddr(long hwnd, LPCTSTR module_name) = 0;
	virtual CString MoveToEx(long x, long y, long w, long h) = 0;
	virtual CString MatchPicName(LPCTSTR pic_name) = 0;	
	virtual long AddDict(long index, LPCTSTR dict_info) = 0;
	virtual long EnterCri() = 0;
	virtual long LeaveCri() = 0;
	virtual long WriteInt(long hwnd, LPCTSTR addr, long type, long v) = 0;
	virtual long WriteFloat(long hwnd, LPCTSTR addr, float v) = 0;
	virtual long WriteDouble(long hwnd, LPCTSTR addr, double v) = 0;
	virtual long WriteString(long hwnd, LPCTSTR addr, long type, LPCTSTR v) = 0;
	virtual long AsmAdd(LPCTSTR asm_ins) = 0;	
	virtual long AsmClear() = 0;
	virtual long AsmCall(long hwnd, long mode) = 0;	
	virtual long FindMultiColor(long x1, long y1, long x2, long y2, LPCTSTR first_color, LPCTSTR offset_color, double sim, long dir, VARIANT * x, VARIANT * y) = 0;	
	virtual CString FindMultiColorEx(long x1, long y1, long x2, long y2, LPCTSTR first_color, LPCTSTR offset_color, double sim, long dir) = 0;
	virtual CString AsmCode(long base_addr) = 0;
	virtual CString Assemble(LPCTSTR asm_code, long base_addr, long is_upper) = 0;	
	virtual long SetWindowTransparent(long hwnd, long v) = 0;
	virtual CString ReadData(long hwnd, LPCTSTR addr, long len) = 0;	
	virtual long WriteData(long hwnd, LPCTSTR addr, LPCTSTR data) = 0;	
	virtual CString FindData(long hwnd, LPCTSTR addr_range, LPCTSTR data) = 0;	
	virtual long SetPicPwd(LPCTSTR pwd) = 0;	
	virtual long Log(LPCTSTR info) = 0;	
	virtual CString FindStrE(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim) = 0;
	virtual CString FindColorE(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long dir) = 0;
	virtual CString FindPicE(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir) = 0;	
	virtual CString FindMultiColorE(long x1, long y1, long x2, long y2, LPCTSTR first_color, LPCTSTR offset_color, double sim, long dir) = 0;	
	virtual long SetExactOcr(long exact_ocr) = 0;
	virtual CString ReadString(long hwnd, LPCTSTR addr, long type, long len) = 0;
	virtual long FoobarTextPrintDir(long hwnd, long dir) = 0;
	virtual CString OcrEx(long x1, long y1, long x2, long y2, LPCTSTR color, double sim) = 0;	
	virtual long SetDisplayInput(LPCTSTR mode) = 0;
	virtual long GetTime() = 0;
	virtual long GetScreenWidth() = 0;	
	virtual long GetScreenHeight() = 0;
	virtual long BindWindowEx(long hwnd, LPCTSTR display, LPCTSTR mouse, LPCTSTR keypad, LPCTSTR public_desc, long mode) = 0;
	virtual CString GetDiskSerial() = 0;
	virtual CString Md5(LPCTSTR str) = 0;
	virtual CString GetMac() = 0;
	virtual long ActiveInputMethod(long hwnd, LPCTSTR id) = 0;	
	virtual long CheckInputMethod(long hwnd, LPCTSTR id) = 0;
	virtual long FindInputMethod(LPCTSTR id) = 0;	
	virtual long GetCursorPos(VARIANT * x, VARIANT * y) = 0;	
	virtual long BindWindow(long hwnd, LPCTSTR display, LPCTSTR mouse, LPCTSTR keypad, long mode) = 0;	
	virtual long FindWindow(LPCTSTR class_name, LPCTSTR title_name) = 0;
	virtual long GetScreenDepth() = 0;
	virtual long SetScreen(long width, long height, long depth) = 0;
	virtual long ExitOs(long type) = 0;	
	virtual CString GetDir(long type) = 0;	
	virtual long GetOsType() = 0;
	virtual long FindWindowEx(long parent, LPCTSTR class_name, LPCTSTR title_name) = 0;	
	virtual long SetExportDict(long index, LPCTSTR dict_name) = 0;
	virtual CString GetCursorShape() = 0;	
	virtual long DownCpu(long rate) = 0;
	virtual CString GetCursorSpot() = 0;	
	virtual long SendString2(long hwnd, LPCTSTR str) = 0;	
	virtual long FaqPost(LPCTSTR server, long handle, long request_type, long time_out) = 0;	
	virtual CString FaqFetch() = 0;	
	virtual CString FetchWord(long x1, long y1, long x2, long y2, LPCTSTR color, LPCTSTR word) = 0;
	virtual long CaptureJpg(long x1, long y1, long x2, long y2, LPCTSTR file, long quality) = 0;	
	virtual long FindStrWithFont(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, LPCTSTR font_name, long font_size, long flag, VARIANT * x, VARIANT * y) = 0;
	virtual CString FindStrWithFontE(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, LPCTSTR font_name, long font_size, long flag) = 0;	
	virtual CString FindStrWithFontEx(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, LPCTSTR font_name, long font_size, long flag) = 0;
	virtual CString GetDictInfo(LPCTSTR str, LPCTSTR font_name, long font_size, long flag) = 0;
	virtual long SaveDict(long index, LPCTSTR file) = 0;	
	virtual long GetWindowProcessId(long hwnd) = 0;
	virtual CString GetWindowProcessPath(long hwnd) = 0;
	virtual long LockInput(long lock) = 0;	
	virtual CString GetPicSize(LPCTSTR pic_name) = 0;	
	virtual long GetID() = 0;	
	virtual long CapturePng(long x1, long y1, long x2, long y2, LPCTSTR file) = 0;
	virtual long CaptureGif(long x1, long y1, long x2, long y2, LPCTSTR file, long delay, long time) = 0;	
	virtual long ImageToBmp(LPCTSTR pic_name, LPCTSTR bmp_name) = 0;	
	virtual long FindStrFast(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, VARIANT * x, VARIANT * y) = 0;
	virtual CString FindStrFastEx(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim) = 0;	
	virtual CString FindStrFastE(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim) = 0;	
	virtual long EnableDisplayDebug(long enable_debug) = 0;
	virtual long CapturePre(LPCTSTR file) = 0;
	virtual long RegEx(LPCTSTR code, LPCTSTR Ver, LPCTSTR ip) = 0;	
	virtual CString GetMachineCode() = 0;
	virtual long SetClipboard(LPCTSTR data) = 0;
	virtual CString GetClipboard() = 0;
	virtual long GetNowDict() = 0;
	virtual long Is64Bit() = 0;
	virtual long GetColorNum(long x1, long y1, long x2, long y2, LPCTSTR color, double sim) = 0;	
	virtual CString EnumWindowByProcess(LPCTSTR process_name, LPCTSTR title, LPCTSTR class_name, long filter) = 0;	
	virtual long GetDictCount(long index) = 0;	
	virtual long GetLastError() = 0;
	virtual CString GetNetTime() = 0;	
	virtual long EnableGetColorByCapture(long en) = 0;
	virtual long CheckUAC() = 0;
	virtual long SetUAC(long uac) = 0;	
	virtual long DisableFontSmooth() = 0;	
	virtual long CheckFontSmooth() = 0;
	virtual long SetDisplayAcceler(long level) = 0;	
	virtual long FindWindowByProcess(LPCTSTR process_name, LPCTSTR class_name, LPCTSTR title_name) = 0;	
	virtual long FindWindowByProcessId(long process_id, LPCTSTR class_name, LPCTSTR title_name) = 0;	
	virtual CString ReadIni(LPCTSTR section, LPCTSTR key, LPCTSTR file) = 0;	
	virtual long WriteIni(LPCTSTR section, LPCTSTR key, LPCTSTR v, LPCTSTR file) = 0;
	virtual long RunApp(LPCTSTR path, long mode) = 0;
	virtual long delay(long mis) = 0;	
	virtual long FindWindowSuper(LPCTSTR spec1, long flag1, long type1, LPCTSTR spec2, long flag2, long type2) = 0;
	virtual CString ExcludePos(LPCTSTR all_pos, long type, long x1, long y1, long x2, long y2) = 0;	
	virtual CString FindNearestPos(LPCTSTR all_pos, long type, long x, long y) = 0;	
	virtual CString SortPosDistance(LPCTSTR all_pos, long type, long x, long y) = 0;	
	virtual long FindPicMem(long x1, long y1, long x2, long y2, LPCTSTR pic_info, LPCTSTR delta_color, double sim, long dir, VARIANT * x, VARIANT * y) = 0;	
	virtual CString FindPicMemEx(long x1, long y1, long x2, long y2, LPCTSTR pic_info, LPCTSTR delta_color, double sim, long dir) = 0;	
	virtual CString FindPicMemE(long x1, long y1, long x2, long y2, LPCTSTR pic_info, LPCTSTR delta_color, double sim, long dir) = 0;
	virtual CString AppendPicAddr(LPCTSTR pic_info, long addr, long size) = 0;	
	virtual long WriteFile(LPCTSTR file, LPCTSTR content) = 0;	
	virtual long Stop(long id) = 0;
	virtual long SetDictMem(long index, long addr, long size) = 0;	
	virtual CString GetNetTimeSafe() = 0;
	virtual long ForceUnBindWindow(long hwnd) = 0;
	virtual CString ReadIniPwd(LPCTSTR section, LPCTSTR key, LPCTSTR file, LPCTSTR pwd) = 0;	
	virtual long WriteIniPwd(LPCTSTR section, LPCTSTR key, LPCTSTR v, LPCTSTR file, LPCTSTR pwd) = 0;	
	virtual long DecodeFile(LPCTSTR file, LPCTSTR pwd) = 0;	
	virtual long KeyDownChar(LPCTSTR key_str) = 0;	
	virtual long KeyUpChar(LPCTSTR key_str) = 0;
	virtual long KeyPressChar(LPCTSTR key_str) = 0;	
	virtual long KeyPressStr(LPCTSTR key_str, long delay) = 0;
	virtual long EnableKeypadPatch(long en) = 0;	
	virtual long EnableKeypadSync(long en, long time_out) = 0;	
	virtual long EnableMouseSync(long en, long time_out) = 0;
	virtual long DmGuard(long en, LPCTSTR type) = 0;
	virtual long FaqCaptureFromFile(long x1, long y1, long x2, long y2, LPCTSTR file, long quality) = 0;	
	virtual CString FindIntEx(long hwnd, LPCTSTR addr_range, long int_value_min, long int_value_max, long type, long step, long multi_thread, long mode) = 0;
	virtual CString FindFloatEx(long hwnd, LPCTSTR addr_range, float float_value_min, float float_value_max, long step, long multi_thread, long mode) = 0;
	virtual CString FindDoubleEx(long hwnd, LPCTSTR addr_range, double double_value_min, double double_value_max, long step, long multi_thread, long mode) = 0;	
	virtual CString FindStringEx(long hwnd, LPCTSTR addr_range, LPCTSTR string_value, long type, long step, long multi_thread, long mode) = 0;
	virtual CString FindDataEx(long hwnd, LPCTSTR addr_range, LPCTSTR data, long step, long multi_thread, long mode) = 0;
	virtual long EnableRealMouse(long en, long mousedelay, long mousestep) = 0;
	virtual long EnableRealKeypad(long en) = 0;
	virtual long SendStringIme(LPCTSTR str) = 0;
	virtual long FoobarDrawLine(long hwnd, long x1, long y1, long x2, long y2, LPCTSTR color, long style, long width) = 0;
	virtual CString FindStrEx(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim) = 0;
	virtual long IsBind(long hwnd) = 0;
	virtual long SetDisplayDelay(long t) = 0;
	virtual long GetDmCount() = 0;	
	virtual long DisableScreenSave() = 0;	
	virtual long DisablePowerSave() = 0;	
	virtual long SetMemoryHwndAsProcessId(long en) = 0;
	virtual long FindShape(long x1, long y1, long x2, long y2, LPCTSTR offset_color, double sim, long dir, VARIANT * x, VARIANT * y) = 0;
	virtual CString FindShapeE(long x1, long y1, long x2, long y2, LPCTSTR offset_color, double sim, long dir) = 0;
	virtual CString FindShapeEx(long x1, long y1, long x2, long y2, LPCTSTR offset_color, double sim, long dir) = 0;	
	virtual CString FindStrS(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, VARIANT * x, VARIANT * y) = 0;
	virtual CString FindStrExS(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim) = 0;
	virtual CString FindStrFastS(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim, VARIANT * x, VARIANT * y) = 0;	
	virtual CString FindStrFastExS(long x1, long y1, long x2, long y2, LPCTSTR str, LPCTSTR color, double sim) = 0;
	virtual CString FindPicS(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir, VARIANT * x, VARIANT * y) = 0;
	virtual CString FindPicExS(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir) = 0;
	virtual long ClearDict(long index) = 0;
	virtual CString GetMachineCodeNoMac() = 0;
	virtual long GetClientRect(long hwnd, VARIANT * x1, VARIANT * y1, VARIANT * x2, VARIANT * y2) = 0;
	virtual long EnableFakeActive(long en) = 0;
	virtual long GetScreenDataBmp(long x1, long y1, long x2, long y2, VARIANT * data, VARIANT * size) = 0;	
	virtual long EncodeFile(LPCTSTR file, LPCTSTR pwd) = 0;
	virtual CString GetCursorShapeEx(long type) = 0;
	virtual long FaqCancel() = 0;
	virtual CString IntToData(long int_value, long type) = 0;
	virtual CString FloatToData(float float_value) = 0;	
	virtual CString DoubleToData(double double_value) = 0;	
	virtual CString StringToData(LPCTSTR string_value, long type) = 0;
	virtual long SetMemoryFindResultToFile(LPCTSTR file) = 0;
	virtual long EnableBind(long en) = 0;
	virtual long SetSimMode(long mode) = 0;	
	virtual long LockMouseRect(long x1, long y1, long x2, long y2) = 0;
	virtual long SendPaste(long hwnd) = 0;	
	virtual long IsDisplayDead(long x1, long y1, long x2, long y2, long t) = 0;	
	virtual long GetKeyState(long vk) = 0;	
	virtual long CopyFile(LPCTSTR src_file, LPCTSTR dst_file, long over) = 0;
	virtual long IsFileExist(LPCTSTR file) = 0;	
	virtual long DeleteFile(LPCTSTR file) = 0;
	virtual long MoveFile(LPCTSTR src_file, LPCTSTR dst_file) = 0;
	virtual long CreateFolder(LPCTSTR folder_name) = 0;
	virtual long DeleteFolder(LPCTSTR folder_name) = 0;
	virtual long GetFileLength(LPCTSTR file) = 0;
	virtual CString ReadFile(LPCTSTR file) = 0;
	virtual long WaitKey(long key_code, long time_out) = 0;	
	virtual long DeleteIni(LPCTSTR section, LPCTSTR key, LPCTSTR file) = 0;	
	virtual long DeleteIniPwd(LPCTSTR section, LPCTSTR key, LPCTSTR file, LPCTSTR pwd) = 0;	
	virtual long EnableSpeedDx(long en) = 0;
	virtual long EnableIme(long en) = 0;
	virtual long Reg(LPCTSTR code, LPCTSTR Ver) = 0;	
	virtual CString SelectFile() = 0;
	virtual CString SelectDirectory() = 0;
	virtual long LockDisplay(long lock) = 0;
	virtual long FoobarSetSave(long hwnd, LPCTSTR file, long en, LPCTSTR header) = 0;	
	virtual CString EnumWindowSuper(LPCTSTR spec1, long flag1, long type1, LPCTSTR spec2, long flag2, long type2, long sort) = 0;
	virtual long DownloadFile(LPCTSTR url, LPCTSTR save_file, long timeout) = 0;	
	virtual long EnableKeypadMsg(long en) = 0;	
	virtual long EnableMouseMsg(long en) = 0;
	virtual long RegNoMac(LPCTSTR code, LPCTSTR Ver) = 0;	
	virtual long RegExNoMac(LPCTSTR code, LPCTSTR Ver, LPCTSTR ip) = 0;
	virtual long SetEnumWindowDelay(long delay) = 0;
	virtual long FindMulColor(long x1, long y1, long x2, long y2, LPCTSTR color, double sim) = 0;
	virtual CString GetDict(long index, long font_index) = 0;	
	virtual long GetBindWindow() = 0;
	virtual long FoobarStartGif(long hwnd, long x, long y, LPCTSTR pic_name, long repeat_limit, long delay) = 0;	
	virtual long FoobarStopGif(long hwnd, long x, long y, LPCTSTR pic_name) = 0;
	virtual long FreeProcessMemory(long hwnd) = 0;	
	virtual CString ReadFileData(LPCTSTR file, long start_pos, long end_pos) = 0;	
	virtual long VirtualAllocEx(long hwnd, long addr, long size, long type) = 0;
	virtual long VirtualFreeEx(long hwnd, long addr) = 0;	
	virtual CString GetCommandLine(long hwnd) = 0;	
	virtual long TerminateProcess(long pid) = 0;
	virtual CString GetNetTimeByIp(LPCTSTR ip) = 0;
	virtual CString EnumProcess(LPCTSTR name) = 0;	
	virtual CString GetProcessInfo(long pid) = 0;	
	virtual long ReadIntAddr(long hwnd, long addr, long type) = 0;	
	virtual CString ReadDataAddr(long hwnd, long addr, long len) = 0;	
	virtual double ReadDoubleAddr(long hwnd, long addr) = 0;
	virtual float ReadFloatAddr(long hwnd, long addr) = 0;
	virtual CString ReadStringAddr(long hwnd, long addr, long type, long len) = 0;	
	virtual long WriteDataAddr(long hwnd, long addr, LPCTSTR data) = 0;	
	virtual long WriteDoubleAddr(long hwnd, long addr, double v) = 0;
	virtual long WriteFloatAddr(long hwnd, long addr, float v) = 0;
	virtual long WriteIntAddr(long hwnd, long addr, long type, long v) = 0;
	virtual long WriteStringAddr(long hwnd, long addr, long type, LPCTSTR v) = 0;	
	virtual long Delays(long min_s, long max_s) = 0;	
	virtual long FindColorBlock(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long count, long width, long height, VARIANT * x, VARIANT * y) = 0;
	virtual CString FindColorBlockEx(long x1, long y1, long x2, long y2, LPCTSTR color, double sim, long count, long width, long height) = 0;
	virtual long OpenProcess(long pid) = 0;
	virtual CString EnumIniSection(LPCTSTR file) = 0;	
	virtual CString EnumIniSectionPwd(LPCTSTR file, LPCTSTR pwd) = 0;
	virtual CString EnumIniKey(LPCTSTR section, LPCTSTR file) = 0;	
	virtual CString EnumIniKeyPwd(LPCTSTR section, LPCTSTR file, LPCTSTR pwd) = 0;	
	virtual long SwitchBindWindow(long hwnd) = 0;
	virtual long InitCri() = 0;
	virtual long SendStringIme2(long hwnd, LPCTSTR str, long mode) = 0;
	virtual CString EnumWindowByProcessId(long pid, LPCTSTR title, LPCTSTR class_name, long filter) = 0;
	virtual CString GetDisplayInfo() = 0;
	virtual long EnableFontSmooth() = 0;
	virtual CString OcrExOne(long x1, long y1, long x2, long y2, LPCTSTR color, double sim) = 0;
	virtual long SetAero(long en) = 0;
	virtual long FoobarSetTrans(long hwnd, long trans, LPCTSTR color, double sim) = 0;
	virtual long EnablePicCache(long en) = 0;	
	virtual CString GetInfo(LPCTSTR cmd, LPCTSTR param) = 0;	
	virtual long FaqIsPosted() = 0;
	virtual long LoadPicByte(long addr, long size, LPCTSTR name) = 0;	
	virtual long MiddleDown() = 0;
	virtual long MiddleUp() = 0;

	// Idmsoft properties
public:

//////////////////////////////////////////////////////////////////////////
public:
protected:
private:
};
#endif // CXX_AIDPLUG_H
/* EOF */
