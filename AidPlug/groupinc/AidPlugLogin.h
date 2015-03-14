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

#ifndef CXX_AIDPLUGLOGIN_H
#define CXX_AIDPLUGLOGIN_H

#include "Cdmsoft.h"

class AidPlugLogin
{
public:
	enum AIDPLUG_TYPE {
		AIDPLUG_NON = 0x00,
		AIDPLUG_EY,
		AIDPLUG_PIAO,

		AIDPLUG_ALL,
		AIDPLUG_INVALID = -1,
	};
public:
	AidPlugLogin() {};
	virtual ~AidPlugLogin() {};
	virtual AIDPLUG_TYPE C_GetAidPlugType() = 0x00;

	virtual CString C_UserRegister(LPCTSTR userName, LPCTSTR userPwd, LPCTSTR userEmail) = 0x00;
	virtual long C_UserLogin(LPCTSTR userName, LPCTSTR userPwd, CString& cstrRet) = 0x00;
	virtual CString C_UpdatePwd(PCTSTR userName, LPCTSTR userOldPwd, LPCTSTR userNewPwd, LPCTSTR userEmail) = 0x00;
	virtual CString C_GetStaticValue() = 0x00;	//服务器重要静态数据
	virtual CString C_CardReCharge(LPCTSTR uName, LPCTSTR cardPwd, LPCTSTR usert) = 0x00;
	virtual long C_CheckUserStatus(CString& cstrRet) = 0x00;
	virtual CString C_GetExpired(PCTSTR userName) = 0x00;
public:
protected:
private:
};
#endif // CXX_AIDPLUGLOGIN_H
/* EOF */