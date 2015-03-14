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

#ifndef CXX_AIDPLUGDM_H
#include "AidPlugDM.h"
#endif

#ifndef CXX_AIDPLUGFREEDM_H
#include "AidPlugFreeDM.h"
#endif

#ifndef CXX_AIDPLUGIDENTIFYIF_H
#include "AidPlugIdentifyIF.h"
#endif

#ifndef AIDPLUGLOGINIF_H
#include "AidPlugLoginIF.h"
#endif

#ifndef CXX_SETTINGIF_H
#include "SettingIF.h"
#endif

#ifndef CXX_COMMONFUNCTION_H
#include "CommonFuncion.h"
#endif

AidPlugIdentifyIF* AidPlugIdentifyIF::s_pcInstance =  NULL;
const CString AidPlugIdentifyIF::CSTRING_PASSWORD = _T("!@#3CxtTtdsg");
const CString AidPlugIdentifyIF::CSTRING_CAPTURE_FOLDER = _T("��ͼ");

void
AidPlugIdentifyIF::Destroy(void)
{
	if (NULL != s_pcInstance) {
		delete s_pcInstance;
		s_pcInstance = NULL;
	}
}

long 
AidPlugIdentifyIF::API_FindWindow()
{
	SettingIF::SimulatorInfo sSimulatorInfo = SettingIF::Instance()->GetUsingSimulatorInfo();
	switch (sSimulatorInfo.eSimulator) {
		case SettingIF::SIMULATOR_TYPE_BLUESTACKS:
			m_hwnd = FindWindowByProcess(_T("HD-Frontend.exe"), _T(""), _T("BlueStacks App Player"));
			break;
		case SettingIF::SIMULATOR_TYPE_KAOPU_JINDAINBAN:
			break;
		case SettingIF::SIMULATOR_TYPE_KAOPU_JISUBAN:
			m_hwnd = FindWindowByProcess(_T("TianTianPlayer.exe"), _T(""), _T("Powered by TianTian"));
			break;
		case SettingIF::SIMULATOR_TYPE_KAOPU_ZUIXINBAN:
			m_hwnd = FindWindowByProcess(_T("NK-Frontend.exe"), _T(""), _T("Powered by BlueStacks"));
			break;
		default:
			CString cstrMsg;
			cstrMsg.Format("����û������ģ������");
			MessageBox(NULL,cstrMsg,"����",MB_OK);
			break;
	}
	return m_hwnd;
}

long 
AidPlugIdentifyIF::API_BindWindow()
{
	if (0 == API_FindWindow()) {
		return 0;
	}
	//�����
	SetWindowState(1);
	long lBindWindow = 0x00;
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	CString cstrDisplay = SettingIF::Instance()->GetBindWindowInfoDisplay();
	CString cstrMouse = SettingIF::Instance()->GetBindWindowInfoMouse();
	CString cstrKeyboard = SettingIF::Instance()->GetBindWindowInfoKeyboard();
	CString cstrPublic = SettingIF::Instance()->GetBindWindowInfoPublic();
	if (SettingIF::BINDWINDOWINFO_MODEL_AUTO != sBindWindowInfo.eModel) {
		lBindWindow = BindWindowEx(cstrDisplay, cstrMouse, cstrKeyboard, cstrPublic, sBindWindowInfo.eModel); 
	}
	else {
		lBindWindow = BindWindowEx(cstrDisplay, cstrMouse, cstrKeyboard, cstrPublic, SettingIF::BINDWINDOWINFO_MODEL_0);
		if (0x00 == lBindWindow) {
			lBindWindow = BindWindowEx(cstrDisplay, cstrMouse, cstrKeyboard, cstrPublic, SettingIF::BINDWINDOWINFO_MODEL_1);
		}
		if (0x00 == lBindWindow) {
			lBindWindow = BindWindowEx(cstrDisplay, cstrMouse, cstrKeyboard, cstrPublic, SettingIF::BINDWINDOWINFO_MODEL_2);
		}
		if (0x00 == lBindWindow) {
			lBindWindow = BindWindowEx(cstrDisplay, cstrMouse, cstrKeyboard, cstrPublic, SettingIF::BINDWINDOWINFO_MODEL_3);
		}
		if (0x00 == lBindWindow) {
			lBindWindow = BindWindowEx(cstrDisplay, cstrMouse, cstrKeyboard, cstrPublic, SettingIF::BINDWINDOWINFO_MODEL_4);
		}
		if (0x00 == lBindWindow) {
			lBindWindow = BindWindowEx(cstrDisplay, cstrMouse, cstrKeyboard, cstrPublic, SettingIF::BINDWINDOWINFO_MODEL_5);
		}
		if (0x00 == lBindWindow) {
			lBindWindow = BindWindowEx(cstrDisplay, cstrMouse, cstrKeyboard, cstrPublic, SettingIF::BINDWINDOWINFO_MODEL_6);
		}
		if (0x00 == lBindWindow) {
			lBindWindow = BindWindowEx(cstrDisplay, cstrMouse, cstrKeyboard, cstrPublic, SettingIF::BINDWINDOWINFO_MODEL_7);
		}
		if (0x00 == lBindWindow) {
			lBindWindow = BindWindowEx(cstrDisplay, cstrMouse, cstrKeyboard, cstrPublic, SettingIF::BINDWINDOWINFO_MODEL_101);
		}
		if (0x00 == lBindWindow) {
			lBindWindow = BindWindowEx(cstrDisplay, cstrMouse, cstrKeyboard, cstrPublic, SettingIF::BINDWINDOWINFO_MODEL_103);
		}
	}

	if (0x00 == lBindWindow) {
		CString cstrMsg;
		cstrMsg.Format("����󶨴���ʧ�ܣ�����ֵ��:%d", GetLastError());
		MessageBox(NULL,cstrMsg,"�ش����",MB_OK);
		return lBindWindow;
	}
	//���ش���
	SetWindowState(6);
	return lBindWindow;
}

long 
AidPlugIdentifyIF::API_BindWindowNormal()
{
	if (0 == API_FindWindow()) {
		return 0;
	}

	AidPlugIdentifyIF::Instance()->SetWindowState(1);	//1 : ����ָ������
	long lBindWindow = BindWindowEx("normal", "normal", "normal","",0);
	if (0x00 == lBindWindow) {
		lBindWindow = BindWindowEx("normal", "normal", "normal","",2);
	}
	if (0x00 == lBindWindow) {
		CString cstrMsg;
		cstrMsg.Format("����󶨴���ʧ�ܣ�����ֵ��:%d", GetLastError());
		MessageBox(NULL,cstrMsg,"�ش����",MB_OK);
		return 0;
	}
	return 1;
}

long 
AidPlugIdentifyIF::API_LeftClick(long x, long y, long lSleep)
{
	if (0x00 != MoveTo(x, y)) {
		LONG lRet = LeftClick();
		Sleep(lSleep);
		return lRet;
	}
	return 0x00;
}

long 
AidPlugIdentifyIF::API_CapturePreFromTime(CString strFolderPath)
{
	CString cstrTime = CTime::GetCurrentTime().Format("%Y%m%d%H%M%S"); //��ȡϵͳʱ��
	//�ж�·���Ƿ����   
	strFolderPath = CSTRING_CAPTURE_FOLDER + _T("\\") + strFolderPath;
	if(!PathIsDirectory(strFolderPath)) {   
		CreateDirectory((strFolderPath), NULL);
	} 
	CString cstrFileName = strFolderPath + _T("\\") + cstrTime + _T(".bmp");
	long lret = CapturePre(cstrFileName);		//��ͼ����������ᵼ�µ��ʧ��
	return lret;
}

long 
AidPlugIdentifyIF::API_CaptureFromTime(long x1, long y1, long x2, long y2, CString strFolderPath)
{
	CString cstrTime = CTime::GetCurrentTime().Format("%Y%m%d%H%M%S"); //��ȡϵͳʱ��
	//�ж�·���Ƿ����   
	strFolderPath = CSTRING_CAPTURE_FOLDER + _T("\\") + strFolderPath;
	if(!PathIsDirectory(strFolderPath)) {   
		CreateDirectory((strFolderPath), NULL);
	} 
	CString cstrFileName = strFolderPath + _T("\\") + cstrTime + _T(".bmp");
	long lret = Capture(x1, y1, x2, y2, cstrFileName);		//��ͼ����������ᵼ�µ��ʧ��
	return lret;
}

AidPlugIdentifyIF::WidthHeight 
AidPlugIdentifyIF::API_GetPicSize(LPCTSTR pic_name)
{
	WidthHeight sWidthHeight = {0x00};
	CString cstrRet = GetPicSize(pic_name);
	if (0x00 == cstrRet.GetLength()) {
		return sWidthHeight;
	}
	vector<string> strDest;
//	CommonFuncion::split(LPCSTR(cstrRet), _T(","), strDest);
	sWidthHeight.lWidth = atoi(strDest[0].c_str());
	sWidthHeight.lHeight = atoi(strDest[1].c_str());
	return sWidthHeight;
}

vector<AidPlugIdentifyIF::Coordinate>
AidPlugIdentifyIF::API_FindMultiPic(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir)
{
	vector<CString> strDest;
//	CommonFuncion::split(pic_name, _T("||"), strDest);
	AidPlugIdentifyIF::WidthHeight sMaxWidthHeight = {0x00};
	AidPlugIdentifyIF::WidthHeight sMinWidthHeight = {10000, 10000};
	AidPlugIdentifyIF::WidthHeight sWidthHeight = {0x00};
	for (int i=0x00; i<(int)strDest.size(); i++) {
		sWidthHeight = API_GetPicSize(strDest[i]);
		if (sMaxWidthHeight.lWidth < sWidthHeight.lWidth) {
			sMaxWidthHeight.lWidth = sWidthHeight.lWidth;
		}
		if (sMaxWidthHeight.lHeight < sWidthHeight.lHeight) {
			sMaxWidthHeight.lHeight = sWidthHeight.lHeight;
		}
		if (sMinWidthHeight.lWidth > sWidthHeight.lWidth) {
			sMinWidthHeight.lWidth = sWidthHeight.lWidth;
		}
		if (sMinWidthHeight.lHeight > sWidthHeight.lHeight) {
			sMinWidthHeight.lHeight = sWidthHeight.lHeight;
		}
	}
	
 	vector<Coordinate> vCoord;
	API_FindMultiPicRecursion(x1, y1, x2, y2, pic_name, delta_color, sim, dir, sMaxWidthHeight, &vCoord);
	
	//�ݴ�����ͼƬ��С��һ ���ܻ����ظ��������
	vector<Coordinate> vCoordFix;
	bool bSamePoint = false;
	for (int iCnt=0x00; iCnt<(int)vCoord.size(); iCnt++) {
		bSamePoint = false;
		for (int jCnt=0x00; jCnt<(int)vCoordFix.size(); jCnt++) {
			if (abs(vCoord[iCnt].lx-vCoordFix[jCnt].lx)<sMinWidthHeight.lWidth 
				&& abs(vCoord[iCnt].ly-vCoordFix[jCnt].ly)<sMinWidthHeight.lHeight) {
				bSamePoint = true;
			}
		}
		if (false == bSamePoint) {
			vCoordFix.push_back(vCoord[iCnt]);
		}
	}
	return vCoordFix;
}

vector<AidPlugIdentifyIF::Coordinate> 
AidPlugIdentifyIF::API_FindMultiPicBlur(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir,  long lFindType)
{
	vector<Coordinate> vCoord;
	API_FindMultiPicBlurRecursion(x1, y1, x2, y2, pic_name, delta_color, sim, dir, lFindType, &vCoord);
	return vCoord;
}

AidPlugIdentifyIF::AIDPLUG_TYPE 
AidPlugIdentifyIF::API_GetAidPlugType()
{
	//����ʵ���������ѡ��
	return AIDPLUG_FREE_DM;
}

void 
AidPlugIdentifyIF::API_FindMultiPicRecursion(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir, WidthHeight sMaxWidthHeight, vector<Coordinate>* vCoord)
{
	Coordinate sCoord = {0x00};
	CString cstrPic = FindPicS(x1, y1, x2, y2, pic_name, delta_color, sim, dir, &sCoord.lx, &sCoord.ly);
	if (0x00 != cstrPic.GetLength()) {
		//�ҵ�ͼƬ
		vCoord->push_back(sCoord);
		AidPlugIdentifyIF::WidthHeight sWidthHeight = API_GetPicSize(cstrPic);
		//���ҵ�ǰͼƬ���ڵ�����
		long x1Min, y1Min, x2Min, y2Min;
		long x1Max, y1Max, x2Max, y2Max;
		x1Min = sCoord.lx+1;
		y1Min = sCoord.ly+1;
		x2Min = sCoord.lx+sWidthHeight.lWidth-1;
		y2Min = sCoord.ly+sWidthHeight.lHeight-1;

		x1Max = sCoord.lx-(sMaxWidthHeight.lWidth-sWidthHeight.lWidth);
		y1Max = sCoord.ly-(sMaxWidthHeight.lHeight-sWidthHeight.lHeight);
		x2Max = sCoord.lx+sMaxWidthHeight.lWidth;
		y2Max = sCoord.ly+sMaxWidthHeight.lHeight;
		
		//�Ե�ǰͼƬΪ�ο��з��ĸ������������
		if (x2Max>x1 && y2Min>y1) {
			//����
			API_FindMultiPicRecursion(x1, y1, x2Max, y2Min, pic_name, delta_color, sim, dir, sMaxWidthHeight, vCoord);
		}
		if (x2>x1Min && y2Max>y1) {
			//����
			API_FindMultiPicRecursion(x1Min, y1, x2, y2Max, pic_name, delta_color, sim, dir, sMaxWidthHeight, vCoord);
		}
		if (x2>x1Max && y2>y1Min) {
			//����
			API_FindMultiPicRecursion(x1Max, y1Min, x2, y2, pic_name, delta_color, sim, dir, sMaxWidthHeight, vCoord);
		}
		if (x2Min>x1 && y2>y1Max) {
			//����
			API_FindMultiPicRecursion(x1, y1Max, x2Min, y2, pic_name, delta_color, sim, dir, sMaxWidthHeight, vCoord);
		}
		
	}
}

void 
AidPlugIdentifyIF::API_FindMultiPicBlurRecursion(long x1, long y1, long x2, long y2, LPCTSTR pic_name, LPCTSTR delta_color, double sim, long dir, long lFindType, vector<Coordinate>* vCoord)
{
	Coordinate sCoord = {0x00};
	long x1Find, y1Find, x2Find, y2Find;
	CString cstrPic = FindPicS(x1, y1, x2, y2, pic_name, delta_color, sim, dir, &sCoord.lx, &sCoord.ly);
	if (0x00 != cstrPic.GetLength()) {
		//�ҵ�ͼƬ
		vCoord->push_back(sCoord);
		AidPlugIdentifyIF::WidthHeight sWidthHeight = API_GetPicSize(cstrPic);
		if (0x00 == lFindType) {
			x1Find = sCoord.lx + sWidthHeight.lWidth/2;
			y1Find = sCoord.ly + sWidthHeight.lHeight/2;
			x2Find = sCoord.lx + sWidthHeight.lWidth/2;
			y2Find = sCoord.ly + sWidthHeight.lHeight/2;
		}
		else if (0x01 == lFindType) {
			x1Find = sCoord.lx;
			y1Find = sCoord.ly;
			x2Find = sCoord.lx + sWidthHeight.lWidth;
			y2Find = sCoord.ly + sWidthHeight.lHeight;
		}
		else {
			;
		}
		if (x1Find>x1 && y1Find>y1) {
			//����
			API_FindMultiPicBlurRecursion(x1, y1, x1Find, y1Find, pic_name, delta_color, sim, dir, lFindType, vCoord);
		}
		if (x2>x2Find && y1Find>y1) {
			//����
			API_FindMultiPicBlurRecursion(x2Find, y1, x2, y1Find, pic_name, delta_color, sim, dir, lFindType, vCoord);
		}
		if (x2>x2Find && y2>y2Find) {
			//����
			API_FindMultiPicBlurRecursion(x2Find, y2Find, x2, y2, pic_name, delta_color, sim, dir, lFindType, vCoord);
		}
		if (x1Find>x1 && y2>y2Find) {
			//����
			API_FindMultiPicBlurRecursion(x1, y2Find, x1Find, y2, pic_name, delta_color, sim, dir, lFindType, vCoord);
		}
	}
}

AidPlugIdentifyIF::AidPlugIdentifyIF():
m_pPlugIdentify(NULL),
m_hwnd(0x00)
{
	AIDPLUG_TYPE eAidPlugType = API_GetAidPlugType();
	switch (eAidPlugType) {
		case AIDPLUG_PAY_DM:
			m_pPlugIdentify = new AidPlugDM;
			break;
		case AIDPLUG_FREE_DM:
		default:
			m_pPlugIdentify = new AidPlugFreeDM;
			break;
	}
	InitResource();
}

AidPlugIdentifyIF::~AidPlugIdentifyIF()
{
	if (NULL != m_pPlugIdentify) {
		delete m_pPlugIdentify;
		m_pPlugIdentify = NULL;
	}
}

void 
AidPlugIdentifyIF::InitResource()
{
	//������Դ����
	SetPicPwd(CSTRING_PASSWORD);
	SetDictPwd(CSTRING_PASSWORD);

	//�����ֵ�

	//����
	SetKeypadDelay(_T("dx.public.active.api|dx.public.active.message|dx.keypad.state.api|dx.keypad.api|dx.keypad.input.lock.api|dx.keypad.raw.input"), 100);
	SetMouseDelay(_T("dx.public.active.api|dx.public.active.message|dx.keypad.state.api|dx.keypad.api|dx.keypad.input.lock.api|dx.keypad.raw.input"), 50);
// 	EnableRealKeypad(1);
// 	EnableRealMouse(2,50,100);
	SetShowErrorMsg(0);	//�����Ƿ񵯳�������Ϣ

	//��ʼ����ͼ�ļ���
	if(!PathIsDirectory(CSTRING_CAPTURE_FOLDER)) {   
		CreateDirectory(CSTRING_CAPTURE_FOLDER, NULL);
	}
	
	//ϵͳ
	//��Դ����
// 	if (0 == DisablePowerSave()) {
// 		MessageBox(NULL,_T("ǿ�ƹرյ�ǰϵͳ�رյ�Դ����(��ֹ����˯��)ʧ�ܣ����ֶ��رգ�"),_T("��ܰ��ʾ"),MB_OK);
// 	}

	//�رյ�ǰϵͳƽ������		������ᵼ�������ѿ�����ʱ������
// 	if (1 == CheckFontSmooth()) {
// 		if(IDYES==MessageBox(NULL,_T("��ǰϵͳ�п���ƽ�����壡�������رյ�ǰϵͳƽ������,������Ч��"),_T("��ܰ��ʾ"),MB_YESNO)) {
// 			//TODO:Here add your codes.
// 			if (1 == DisableFontSmooth()) {
// 				ExitOs(2);		//��������
// 			}
// 			else {
// 				MessageBox(NULL,_T("�رյ�ǰϵͳƽ������ʧ�ܣ����ֶ��رգ�"),_T("��ܰ��ʾ"),MB_OK);
// 			}
// 		}
// 	}
}


short 
AidPlugIdentifyIF::vartoi(const _variant_t& var) 
{ 
	short value = 0; 
	switch (var.vt) 
	{ 
	case VT_BOOL: 
		value = var.boolVal; 
		break; 
	case VT_UI1: 
	case VT_I1: 
		value = var.bVal; 
		break; 
	case VT_I2: 
	case VT_UI2: 
		value = var.iVal; 
		break; 
	case VT_NULL: 
	case VT_EMPTY: 
		value = 0; 
		break; 
	default: 
		TRACE(_T("Warning: δ����� _variant_t ����ֵ; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__); 
	} 
	return value; 
} 

long 
AidPlugIdentifyIF::vartol(const _variant_t& var) 
{ 
	long value = 0; 
	switch (var.vt) 
	{ 
	case VT_BOOL: 
		value = var.boolVal; 
		break; 
	case VT_UI1: 
	case VT_I1: 
		value = var.bVal; 
		break; 
	case VT_UI2: 
	case VT_I2: 
		value = var.iVal; 
		break; 
	case VT_I4: 
	case VT_UI4: 
		value = var.lVal; 
		break; 
	case VT_INT: 
		value = var.intVal; 
		break; 
	case VT_R4: 
		value = (long)(var.fltVal + 0.5); 
		break; 
	case VT_R8: 
		value = (long)(var.dblVal + 0.5); 
		break; 
	case VT_DECIMAL: 
		value = (long)var; 
		break; 
	case VT_CY: 
		value = (long)var; 
		break; 
	case VT_BSTR://�ַ��� 
	case VT_LPSTR://�ַ��� 
	case VT_LPWSTR://�ַ��� 
		value = atol((LPCTSTR)(_bstr_t)var); 
		break; 
	case VT_NULL: 
	case VT_EMPTY: 
		value = 0; 
		break; 
	default: 
		TRACE(_T("Warning: δ����� _variant_t ����ֵ; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__); 
	} 
	return value; 
} 

double 
AidPlugIdentifyIF::vartof(const _variant_t& var) 
{ 
	double value = 0; 
	switch (var.vt) 
	{ 
	case VT_R4: 
		value = var.fltVal; 
		break; 
	case VT_R8: 
		value = var.dblVal; 
		break; 
	case VT_DECIMAL: 
		value = (double)var; 
		break; 
	case VT_CY: 
		value = (double)var; 
		break; 
	case VT_BOOL: 
		value = var.boolVal; 
		break; 
	case VT_UI1: 
	case VT_I1: 
		value = var.bVal; 
		break; 
	case VT_UI2: 
	case VT_I2: 
		value = var.iVal; 
		break; 
	case VT_UI4: 
	case VT_I4: 
		value = var.lVal; 
		break; 
	case VT_INT: 
		value = var.intVal; 
		break; 
	case VT_BSTR://�ַ��� 
	case VT_LPSTR://�ַ��� 
	case VT_LPWSTR://�ַ��� 
		value = atof((LPCTSTR)(_bstr_t)var); 
		break; 
	case VT_NULL: 
	case VT_EMPTY: 
		value = 0; 
		break; 
	default: 
		value = 0; 
		TRACE(_T("Warning: δ����� _variant_t ����ֵ; �ļ�: %s; ��: %d\n"), __FILE__, __LINE__); 
	} 
	return value; 
}
CString 
AidPlugIdentifyIF::vartocstring(_variant_t var)
{
	CString strValue;
	_variant_t var_t;
	_bstr_t bstr_t;
	time_t cur_time;
	CTime time_value;
	COleCurrency var_currency;
	switch(var.vt) {
		case VT_EMPTY:
		case VT_NULL:strValue=_T("");break;
		case VT_UI1:strValue.Format("%d",var.bVal);break;
		case VT_I2:strValue.Format("%d",var.iVal);break;
		case VT_I4:strValue.Format("%d",var.lVal);break;
		case VT_R4:strValue.Format("%f",var.fltVal);break;
		case VT_R8:strValue.Format("%f",var.dblVal);break;
		case VT_CY:
			var_currency=var;
			strValue=var_currency.Format(0);break;
		case VT_BSTR:
			var_t =var;
			bstr_t=var_t;
			strValue.Format("%s",(const char *)bstr_t);break;
		case VT_DATE:
			cur_time=(time_t)var.date;
			time_value=cur_time;
			strValue.Format("%A,%B,%d,%Y");break;
		case VT_BOOL:strValue.Format("%d",var.boolVal);break;
		default:strValue=_T("");break;
	}
	return strValue;
}
/* EOF */
