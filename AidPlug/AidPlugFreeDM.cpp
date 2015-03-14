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

CString AidPlugFreeDM::AID_PLUG_VERSION = _T("3.1233");

AidPlugFreeDM::AidPlugFreeDM():
m_pIdmsoft(NULL)
{
	m_pIdmsoft = InitNewDll();
	if (NULL == m_pIdmsoft) {
		CString cstrMsg;
		cstrMsg.Format("�������ʧ�ܣ�����ϵ��������");
		MessageBox(NULL,cstrMsg,"�ش����",MB_OK);
		PostMessage(AfxGetApp()->GetMainWnd()->GetSafeHwnd(),WM_QUIT,0,0);
		return;
	}
	/*
	if (AID_PLUG_LOGIN_VERSION != m_pIdmsoft->Ver()) {
		//����汾��ƥ�� ��ע�᷽ʽ���ÿ���
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

Idmsoft* 
AidPlugFreeDM::InitNewDll()
{
	Idmsoft* pDll = NULL;
	//COleVariant temp1,temp2;
	bool m_bInit = false;	

	//����ֱ�Ӽ���dll�������󣬱������ע���ļ�
	typedef HRESULT (__stdcall * pfnGCO) (REFCLSID, REFIID, void**); 
	pfnGCO fnGCO = NULL; 
	HINSTANCE hdllInst = LoadLibrary(_T("AidPlugFree.dll")); 
	fnGCO = (pfnGCO)GetProcAddress(hdllInst, _T("DllGetClassObject")); 
	if (fnGCO != 0) 
	{ 
		IClassFactory* pcf = NULL; 
		HRESULT hr=(fnGCO)(__uuidof(dmsoft), IID_IClassFactory, (void**)&pcf); 
		if (SUCCEEDED(hr) && (pcf != NULL)) 
		{ 
			hr = pcf->CreateInstance(NULL, __uuidof(Idmsoft), (void**)&pDll); 
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
