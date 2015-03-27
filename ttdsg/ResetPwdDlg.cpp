// ResetPwdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ttdsg.h"
#include "ResetPwdDlg.h"

#ifndef AIDPLUGLOGINIF_H
#include "AidPlugLoginIF.h"
#endif

#ifndef CXX_SETTINGIF_H
#include "SettingIF.h"
#endif
// ResetPwdDlg dialog

IMPLEMENT_DYNAMIC(ResetPwdDlg, CDialog)

ResetPwdDlg::ResetPwdDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ResetPwdDlg::IDD, pParent)
{

}

ResetPwdDlg::~ResetPwdDlg()
{
}

void ResetPwdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ResetPwdDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_RESETPWD_OK, &ResetPwdDlg::OnBnClickedButtonUserResetpwdOk)
END_MESSAGE_MAP()

BOOL 
ResetPwdDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) return TRUE;
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) {
		OnBnClickedButtonUserResetpwdOk();
		return TRUE;
	}
	else
		return CDialog::PreTranslateMessage(pMsg);
}

void 
ResetPwdDlg::OnInitCtrl()
{
	AidPlugLogin::AIDPLUG_TYPE eAidPlug = AidPlugLoginIF::Instance()->API_GetAidPlugType();
	switch(eAidPlug) {
		case AidPlugLogin::AIDPLUG_EY:
			GetDlgItem(IDC_STATIC_RESETPWD_EMAIL)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT_RESETPWD_EMAIL)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_BUTTON_RESETPWD_OK)->SetWindowText(_T("发送"));
			break;
		case  AidPlugLogin::AIDPLUG_PIAO:
			GetDlgItem(IDC_STATIC_RESETPWD_OLDPWD)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_STATIC_RESETPWD_NEWPWD)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_STATIC_RESETPWD_NEWPWD1)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT_RESETPWD_OLDPWD)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT_RESETPWD_NEWPWD)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT_RESETPWD_NEWPWD1)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_BUTTON_RESETPWD_OK)->SetWindowText(_T("修改"));
			break;
		default:
			break;
	}
}

// ResetPwdDlg message handlers

void ResetPwdDlg::OnBnClickedButtonUserResetpwdOk()
{
	// TODO: Add your control notification handler code here
	CButton* pCButton = (CButton*)GetDlgItem(IDC_BUTTON_RESETPWD_OK);
	pCButton->EnableWindow(FALSE);

	CString cstrEditUserName;
	CString cstrEditEmail;
	CString cstrEditOldPwd;
	CString cstrEditNewPwd;
	CString cstrEditNewPwd1;
	GetDlgItem(IDC_EDIT_RESETPWD_USERNAME)->GetWindowText(cstrEditUserName);
	if (0x00 == cstrEditUserName.GetLength()) {
		MessageBox(_T("请输入您注册时的用户名！"));
		pCButton->EnableWindow(TRUE);
		return;
	}

	AidPlugLogin::AIDPLUG_TYPE eAidPlug = AidPlugLoginIF::Instance()->API_GetAidPlugType();
	switch(eAidPlug) {
		case AidPlugLogin::AIDPLUG_EY:
			GetDlgItem(IDC_EDIT_RESETPWD_EMAIL)->GetWindowText(cstrEditEmail);
			if (0x00 == cstrEditEmail.GetLength()) {
				MessageBox(_T("请输入您注册时的邮箱！"));
				pCButton->EnableWindow(TRUE);
				return;
			}
			break;
		case  AidPlugLogin::AIDPLUG_PIAO:
			GetDlgItem(IDC_EDIT_RESETPWD_OLDPWD)->GetWindowText(cstrEditOldPwd);
			if (0x00 == cstrEditOldPwd.GetLength()) {
				MessageBox(_T("请输入您的旧密码！"));
				pCButton->EnableWindow(TRUE);
				return;
			}
			GetDlgItem(IDC_EDIT_RESETPWD_NEWPWD)->GetWindowText(cstrEditNewPwd);
			if (0x00 == cstrEditNewPwd.GetLength()) {
				MessageBox(_T("请输入您的新密码！"));
				pCButton->EnableWindow(TRUE);
				return;
			}
			GetDlgItem(IDC_EDIT_RESETPWD_NEWPWD1)->GetWindowText(cstrEditNewPwd1);
			if (0x00 == cstrEditNewPwd1.GetLength()) {
				MessageBox(_T("请再次输入您的新密码！"));
				pCButton->EnableWindow(TRUE);
				return;
			}
			if (cstrEditNewPwd != cstrEditNewPwd1) {
				MessageBox(_T("二次输入密码不匹配！"));
				pCButton->EnableWindow(TRUE);
				return;
			}
			break;
		default:
			break;
	}
	
	MessageBox(AidPlugLoginIF::Instance()->API_UpdatePwd(cstrEditUserName, cstrEditOldPwd, cstrEditNewPwd, cstrEditEmail));
	pCButton->EnableWindow(TRUE);
}

BOOL ResetPwdDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	OnInitCtrl();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
