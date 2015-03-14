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

#ifndef CXX_SETTINGIF_H
#define CXX_SETTINGIF_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef INIFILE_H
#include "inifile.h"
#endif

class SettingIF
{
public:
	enum BINDWINDOWINFO_DISPLAY_TYPE
	{
		BINDWINDOWINFO_DISPLAY_NON = 0,
		BINDWINDOWINFO_DISPLAY_NORMAL,
		BINDWINDOWINFO_DISPLAY_GDI,
		BINDWINDOWINFO_DISPLAY_GDI2,
		BINDWINDOWINFO_DISPLAY_DX3,
		BINDWINDOWINFO_DISPLAY_DX2,

		BINDWINDOWINFO_DISPLAY_DX,
		BINDWINDOWINFO_DISPLAY_ALL,
		BINDWINDOWINFO_DISPLAY_INVALID = -1,
	};
	enum BINDWINDOWINFO_DISPLAY_DX_TYPE
	{
		BINDWINDOWINFO_DISPLAY_DX_NON					= 0x00000000,
		BINDWINDOWINFO_DISPLAY_DX_2D					= 0x00000001,
		BINDWINDOWINFO_DISPLAY_DX_2D_2					= 0x00000002,
		BINDWINDOWINFO_DISPLAY_DX_3D					= 0x00000004,
		BINDWINDOWINFO_DISPLAY_DX_3D_8					= 0x00000008,
		BINDWINDOWINFO_DISPLAY_DX_OPENGL				= 0x00000010,
	};

	enum BINDWINDOWINFO_MOUSE_TYPE
	{
		BINDWINDOWINFO_MOUSE_NON = 0,
		BINDWINDOWINFO_MOUSE_NORMAL,
		BINDWINDOWINFO_MOUSE_WINDOWS,
		BINDWINDOWINFO_MOUSE_WINDOWS3,

		BINDWINDOWINFO_MOUSE_DX,
		BINDWINDOWINFO_MOUSE_ALL,
		BINDWINDOWINFO_MOUSE_INVALID = -1,
	};
	enum BINDWINDOWINFO_MOUSE_DX_TYPE
	{
		BINDWINDOWINFO_MOUSE_DX_NON						= 0x00000000,
		BINDWINDOWINFO_MOUSE_DX_POSITION_LOCK_API		= 0x00000001,
		BINDWINDOWINFO_MOUSE_DX_POSITION_LOCK_MESSAGE	= 0x00000002,
		BINDWINDOWINFO_MOUSE_DX_FOCUS_INPUT_API			= 0x00000004,
		BINDWINDOWINFO_MOUSE_DX_FOCUS_INPUT_MESSAGE		= 0x00000008,
		BINDWINDOWINFO_MOUSE_DX_CLIP_LOCK_API			= 0x00000010,
		BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API			= 0x00000020,
		BINDWINDOWINFO_MOUSE_DX_STATE_API				= 0x00000040,
		BINDWINDOWINFO_MOUSE_DX_STATE_MESSAGE			= 0x00000080,
		BINDWINDOWINFO_MOUSE_DX_API						= 0x00000100,
		BINDWINDOWINFO_MOUSE_DX_CURSOR					= 0x00000200,
		BINDWINDOWINFO_MOUSE_DX_RAW_INPUT				= 0x00000400,
		BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API2			= 0x00000800,
		BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API3			= 0x00001000,
	};

	enum BINDWINDOWINFO_KEYBOARD_TYPE
	{
		BINDWINDOWINFO_KEYBOARD_NON = 0,
		BINDWINDOWINFO_KEYBOARD_NORMAL,
		BINDWINDOWINFO_KEYBOARD_WINDOWS,

		BINDWINDOWINFO_KEYBOARD_DX,
		BINDWINDOWINFO_KEYBOARD_ALL,
		BINDWINDOWINFO_KEYBOARD_INVALID = -1,
	};
	enum BINDWINDOWINFO_KEYBOARD_DX_TYPE
	{
		BINDWINDOWINFO_KEYBOARD_DX_NON					= 0X00000000,
		BINDWINDOWINFO_KEYBOARD_DX_INPUT_LOCK_API		= 0X00000001,
		BINDWINDOWINFO_KEYBOARD_DX_STATE_API			= 0X00000002,
		BINDWINDOWINFO_KEYBOARD_DX_API					= 0X00000004,
		BINDWINDOWINFO_KEYBOARD_DX_RAW_INPUT			= 0X00000008,
	};

	enum BINDWINDOWINFO_PUBLIC_DX_TYPE
	{
		BINDWINDOWINFO_PUBLIC_DX_NON					= 0X00000000,
		BINDWINDOWINFO_PUBLIC_DX_ACTIVE_API				= 0X00000001,
		BINDWINDOWINFO_PUBLIC_DX_ACTIVE_MESSAGE			= 0X00000002,
		BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_POSITION= 0X00000004,
		BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_SIZE	= 0X00000008,
		BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_MINMAX	= 0X00000010,
		BINDWINDOWINFO_PUBLIC_DX_FAKE_WINDOW_MIN		= 0X00000020,
		BINDWINDOWINFO_PUBLIC_DX_HIDE_DLL				= 0X00000040,
		BINDWINDOWINFO_PUBLIC_DX_ACTIVE_API2			= 0X00000080,
		BINDWINDOWINFO_PUBLIC_DX_INPUT_IME				= 0X00000100,
		BINDWINDOWINFO_PUBLIC_DX_GRAPHIC_PROTECT		= 0X00000200,
		BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_SHOW	= 0X00000400,
		BINDWINDOWINFO_PUBLIC_DX_ANTI_API				= 0X00000800,
		BINDWINDOWINFO_PUBLIC_DX_MEMORY					= 0X00001000,
		BINDWINDOWINFO_PUBLIC_DX_KM_PROTECT				= 0X00002000,
		BINDWINDOWINFO_PUBLIC_DX_PREVENT_BLOCK			= 0X00004000,
		BINDWINDOWINFO_PUBLIC_DX_ORI_PROC				= 0X00008000,
		BINDWINDOWINFO_PUBLIC_DX_DOWN_CPU				= 0X00010000,
		BINDWINDOWINFO_PUBLIC_DX_FOCUS_MESSAGE			= 0X00020000,
	};

	enum BINDWINDOWINFO_MODEL_TYPE
	{
		BINDWINDOWINFO_MODEL_0		= 0,
		BINDWINDOWINFO_MODEL_1		= 1,
		BINDWINDOWINFO_MODEL_2		= 2,
		BINDWINDOWINFO_MODEL_3		= 3,
		BINDWINDOWINFO_MODEL_4		= 4,
		BINDWINDOWINFO_MODEL_5		= 5,
		BINDWINDOWINFO_MODEL_6		= 6,
		BINDWINDOWINFO_MODEL_7		= 7,
		BINDWINDOWINFO_MODEL_101	= 101,
		BINDWINDOWINFO_MODEL_103	= 103,

		BINDWINDOWINFO_MODEL_AUTO,
		BINDWINDOWINFO_MODEL_INVALID = -1,
	};

	struct BindWindowInfo{
		BINDWINDOWINFO_DISPLAY_TYPE eDisplay;
		long lDisplayDx;
		BINDWINDOWINFO_MOUSE_TYPE eMouse;
		long lMouseDx;
		BINDWINDOWINFO_KEYBOARD_TYPE eKeyboard;
		long lKeyboardDx;
		bool bPublic;		//非0为Dx模式
		long lPublicDx;
		BINDWINDOWINFO_MODEL_TYPE eModel;
	};

	enum SIMULATOR_TYPE{
		SIMULATOR_TYPE_NON = 0x00,
		SIMULATOR_TYPE_BLUESTACKS,
		SIMULATOR_TYPE_KAOPU_JINDAINBAN,
		SIMULATOR_TYPE_KAOPU_JISUBAN,
		SIMULATOR_TYPE_KAOPU_ZUIXINBAN,

		SIMULATOR_TYPE_ALL,
		SIMULATOR_TYPE_INVALID,
	};
	struct SimulatorInfo
	{
		SIMULATOR_TYPE eSimulator;
		char chSimulatorName[40];
		char chDataDir[MAX_PATH];
		char chInstallDir[MAX_PATH];
		char chLogDir[MAX_PATH];
		char chUserDefinedDir[MAX_PATH];
		char chVersion[MAX_PATH];
		char chQuit[MAX_PATH];
		char chRunApp[MAX_PATH];
		char chQuitWinExec[MAX_PATH];
		char chRunAppWinExec[MAX_PATH];
		DWORD dwFullScreen;
		DWORD dwWidth;
		DWORD dwHeight;
		DWORD dwWindowWidth;
		DWORD dwWindowHeight;
	};

	enum RESET_SIMULATOR_TYPE
	{
		RESET_SIMULATOR_NON = 0,
		RESET_SIMULATOR_DOWN,
		RESET_SIMULATOR_CTRL_MINUS,
		RESET_SIMULATOR_CTRL_WHEELDOWN,
		RESET_SIMULATOR_CTRL_LEFTCLICK,

		RESET_SIMULATOR_ALL,
		RESET_SIMULATOR_INVALID = -1,
	};

public:
	CString cstrBindWindowTemp;
	static SettingIF* Instance(void);
	static void Destroy();

	void SetUserName(const char* pchUserName);
	const char* GetUserName() {return m_sStorageInfo.chUserName;}
	void SetPassword(const char* pchPassword);
	const char* GetPassword() {return m_sStorageInfo.chPassword;}
	void SetPasswordStore(bool bPasswordStore);
	bool GetPasswordStore() {return m_sStorageInfo.bPasswordStore;}

	void SetUsingSimulatorType(SIMULATOR_TYPE eUsingSimulator);

	void SetBindWindowInfo(const BindWindowInfo& sBindWindowInfo);
	BindWindowInfo GetBindWindowInfo() {return m_sStorageInfo.sBindWindowInfo;}
	CString GetBindWindowInfoDisplay();
	CString GetBindWindowInfoMouse();
	CString GetBindWindowInfoKeyboard();
	CString GetBindWindowInfoPublic();
	
	struct ResetSimulator
	{
		bool bOK;
		RESET_SIMULATOR_TYPE eResetSimulator;
		long lPriority;
		bool operator < (const ResetSimulator& t1) const{	//升序排列需要重载的操作符
			return this->lPriority < t1.lPriority; 
		}; 
		bool operator > (const ResetSimulator& t1) const{	//降序排列需要重载的操作符
			return this->lPriority > t1.lPriority; 
		}; 
	};
	void SetResetSimulator(RESET_SIMULATOR_TYPE eResetSimulator, const ResetSimulator& sResetSimulator);
	ResetSimulator GetResetSimulator(RESET_SIMULATOR_TYPE eResetSimulator) {return m_sStorageInfo.sResetSimulator[eResetSimulator];}
	void GetResetSimulatorFromPriority(vector<ResetSimulator> *vResetSimulatorPriority);

	void GetSimulatorInfo(vector<SimulatorInfo> *vSimulatorInfo);
	SimulatorInfo GetUsingSimulatorInfo();

	//////////////////////////////////////////////////////////////////////////
	void InitDefaultSetting();

	void ReadSettingFromFile();
	void WriteSettingToFile();
	
protected:
private:
	SettingIF();
	~SettingIF();
	void InitializeSimulatorInfo();
	SimulatorInfo InitSimulatorInfo(SIMULATOR_TYPE eSimulatorType, CString cstrName, CString cstrQuit, CString cstrRunApp, CString cstrKeyPath);
private:
	struct StorageInfo
	{
		char chUserName[33];
		char chPassword[33];
		bool bPasswordStore;
		SIMULATOR_TYPE eUsingSimulator;
		BindWindowInfo sBindWindowInfo;
		ResetSimulator sResetSimulator[RESET_SIMULATOR_ALL];
	};
	static SettingIF* s_pcInstance;

	StorageInfo m_sStorageInfo;
	
	vector<SimulatorInfo> m_vSimulatorInfo;
	CIniFile* m_pIniFile;
};
#endif // CXX_SETTINGIF_H
/* EOF */