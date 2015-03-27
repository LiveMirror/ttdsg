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
#include "stdafx.h"

#ifndef AIDPLUGEYLOGIN_H
#include "AidPlugPiaoLogin.h"
#endif

CString AidPlugPiaoLogin::AID_PLUG_VERSION = _T("1.0.2.4");

AidPlugPiaoLogin::AidPlugPiaoLogin()
{
	//飘零金盾初始化开始
	PLJD_DllMain(GetModuleHandle(NULL) , DLL_PROCESS_ATTACH , NULL);
	if (0x00 == P_LoadSystem(80,0,"arvinmxfz2014",
		"1A417FCBFDDA177945EA9468F229C5652C718344878CD32B0973F55EE08E5DB9229AC42CDB11F17BA39BE10CF54E59AC1E1968C17F9535E4D8AF099763985BDC",
		"BD0937E3C57235DF50F992E7E484789970B406E4AF4976FB055D49A7437E8724","1+3+4+",1)) {
		//初始化失败
		CString cstrMsg;
		cstrMsg.Format("登陆插件初始化失败！请查看您的网络是否通畅");
		MessageBox(NULL,cstrMsg,"重大错误",MB_OK);
	}
	//飘零金盾初始化结束
}

AidPlugPiaoLogin::~AidPlugPiaoLogin()
{
}

AidPlugPiaoLogin::AIDPLUG_TYPE 
AidPlugPiaoLogin::C_GetAidPlugType()
{
	return AidPlugPiaoLogin::AIDPLUG_PIAO;
}

CString 
AidPlugPiaoLogin::C_UserRegister(LPCTSTR userName, LPCTSTR userPwd, LPCTSTR userEmail)
{
	//飘零验证会过滤关键字
	CString cstErrRegisterInfo = P_UserReg((char*)userName, (char*)userPwd, _T(""), _T(""), _T(""));
	if (0x00 == cstErrRegisterInfo.Compare("Error,信息不完整.")) {
		//"exec|select|drop|alter|exists|union|and|or|xor|order|mid|asc|execute|xp_cmdshell|insert|update|delete|join|declare|char|sp_oacreate|wscript.shell|xp_regwrite|'|;|--"
		cstErrRegisterInfo += "\r\n请确认是含有以下关键字：\r\nexec|select|drop|alter|exists|union|and|or|xor|order|mid|asc|execute|xp_cmdshell|insert|update|delete|join|declare|char|sp_oacreate|wscript.shell|xp_regwrite|'|;|--";
	}
	return cstErrRegisterInfo;
}

long 
AidPlugPiaoLogin::C_UserLogin(LPCTSTR userName, LPCTSTR userPwd, CString& cstrRet)
{
	long lRet = P_UserLogin((char*)userName, (char*)userPwd); 
	if (0x01 == lRet) {
		cstrRet.Format(_T("用户登陆成功！%s"), (LPSTR)(LPCSTR)P_GetLoginIn());
	}
	else {
		cstrRet.Format(_T("用户登陆失败！%s"), (LPSTR)(LPCSTR)P_GetLoginIn());
	}
	return lRet;
}

CString 
AidPlugPiaoLogin::C_UpdatePwd(PCTSTR userName, LPCTSTR userOldPwd, LPCTSTR userNewPwd, LPCTSTR userEmail)
{
	return P_ChangePwd((char*)userName, (char*)userOldPwd, (char*)userNewPwd);
}

CString 
AidPlugPiaoLogin::C_GetStaticValue()
{
	return P_GetStaticValue(_T("datakeycoc2014"));
}

CString 
AidPlugPiaoLogin::C_CardReCharge(LPCTSTR uName, LPCTSTR cardPwd, LPCTSTR usert)
{
	return P_CardReCharge((char*)uName, (char*)cardPwd, (char*)usert);
}

long 
AidPlugPiaoLogin::C_CheckUserStatus(CString& cstrRet)
{
	long lRet = P_Checktime();
	if (0x08 == lRet) {
		cstrRet.Format(_T("检测用户状态成功！"));
		lRet = 1;
	}
	else {
		//返回1 帐号被锁定 
		//返回2 帐号过期  
		//返回3 内部错误  
		//返回4 帐号已在别处登录,被迫下线  
		//返回5 服务器已停止运营
		switch (lRet) {
			case 1:
				cstrRet.Format(_T("帐号被锁定"));
				lRet = -998;
				break;
			case 2:
				cstrRet.Format(_T("帐号过期"));
				break;
			case 3:
				cstrRet.Format(_T("内部错误"));
				break;
			case 4:
				cstrRet.Format(_T("帐号已在别处登录,被迫下线"));
				lRet = -999;
				break;
			case 5:
				cstrRet.Format(_T("服务器已停止运营"));
				break;
		}
	}
	return lRet;
}

CString 
AidPlugPiaoLogin::C_GetExpired(PCTSTR userName)
{
	return P_GetExpireTime((char*)userName);
}
/* EOF */
