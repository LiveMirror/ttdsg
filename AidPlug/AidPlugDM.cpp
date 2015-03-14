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

#ifndef CXX_AIDPLUGDM_H
#include "AidPlugDM.h"
#endif

#ifndef AIDPLUGLOGINIF_H
#include "AidPlugLoginIF.h"
#endif

CString AidPlugDM::AID_PLUG_VERSION = _T("5.1423");

AidPlugDM::AidPlugDM():
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

	//ע��
	CString cstrRegKey = AidPlugLoginIF::Instance()->API_GetStaticValue();		//�շѰ�
	if (0x00 == cstrRegKey.GetLength()) {
		CString cstrMsg;
		cstrMsg.Format(_T("���������������ظ�������л�������븨����֧�֣�"));
		MessageBox(NULL,cstrMsg,"�Ƿ�ʹ��",MB_OK);
		PostMessage(AfxGetApp()->GetMainWnd()->GetSafeHwnd(),WM_QUIT,0,0);
		return;
	}

	long ret = Reg(cstrRegKey,_T(""));
	if (0x01 != ret) {
		ret = RegEx(cstrRegKey,_T(""),_T("122.10.92.197|122.10.93.166|42.51.15.137|98.126.127.97"));
	}

	/*
	vector<CString> vRegKey;
	split(cstrRegKey, _T("|"), vRegKey);
	long ret = 0x00;
	for (int iCnt=0x00; iCnt<(int)vRegKey.size(); iCnt++) {
		ret = Reg(vRegKey[iCnt],_T(""));
		if (1 != ret) {
			ret = RegEx(vRegKey[iCnt],_T(""),_T("122.10.92.197|122.10.93.166|42.51.15.137|98.126.127.97"));
		}
		if (1 == ret) {
			break;
		}
	}
	*/

	if (1 != ret) {
		CString cstrMsg;
		cstrMsg.Format(_T("���ע��ʧ�ܣ�����ֵ��:%d"),ret);
		MessageBox(NULL,cstrMsg,_T("�ش����"),MB_OK);
		PostMessage(AfxGetApp()->GetMainWnd()->GetSafeHwnd(),WM_QUIT,0,0);
		return;
	}
}

AidPlugDM::~AidPlugDM()
{
	if (NULL != m_pIdmsoft){
		delete m_pIdmsoft;
		m_pIdmsoft = NULL;
	}
}

Idmsoft* 
AidPlugDM::InitNewDll()
{
	Idmsoft* pDll = NULL;
	//COleVariant temp1,temp2;
	bool m_bInit = false;	

	//����ֱ�Ӽ���dll�������󣬱������ע���ļ�
	typedef HRESULT (__stdcall * pfnGCO) (REFCLSID, REFIID, void**); 
	pfnGCO fnGCO = NULL; 
	HINSTANCE hdllInst = LoadLibrary(_T("AidPlug.dll")); 
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
