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
#include "AidPlugEYLogin.h"
#endif

CString AidPlugEYLogin::AID_PLUG_VERSION = _T("1.0.2.4");

AidPlugEYLogin::AidPlugEYLogin():
m_pCEyLoginSoft(NULL)
{
	m_pCEyLoginSoft = InitNewDll();
	if (NULL == m_pCEyLoginSoft) {
		CString cstrMsg;
		cstrMsg.Format("登陆插件创建失败！请联系开发作者");
		MessageBox(NULL,cstrMsg,"重大错误",MB_OK);
	}
	/*
	if (AID_PLUG_VERSION != m_pCEyLoginSoft->Ver()) {
		//插件版本不匹配 免注册方式不用考虑
	}
	*/
	
#ifdef  COCASSIST_FOR_FREE
	m_pCEyLoginSoft->SetAppKey("A4728B9DB5D9456D86E51A6262F28922");	//免费版
#else
	m_pCEyLoginSoft->SetAppKey("958A57FB39FA4C0287C1907D4F51984C");	//收费版
#endif
	
}

AidPlugEYLogin::~AidPlugEYLogin()
{
	if (NULL != m_pCEyLoginSoft) {
		delete m_pCEyLoginSoft;
		m_pCEyLoginSoft = NULL;
	}
}

AidPlugEYLogin::AIDPLUG_TYPE 
AidPlugEYLogin::C_GetAidPlugType()
{
	return AidPlugEYLogin::AIDPLUG_EY;
}

CString 
AidPlugEYLogin::C_UserRegister(LPCTSTR userName, LPCTSTR userPwd, LPCTSTR userEmail)
{
	CString cstrRet;
	if (0x01 == m_pCEyLoginSoft->UserRegin(userName, userPwd, userEmail, _T(""))) {
		cstrRet.Format(_T("用户注册成功！\r\n用户名：%s\r\n注册邮箱：%s"), userName, userEmail);
	}
	else {
		cstrRet.Format(_T("错误提示：%s\r\n错误代码：%ld"), (LPSTR)(LPCSTR)m_pCEyLoginSoft->GetLastMessages(), m_pCEyLoginSoft->GetLastError());
	}
	return cstrRet;
}

long 
AidPlugEYLogin::C_UserLogin(LPCTSTR userName, LPCTSTR userPwd, CString& cstrRet)
{
	long lRet = m_pCEyLoginSoft->UserLogin(userName, userPwd, _T("1.090000"), m_pCEyLoginSoft->GetMACAddress()); 
	if (0x01 == lRet) {
		cstrRet.Format(_T("用户登陆成功！"));
	}
	else {
		cstrRet.Format(_T("错误提示：%s\r\n错误代码：%ld"), (LPSTR)(LPCSTR)m_pCEyLoginSoft->GetLastMessages(), m_pCEyLoginSoft->GetLastError());
	}
	return lRet;
}

CString 
AidPlugEYLogin::C_UpdatePwd(PCTSTR userName, LPCTSTR userOldPwd, LPCTSTR userNewPwd, LPCTSTR userEmail)
{
	CString cstrRet;
	if (0x01 == m_pCEyLoginSoft->UpdatePwd(userName, userEmail)) {
		cstrRet.Format(_T("已发送修改密码相关的邮件至邮箱，请注意查收！"));
	}
	else {
		cstrRet.Format(_T("错误提示：%s\r\n错误代码：%ld"), (LPSTR)(LPCSTR)m_pCEyLoginSoft->GetLastMessages(), m_pCEyLoginSoft->GetLastError());
	}
	return cstrRet;
}

CString 
AidPlugEYLogin::C_GetStaticValue()
{
	return m_pCEyLoginSoft->GetAppCodeRT();
}

CString 
AidPlugEYLogin::C_CardReCharge(LPCTSTR uName, LPCTSTR cardPwd, LPCTSTR usert)
{
	CString cstrRet;
	if (0X01 == m_pCEyLoginSoft->RechargeEx(uName, cardPwd, usert)) {
		cstrRet.Format(_T("冲值提示：%s"), (LPSTR)(LPCSTR)m_pCEyLoginSoft->GetLastMessages());
	}
	else {
		cstrRet.Format(_T("错误提示：%s\r\n错误代码：%ld"), (LPSTR)(LPCSTR)m_pCEyLoginSoft->GetLastMessages(), m_pCEyLoginSoft->GetLastError());
	}
	return cstrRet;
}

long 
AidPlugEYLogin::C_CheckUserStatus(CString& cstrRet)
{
	long lRet = m_pCEyLoginSoft->CheckUserStatus();
	if (0x01 == lRet) {
		cstrRet.Format(_T("检测用户状态成功！"));
	}
	else {
		cstrRet.Format(_T("错误提示：%s\r\n错误代码：%ld"), (LPSTR)(LPCSTR)m_pCEyLoginSoft->GetLastMessages(), m_pCEyLoginSoft->GetLastError());
		if (-112 == m_pCEyLoginSoft->GetLastError()) {
			//帐号已在别处登录
			lRet = -999;
		}
	}
	return lRet;
}

CString 
AidPlugEYLogin::C_GetExpired(PCTSTR userName)
{
	return m_pCEyLoginSoft->GetExpired(userName);
}


IEyLoginSoft*
AidPlugEYLogin::InitNewDll()
{
	IEyLoginSoft* pDll = NULL;
	//COleVariant temp1,temp2;
	bool m_bInit = false;	

	//下面直接加载dll创建对象，避免进行注册文件
	typedef HRESULT (__stdcall * pfnGCO) (REFCLSID, REFIID, void**); 
	pfnGCO fnGCO = NULL; 
	HINSTANCE hdllInst = LoadLibrary(_T("AidPlugLogin.dll")); 
	fnGCO = (pfnGCO)GetProcAddress(hdllInst, _T("DllGetClassObject")); 
	if (fnGCO != 0) 
	{ 
		IClassFactory* pcf = NULL; 
		HRESULT hr=(fnGCO)(__uuidof(EyLoginSoft), IID_IClassFactory, (void**)&pcf); 
		if (SUCCEEDED(hr) && (pcf != NULL)) 
		{ 
			hr = pcf->CreateInstance(NULL, __uuidof(IEyLoginSoft), (void**)&pDll); 
			if ((SUCCEEDED(hr) && (pDll != NULL))==FALSE) {
				delete pDll;
				pDll = NULL;
			}
		} 
		if (NULL != pcf) {
			pcf->Release(); 
		}
	} 
	return pDll;
}
/* EOF */
