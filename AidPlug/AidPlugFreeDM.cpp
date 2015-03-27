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
#include<vector>
using namespace std;

#ifndef CXX_AIDPLUGFREEDM_H
#include "AidPlugFreeDM.h"
#endif

#ifndef AIDPLUGLOGINIF_H
#include "AidPlugLoginIF.h"
#endif

CString AidPlugFreeDM::AID_PLUG_DLL = _T("AidPlug.dll");
CString AidPlugFreeDM::AID_PLUG_VERSION = _T("3.1233");

AidPlugFreeDM::AidPlugFreeDM():
m_pIdmsoft(NULL)
{
	m_pIdmsoft = InitNewDll(AID_PLUG_DLL);
	if (NULL == m_pIdmsoft) {
		CString cstrMsg;
		cstrMsg.Format("插件创建失败！请联系开发作者");
		MessageBox(NULL,cstrMsg,"重大错误",MB_OK);
		PostMessage(AfxGetApp()->GetMainWnd()->GetSafeHwnd(),WM_QUIT,0,0);
		return;
	}
	/*
	if (AID_PLUG_LOGIN_VERSION != m_pIdmsoft->Ver()) {
		//插件版本不匹配 免注册方式不用考虑
	}
	*/
}

AidPlugFreeDM::~AidPlugFreeDM()
{
	if (NULL != m_pIdmsoft){
		delete m_pIdmsoft;
		m_pIdmsoft = NULL;
	}
}
/* EOF */
