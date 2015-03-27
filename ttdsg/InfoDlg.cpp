// UserInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CocAssist.h"
#include "UserInfoDlg.h"

#ifndef AIDPLUGLOGINIF_H
#include "AidPlugLoginIF.h"
#endif

#ifndef CXX_COMMONFUNCTION_H
#include "CommonFuncion.h"
#endif

#ifndef CXX_SETTINGIF_H
#include "SettingIF.h"
#endif
// UserInfoDlg dialog

IMPLEMENT_DYNAMIC(UserInfoDlg, CDialog)

UserInfoDlg::UserInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(UserInfoDlg::IDD, pParent)
{

}

UserInfoDlg::~UserInfoDlg()
{
}

void UserInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UserInfoDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_USERINFO_RECHARGE, &UserInfoDlg::OnBnClickedButtonUserinfoRecharge)
	ON_BN_CLICKED(IDC_BUTTON_USERINFO_PWDMODIFY, &UserInfoDlg::OnBnClickedButtonUserinfoPwdmodify)
END_MESSAGE_MAP()


// UserInfoDlg message handlers

void UserInfoDlg::OnBnClickedButtonUserinfoRecharge()
{
	// TODO: Add your control notification handler code here
	CButton* pCButton = (CButton*)GetDlgItem(IDC_BUTTON_USERINFO_RECHARGE);
	pCButton->EnableWindow(FALSE);

	CString cstrEditCardPwd;
	CString cstrEditReCommendUser;
	GetDlgItem(IDC_EDIT_USERINFO_CARDPWD)->GetWindowText(cstrEditCardPwd);
	GetDlgItem(IDC_EDIT_USERINFO_RECOMMENDUSER)->GetWindowText(cstrEditReCommendUser);
	if (0x00 == cstrEditCardPwd.GetLength()) {
		MessageBox(_T("ÇëÊäÈëÄú³äÖµ¿¨ÃÜÂë£¡"));
		pCButton->EnableWindow(TRUE);
		return;
	}

	MessageBox(AidPlugLoginIF::Instance()->API_CardReCharge(SettingIF::Instance()->GetUserName(), cstrEditCardPwd, cstrEditReCommendUser));
	pCButton->EnableWindow(TRUE);
	UpdateCtrl();
}

BOOL UserInfoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	OnInitCtrl();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void 
UserInfoDlg::UpdateCtrl()
{
	GetDlgItem(IDC_STATIC_USERINFO_USERNAME)->SetWindowText(SettingIF::Instance()->GetUserName());
	GetDlgItem(IDC_STATIC_USERINFO_EXPIRED)->SetWindowText(AidPlugLoginIF::Instance()->API_GetExpired(SettingIF::Instance()->GetUserName()));
}

void 
UserInfoDlg::OnInitCtrl()
{
	AidPlugLogin::AIDPLUG_TYPE eAidPlug = AidPlugLoginIF::Instance()->API_GetAidPlugType();
	switch(eAidPlug) {
		case AidPlugLogin::AIDPLUG_EY:
			GetDlgItem(IDC_STATIC_USERINFO_EMAIL)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT_USERINFO_EMAIL)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_BUTTON_USERINFO_PWDMODIFY)->SetWindowText(_T("·¢ËÍ"));
			break;
		case  AidPlugLogin::AIDPLUG_PIAO:
			GetDlgItem(IDC_STATIC_USERINFO_NEWPWD)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_STATIC_USERINFO_NEWPWD1)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT_USERINFO_NEWPWD)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT_USERINFO_NEWPWD1)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_BUTTON_USERINFO_PWDMODIFY)->SetWindowText(_T("ÐÞ¸Ä"));
			break;
		default:
			break;
	}
}

BOOL 
UserInfoDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message==WM_KEYDOWN && (pMsg->wParam==VK_ESCAPE || pMsg->wParam==VK_RETURN)) return TRUE;
	else
		return CDialog::PreTranslateMessage(pMsg);
}

void UserInfoDlg::OnBnClickedButtonUserinfoPwdmodify()
{
	// TODO: Add your control notification handler code here
	CButton* pCButton = (CButton*)GetDlgItem(IDC_BUTTON_USERINFO_PWDMODIFY);
	pCButton->EnableWindow(FALSE);

	CString cstrEditEmail;
	CString cstrEditNewPwd;
	CString cstrEditNewPwd1;
	AidPlugLogin::AIDPLUG_TYPE eAidPlug = AidPlugLoginIF::Instance()->API_GetAidPlugType();
	switch(eAidPlug) {
		case AidPlugLogin::AIDPLUG_EY:
			GetDlgItem(IDC_EDIT_USERINFO_EMAIL)->GetWindowText(cstrEditEmail);
			if (0x00 == cstrEditEmail.GetLength()) {
				MessageBox(_T("ÇëÊäÈëÄú×¢²áÊ±µÄÓÊÏä£¡"));
				pCButton->EnableWindow(TRUE);
				return;
			}
			break;
		case  AidPlugLogin::AIDPLUG_PIAO:
			GetDlgItem(IDC_EDIT_USERINFO_NEWPWD)->GetWindowText(cstrEditNewPwd);
			if (0x00 == cstrEditNewPwd.GetLength()) {
				MessageBox(_T("ÇëÊäÈëÄúµÄÐÂÃÜÂë£¡"));
				pCButton->EnableWindow(TRUE);
				return;
			}
			GetDlgItem(IDC_EDIT_USERINFO_NEWPWD1)->GetWindowText(cstrEditNewPwd1);
			if (0x00 == cstrEditNewPwd1.GetLength()) {
				MessageBox(_T("ÇëÔÙ´ÎÊäÈëÄúµÄÐÂÃÜÂë£¡"));
				pCButton->EnableWindow(TRUE);
				return;
			}
			if (cstrEditNewPwd != cstrEditNewPwd1) {
				MessageBox(_T("¶þ´ÎÊäÈëÃÜÂë²»Æ¥Åä£¡"));
				pCButton->EnableWindow(TRUE);
				return;
			}
			break;
		default:
			break;
	}
	MessageBox(AidPlugLoginIF::Instance()->API_UpdatePwd(SettingIF::Instance()->GetUserName(), SettingIF::Instance()->GetPassword(), cstrEditNewPwd, cstrEditEmail));
	pCButton->EnableWindow(TRUE);
}
