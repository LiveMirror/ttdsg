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

#ifndef CXX_SIMULATORSETTINGIF_H
#define CXX_SIMULATORSETTINGIF_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef INIFILE_H
#include "inifile.h"
#endif

class SimulatorSettingIF
{
public:
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
	static SimulatorSettingIF* Instance(void);
	static void Destroy();

	void SetUsingSimulatorType(SIMULATOR_TYPE eUsingSimulator);
	SIMULATOR_TYPE GetUsingSimulatorType() {return m_sStorageInfo.eUsingSimulator;};
	
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
	void SetResetSimulator(const ResetSimulator& sResetSimulator);
	ResetSimulator GetResetSimulator(RESET_SIMULATOR_TYPE eResetSimulator) {return m_sStorageInfo.sResetSimulator[eResetSimulator];}
	void GetResetSimulatorFromPriority(vector<ResetSimulator> *vResetSimulatorPriority);

	void GetSimulatorInfo(vector<SimulatorInfo> *vSimulatorInfo);
	SimulatorInfo GetUsingSimulatorInfo();

	//////////////////////////////////////////////////////////////////////////
	void InitDefaultSetting();

	bool ReadSettingFromFile();
	void WriteSettingToFile();
	
protected:
private:
	SimulatorSettingIF();
	~SimulatorSettingIF();
	void InitializeSimulatorInfo();
	SimulatorInfo InitSimulatorInfo(SIMULATOR_TYPE eSimulatorType, CString cstrName, CString cstrQuit, CString cstrRunApp, CString cstrKeyPath);
private:
	struct StorageInfo
	{
		SIMULATOR_TYPE eUsingSimulator;
		ResetSimulator sResetSimulator[RESET_SIMULATOR_ALL];
	};

	static SimulatorSettingIF* s_pcInstance;
	StorageInfo m_sStorageInfo;
	vector<SimulatorInfo> m_vSimulatorInfo;
	CIniFile* m_pIniFile;
};
#endif // CXX_SIMULATORSETTINGIF_H
/* EOF */