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

#ifndef CXX_SIMULATORSETTINGIF_H
#include "SimulatorSettingIF.h"
#endif

#ifndef CXX_AIDPLUGIDENTIFYIF_H
#include "AidPlugIdentifyIF.h"
#endif

SimulatorSettingIF* SimulatorSettingIF::s_pcInstance = NULL;

const TCHAR TCHAR_INI_SIMULATOR_SETTING_FILE[] = _T("simulator_setting.ini");


const TCHAR TCHAR_SECTION_SIMULATOR[] = _T("ģ����");
const TCHAR TCHAR_KEY_SIMULATOR_TYPE[] = _T("ʹ��ģ��������");

const TCHAR TCHAR_SECTION_RESETSIMULATORSIZE[] = _T("ģ��������");
const TCHAR TCHAR_KEY_RESETSIMULATORSIZE_DOWN_OK[] = _T("Downʹ��");
const TCHAR TCHAR_KEY_RESETSIMULATORSIZE_DOWN_VALUE[] = _T("Down���ȶ�");
const TCHAR TCHAR_KEY_RESETSIMULATORSIZE_CTRL_MINUS_OK[] = _T("Ctrl+-ʹ��");
const TCHAR TCHAR_KEY_RESETSIMULATORSIZE_CTRL_MINUS_VALUE[] = _T("Ctrl+-���ȶ�");
const TCHAR TCHAR_KEY_RESETSIMULATORSIZE_CTRL_WHEELDOWN_OK[] = _T("Ctrl+WheeldDwonʹ��");
const TCHAR TCHAR_KEY_RESETSIMULATORSIZE_CTRL_WHEELDOWN_VALUE[] = _T("Ctrl+WheelDwon���ȶ�");
const TCHAR TCHAR_KEY_RESETSIMULATORSIZE_CTRL_LEFTCLICK_OK[] = _T("Ctrl+LeftClickʹ��");
const TCHAR TCHAR_KEY_RESETSIMULATORSIZE_CTRL_LEFTCLICK_VALUE[] = _T("Ctrl+LeftClick���ȶ�");

SimulatorSettingIF* 
SimulatorSettingIF::Instance(void)
{
	if (NULL == s_pcInstance) {
		s_pcInstance = new SimulatorSettingIF;
	}
	return s_pcInstance;
}

void
SimulatorSettingIF::Destroy(void)
{
	if (NULL != s_pcInstance) {
		delete s_pcInstance;
		s_pcInstance = NULL;
	}
}

void 
SimulatorSettingIF::SetUsingSimulatorType(SIMULATOR_TYPE eUsingSimulator)
{
	m_sStorageInfo.eUsingSimulator = eUsingSimulator;
	m_pIniFile->WriteInt(TCHAR_SECTION_SIMULATOR, TCHAR_KEY_SIMULATOR_TYPE, eUsingSimulator);
}

void 
SimulatorSettingIF::SetResetSimulator(const ResetSimulator& sResetSimulator) 
{
	m_sStorageInfo.sResetSimulator[sResetSimulator.eResetSimulator] = sResetSimulator;
	switch(sResetSimulator.eResetSimulator) {
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
SimulatorSettingIF::GetSimulatorInfo(vector<SimulatorInfo> *vSimulatorInfo)
{
	if (NULL == vSimulatorInfo) {
		return;
	}
	*vSimulatorInfo = m_vSimulatorInfo;
}

SimulatorSettingIF::SimulatorInfo 
SimulatorSettingIF::GetUsingSimulatorInfo()
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
SimulatorSettingIF::GetResetSimulatorFromPriority(vector<ResetSimulator> *vResetSimulatorPriority)
{
	vResetSimulatorPriority->clear();
	for (int i=RESET_SIMULATOR_NON+1; i<RESET_SIMULATOR_ALL; i++) {
		if (true == m_sStorageInfo.sResetSimulator[i].bOK) {
			vResetSimulatorPriority->push_back(m_sStorageInfo.sResetSimulator[i]);
		}
	}
	//������˳��
	sort(vResetSimulatorPriority->begin(), vResetSimulatorPriority->end(),greater<ResetSimulator>());//��������
	//	sort(vSoldierPriority->begin(), vSoldierPriority->end(),less<SoldierSate>()); //��������
}


void
SimulatorSettingIF::InitDefaultSetting()
{
	//[ģ����]
	SetUsingSimulatorType(SIMULATOR_TYPE_NON);

	//[ģ��������]
	ResetSimulator sResetSimulator;
	for (int i=RESET_SIMULATOR_NON+1; i<RESET_SIMULATOR_ALL; i++) {
		memset(&sResetSimulator, 0x00, sizeof(sResetSimulator));
		sResetSimulator.bOK = true;
		sResetSimulator.eResetSimulator = static_cast<RESET_SIMULATOR_TYPE>(i);
		sResetSimulator.lPriority = RESET_SIMULATOR_ALL-i;
		SetResetSimulator(sResetSimulator);
	}
}

bool 
SimulatorSettingIF::ReadSettingFromFile()
{
	if (false == m_pIniFile->OpenIniFile(TCHAR_INI_SIMULATOR_SETTING_FILE)) {
		return false;
	}

	const char* pReadString = NULL;
	m_sStorageInfo.eUsingSimulator = static_cast<SIMULATOR_TYPE>(m_pIniFile->ReadInt(TCHAR_SECTION_SIMULATOR, TCHAR_KEY_SIMULATOR_TYPE, INT_DEFAULT));
	m_sStorageInfo.sResetSimulator[RESET_SIMULATOR_DOWN].bOK = m_pIniFile->ReadBool(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_DOWN_OK, BOOL_DEFAULT);
	m_sStorageInfo.sResetSimulator[RESET_SIMULATOR_DOWN].lPriority = m_pIniFile->ReadInt(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_DOWN_VALUE, INT_DEFAULT);
	m_sStorageInfo.sResetSimulator[RESET_SIMULATOR_CTRL_MINUS].bOK = m_pIniFile->ReadBool(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_CTRL_MINUS_OK, BOOL_DEFAULT);
	m_sStorageInfo.sResetSimulator[RESET_SIMULATOR_CTRL_MINUS].lPriority = m_pIniFile->ReadInt(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_CTRL_MINUS_VALUE, INT_DEFAULT);
	m_sStorageInfo.sResetSimulator[RESET_SIMULATOR_CTRL_WHEELDOWN].bOK = m_pIniFile->ReadBool(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_CTRL_WHEELDOWN_OK, BOOL_DEFAULT);
	m_sStorageInfo.sResetSimulator[RESET_SIMULATOR_CTRL_WHEELDOWN].lPriority = m_pIniFile->ReadInt(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_CTRL_WHEELDOWN_VALUE, INT_DEFAULT);
	m_sStorageInfo.sResetSimulator[RESET_SIMULATOR_CTRL_LEFTCLICK].bOK = m_pIniFile->ReadBool(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_CTRL_LEFTCLICK_OK, BOOL_DEFAULT);
	m_sStorageInfo.sResetSimulator[RESET_SIMULATOR_CTRL_LEFTCLICK].lPriority = m_pIniFile->ReadInt(TCHAR_SECTION_RESETSIMULATORSIZE, TCHAR_KEY_RESETSIMULATORSIZE_CTRL_LEFTCLICK_VALUE, INT_DEFAULT);
	return true;
}

void 
SimulatorSettingIF::WriteSettingToFile()
{
	m_pIniFile->WriteIniFile(TCHAR_INI_SIMULATOR_SETTING_FILE);
}

SimulatorSettingIF::SimulatorSettingIF():
m_pIniFile(NULL)
{
	if (NULL == m_pIniFile) {
		m_pIniFile = new CIniFile;
	}

	memset(&m_sStorageInfo, 0x00, sizeof(m_sStorageInfo));
	for (int k=RESET_SIMULATOR_DOWN; k<=RESET_SIMULATOR_CTRL_LEFTCLICK; k++) {
		m_sStorageInfo.sResetSimulator[k].eResetSimulator = static_cast<RESET_SIMULATOR_TYPE>(k);
	}
	m_vSimulatorInfo.clear();
	m_sStorageInfo.eUsingSimulator = SIMULATOR_TYPE_NON;
	InitializeSimulatorInfo();

	if (false == ReadSettingFromFile()) {
		InitDefaultSetting();
	}
}


SimulatorSettingIF::~SimulatorSettingIF()
{
	m_pIniFile->CloseIniFile();
}
void 
SimulatorSettingIF::InitializeSimulatorInfo()
{
	//������׿ģ����(BlueStacks)
	SimulatorInfo sSimulatorInfo = InitSimulatorInfo(SIMULATOR_TYPE_BLUESTACKS, _T("������׿ģ����(BlueStacks)"), _T("HD-Quit.exe"), _T("HD-RunApp.exe"), _T("SOFTWARE\\BlueStacks"));
	if (SIMULATOR_TYPE_NON != sSimulatorInfo.eSimulator) {
		m_vSimulatorInfo.push_back(sSimulatorInfo);
	}

// 	//���׾���� ClueStacks			---��֧�ֲ����ͻ
// 	sSimulatorInfo = InitSimulatorInfo(SIMULATOR_TYPE_KAOPU_JINDAINBAN, _T("���װ�׿ģ����(�����)"), _T("KP-Quit.exe"), _T("KP-RunApp.exe"), _T("SOFTWARE\\ClueStacks"));
// 	if (SIMULATOR_TYPE_NON != sSimulatorInfo.eSimulator) {
// 		m_vSimulatorInfo.push_back(sSimulatorInfo);
// 	}

	//�������°� NlueStacks
	sSimulatorInfo = InitSimulatorInfo(SIMULATOR_TYPE_KAOPU_ZUIXINBAN, _T("���װ�׿ģ����(���°�)"), _T("NK-Quit.exe"), _T("NK-RunApp.exe"), _T("SOFTWARE\\NlueStacks"));
	if (SIMULATOR_TYPE_NON != sSimulatorInfo.eSimulator) {
		m_vSimulatorInfo.push_back(sSimulatorInfo);
	}

	//���׼��ٰ� ClueStacks	
	CRegKey regKey;
	DWORD dwBufLen = MAX_PATH;
	memset(&sSimulatorInfo, 0x00, sizeof(sSimulatorInfo));
	if (ERROR_SUCCESS == regKey.Open(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\TianTian\\Setup"))) {
		sSimulatorInfo.eSimulator = SIMULATOR_TYPE_KAOPU_JISUBAN;
		strcpy_s(sSimulatorInfo.chSimulatorName, sizeof(sSimulatorInfo.chSimulatorName), _T("���װ�׿ģ����(���ٰ�)-�����ݲ�֧������"));
		dwBufLen = MAX_PATH;
		regKey.QueryValue(sSimulatorInfo.chInstallDir,_T("InstallPath"),&dwBufLen);
		dwBufLen = MAX_PATH;
		regKey.QueryValue(sSimulatorInfo.chVersion,_T("Version"),&dwBufLen);

		strcpy_s(sSimulatorInfo.chQuit, sizeof(sSimulatorInfo.chQuit), _T("��֧���˳�"));
		strcpy_s(sSimulatorInfo.chRunApp, sizeof(sSimulatorInfo.chRunApp), _T("��֧������"));
		regKey.Close();
	}
	if (SIMULATOR_TYPE_NON != sSimulatorInfo.eSimulator) {
		m_vSimulatorInfo.push_back(sSimulatorInfo);
	}

	if (0x01 == m_vSimulatorInfo.size()) {
		//ֻ��һ��ģ����
		sSimulatorInfo = m_vSimulatorInfo.front();
		m_sStorageInfo.eUsingSimulator = sSimulatorInfo.eSimulator;
	}
}

SimulatorSettingIF::SimulatorInfo 
SimulatorSettingIF::InitSimulatorInfo(SIMULATOR_TYPE eSimulatorType, CString cstrName, CString cstrQuit, CString cstrRunApp, CString cstrKeyPath)
{
	CRegKey regKey;
	DWORD dwBufLen = MAX_PATH;

	SimulatorInfo sSimulatorInfo;
	memset(&sSimulatorInfo, 0x00, sizeof(sSimulatorInfo));
	if (ERROR_SUCCESS == regKey.Open(HKEY_LOCAL_MACHINE, cstrKeyPath)) {
		sSimulatorInfo.eSimulator = eSimulatorType;
		strcpy_s(sSimulatorInfo.chSimulatorName, sizeof(sSimulatorInfo.chSimulatorName), cstrName);

		dwBufLen = MAX_PATH;
		regKey.QueryValue(sSimulatorInfo.chDataDir,_T("DataDir"),&dwBufLen);
		dwBufLen = MAX_PATH;
		regKey.QueryValue(sSimulatorInfo.chInstallDir,_T("InstallDir"),&dwBufLen);
		dwBufLen = MAX_PATH;
		regKey.QueryValue(sSimulatorInfo.chLogDir,_T("LogDir"),&dwBufLen);
		dwBufLen = MAX_PATH;
		regKey.QueryValue(sSimulatorInfo.chUserDefinedDir,_T("UserDefinedDir"),&dwBufLen);
		dwBufLen = MAX_PATH;
		regKey.QueryValue(sSimulatorInfo.chVersion,_T("Version"),&dwBufLen);

		strcpy_s(sSimulatorInfo.chQuit, sizeof(sSimulatorInfo.chQuit), sSimulatorInfo.chInstallDir);
		strcat_s(sSimulatorInfo.chQuit, sizeof(sSimulatorInfo.chQuit)-strlen(sSimulatorInfo.chQuit),cstrQuit);

		strcpy_s(sSimulatorInfo.chRunApp, sizeof(sSimulatorInfo.chRunApp), sSimulatorInfo.chInstallDir);
		strcat_s(sSimulatorInfo.chRunApp, sizeof(sSimulatorInfo.chRunApp)-strlen(sSimulatorInfo.chRunApp), cstrRunApp);

		//�˳�ģ����
		CString cstrWinExecPath = sSimulatorInfo.chQuit;
		cstrWinExecPath.Replace(_T("\\"), _T("\\\\"));
		CString cstrWinExec = _T("\"") + cstrWinExecPath + _T("\" Android");
		strcat_s(sSimulatorInfo.chQuitWinExec, sizeof(sSimulatorInfo.chQuitWinExec), (LPSTR)(LPCTSTR)cstrWinExec);

		//������Ϸ
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
/* EOF */