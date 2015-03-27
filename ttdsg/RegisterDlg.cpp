// RegisterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ttdsg.h"
#include "RegisterDlg.h"

#ifndef CXX_COMMONFUNCTION_H
#include "CommonFuncion.h"
#endif

#ifndef AIDPLUGLOGINIF_H
#include "AidPlugLoginIF.h"
#endif

// RegisterDlg dialog

IMPLEMENT_DYNAMIC(RegisterDlg, CDialog)

RegisterDlg::RegisterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(RegisterDlg::IDD, pParent)
{

}

RegisterDlg::~RegisterDlg()
{
}

void RegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RegisterDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_REGISTER_RESETINFO, &RegisterDlg::OnBnClickedButtonUserRegisterResetinfo)
	ON_BN_CLICKED(IDC_BUTTON_REGISTER_REGISTER, &RegisterDlg::OnBnClickedButtonUserRegisterRegister)
END_MESSAGE_MAP()


// RegisterDlg message handlers

void RegisterDlg::OnBnClickedButtonUserRegisterResetinfo()
{
	// TODO: Add your control notification handler code here
	CEdit* pCEdit = NULL;
	pCEdit = (CEdit*)GetDlgItem(IDC_EDIT_REGISTER_USERNAME);
	if (NULL != pCEdit) {
		pCEdit->SetWindowText( _T(""));
	}
	pCEdit = (CEdit*)GetDlgItem(IDC_EDIT_REGISTER_PASSWORD);
	if (NULL != pCEdit) {
		pCEdit->SetWindowText( _T(""));
	}
	pCEdit = (CEdit*)GetDlgItem(IDC_EDIT_REGISTER_REPASSWORD);
	if (NULL != pCEdit) {
		pCEdit->SetWindowText( _T(""));
	}
	pCEdit = (CEdit*)GetDlgItem(IDC_EDIT_REGISTER_EMAIL);
	if (NULL != pCEdit) {
		pCEdit->SetWindowText( _T(""));
	}
}

void RegisterDlg::OnBnClickedButtonUserRegisterRegister()
{
	// TODO: Add your control notification handler code here
	CButton* pCButton = (CButton*)GetDlgItem(IDC_BUTTON_REGISTER_REGISTER);
	pCButton->SetWindowText(_T("×¢²áÖÐ"));
	pCButton->EnableWindow(false);
	GetDlgItem(IDC_BUTTON_REGISTER_RESETINFO)->EnableWindow(false);

	//¿ªÊ¼×¢²á
	CString cstrEditUserName;
	CString cstrEditPassword;
	CString cstrEditPassword2;
	CString cstrEditEmail;
	GetDlgItem(IDC_EDIT_REGISTER_USERNAME)->GetWindowText(cstrEditUserName);
	GetDlgItem(IDC_EDIT_REGISTER_PASSWORD)->GetWindowText(cstrEditPassword);
	GetDlgItem(IDC_EDIT_REGISTER_REPASSWORD)->GetWindowText(cstrEditPassword2);
	GetDlgItem(IDC_EDIT_REGISTER_EMAIL)->GetWindowText(cstrEditEmail);

	if (0x00 == cstrEditUserName.GetLength()) {
		MessageBox(_T("ÇëÊäÈëÓÃ»§Ãû£¡"));
		pCButton->SetWindowText(_T("×¢²á"));
		pCButton->EnableWindow(true);
		GetDlgItem(IDC_BUTTON_REGISTER_RESETINFO)->EnableWindow(true);
		return;
	}
	if (0x00 == cstrEditPassword.GetLength()) {
		MessageBox(_T("ÇëÊäÈëÃÜÂë£¡"));
		pCButton->SetWindowText(_T("×¢²á"));
		pCButton->EnableWindow(true);
		GetDlgItem(IDC_BUTTON_REGISTER_RESETINFO)->EnableWindow(true);
		return;
	}
	if (cstrEditPassword != cstrEditPassword2) {
		MessageBox(_T("¶þ´ÎÊäÈëÃÜÂë²»Æ¥Åä£¬ÇëÔÙ´ÎÈ·ÈÏ"));
		pCButton->SetWindowText(_T("×¢²á"));
		pCButton->EnableWindow(true);
		GetDlgItem(IDC_BUTTON_REGISTER_RESETINFO)->EnableWindow(true);
		return;
	}
	if (0x00 == cstrEditEmail.GetLength()) {
		MessageBox(_T("ÇëÊäÈëÓÊÏä£¡"));
		pCButton->SetWindowText(_T("×¢²á"));
		pCButton->EnableWindow(true);
		GetDlgItem(IDC_BUTTON_REGISTER_RESETINFO)->EnableWindow(true);
		return;
	}

	pCButton->SetWindowText(_T("×¢²á"));
	pCButton->EnableWindow(true);
	GetDlgItem(IDC_BUTTON_REGISTER_RESETINFO)->EnableWindow(true);
	MessageBox(AidPlugLoginIF::Instance()->API_UserRegister(cstrEditUserName, cstrEditPassword, cstrEditEmail));
}

BOOL RegisterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

BOOL 
RegisterDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) return TRUE;
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) {
		OnBnClickedButtonUserRegisterRegister();
		return TRUE;
	}
	else
		return CDialog::PreTranslateMessage(pMsg);
}