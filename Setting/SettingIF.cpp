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

const TCHAR TCHAR_DEFAULT[] = _T("Default");
bool		BOOL_DEFAULT = FALSE;
int			INT_DEFAULT = 0;
double		DOUBLE_DEFAULT = 0.0;

SettingIF* SettingIF::s_pcInstance = NULL;

const TCHAR TCHAR_INI_SETTING_FILE[] = _T("setting.ini");
const TCHAR TCHAR_INI_SETTING_FILE_DEFAULT[] = _T("data\\setting_default.ini");

const TCHAR TCHAR_SECTION_USERINFO[] = _T("用户信息");
const TCHAR TCHAR_KEY_USERINFO_UNSERNAME[] = _T("用户名");
const TCHAR TCHAR_KEY_USERINFO_PASSWORD[] = _T("密码");
const TCHAR TCHAR_KEY_USERINFO_STORE[] = _T("保存");

const TCHAR TCHAR_SECTION_SIMULATOR[] = _T("模拟器");
const TCHAR TCHAR_KEY_SIMULATOR_TYPE[] = _T("使用模拟器类型");

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

const TCHAR TCHAR_SECTION_RESETSIMULATORSIZE[] = _T("模拟器重置");
const TCHAR TCHAR_KEY_RESETSIMULATORSIZE_DOWN_OK[] = _T("Down使用");
const TCHAR TCHAR_KEY_RESETSIMULATORSIZE_DOWN_VALUE[] = _T("Down优先度");
const TCHAR TCHAR_KEY_RESETSIMULATORSIZE_CTRL_MINUS_OK[] = _T("Ctrl+-使用");
const TCHAR TCHAR_KEY_RESETSIMULATORSIZE_CTRL_MINUS_VALUE[] = _T("Ctrl+-优先度");
const TCHAR TCHAR_KEY_RESETSIMULATORSIZE_CTRL_WHEELDOWN_OK[] = _T("Ctrl+WheeldDwon使用");
const TCHAR TCHAR_KEY_RESETSIMULATORSIZE_CTRL_WHEELDOWN_VALUE[] = _T("Ctrl+WheelDwon优先度");
const TCHAR TCHAR_KEY_RESETSIMULATORSIZE_CTRL_LEFTCLICK_OK[] = _T("Ctrl+LeftClick使用");
const TCHAR TCHAR_KEY_RESETSIMULATORSIZE_CTRL_LEFTCLICK_VALUE[] = _T("Ctrl+LeftClick优先度");

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
SettingIF::SetUsingSimulatorType(SIMULATOR_TYPE eUsingSimulator)
{
	m_sStorageInfo.eUsingSimulator = eUsingSimulator;
	m_pIniFile->WriteInt(TCHAR_SECTION_SIMULATOR, TCHAR_KEY_SIMULATOR_TYPE, eUsingSimulator);
}

void 
SettingIF::SetBindWindowInfo(const BindWindowInfo& sBindWindowInfo) 
{
	m_sStorageInfo.sBindWindowInfo = sBindWindowInfo;
	m_pIniFile->WriteInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_DISPLAY, sBindWindowInfo.eDisplay);
	m_pIniFile->WriteInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_DISPLAYDX, sBindWindowInfo.lDisplayDx);
	m_pIniFile->WriteInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_MOUSE, sBindWindowInfo.eMouse);
	m_pIniFile->WriteInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_MOUSEDX, sBindWindowInfo.lMouseDx);
	m_pIniFile->WriteInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_KEYBOARD, sBindWindowInfo.eKeyboard);
	m_pIniFile->WriteInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_KEYBOARDDX, sBindWindowInfo.lKeyboardDx);
	m_pIniFile->WriteBool(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_PUBLIC, sBindWindowInfo.bPublic);
	m_pIniFile->WriteInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_PUBLICDX, sBindWindowInfo.lPublicDx);
	m_pIniFile->WriteInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_MODEL, sBindWindowInfo.eModel);
}

void 
SettingIF::SetResetSimulator(RESET_SIMULATOR_TYPE eResetSimulator, const ResetSimulator& sResetSimulator) 
{
	m_sStorageInfo.sResetSimulator[eResetSimulator] = sResetSimulator;
	switch(eResetSimulator) {
		case RESET_SIMULATOR_DOWN:
			m_pIniFile->WriteBool(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_DOWN_OK, sResetSimulator.bOK);
			m_pIniFile->WriteInt(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_DOWN_VALUE, sResetSimulator.lPriority);
			break;
		case RESET_SIMULATOR_CTRL_MINUS:
			m_pIniFile->WriteBool(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_CTRL_MINUS_OK, sResetSimulator.bOK);
			m_pIniFile->WriteInt(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_CTRL_MINUS_VALUE, sResetSimulator.lPriority);
			break;
		case RESET_SIMULATOR_CTRL_WHEELDOWN:
			m_pIniFile->WriteBool(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_CTRL_WHEELDOWN_OK, sResetSimulator.bOK);
			m_pIniFile->WriteInt(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_CTRL_WHEELDOWN_VALUE, sResetSimulator.lPriority);
			break;
		case RESET_SIMULATOR_CTRL_LEFTCLICK:
			m_pIniFile->WriteBool(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_CTRL_LEFTCLICK_OK, sResetSimulator.bOK);
			m_pIniFile->WriteInt(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_CTRL_LEFTCLICK_VALUE, sResetSimulator.lPriority);
			break;
		default:
			break;
	}
}

void 
SettingIF::GetSimulatorInfo(vector<SimulatorInfo> *vSimulatorInfo)
{
	if (NULL == vSimulatorInfo) {
		return;
	}
	*vSimulatorInfo = m_vSimulatorInfo;
}

SettingIF::SimulatorInfo 
SettingIF::GetUsingSimulatorInfo()
{
	if (1 == m_vSimulatorInfo.size()) {
		return m_vSimulatorInfo[0];
	}
	SimulatorInfo sSimulatorInfo;
	memset(&sSimulatorInfo, 0x00, sizeof(sSimulatorInfo));
	for(vector<SimulatorInfo>::const_iterator citer = m_vSimulatorInfo.begin(); citer != m_vSimulatorInfo.end(); ++citer) {
		if (m_sStorageInfo.eUsingSimulator == citer->eSimulator) {
			sSimulatorInfo = *citer;
		}
	}
	return sSimulatorInfo;
}

void 
SettingIF::GetResetSimulatorFromPriority(vector<ResetSimulator> *vResetSimulatorPriority)
{
	vResetSimulatorPriority->clear();
	for (int i=RESET_SIMULATOR_NON+1; i<RESET_SIMULATOR_ALL; i++) {
		if (true == m_sStorageInfo.sResetSimulator[i].bOK) {
			vResetSimulatorPriority->push_back(m_sStorageInfo.sResetSimulator[i]);
		}
	}
	//更新下顺序
	sort(vResetSimulatorPriority->begin(), vResetSimulatorPriority->end(),greater<ResetSimulator>());//降序排列
	//	sort(vSoldierPriority->begin(), vSoldierPriority->end(),less<SoldierSate>()); //升序排列
}


void
SettingIF::InitDefaultSetting()
{
	delete m_pIniFile;
	m_pIniFile = new CIniFile;
	if (true == m_pIniFile->OpenIniFile(TCHAR_INI_SETTING_FILE_DEFAULT)) {
		return;
	}

	m_sStorageInfo.eUsingSimulator = SIMULATOR_TYPE_NON;
	m_sStorageInfo.sBindWindowInfo.eDisplay = BINDWINDOWINFO_DISPLAY_DX;
	m_sStorageInfo.sBindWindowInfo.lDisplayDx = BINDWINDOWINFO_DISPLAY_DX_OPENGL;
	m_sStorageInfo.sBindWindowInfo.eMouse = BINDWINDOWINFO_MOUSE_WINDOWS3;
	m_sStorageInfo.sBindWindowInfo.lMouseDx = BINDWINDOWINFO_MOUSE_DX_NON;
	m_sStorageInfo.sBindWindowInfo.eKeyboard = BINDWINDOWINFO_KEYBOARD_WINDOWS;
	m_sStorageInfo.sBindWindowInfo.lKeyboardDx = BINDWINDOWINFO_KEYBOARD_DX_NON;
	m_sStorageInfo.sBindWindowInfo.bPublic = false;
	m_sStorageInfo.sBindWindowInfo.lPublicDx = BINDWINDOWINFO_PUBLIC_DX_NON;
	m_sStorageInfo.sBindWindowInfo.eModel = BINDWINDOWINFO_MODEL_AUTO;

	for (int i=RESET_SIMULATOR_NON+1; i<RESET_SIMULATOR_ALL; i++) {
		m_sStorageInfo.sResetSimulator[i].bOK = true;
		m_sStorageInfo.sResetSimulator[i].eResetSimulator = static_cast<RESET_SIMULATOR_TYPE>(i);
		m_sStorageInfo.sResetSimulator[i].lPriority = RESET_SIMULATOR_ALL-i;
	}
}

void 
SettingIF::ReadSettingFromFile()
{
	if (false == m_pIniFile->ReadEnable()) {
		return;
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

	m_sStorageInfo.eUsingSimulator = static_cast<SIMULATOR_TYPE>(m_pIniFile->ReadInt(TCHAR_SECTION_SIMULATOR, TCHAR_KEY_SIMULATOR_TYPE, INT_DEFAULT));
	m_sStorageInfo.sBindWindowInfo.eDisplay = static_cast<SettingIF::BINDWINDOWINFO_DISPLAY_TYPE>(m_pIniFile->ReadInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_DISPLAY, INT_DEFAULT));
	m_sStorageInfo.sBindWindowInfo.lDisplayDx = m_pIniFile->ReadInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_DISPLAYDX, INT_DEFAULT);
	m_sStorageInfo.sBindWindowInfo.eMouse = static_cast<SettingIF::BINDWINDOWINFO_MOUSE_TYPE>(m_pIniFile->ReadInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_MOUSE, INT_DEFAULT));
	m_sStorageInfo.sBindWindowInfo.lMouseDx = m_pIniFile->ReadInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_MOUSEDX, INT_DEFAULT);
	m_sStorageInfo.sBindWindowInfo.eKeyboard = static_cast<SettingIF::BINDWINDOWINFO_KEYBOARD_TYPE>(m_pIniFile->ReadInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_KEYBOARD, INT_DEFAULT));
	m_sStorageInfo.sBindWindowInfo.lKeyboardDx = m_pIniFile->ReadInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_KEYBOARDDX, INT_DEFAULT);
	m_sStorageInfo.sBindWindowInfo.bPublic = m_pIniFile->ReadBool(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_PUBLIC, BOOL_DEFAULT);
	m_sStorageInfo.sBindWindowInfo.lPublicDx = m_pIniFile->ReadInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_PUBLICDX, INT_DEFAULT);
	m_sStorageInfo.sBindWindowInfo.eModel = static_cast<SettingIF::BINDWINDOWINFO_MODEL_TYPE>(m_pIniFile->ReadInt(TCHAR_SECTION_BINDWINDOWINFO, TCHAR_KEY_BINDWINDOWINFO_MODEL, INT_DEFAULT));
	m_sStorageInfo.sResetSimulator[RESET_SIMULATOR_DOWN].bOK = m_pIniFile->ReadBool(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_DOWN_OK, BOOL_DEFAULT);
	m_sStorageInfo.sResetSimulator[RESET_SIMULATOR_DOWN].lPriority = m_pIniFile->ReadInt(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_DOWN_VALUE, INT_DEFAULT);
	m_sStorageInfo.sResetSimulator[RESET_SIMULATOR_CTRL_MINUS].bOK = m_pIniFile->ReadBool(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_CTRL_MINUS_OK, BOOL_DEFAULT);
	m_sStorageInfo.sResetSimulator[RESET_SIMULATOR_CTRL_MINUS].lPriority = m_pIniFile->ReadInt(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_CTRL_MINUS_VALUE, INT_DEFAULT);
	m_sStorageInfo.sResetSimulator[RESET_SIMULATOR_CTRL_WHEELDOWN].bOK = m_pIniFile->ReadBool(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_CTRL_WHEELDOWN_OK, BOOL_DEFAULT);
	m_sStorageInfo.sResetSimulator[RESET_SIMULATOR_CTRL_WHEELDOWN].lPriority = m_pIniFile->ReadInt(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_CTRL_WHEELDOWN_VALUE, INT_DEFAULT);
	m_sStorageInfo.sResetSimulator[RESET_SIMULATOR_CTRL_LEFTCLICK].bOK = m_pIniFile->ReadBool(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_CTRL_LEFTCLICK_OK, BOOL_DEFAULT);
	m_sStorageInfo.sResetSimulator[RESET_SIMULATOR_CTRL_LEFTCLICK].lPriority = m_pIniFile->ReadInt(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_CTRL_LEFTCLICK_VALUE, INT_DEFAULT);
}

void 
SettingIF::WriteSettingToFile()
{
	m_pIniFile->WriteIniFile(TCHAR_INI_SETTING_FILE);
}

SettingIF::SettingIF():
m_pIniFile(NULL)
{
	memset(&m_sStorageInfo, 0x00, sizeof(m_sStorageInfo));
	for (int k=RESET_SIMULATOR_DOWN; k<=RESET_SIMULATOR_CTRL_LEFTCLICK; k++) {
		m_sStorageInfo.sResetSimulator[k].eResetSimulator = static_cast<RESET_SIMULATOR_TYPE>(k);
	}
	
	m_vSimulatorInfo.clear();
	m_sStorageInfo.eUsingSimulator = SIMULATOR_TYPE_NON;

	if (NULL == m_pIniFile) {
		m_pIniFile = new CIniFile;
	}
	
	if (false == m_pIniFile->OpenIniFile(TCHAR_INI_SETTING_FILE)) {
		InitDefaultSetting();
	}
	ReadSettingFromFile();
	InitializeSimulatorInfo();
}


SettingIF::~SettingIF()
{
	m_pIniFile->CloseIniFile();
}
void 
SettingIF::InitializeSimulatorInfo()
{
	//蓝叠安卓模拟器(BlueStacks)
	SimulatorInfo sSimulatorInfo = InitSimulatorInfo(SIMULATOR_TYPE_BLUESTACKS, _T("蓝叠安卓模拟器(BlueStacks)"), _T("HD-Quit.exe"), _T("HD-RunApp.exe"), _T("SOFTWARE\\BlueStacks"));
	if (SIMULATOR_TYPE_NON != sSimulatorInfo.eSimulator) {
		m_vSimulatorInfo.push_back(sSimulatorInfo);
	}

// 	//靠谱经典版 ClueStacks			---不支持部落冲突
// 	sSimulatorInfo = InitSimulatorInfo(SIMULATOR_TYPE_KAOPU_JINDAINBAN, _T("靠谱安卓模拟器(经典版)"), _T("KP-Quit.exe"), _T("KP-RunApp.exe"), _T("SOFTWARE\\ClueStacks"));
// 	if (SIMULATOR_TYPE_NON != sSimulatorInfo.eSimulator) {
// 		m_vSimulatorInfo.push_back(sSimulatorInfo);
// 	}

	//靠谱最新版 NlueStacks
	sSimulatorInfo = InitSimulatorInfo(SIMULATOR_TYPE_KAOPU_ZUIXINBAN, _T("靠谱安卓模拟器(最新版)"), _T("NK-Quit.exe"), _T("NK-RunApp.exe"), _T("SOFTWARE\\NlueStacks"));
	if (SIMULATOR_TYPE_NON != sSimulatorInfo.eSimulator) {
		m_vSimulatorInfo.push_back(sSimulatorInfo);
	}

	//靠谱极速版 ClueStacks	
	CRegKey regKey;
	DWORD dwBufLen = MAX_PATH;
	memset(&sSimulatorInfo, 0x00, sizeof(sSimulatorInfo));
	if (ERROR_SUCCESS == regKey.Open(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\TianTian\\Setup"))) {
		sSimulatorInfo.eSimulator = SIMULATOR_TYPE_KAOPU_JISUBAN;
		strcpy_s(sSimulatorInfo.chSimulatorName, sizeof(sSimulatorInfo.chSimulatorName), _T("靠谱安卓模拟器(极速版)-天天暂不支持重启"));
		dwBufLen = MAX_PATH;
		regKey.QueryMultiStringValue(sSimulatorInfo.chInstallDir,_T("InstallPath"),&dwBufLen);
		dwBufLen = MAX_PATH;
		regKey.QueryMultiStringValue(sSimulatorInfo.chVersion,_T("Version"),&dwBufLen);

		strcpy_s(sSimulatorInfo.chQuit, sizeof(sSimulatorInfo.chQuit), _T("不支持退出"));
		strcpy_s(sSimulatorInfo.chRunApp, sizeof(sSimulatorInfo.chRunApp), _T("不支持启动"));
		regKey.Close();
	}
	if (SIMULATOR_TYPE_NON != sSimulatorInfo.eSimulator) {
		m_vSimulatorInfo.push_back(sSimulatorInfo);
	}

	if (0x01 == m_vSimulatorInfo.size()) {
		//只有一个模拟器
		sSimulatorInfo = m_vSimulatorInfo.front();
		m_sStorageInfo.eUsingSimulator = sSimulatorInfo.eSimulator;
	}
}

SettingIF::SimulatorInfo 
SettingIF::InitSimulatorInfo(SIMULATOR_TYPE eSimulatorType, CString cstrName, CString cstrQuit, CString cstrRunApp, CString cstrKeyPath)
{
	CRegKey regKey;
	DWORD dwBufLen = MAX_PATH;

	SimulatorInfo sSimulatorInfo;
	memset(&sSimulatorInfo, 0x00, sizeof(sSimulatorInfo));
	if (ERROR_SUCCESS == regKey.Open(HKEY_LOCAL_MACHINE, cstrKeyPath)) {
		sSimulatorInfo.eSimulator = eSimulatorType;
		strcpy_s(sSimulatorInfo.chSimulatorName, sizeof(sSimulatorInfo.chSimulatorName), cstrName);

		dwBufLen = MAX_PATH;
		regKey.QueryMultiStringValue(sSimulatorInfo.chDataDir,_T("DataDir"),&dwBufLen);
		dwBufLen = MAX_PATH;
		regKey.QueryMultiStringValue(sSimulatorInfo.chInstallDir,_T("InstallDir"),&dwBufLen);
		dwBufLen = MAX_PATH;
		regKey.QueryMultiStringValue(sSimulatorInfo.chLogDir,_T("LogDir"),&dwBufLen);
		dwBufLen = MAX_PATH;
		regKey.QueryMultiStringValue(sSimulatorInfo.chUserDefinedDir,_T("UserDefinedDir"),&dwBufLen);
		dwBufLen = MAX_PATH;
		regKey.QueryMultiStringValue(sSimulatorInfo.chVersion,_T("Version"),&dwBufLen);

		strcpy_s(sSimulatorInfo.chQuit, sizeof(sSimulatorInfo.chQuit), sSimulatorInfo.chInstallDir);
		strcat_s(sSimulatorInfo.chQuit, sizeof(sSimulatorInfo.chQuit)-strlen(sSimulatorInfo.chQuit),cstrQuit);

		strcpy_s(sSimulatorInfo.chRunApp, sizeof(sSimulatorInfo.chRunApp), sSimulatorInfo.chInstallDir);
		strcat_s(sSimulatorInfo.chRunApp, sizeof(sSimulatorInfo.chRunApp)-strlen(sSimulatorInfo.chRunApp), cstrRunApp);

		//退出模拟器
		CString cstrWinExecPath = sSimulatorInfo.chQuit;
		cstrWinExecPath.Replace(_T("\\"), _T("\\\\"));
		CString cstrWinExec = _T("\"") + cstrWinExecPath + _T("\" Android");
		strcat_s(sSimulatorInfo.chQuitWinExec, sizeof(sSimulatorInfo.chQuitWinExec), (LPSTR)(LPCTSTR)cstrWinExec);

		//启动游戏
		cstrWinExecPath = sSimulatorInfo.chRunApp;
		cstrWinExecPath.Replace(_T("\\"), _T("\\\\"));
		cstrWinExec = _T("\"") + cstrWinExecPath + _T("\" Android com.supercell.clashofclans com.supercell.clashofclans.GameApp");
		strcat_s(sSimulatorInfo.chRunAppWinExec, sizeof(sSimulatorInfo.chRunAppWinExec), (LPSTR)(LPCTSTR)cstrWinExec);
		regKey.Close();
	}

	if (ERROR_SUCCESS == regKey.Open(HKEY_LOCAL_MACHINE, cstrKeyPath+_T("\\Guests\\Android\\FrameBuffer\\0"))) {
		regKey.QueryDWORDValue(_T("FullScreen"), sSimulatorInfo.dwFullScreen);
		if (0x00 != sSimulatorInfo.dwFullScreen) {
			sSimulatorInfo.dwFullScreen = 0x00;
			regKey.SetDWORDValue(_T("FullScreen"), sSimulatorInfo.dwFullScreen);
		}
		regKey.QueryDWORDValue(_T("Width"), sSimulatorInfo.dwWidth);
		if (800 != sSimulatorInfo.dwWidth) {
			sSimulatorInfo.dwWidth = 800;
			regKey.SetDWORDValue(_T("Width"), sSimulatorInfo.dwWidth);
		}
		regKey.QueryDWORDValue(_T("Height"), sSimulatorInfo.dwHeight);
		if (600 != sSimulatorInfo.dwHeight) {
			sSimulatorInfo.dwHeight = 600;
			regKey.SetDWORDValue(_T("Height"), sSimulatorInfo.dwHeight);
		}
// 		regKey.QueryDWORDValue(_T("WindowWidth"), sSimulatorInfo.dwWindowWidth);
// 		if (800 != sSimulatorInfo.dwWindowWidth) {
// 			sSimulatorInfo.dwWindowWidth = 800;
// 			regKey.SetDWORDValue(_T("WindowWidth"), sSimulatorInfo.dwWindowWidth);
// 		}
// 		regKey.QueryDWORDValue(_T("WindowHeight"), sSimulatorInfo.dwWindowHeight);
// 		if (600 != sSimulatorInfo.dwWindowHeight) {
// 			sSimulatorInfo.dwWindowHeight = 600;
// 			regKey.SetDWORDValue(_T("Height"), sSimulatorInfo.dwWindowHeight);
// 		}
		regKey.Close();
	}
	return sSimulatorInfo;
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