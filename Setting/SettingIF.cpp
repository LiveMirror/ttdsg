/**
@(#)$Id$
* @(#)
*
* (c)  XIAOTING PRIVATE PERSON  2014
* All Rights Reserved.
*/

/**
@brief  Setting IF
@Author $Author$
@Date $Date$
@Revision $Revision$
@URL $URL$
@Header $Header$
*/
#include "stdafx.h"
#include<fstream>
#include<vector>
#include <algorithm>
#include <functional>
using namespace std;

#ifndef CXX_SETTINGIF_H
#include "SettingIF.h"
#endif

#ifndef CXX_AIDPLUGIDENTIFYIF_H
#include "AidPlugIdentifyIF.h"
#endif


SettingIF* SettingIF::s_pcInstance = NULL;

const TCHAR TCHAR_INI_SETTING_FILE[] = _T("setting.ini");

const TCHAR TCHAR_SECTION_USERINFO[] = _T("用户信息");
const TCHAR TCHAR_KEY_USERINFO_UNSERNAME[] = _T("用户名");
const TCHAR TCHAR_KEY_USERINFO_PASSWORD[] = _T("密码");
const TCHAR TCHAR_KEY_USERINFO_STORE[] = _T("保存");

const TCHAR TCHAR_SECTION_BINDWINDOWINFO[] = _T("窗口绑定");
const TCHAR TCHAR_KEY_BINDWINDOWINFO_DISPLAY[] = _T("屏幕颜色获取方式");
const TCHAR TCHAR_KEY_BINDWINDOWINFO_DISPLAYDX[] = _T("屏幕颜色dx模式");
const TCHAR TCHAR_KEY_BINDWINDOWINFO_MOUSE[] = _T("鼠标仿真模式");
const TCHAR TCHAR_KEY_BINDWINDOWINFO_MOUSEDX[] = _T("鼠标dx模式");
const TCHAR TCHAR_KEY_BINDWINDOWINFO_KEYBOARD[] = _T("键盘仿真模式");
const TCHAR TCHAR_KEY_BINDWINDOWINFO_KEYBOARDDX[] = _T("键盘dx模式");
const TCHAR TCHAR_KEY_BINDWINDOWINFO_PUBLIC[] = _T("公共属性");
const TCHAR TCHAR_KEY_BINDWINDOWINFO_PUBLICDX[] = _T("公共属性dx模式");
const TCHAR TCHAR_KEY_BINDWINDOWINFO_MODEL[] = _T("模式");

const TCHAR TCHAR_SECTION_HOTKEY[] = _T("热键");
const TCHAR TCHAR_KEY_HOTKEY_HIDE[] = _T("隐藏");

SettingIF* 
SettingIF::Instance(void)
{
	if (NULL == s_pcInstance) {
		s_pcInstance = new SettingIF;
	}
	return s_pcInstance;
}

void
SettingIF::Destroy(void)
{
	if (NULL != s_pcInstance) {
		delete s_pcInstance;
		s_pcInstance = NULL;
	}
}

void 
SettingIF::SetUserName(const char* pchUserName)
{
	strcpy_s(m_sStorageInfo.chUserName, sizeof(m_sStorageInfo.chUserName), pchUserName);
	m_pIniFile->WriteString(TCHAR_SECTION_USERINFO, TCHAR_KEY_USERINFO_UNSERNAME, pchUserName);
}

void 
SettingIF::SetPassword(const char* pchPassword)
{
	strcpy_s(m_sStorageInfo.chPassword, sizeof(m_sStorageInfo.chPassword), pchPassword);
	m_pIniFile->WriteString(TCHAR_SECTION_USERINFO, TCHAR_KEY_USERINFO_PASSWORD, pchPassword);
}

void 
SettingIF::SetPasswordStore(bool bPasswordStore)
{
	m_sStorageInfo.bPasswordStore = bPasswordStore;
	m_pIniFile->WriteBool(TCHAR_SECTION_USERINFO, TCHAR_KEY_USERINFO_STORE, bPasswordStore);
}

void 
SettingIF::SetBindWindowInfo(const BindWindowInfo& sBindWindowInfo) 
{
	m_sStorageInfo.sBindWindowInfo = sBindWindowInfo;
	m_pIniFile->WriteInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_MODEL, sBindWindowInfo.eModel);
	m_pIniFile->WriteInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_PUBLICDX, sBindWindowInfo.lPublicDx);
	m_pIniFile->WriteBool(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_PUBLIC, sBindWindowInfo.bPublic);
	m_pIniFile->WriteInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_KEYBOARDDX, sBindWindowInfo.lKeyboardDx);
	m_pIniFile->WriteInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_KEYBOARD, sBindWindowInfo.eKeyboard);
	m_pIniFile->WriteInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_MOUSEDX, sBindWindowInfo.lMouseDx);
	m_pIniFile->WriteInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_MOUSE, sBindWindowInfo.eMouse);
	m_pIniFile->WriteInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_DISPLAYDX, sBindWindowInfo.lDisplayDx);
	m_pIniFile->WriteInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_DISPLAY, sBindWindowInfo.eDisplay);
}

void 
SettingIF::SetHotKey(const Hotkey& sHotkey)
{
	m_sStorageInfo.sHotkey[sHotkey.eHotKey] = sHotkey;
	switch(sHotkey.eHotKey) {
		case SettingIF::HOTKEY_HIDE:
			m_pIniFile->WriteInt(TCHAR_SECTION_HOTKEY, TCHAR_KEY_HOTKEY_HIDE, sHotkey.uiHotKey);
			break;
		default:
			break;
	}	
}

void
SettingIF::InitDefaultSetting()
{
	//[用户信息]
	SetPasswordStore(true);
	SetPassword("mxfzttdsg");
	SetUserName("mxfzttdsg");

	BindWindowInfo sBindWindowInfo;
	memset(&sBindWindowInfo, 0x00, sizeof(sBindWindowInfo));
	sBindWindowInfo.eDisplay = BINDWINDOWINFO_DISPLAY_DX;
	sBindWindowInfo.lDisplayDx = BINDWINDOWINFO_DISPLAY_DX_OPENGL;
	sBindWindowInfo.eMouse = BINDWINDOWINFO_MOUSE_WINDOWS3;
	sBindWindowInfo.lMouseDx = BINDWINDOWINFO_MOUSE_DX_NON;
	sBindWindowInfo.eKeyboard = BINDWINDOWINFO_KEYBOARD_WINDOWS;
	sBindWindowInfo.lKeyboardDx = BINDWINDOWINFO_KEYBOARD_DX_NON;
	sBindWindowInfo.bPublic = false;
	sBindWindowInfo.lPublicDx = BINDWINDOWINFO_PUBLIC_DX_NON;
	sBindWindowInfo.eModel = BINDWINDOWINFO_MODEL_AUTO;
	SetBindWindowInfo(sBindWindowInfo);

	//[热键]
	Hotkey sHotkey;
	memset(&sHotkey, 0x00, sizeof(sHotkey));
	sHotkey.eHotKey = HOTKEY_HIDE;
	sHotkey.uiHotKey = VK_F3;//VK_HOME;
	SetHotKey(sHotkey);
}

bool 
SettingIF::ReadSettingFromFile()
{
	if (false == m_pIniFile->OpenIniFile(TCHAR_INI_SETTING_FILE)) {
		return false;
	}

	const char* pReadString = NULL;
	pReadString = m_pIniFile->ReadString(TCHAR_SECTION_USERINFO, TCHAR_KEY_USERINFO_UNSERNAME, TCHAR_DEFAULT);
	if (0x00 != strcmp(pReadString, TCHAR_DEFAULT)) {
		strcpy_s(m_sStorageInfo.chUserName, sizeof(m_sStorageInfo.chUserName), pReadString);
	}
	pReadString = m_pIniFile->ReadString(TCHAR_SECTION_USERINFO, TCHAR_KEY_USERINFO_PASSWORD, TCHAR_DEFAULT);
	if (0x00 != strcmp(pReadString, TCHAR_DEFAULT)) {
		strcpy_s(m_sStorageInfo.chPassword, sizeof(m_sStorageInfo.chPassword), pReadString);
	}
	bool bReadBool = BOOL_DEFAULT;
	int iReadInt =  INT_DEFAULT;
	bReadBool = m_pIniFile->ReadBool(TCHAR_SECTION_USERINFO, TCHAR_KEY_USERINFO_STORE, BOOL_DEFAULT);
	if (BOOL_DEFAULT != bReadBool) {
		m_sStorageInfo.bPasswordStore = bReadBool;
	}

	m_sStorageInfo.sBindWindowInfo.eDisplay = static_cast<SettingIF::BINDWINDOWINFO_DISPLAY_TYPE>(m_pIniFile->ReadInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_DISPLAY, INT_DEFAULT));
	m_sStorageInfo.sBindWindowInfo.lDisplayDx = m_pIniFile->ReadInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_DISPLAYDX, INT_DEFAULT);
	m_sStorageInfo.sBindWindowInfo.eMouse = static_cast<SettingIF::BINDWINDOWINFO_MOUSE_TYPE>(m_pIniFile->ReadInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_MOUSE, INT_DEFAULT));
	m_sStorageInfo.sBindWindowInfo.lMouseDx = m_pIniFile->ReadInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_MOUSEDX, INT_DEFAULT);
	m_sStorageInfo.sBindWindowInfo.eKeyboard = static_cast<SettingIF::BINDWINDOWINFO_KEYBOARD_TYPE>(m_pIniFile->ReadInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_KEYBOARD, INT_DEFAULT));
	m_sStorageInfo.sBindWindowInfo.lKeyboardDx = m_pIniFile->ReadInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_KEYBOARDDX, INT_DEFAULT);
	m_sStorageInfo.sBindWindowInfo.bPublic = m_pIniFile->ReadBool(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_PUBLIC, BOOL_DEFAULT);
	m_sStorageInfo.sBindWindowInfo.lPublicDx = m_pIniFile->ReadInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_PUBLICDX, INT_DEFAULT);
	m_sStorageInfo.sBindWindowInfo.eModel = static_cast<SettingIF::BINDWINDOWINFO_MODEL_TYPE>(m_pIniFile->ReadInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_MODEL, INT_DEFAULT));
	m_sStorageInfo.sHotkey[HOTKEY_HIDE].uiHotKey = static_cast<SettingIF::HOTKEY_TYPE>(m_pIniFile->ReadInt(TCHAR_SECTION_HOTKEY, TCHAR_KEY_HOTKEY_HIDE, INT_DEFAULT));
	return true;
}

void 
SettingIF::WriteSettingToFile()
{
	m_pIniFile->WriteIniFile(TCHAR_INI_SETTING_FILE);
}

SettingIF::SettingIF():
m_pIniFile(NULL)
{
	if (NULL == m_pIniFile) {
		m_pIniFile = new CIniFile;
	}

	memset(&m_sStorageInfo, 0x00, sizeof(m_sStorageInfo));
	for (int i=HOTKEY_NON+1; i<HOTKEY_ALL; i++) {
		m_sStorageInfo.sHotkey[i].eHotKey =  static_cast<HOTKEY_TYPE>(i);
	}
	
	if (false == ReadSettingFromFile()) {
		InitDefaultSetting();
	}
}


SettingIF::~SettingIF()
{
	m_pIniFile->CloseIniFile();
}

CString 
SettingIF::GetBindWindowInfoDisplay()
{
	CString cstrDisplay;
	switch (m_sStorageInfo.sBindWindowInfo.eDisplay) {
		case BINDWINDOWINFO_DISPLAY_NORMAL:
			cstrDisplay = _T("normal");
			break;
		case BINDWINDOWINFO_DISPLAY_GDI:
			cstrDisplay = _T("gdi");
			break;
		case BINDWINDOWINFO_DISPLAY_GDI2:
			cstrDisplay = _T("gdi2");
			break;
		case BINDWINDOWINFO_DISPLAY_DX3:
			cstrDisplay = _T("dx2");
			break;
		case BINDWINDOWINFO_DISPLAY_DX2:
			cstrDisplay = _T("dx3");
			break;
		case BINDWINDOWINFO_DISPLAY_DX:
			if (BINDWINDOWINFO_DISPLAY_DX_2D == (BINDWINDOWINFO_DISPLAY_DX_2D&m_sStorageInfo.sBindWindowInfo.lDisplayDx)) {
				cstrDisplay += cstrDisplay.IsEmpty()?_T(""):_T("|");
				cstrDisplay += _T("dx.graphic.2d");
			}
			if (BINDWINDOWINFO_DISPLAY_DX_2D_2 == (BINDWINDOWINFO_DISPLAY_DX_2D_2&m_sStorageInfo.sBindWindowInfo.lDisplayDx)) {
				cstrDisplay += cstrDisplay.IsEmpty()?_T(""):_T("|");
				cstrDisplay += _T("dx.graphic.2d.2");
			}
			if (BINDWINDOWINFO_DISPLAY_DX_3D == (BINDWINDOWINFO_DISPLAY_DX_3D&m_sStorageInfo.sBindWindowInfo.lDisplayDx)) {
				cstrDisplay += cstrDisplay.IsEmpty()?_T(""):_T("|");
				cstrDisplay += _T("dx.graphic.3d");
			}
			if (BINDWINDOWINFO_DISPLAY_DX_3D_8 == (BINDWINDOWINFO_DISPLAY_DX_3D_8&m_sStorageInfo.sBindWindowInfo.lDisplayDx)) {
				cstrDisplay += cstrDisplay.IsEmpty()?_T(""):_T("|");
				cstrDisplay += _T("dx.graphic.3d.8");
			}
			if (BINDWINDOWINFO_DISPLAY_DX_OPENGL == (BINDWINDOWINFO_DISPLAY_DX_OPENGL&m_sStorageInfo.sBindWindowInfo.lDisplayDx)) {
				cstrDisplay += cstrDisplay.IsEmpty()?_T(""):_T("|");
				cstrDisplay += _T("dx.graphic.opengl");
			}
			break;
		default:
			break;
	}
	return cstrDisplay;
}

CString
SettingIF::GetBindWindowInfoMouse()
{
	CString cstrMouse;
	switch (m_sStorageInfo.sBindWindowInfo.eMouse) {
		case BINDWINDOWINFO_MOUSE_NORMAL:
			cstrMouse = _T("normal");
			break;
		case BINDWINDOWINFO_MOUSE_WINDOWS:
			cstrMouse = _T("windows");
			break;
		case BINDWINDOWINFO_MOUSE_WINDOWS3:
			cstrMouse = _T("windows3");
			break;
		case BINDWINDOWINFO_MOUSE_DX:
			if (BINDWINDOWINFO_MOUSE_DX_POSITION_LOCK_API == (BINDWINDOWINFO_MOUSE_DX_POSITION_LOCK_API&m_sStorageInfo.sBindWindowInfo.lMouseDx)) {
				cstrMouse += cstrMouse.IsEmpty()?_T(""):_T("|");
				cstrMouse += _T("dx.mouse.position.lock.api");
			}
			if (BINDWINDOWINFO_MOUSE_DX_POSITION_LOCK_MESSAGE == (BINDWINDOWINFO_MOUSE_DX_POSITION_LOCK_MESSAGE&m_sStorageInfo.sBindWindowInfo.lMouseDx)) {
				cstrMouse += cstrMouse.IsEmpty()?_T(""):_T("|");
				cstrMouse += _T("dx.mouse.position.lock.message");
			}
			if (BINDWINDOWINFO_MOUSE_DX_FOCUS_INPUT_API == (BINDWINDOWINFO_MOUSE_DX_FOCUS_INPUT_API&m_sStorageInfo.sBindWindowInfo.lMouseDx)) {
				cstrMouse += cstrMouse.IsEmpty()?_T(""):_T("|");
				cstrMouse += _T("dx.mouse.focus.input.api");
			}
			if (BINDWINDOWINFO_MOUSE_DX_FOCUS_INPUT_MESSAGE == (BINDWINDOWINFO_MOUSE_DX_FOCUS_INPUT_MESSAGE&m_sStorageInfo.sBindWindowInfo.lMouseDx)) {
				cstrMouse += cstrMouse.IsEmpty()?_T(""):_T("|");
				cstrMouse += _T("dx.mouse.focus.input.message");
			}
			if (BINDWINDOWINFO_MOUSE_DX_CLIP_LOCK_API == (BINDWINDOWINFO_MOUSE_DX_CLIP_LOCK_API&m_sStorageInfo.sBindWindowInfo.lMouseDx)) {
				cstrMouse += cstrMouse.IsEmpty()?_T(""):_T("|");
				cstrMouse += _T("dx.mouse.clip.lock.api");
			}
			if (BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API == (BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API&m_sStorageInfo.sBindWindowInfo.lMouseDx)) {
				cstrMouse += cstrMouse.IsEmpty()?_T(""):_T("|");
				cstrMouse += _T("dx.mouse.input.lock.api");
			}
			if (BINDWINDOWINFO_MOUSE_DX_STATE_API == (BINDWINDOWINFO_MOUSE_DX_STATE_API&m_sStorageInfo.sBindWindowInfo.lMouseDx)) {
				cstrMouse += cstrMouse.IsEmpty()?_T(""):_T("|");
				cstrMouse += _T("dx.mouse.state.api");
			}
			if (BINDWINDOWINFO_MOUSE_DX_STATE_MESSAGE == (BINDWINDOWINFO_MOUSE_DX_STATE_MESSAGE&m_sStorageInfo.sBindWindowInfo.lMouseDx)) {
				cstrMouse += cstrMouse.IsEmpty()?_T(""):_T("|");
				cstrMouse += _T("dx.mouse.state.message");
			}
			if (BINDWINDOWINFO_MOUSE_DX_API == (BINDWINDOWINFO_MOUSE_DX_API&m_sStorageInfo.sBindWindowInfo.lMouseDx)) {
				cstrMouse += cstrMouse.IsEmpty()?_T(""):_T("|");
				cstrMouse += _T("dx.mouse.api");
			}
			if (BINDWINDOWINFO_MOUSE_DX_CURSOR == (BINDWINDOWINFO_MOUSE_DX_CURSOR&m_sStorageInfo.sBindWindowInfo.lMouseDx)) {
				cstrMouse += cstrMouse.IsEmpty()?_T(""):_T("|");
				cstrMouse += _T("dx.mouse.cursor");
			}
			if (BINDWINDOWINFO_MOUSE_DX_RAW_INPUT == (BINDWINDOWINFO_MOUSE_DX_RAW_INPUT&m_sStorageInfo.sBindWindowInfo.lMouseDx)) {
				cstrMouse += cstrMouse.IsEmpty()?_T(""):_T("|");
				cstrMouse += _T("dx.mouse.raw.input");
			}
			if (BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API2 == (BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API2&m_sStorageInfo.sBindWindowInfo.lMouseDx)) {
				cstrMouse += cstrMouse.IsEmpty()?_T(""):_T("|");
				cstrMouse += _T("dx.mouse.input.lock.api2");
			}
			if (BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API3 == (BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API3&m_sStorageInfo.sBindWindowInfo.lMouseDx)) {
				cstrMouse += cstrMouse.IsEmpty()?_T(""):_T("|");
				cstrMouse += _T("dx.mouse.input.lock.api3");
			}
			break;
		default:
			break;
	}
	return cstrMouse;
}

CString 
SettingIF::GetBindWindowInfoKeyboard()
{
	CString cstrKeyboard;
	switch (m_sStorageInfo.sBindWindowInfo.eKeyboard) {
		case BINDWINDOWINFO_KEYBOARD_NORMAL:
			cstrKeyboard = _T("normal");
			break;
		case BINDWINDOWINFO_KEYBOARD_WINDOWS:
			cstrKeyboard = _T("windows");
			break;
		case BINDWINDOWINFO_KEYBOARD_DX:
			if (BINDWINDOWINFO_KEYBOARD_DX_INPUT_LOCK_API == (BINDWINDOWINFO_KEYBOARD_DX_INPUT_LOCK_API&m_sStorageInfo.sBindWindowInfo.lKeyboardDx)) {
				cstrKeyboard += cstrKeyboard.IsEmpty()?_T(""):_T("|");
				cstrKeyboard += _T("dx.keypad.input.lock.api");
			}
			if (BINDWINDOWINFO_KEYBOARD_DX_STATE_API == (BINDWINDOWINFO_KEYBOARD_DX_STATE_API&m_sStorageInfo.sBindWindowInfo.lKeyboardDx)) {
				cstrKeyboard += cstrKeyboard.IsEmpty()?_T(""):_T("|");
				cstrKeyboard += _T("dx.keypad.state.api");
			}
			if (BINDWINDOWINFO_KEYBOARD_DX_API == (BINDWINDOWINFO_KEYBOARD_DX_API&m_sStorageInfo.sBindWindowInfo.lKeyboardDx)) {
				cstrKeyboard += cstrKeyboard.IsEmpty()?_T(""):_T("|");
				cstrKeyboard += _T("dx.keypad.api");
			}
			if (BINDWINDOWINFO_KEYBOARD_DX_RAW_INPUT == (BINDWINDOWINFO_KEYBOARD_DX_RAW_INPUT&m_sStorageInfo.sBindWindowInfo.lKeyboardDx)) {
				cstrKeyboard += cstrKeyboard.IsEmpty()?_T(""):_T("|");
				cstrKeyboard += _T("dx.keypad.raw.input");
			}
			break;
		default:
			break;
	}
	return cstrKeyboard;
}

CString 
SettingIF::GetBindWindowInfoPublic()
{
	CString cstrPublic;
	if (false == m_sStorageInfo.sBindWindowInfo.bPublic) {
		return cstrPublic;
	}
	if (BINDWINDOWINFO_PUBLIC_DX_ACTIVE_API == (BINDWINDOWINFO_PUBLIC_DX_ACTIVE_API&m_sStorageInfo.sBindWindowInfo.lPublicDx)) {
		cstrPublic += cstrPublic.IsEmpty()?_T(""):_T("|");
		cstrPublic += _T("dx.public.active.api");
	}
	if (BINDWINDOWINFO_PUBLIC_DX_ACTIVE_MESSAGE == (BINDWINDOWINFO_PUBLIC_DX_ACTIVE_MESSAGE&m_sStorageInfo.sBindWindowInfo.lPublicDx)) {
		cstrPublic += cstrPublic.IsEmpty()?_T(""):_T("|");
		cstrPublic += _T("dx.public.active.message");
	}
	if (BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_POSITION == (BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_POSITION&m_sStorageInfo.sBindWindowInfo.lPublicDx)) {
		cstrPublic += cstrPublic.IsEmpty()?_T(""):_T("|");
		cstrPublic += _T("dx.public.disable.window.position");
	}
	if (BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_SIZE == (BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_SIZE&m_sStorageInfo.sBindWindowInfo.lPublicDx)) {
		cstrPublic += cstrPublic.IsEmpty()?_T(""):_T("|");
		cstrPublic += _T("dx.public.disable.window.size");
	}
	if (BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_MINMAX == (BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_MINMAX&m_sStorageInfo.sBindWindowInfo.lPublicDx)) {
		cstrPublic += cstrPublic.IsEmpty()?_T(""):_T("|");
		cstrPublic += _T("dx.public.disable.window.minmax");
	}
	if (BINDWINDOWINFO_PUBLIC_DX_FAKE_WINDOW_MIN == (BINDWINDOWINFO_PUBLIC_DX_FAKE_WINDOW_MIN&m_sStorageInfo.sBindWindowInfo.lPublicDx)) {
		cstrPublic += cstrPublic.IsEmpty()?_T(""):_T("|");
		cstrPublic += _T("dx.public.fake.window.min");
	}
	if (BINDWINDOWINFO_PUBLIC_DX_HIDE_DLL == (BINDWINDOWINFO_PUBLIC_DX_HIDE_DLL&m_sStorageInfo.sBindWindowInfo.lPublicDx)) {
		cstrPublic += cstrPublic.IsEmpty()?_T(""):_T("|");
		cstrPublic += _T("dx.public.hide.dll");
	}
	if (BINDWINDOWINFO_PUBLIC_DX_ACTIVE_API2 == (BINDWINDOWINFO_PUBLIC_DX_ACTIVE_API2&m_sStorageInfo.sBindWindowInfo.lPublicDx)) {
		cstrPublic += cstrPublic.IsEmpty()?_T(""):_T("|");
		cstrPublic += _T("dx.public.active.api2");
	}
	if (BINDWINDOWINFO_PUBLIC_DX_INPUT_IME == (BINDWINDOWINFO_PUBLIC_DX_INPUT_IME&m_sStorageInfo.sBindWindowInfo.lPublicDx)) {
		cstrPublic += cstrPublic.IsEmpty()?_T(""):_T("|");
		cstrPublic += _T("dx.public.input.ime");
	}
	if (BINDWINDOWINFO_PUBLIC_DX_GRAPHIC_PROTECT == (BINDWINDOWINFO_PUBLIC_DX_GRAPHIC_PROTECT&m_sStorageInfo.sBindWindowInfo.lPublicDx)) {
		cstrPublic += cstrPublic.IsEmpty()?_T(""):_T("|");
		cstrPublic += _T("dx.public.graphic.protect");
	}
	if (BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_SHOW == (BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_SHOW&m_sStorageInfo.sBindWindowInfo.lPublicDx)) {
		cstrPublic += cstrPublic.IsEmpty()?_T(""):_T("|");
		cstrPublic += _T("dx.public.disable.window.show");
	}
	if (BINDWINDOWINFO_PUBLIC_DX_ANTI_API == (BINDWINDOWINFO_PUBLIC_DX_ANTI_API&m_sStorageInfo.sBindWindowInfo.lPublicDx)) {
		cstrPublic += cstrPublic.IsEmpty()?_T(""):_T("|");
		cstrPublic += _T("dx.public.anti.api");
	}
	if (BINDWINDOWINFO_PUBLIC_DX_MEMORY == (BINDWINDOWINFO_PUBLIC_DX_MEMORY&m_sStorageInfo.sBindWindowInfo.lPublicDx)) {
		cstrPublic += cstrPublic.IsEmpty()?_T(""):_T("|");
		cstrPublic += _T("dx.public.memory");
	}
	if (BINDWINDOWINFO_PUBLIC_DX_KM_PROTECT == (BINDWINDOWINFO_PUBLIC_DX_KM_PROTECT&m_sStorageInfo.sBindWindowInfo.lPublicDx)) {
		cstrPublic += cstrPublic.IsEmpty()?_T(""):_T("|");
		cstrPublic += _T("dx.public.km.protect");
	}
	if (BINDWINDOWINFO_PUBLIC_DX_PREVENT_BLOCK == (BINDWINDOWINFO_PUBLIC_DX_PREVENT_BLOCK&m_sStorageInfo.sBindWindowInfo.lPublicDx)) {
		cstrPublic += cstrPublic.IsEmpty()?_T(""):_T("|");
		cstrPublic += _T("dx.public.prevent.block");
	}
	if (BINDWINDOWINFO_PUBLIC_DX_ORI_PROC == (BINDWINDOWINFO_PUBLIC_DX_ORI_PROC&m_sStorageInfo.sBindWindowInfo.lPublicDx)) {
		cstrPublic += cstrPublic.IsEmpty()?_T(""):_T("|");
		cstrPublic += _T("dx.public.ori.proc");
	}
	if (BINDWINDOWINFO_PUBLIC_DX_DOWN_CPU == (BINDWINDOWINFO_PUBLIC_DX_DOWN_CPU&m_sStorageInfo.sBindWindowInfo.lPublicDx)) {
		cstrPublic += cstrPublic.IsEmpty()?_T(""):_T("|");
		cstrPublic += _T("dx.public.down.cpu");
	}
	if (BINDWINDOWINFO_PUBLIC_DX_FOCUS_MESSAGE == (BINDWINDOWINFO_PUBLIC_DX_FOCUS_MESSAGE&m_sStorageInfo.sBindWindowInfo.lPublicDx)) {
		cstrPublic += cstrPublic.IsEmpty()?_T(""):_T("|");
		cstrPublic += _T("dx.public.focus.message");
	}
	return cstrPublic;
}
/* EOF */