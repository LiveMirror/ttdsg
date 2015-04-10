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

#ifndef AIDPLUGPLOGIN_H
#define AIDPLUGPLOGIN_H

#include "pljd.h"

#ifndef CXX_AIDPLUGLOGIN_H
#include "AidPlugLogin.h"
#endif

class AidPlugPLogin : public AidPlugLogin
{
public:
	AidPlugPLogin();
	~AidPlugPLogin();
	virtual AIDPLUG_TYPE C_GetAidPlugType();

	virtual CString C_UserRegister(LPCTSTR userName, LPCTSTR userPwd, LPCTSTR userEmail);
	virtual long C_UserLogin(LPCTSTR userName, LPCTSTR userPwd, CString& cstrRet);
	virtual CString C_UpdatePwd(PCTSTR userName, LPCTSTR userOldPwd, LPCTSTR userNewPwd, LPCTSTR userEmail);
	virtual CString C_GetStaticValue();	//服务器重要静态数据
	virtual CString C_CardReCharge(LPCTSTR uName, LPCTSTR cardPwd, LPCTSTR usert);
	virtual long C_CheckUserStatus(CString& cstrRet);
	virtual CString C_GetExpired(PCTSTR userName);

//////////////////////////////////////////////////////////////////////////
public:
protected:
private:
	static CString AID_PLUG_VERSION;
};
#endif // AIDPLUGPLOGIN_H
/* EOF */
