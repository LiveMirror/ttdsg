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

#ifndef AIDPLUGEYLOGIN_H
#define AIDPLUGEYLOGIN_H
#pragma warning (disable:4927)
 
#include "CEyLoginSoft.h"

#ifndef CXX_AIDPLUGLOGIN_H
#include "AidPlugLogin.h"
#endif

class AidPlugEYLogin : public AidPlugLogin
{
public:
	AidPlugEYLogin();
	~AidPlugEYLogin();
	virtual AIDPLUG_TYPE C_GetAidPlugType();

	virtual CString C_UserRegister(LPCTSTR userName, LPCTSTR userPwd, LPCTSTR userEmail);
	virtual long C_UserLogin(LPCTSTR userName, LPCTSTR userPwd, CString& cstrRet);
	virtual CString C_UpdatePwd(PCTSTR userName, LPCTSTR userOldPwd, LPCTSTR userNewPwd, LPCTSTR userEmail);
	virtual CString C_GetStaticValue();	//服务器重要静态数据
	virtual CString C_CardReCharge(LPCTSTR uName, LPCTSTR cardPwd, LPCTSTR usert);
	virtual long C_CheckUserStatus(CString& cstrRet);
	virtual CString C_GetExpired(PCTSTR userName);

private:
	IEyLoginSoft* InitNewDll();

	// Attributes
public:

	// Operations
public:


	// IEyLoginSoft methods
public:
	CString Ver()
	{
		return m_pCEyLoginSoft->Ver();
	}
	void SetAppKey(LPCTSTR appKey)
	{
		m_pCEyLoginSoft->SetAppKey(appKey);
	}
	long GetLastError()
	{
		return m_pCEyLoginSoft->GetLastError();
	}
	CString GetLastMessages()
	{
		return m_pCEyLoginSoft->GetLastMessages();
	}
	CString GetLatestVersion()
	{
		return m_pCEyLoginSoft->GetLatestVersion();
	}
	CString GetLatestVersionName()
	{
		return m_pCEyLoginSoft->GetLatestVersionName();
	}
	CString GetCurrentVersionName()
	{
		return m_pCEyLoginSoft->GetCurrentVersionName();
	}
	CString GetAppCode()
	{
		return m_pCEyLoginSoft->GetAppCode();
	}
	CString GetVersionCode()
	{
		return m_pCEyLoginSoft->GetVersionCode();
	}
	CString GetBulletin()
	{
		return m_pCEyLoginSoft->GetBulletin();
	}
	CString GetUserExpired()
	{
		return m_pCEyLoginSoft->GetUserExpired();
	}
	long UserLogin(LPCTSTR userName, LPCTSTR userPwd, LPCTSTR appVer, LPCTSTR userMac)
	{
		return m_pCEyLoginSoft->UserLogin(userName, userPwd, appVer, userMac);
	}
	long UserRegin(LPCTSTR userName, LPCTSTR userPwd, LPCTSTR userEmail, LPCTSTR userMac)
	{
		return m_pCEyLoginSoft->UserRegin(userName, userPwd, userEmail, userMac);
	}
	long UserRecharge(LPCTSTR userName, LPCTSTR cardPwd)
	{
		return m_pCEyLoginSoft->UserRecharge(userName, cardPwd);
	}
	long UpdatePwd(LPCTSTR userName, LPCTSTR userEmail)
	{
		return m_pCEyLoginSoft->UpdatePwd(userName, userEmail);
	}
	CString GetExpired(LPCTSTR userName)
	{
		return m_pCEyLoginSoft->GetExpired(userName);
	}
	long CheckUserStatus()
	{
		return m_pCEyLoginSoft->CheckUserStatus();
	}
	long CheckAppVersion(LPCTSTR aVer)
	{
		return m_pCEyLoginSoft->CheckAppVersion(aVer);
	}
	long UpdateUserExpiredDT(LPCTSTR userName, LPCTSTR userExpiredDT, LPCTSTR interfaceKey)
	{
		return m_pCEyLoginSoft->UpdateUserExpiredDT(userName, userExpiredDT, interfaceKey);
	}
	long UserLoginSingle(LPCTSTR userCode, LPCTSTR aVer, LPCTSTR userMac)
	{
		return m_pCEyLoginSoft->UserLoginSingle(userCode, aVer, userMac);
	}
	long CheckUserStatusSingle()
	{
		return m_pCEyLoginSoft->CheckUserStatusSingle();
	}
	long ConversionbindingMAC(LPCTSTR userCode, LPCTSTR newMAC)
	{
		return m_pCEyLoginSoft->ConversionbindingMAC(userCode, newMAC);
	}
	long ConversionbindingIP(LPCTSTR userCode)
	{
		return m_pCEyLoginSoft->ConversionbindingIP(userCode);
	}
	long SingleRecharge(LPCTSTR userCode, LPCTSTR rechargeCard)
	{
		return m_pCEyLoginSoft->SingleRecharge(userCode, rechargeCard);
	}
	long UserConversionbindingMAC(LPCTSTR userName, LPCTSTR userPwd, LPCTSTR newMAC)
	{
		return m_pCEyLoginSoft->UserConversionbindingMAC(userName, userPwd, newMAC);
	}
	long LogOut()
	{
		return m_pCEyLoginSoft->LogOut();
	}
	long OpenUserCheck()
	{
		return m_pCEyLoginSoft->OpenUserCheck();
	}
	long CloseUserCheck()
	{
		return m_pCEyLoginSoft->CloseUserCheck();
	}
	CString GetMACAddress()
	{
		return m_pCEyLoginSoft->GetMACAddress();
	}
	CString GetCpuID()
	{
		return m_pCEyLoginSoft->GetCpuID();
	}
	void SetUserCheckInterval(long interval)
	{
		m_pCEyLoginSoft->SetUserCheckInterval(interval);
	}
	CString GetDiskSerial()
	{
		return m_pCEyLoginSoft->GetDiskSerial();
	}
	CString GetMachineCode()
	{
		return m_pCEyLoginSoft->GetMachineCode();
	}
	void SetMainFormHwnd(long hwnd)
	{
		m_pCEyLoginSoft->SetMainFormHwnd(hwnd);
	}
	CString GetNetTime()
	{
		return m_pCEyLoginSoft->GetNetTime();
	}
	long UserAddDays(LPCTSTR userName, long days, LPCTSTR interfaceKey)
	{
		return m_pCEyLoginSoft->UserAddDays(userName, days, interfaceKey);
	}
	CString GetAppCodeRT()
	{
		return m_pCEyLoginSoft->GetAppCodeRT();
	}
	CString GetBulletinRT()
	{
		return m_pCEyLoginSoft->GetBulletinRT();
	}
	CString GetOnlineStatus()
	{
		return m_pCEyLoginSoft->GetOnlineStatus();
	}
	long OpenUserCheckShowMessage(long times)
	{
		return m_pCEyLoginSoft->OpenUserCheckShowMessage(times);
	}
	CString GetVariable(__int64 id, LPCTSTR key)
	{
		return m_pCEyLoginSoft->GetVariable(id, key);
	}
	long RechargeEx(LPCTSTR uName, LPCTSTR cardPwd, LPCTSTR usert)
	{
		return m_pCEyLoginSoft->RechargeEx(uName, cardPwd, usert);
	}
	long RechargeSingleEx(LPCTSTR uName, LPCTSTR cardPwd, LPCTSTR usert)
	{
		return m_pCEyLoginSoft->RechargeSingleEx(uName, cardPwd, usert);
	}
	CString GetUserData()
	{
		return m_pCEyLoginSoft->GetUserData();
	}
	void SetUserData(LPCTSTR uData)
	{
		m_pCEyLoginSoft->SetUserData(uData);
	}
	CString GenerateSpreadID()
	{
		return m_pCEyLoginSoft->GenerateSpreadID();
	}
	void AutoUpdate(LPCTSTR Ver)
	{
		m_pCEyLoginSoft->AutoUpdate(Ver);
	}
	void SetPath(LPCTSTR path)
	{
		m_pCEyLoginSoft->SetPath(path);
	}
	long SingleExpireAddDays(LPCTSTR userCode, long days, LPCTSTR interfaceKey)
	{
		return m_pCEyLoginSoft->SingleExpireAddDays(userCode, days, interfaceKey);
	}
	long GetOnlineCount(LPCTSTR userName, LPCTSTR userPwd)
	{
		return m_pCEyLoginSoft->GetOnlineCount(userName, userPwd);
	}
	long CleanUserStates(LPCTSTR userName, LPCTSTR userPwd)
	{
		return m_pCEyLoginSoft->CleanUserStates(userName, userPwd);
	}
	// IEyLoginSoft properties
public:

//////////////////////////////////////////////////////////////////////////
public:
protected:
private:
	static CString AID_PLUG_VERSION;
	IEyLoginSoft* m_pCEyLoginSoft;
};
#endif // AIDPLUGEYLOGIN_H
/* EOF */
