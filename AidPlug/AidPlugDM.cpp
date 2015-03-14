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

	//注册
	CString cstrRegKey = AidPlugLoginIF::Instance()->API_GetStaticValue();		//收费版
	if (0x00 == cstrRegKey.GetLength()) {
		CString cstrMsg;
		cstrMsg.Format(_T("请在正规渠道下载辅助，感谢您对梦想辅助的支持！"));
		MessageBox(NULL,cstrMsg,"非法使用",MB_OK);
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
		cstrMsg.Format(_T("插件注册失败！返回值是:%d"),ret);
		MessageBox(NULL,cstrMsg,_T("重大错误"),MB_OK);
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

	//下面直接加载dll创建对象，避免进行注册文件
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
