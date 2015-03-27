// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ttdsg.h"
#include "LoginDlg.h"

#include "RegisterDlg.h"
#include "ResetPwdDlg.h"
#include "ReChargeDlg.h"

#ifndef CXX_SETTINGIF_H
#include "SettingIF.h"
#endif

#ifndef AIDPLUGLOGINIF_H
#include "AidPlugLoginIF.h"
#endif

#ifndef CXX_AIDPLUGIDENTIFYIF_H
#include "AidPlugIdentifyIF.h"
#endif

// LoginDlg dialog


IMPLEMENT_DYNAMIC(LoginDlg, CDialog)

LoginDlg::LoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(LoginDlg::IDD, pParent)
{

}

LoginDlg::~LoginDlg()
{
}

void LoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LoginDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN_REGISTER, &LoginDlg::OnBnClickedButtonUserLoginRegister)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN_LOGIN, &LoginDlg::OnBnClickedButtonUserLoginLogin)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_LOGIN_FORGETPWD, &LoginDlg::OnBnClickedButtonUserLoginForgetpwd)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN_RECHARGE, &LoginDlg::OnBnClickedButtonUserLoginRecharge)
END_MESSAGE_MAP()


// LoginDlg message handlers

void LoginDlg::OnBnClickedButtonUserLoginRegister()
{
	// TODO: Add your control notification handler code here
	ShowWindow(SW_HIDE);
	RegisterDlg cUserRegisterDlg;
	cUserRegisterDlg.DoModal();
	ShowWindow(SW_SHOW);
}

void LoginDlg::OnBnClickedButtonUserLoginLogin()
{
	// TODO: Add your control notification handler code here
	CButton* pCButton = NULL;
	pCButton = (CButton*)GetDlgItem(IDC_BUTTON_LOGIN_LOGIN);
	pCButton->SetWindowText(_T("登陆中"));
	pCButton->EnableWindow(FALSE);

	CString cstrEditUserName;
	CString cstrEditPassword;
	GetDlgItem(IDC_EDIT_LOGIN_USERNAME)->GetWindowText(cstrEditUserName);
	GetDlgItem(IDC_EDIT_LOGIN_PASSWORD)->GetWindowText(cstrEditPassword);

	CString cstrLogin;
	if (0x00 == AidPlugLoginIF::Instance()->API_UserLogin(cstrEditUserName, cstrEditPassword, cstrLogin)) {
		//登陆失败
		pCButton->SetWindowText(_T("登陆"));
		pCButton->EnableWindow(TRUE);
		MessageBox(cstrLogin);
		return;
	}

	//登陆成功
	SettingIF::Instance()->SetUserName((LPSTR)(LPCTSTR)cstrEditUserName);
	SettingIF::Instance()->SetPassword((LPSTR)(LPCTSTR)cstrEditPassword);
	CButton* pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_LOGIN_MEMORIZEPASSWORD);
	bool bPassWordStore = BST_CHECKED==pCButtonCheck->GetCheck()?true:false;
	SettingIF::Instance()->SetPasswordStore(bPassWordStore);
	SettingIF::Instance()->WriteSettingToFile();
	AidPlugIdentifyIF::Instance();	//初始化识别插件 相当花费时间
	srand((int)time(0));		//开启随机种子
	//获取服务器数据
	CString cstrServerSetting;
	//	CString cstrServerSetting = AidPlugLoginIF::Instance()->GetUserData();
	if (0x00 != cstrServerSetting.GetLength()){
		//使用服务器数据
		//SettingIF::Instance()->SetServerSetting(cstrServerSetting);
	}
	else {
		//使用本地服务器数据(数据过大)
		//SettingIF::Instance()->ReadSettingFromFile();
	}
	OnCancel();
}

void LoginDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	CDialog::OnTimer(nIDEvent);
}

void LoginDlg::OnDestroy()
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
}


BOOL 
LoginDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) return TRUE;
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) {
		OnBnClickedButtonUserLoginLogin();
		return TRUE;
	}
	else
		return CDialog::PreTranslateMessage(pMsg);
}

BOOL LoginDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	GetDlgItem(IDC_EDIT_LOGIN_USERNAME)->SetWindowText(SettingIF::Instance()->GetUserName());
	if (true == SettingIF::Instance()->GetPasswordStore()) {
		CButton* pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_LOGIN_MEMORIZEPASSWORD);
		pCButtonCheck->SetCheck(BST_CHECKED);
		GetDlgItem(IDC_EDIT_LOGIN_PASSWORD)->SetWindowText(SettingIF::Instance()->GetPassword());
	}
	
	SetWindowPos(&wndTopMost,0,0,0,0, SWP_NOMOVE | SWP_NOSIZE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void LoginDlg::OnBnClickedButtonUserLoginForgetpwd()
{
	// TODO: Add your control notification handler code here
	ShowWindow(SW_HIDE);
	ResetPwdDlg cResetPwdDlg;
	cResetPwdDlg.DoModal();
	ShowWindow(SW_SHOW);
}

void LoginDlg::OnBnClickedButtonUserLoginRecharge()
{
	// TODO: Add your control notification handler code here
	ShowWindow(SW_HIDE);
	ReChargeDlg cReChargeDlg;
	cReChargeDlg.DoModal();
	ShowWindow(SW_SHOW);
}
