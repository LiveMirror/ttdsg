// BindWindowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ttdsg.h"
#include "BindWindowDlg.h"
#include "BindWindowDxDlg.h"

#ifndef CXX_SETTINGIF_H
#include "SettingIF.h"
#endif

// BindWindowDlg dialog

IMPLEMENT_DYNAMIC(BindWindowDlg, CDialog)

BindWindowDlg::BindWindowDlg(CWnd* pParent /*=NULL*/)
	: CDialog(BindWindowDlg::IDD, pParent)
{

}

BindWindowDlg::~BindWindowDlg()
{
}

void BindWindowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BindWindowDlg, CDialog)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDWINDOW_NORMAL, &BindWindowDlg::OnBnClickedRadioHighinfoBindwindow)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDWINDOW_GDI, &BindWindowDlg::OnBnClickedRadioHighinfoBindwindow)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDWINDOW_GDI2, &BindWindowDlg::OnBnClickedRadioHighinfoBindwindow)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDWINDOW_DX2, &BindWindowDlg::OnBnClickedRadioHighinfoBindwindow)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDWINDOW_DX3, &BindWindowDlg::OnBnClickedRadioHighinfoBindwindow)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDWINDOW_DX, &BindWindowDlg::OnBnClickedRadioHighinfoBindwindow)
	
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDMOUSE_NORMAL, &BindWindowDlg::OnBnClickedRadioHighinfoBindmouse)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDMOUSE_WINDOWS, &BindWindowDlg::OnBnClickedRadioHighinfoBindmouse)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDMOUSE_WINDOWS3, &BindWindowDlg::OnBnClickedRadioHighinfoBindmouse)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDMOUSE_DX, &BindWindowDlg::OnBnClickedRadioHighinfoBindmouse)

	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDKEYBOARD_NORMAL, &BindWindowDlg::OnBnClickedRadioHighinfoBindkeyboard)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDKEYBOARD_WINDOWS, &BindWindowDlg::OnBnClickedRadioHighinfoBindkeyboard)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDKEYBOARD_DX, &BindWindowDlg::OnBnClickedRadioHighinfoBindkeyboard)

	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_BINDPUBIC_DX, &BindWindowDlg::OnBnClickedCheckHighinfoBindpubicDx)

	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDMODEL_0, &BindWindowDlg::OnBnClickedRadioHighinfoBindmodel)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDMODEL_1, &BindWindowDlg::OnBnClickedRadioHighinfoBindmodel)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDMODEL_2, &BindWindowDlg::OnBnClickedRadioHighinfoBindmodel)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDMODEL_3, &BindWindowDlg::OnBnClickedRadioHighinfoBindmodel)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDMODEL_4, &BindWindowDlg::OnBnClickedRadioHighinfoBindmodel)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDMODEL_5, &BindWindowDlg::OnBnClickedRadioHighinfoBindmodel)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDMODEL_6, &BindWindowDlg::OnBnClickedRadioHighinfoBindmodel)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDMODEL_7, &BindWindowDlg::OnBnClickedRadioHighinfoBindmodel)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDMODEL_101, &BindWindowDlg::OnBnClickedRadioHighinfoBindmodel)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDMODEL_103, &BindWindowDlg::OnBnClickedRadioHighinfoBindmodel)
	ON_BN_CLICKED(IDC_RADIO_BINDWINDOW_BINDMODEL_AUTO, &BindWindowDlg::OnBnClickedRadioHighinfoBindmodel)
END_MESSAGE_MAP()


// BindWindowDlg message handlers

void BindWindowDlg::OnBnClickedRadioHighinfoBindwindow()
{
	// TODO: Add your control notification handler code here
	SettingIF::BINDWINDOWINFO_DISPLAY_TYPE eBindWindowDisplay = SettingIF::BINDWINDOWINFO_DISPLAY_NON;
	CButton* pCButtonRadio = NULL;
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDWINDOW_NORMAL);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindWindowDisplay = SettingIF::BINDWINDOWINFO_DISPLAY_NORMAL;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDWINDOW_GDI);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindWindowDisplay = SettingIF::BINDWINDOWINFO_DISPLAY_GDI;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDWINDOW_GDI2);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindWindowDisplay = SettingIF::BINDWINDOWINFO_DISPLAY_GDI2;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDWINDOW_DX3);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindWindowDisplay = SettingIF::BINDWINDOWINFO_DISPLAY_DX3;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDWINDOW_DX2);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindWindowDisplay = SettingIF::BINDWINDOWINFO_DISPLAY_DX2;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDWINDOW_DX);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindWindowDisplay = SettingIF::BINDWINDOWINFO_DISPLAY_DX;
	}

	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	sBindWindowInfo.eDisplay = eBindWindowDisplay;
	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);

	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDWINDOW_DX);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		//Set Dx
		BindWindowDxDlg cBindWindowDxDlg;
		cBindWindowDxDlg.SetBindWindow(BindWindowDxDlg::BINDWINDOWINFO_DISPLAY);
		cBindWindowDxDlg.DoModal();
	}
}

void BindWindowDlg::OnBnClickedRadioHighinfoBindmouse()
{
	// TODO: Add your control notification handler code here
	SettingIF::BINDWINDOWINFO_MOUSE_TYPE eBindMouse = SettingIF::BINDWINDOWINFO_MOUSE_NON;
	CButton* pCButtonRadio = NULL;
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMOUSE_NORMAL);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindMouse = SettingIF::BINDWINDOWINFO_MOUSE_NORMAL;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMOUSE_WINDOWS);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindMouse = SettingIF::BINDWINDOWINFO_MOUSE_WINDOWS;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMOUSE_WINDOWS3);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindMouse = SettingIF::BINDWINDOWINFO_MOUSE_WINDOWS3;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMOUSE_DX);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindMouse = SettingIF::BINDWINDOWINFO_MOUSE_DX;
	}

	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	sBindWindowInfo.eMouse = eBindMouse;
	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);

	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMOUSE_DX);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		//Set Dx
		BindWindowDxDlg cBindWindowDxDlg;
		cBindWindowDxDlg.SetBindWindow(BindWindowDxDlg::BINDWINDOWINFO_MOUSE);
		cBindWindowDxDlg.DoModal();
	}
}

void BindWindowDlg::OnBnClickedRadioHighinfoBindkeyboard()
{
	// TODO: Add your control notification handler code here
	SettingIF::BINDWINDOWINFO_KEYBOARD_TYPE eBindKeyboard = SettingIF::BINDWINDOWINFO_KEYBOARD_NON;
	CButton* pCButtonRadio = NULL;
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDKEYBOARD_NORMAL);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindKeyboard = SettingIF::BINDWINDOWINFO_KEYBOARD_NORMAL;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDKEYBOARD_WINDOWS);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindKeyboard = SettingIF::BINDWINDOWINFO_KEYBOARD_WINDOWS;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDKEYBOARD_DX);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindKeyboard = SettingIF::BINDWINDOWINFO_KEYBOARD_DX;
	}
	
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	sBindWindowInfo.eKeyboard = eBindKeyboard;
	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);

	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDKEYBOARD_DX);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		//Set Dx
		BindWindowDxDlg cBindWindowDxDlg;
		cBindWindowDxDlg.SetBindWindow(BindWindowDxDlg::BINDWINDOWINFO_KEYBOARD);
		cBindWindowDxDlg.DoModal();
	}
}

void BindWindowDlg::OnBnClickedCheckHighinfoBindpubicDx()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_BINDPUBIC_DX);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	sBindWindowInfo.bPublic = BST_CHECKED==pCButtonCheck->GetCheck()?true:false;

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
	if (BST_CHECKED == pCButtonCheck->GetCheck()) {
		BindWindowDxDlg cBindWindowDxDlg;
		cBindWindowDxDlg.SetBindWindow(BindWindowDxDlg::BINDWINDOWINFO_PUBLIC);
		cBindWindowDxDlg.DoModal();
	}
}

void BindWindowDlg::OnBnClickedRadioHighinfoBindmodel()
{
	// TODO: Add your control notification handler code here
	SettingIF::BINDWINDOWINFO_MODEL_TYPE eBindModel = SettingIF::BINDWINDOWINFO_MODEL_0;
	CButton* pCButtonRadio = NULL;
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_0);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindModel = SettingIF::BINDWINDOWINFO_MODEL_0;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_1);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindModel = SettingIF::BINDWINDOWINFO_MODEL_1;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_2);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindModel = SettingIF::BINDWINDOWINFO_MODEL_2;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_3);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindModel = SettingIF::BINDWINDOWINFO_MODEL_3;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_4);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindModel = SettingIF::BINDWINDOWINFO_MODEL_4;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_5);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindModel = SettingIF::BINDWINDOWINFO_MODEL_5;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_6);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindModel = SettingIF::BINDWINDOWINFO_MODEL_6;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_7);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindModel = SettingIF::BINDWINDOWINFO_MODEL_7;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_101);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindModel = SettingIF::BINDWINDOWINFO_MODEL_101;
	}
	pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_103);
	if (BST_CHECKED == pCButtonRadio->GetCheck()) {
		eBindModel = SettingIF::BINDWINDOWINFO_MODEL_103;
	}

	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	sBindWindowInfo.eModel = eBindModel;
	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);

}

BOOL BindWindowDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	UpdateCtrl();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void 
BindWindowDlg::UpdateCtrl()
{
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	CButton* pCButtonRadio = NULL;
	//Display
	switch(sBindWindowInfo.eDisplay) {
		case SettingIF::BINDWINDOWINFO_DISPLAY_NORMAL:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDWINDOW_NORMAL);
			break;
		case SettingIF::BINDWINDOWINFO_DISPLAY_GDI:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDWINDOW_GDI);
			break;
		case SettingIF::BINDWINDOWINFO_DISPLAY_GDI2:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDWINDOW_GDI2);
			break;
		case SettingIF::BINDWINDOWINFO_DISPLAY_DX3:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDWINDOW_DX3);
			break;
		case SettingIF::BINDWINDOWINFO_DISPLAY_DX2:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDWINDOW_DX2);
			break;
		case SettingIF::BINDWINDOWINFO_DISPLAY_DX:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDWINDOW_DX);
			break;
		default:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDWINDOW_NORMAL);
			break;
	}
	pCButtonRadio->SetCheck(BST_CHECKED);

	//Mouse
	pCButtonRadio = NULL;
	switch(sBindWindowInfo.eMouse) {
		case SettingIF::BINDWINDOWINFO_MOUSE_NORMAL:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMOUSE_NORMAL);
			break;
		case SettingIF::BINDWINDOWINFO_MOUSE_WINDOWS:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMOUSE_WINDOWS);
			break;
		case SettingIF::BINDWINDOWINFO_MOUSE_WINDOWS3:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMOUSE_WINDOWS3);
			break;
		case SettingIF::BINDWINDOWINFO_MOUSE_DX:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMOUSE_DX);
			break;
		default:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMOUSE_NORMAL);
			break;
	}
	pCButtonRadio->SetCheck(BST_CHECKED);

	//Keyboard
	pCButtonRadio = NULL;
	switch(sBindWindowInfo.eKeyboard) {
		case SettingIF::BINDWINDOWINFO_KEYBOARD_NORMAL:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDKEYBOARD_NORMAL);
			break;
		case SettingIF::BINDWINDOWINFO_KEYBOARD_WINDOWS:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDKEYBOARD_WINDOWS);
			break;
		case SettingIF::BINDWINDOWINFO_KEYBOARD_DX:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDKEYBOARD_DX);
			break;
		default:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDKEYBOARD_NORMAL);
			break;
	}
	pCButtonRadio->SetCheck(BST_CHECKED);

	//Public
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_BINDPUBIC_DX);
	pCButtonCheck->SetCheck(sBindWindowInfo.bPublic);

	//Model
	pCButtonRadio = NULL;
	switch(sBindWindowInfo.eModel) {
		case SettingIF::BINDWINDOWINFO_MODEL_0:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_0);
			break;
		case SettingIF::BINDWINDOWINFO_MODEL_1:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_1);
			break;
		case SettingIF::BINDWINDOWINFO_MODEL_2:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_2);
			break;
		case SettingIF::BINDWINDOWINFO_MODEL_3:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_3);
			break;
		case SettingIF::BINDWINDOWINFO_MODEL_4:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_4);
			break;
		case SettingIF::BINDWINDOWINFO_MODEL_5:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_5);
			break;
		case SettingIF::BINDWINDOWINFO_MODEL_6:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_6);
			break;
		case SettingIF::BINDWINDOWINFO_MODEL_7:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_7);
			break;
		case SettingIF::BINDWINDOWINFO_MODEL_101:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_101);
			break;
		case SettingIF::BINDWINDOWINFO_MODEL_103:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_103);
			break;
		case SettingIF::BINDWINDOWINFO_MODEL_AUTO:
			pCButtonRadio = (CButton*)GetDlgItem(IDC_RADIO_BINDWINDOW_BINDMODEL_AUTO);
			break;
		default:
			break;
	}
	pCButtonRadio->SetCheck(BST_CHECKED);
}


BOOL 
BindWindowDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message==WM_KEYDOWN && (pMsg->wParam==VK_ESCAPE || pMsg->wParam==VK_RETURN)) return TRUE;
	else
		return CDialog::PreTranslateMessage(pMsg);
}

