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

#ifndef AIDPLUGLOGINIF_H
#define AIDPLUGLOGINIF_H

#ifndef CXX_AIDPLUGLOGIN_H
#include "AidPlugLogin.h"
#endif

class AidPlugLoginIF
{
public:
	static AidPlugLoginIF* Instance(void);
	static void Destroy();

	virtual AidPlugLogin::AIDPLUG_TYPE API_GetAidPlugType()
	{
		return m_pPlugLogin->C_GetAidPlugType();
	}

	virtual CString API_UserRegister(LPCTSTR userName, LPCTSTR userPwd, LPCTSTR userEmail)
	{
		return m_pPlugLogin->C_UserRegister(userName, userPwd, userEmail);
	}
	virtual long API_UserLogin(LPCTSTR userName, LPCTSTR userPwd, CString& cstrRet)
	{
		return m_pPlugLogin->C_UserLogin(userName, userPwd, cstrRet);
	}
	virtual CString API_UpdatePwd(PCTSTR userName, LPCTSTR userOldPwd, LPCTSTR userNewPwd, LPCTSTR userEmail)
	{
		return m_pPlugLogin->C_UpdatePwd(userName, userOldPwd, userNewPwd, userEmail);
	}
	virtual CString API_GetStaticValue()
	{
		return m_pPlugLogin->C_GetStaticValue();
	}
	virtual CString API_CardReCharge(LPCTSTR uName, LPCTSTR cardPwd, LPCTSTR usert)
	{
		return m_pPlugLogin->C_CardReCharge(uName, cardPwd, usert);
	}
	virtual long API_CheckUserStatus(CString& cstrRet)
	{
		return m_pPlugLogin->C_CheckUserStatus(cstrRet);
	}
	virtual CString API_GetExpired(PCTSTR userName)
	{
		return m_pPlugLogin->C_GetExpired(userName);
	}

private:
	AidPlugLoginIF();
	~AidPlugLoginIF();

	// IEyLoginSoft properties
public:
	__forceinline bool API_AntiCrack() {
		static long lTickCountStart = GetTickCount();
		static long lCheckCount = 0x00;
		lCheckCount++;
		if (GetTickCount()-lTickCountStart<= 30*60*1000 && 0x00 != lCheckCount%1800) {
			//三十分钟验证一次+随机验证
			return true;
		}
		lTickCountStart = GetTickCount();
		CString cstrFormat;
		long lRandom = 0x00;
//		long lRandom = random(24);
		cstrFormat.Format(_T("AntiCrack%ld"), lRandom);
		long lTickCount = GetTickCount();
//xiaoting 		while (CSTRING_ANTICRACK[lRandom]!=GetVariable(lRandom+537, cstrFormat)) {
// 			if(GetTickCount() - lTickCount >= 30*60*1000) {
// 				//半小时验证不了，非法使用
// 				CString cstrMsg;
// 				cstrMsg.Format(_T("请在正规渠道下载辅助，感谢您对梦想辅助的支持！"));
// 				MessageBox(NULL,cstrMsg,"非法使用",MB_OK);
// 				return false;
// 			}
// 		}
		return true;
	}

//////////////////////////////////////////////////////////////////////////
public:
protected:
private:
	static AidPlugLoginIF* s_pcInstance;
	static const CString CSTRING_ANTICRACK[24];
	AidPlugLogin* m_pPlugLogin;
};
#endif // AIDPLUGLOGINIF_H
/* EOF */
