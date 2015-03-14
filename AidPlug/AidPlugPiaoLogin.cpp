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
	//Ʈ���ܳ�ʼ����ʼ
	PLJD_DllMain(GetModuleHandle(NULL) , DLL_PROCESS_ATTACH , NULL);
	if (0x00 == P_LoadSystem(80,0,"arvinmxfz2014",
		"1A417FCBFDDA177945EA9468F229C5652C718344878CD32B0973F55EE08E5DB9229AC42CDB11F17BA39BE10CF54E59AC1E1968C17F9535E4D8AF099763985BDC",
		"12F6C6875EEE623CE1584B09EF9D901BEE7E1C0C9F595F4E13B9958430A16844","1+3+4+",1)) {
		//��ʼ��ʧ��
		CString cstrMsg;
		cstrMsg.Format("��½�����ʼ��ʧ�ܣ���鿴���������Ƿ�ͨ��");
		MessageBox(NULL,cstrMsg,"�ش����",MB_OK);
	}
	//Ʈ���ܳ�ʼ������
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
	return P_UserReg((char*)userName, (char*)userPwd, _T(""), _T(""), _T(""));
}

long 
AidPlugPiaoLogin::C_UserLogin(LPCTSTR userName, LPCTSTR userPwd, CString& cstrRet)
{
	long lRet = P_UserLogin((char*)userName, (char*)userPwd); 
	if (0x01 == lRet) {
		cstrRet.Format(_T("�û���½�ɹ���%s"), (LPSTR)(LPCSTR)P_GetLoginIn());
	}
	else {
		cstrRet.Format(_T("�û���½ʧ�ܣ�%s"), (LPSTR)(LPCSTR)P_GetLoginIn());
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
		cstrRet.Format(_T("����û�״̬�ɹ���"));
		lRet = 1;
	}
	else {
		//����1 �ʺű����� 
		//����2 �ʺŹ���  
		//����3 �ڲ�����  
		//����4 �ʺ����ڱ𴦵�¼,��������  
		//����5 ��������ֹͣ��Ӫ
		switch (lRet) {
			case 1:
				cstrRet.Format(_T("�ʺű�����"));
				lRet = -998;
				break;
			case 2:
				cstrRet.Format(_T("�ʺŹ���"));
				break;
			case 3:
				cstrRet.Format(_T("�ڲ�����"));
				break;
			case 4:
				cstrRet.Format(_T("�ʺ����ڱ𴦵�¼,��������"));
				lRet = -999;
				break;
			case 5:
				cstrRet.Format(_T("��������ֹͣ��Ӫ"));
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
