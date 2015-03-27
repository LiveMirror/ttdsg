// ReChargeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ttdsg.h"
#include "ReChargeDlg.h"

#ifndef AIDPLUGLOGINIF_H
#include "AidPlugLoginIF.h"
#endif

// ReChargeDlg dialog

IMPLEMENT_DYNAMIC(ReChargeDlg, CDialog)

ReChargeDlg::ReChargeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ReChargeDlg::IDD, pParent)
{

}

ReChargeDlg::~ReChargeDlg()
{
}

void ReChargeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ReChargeDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_RECHARGE_RECHARGE, &ReChargeDlg::OnBnClickedButtonRechargeRecharge)
END_MESSAGE_MAP()

BOOL 
ReChargeDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) return TRUE;
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) {
		OnBnClickedButtonRechargeRecharge();
		return TRUE;
	}
	else
		return CDialog::PreTranslateMessage(pMsg);
}

// ReChargeDlg message handlers

void ReChargeDlg::OnBnClickedButtonRechargeRecharge()
{
	// TODO: Add your control notification handler code here
	CButton* pCButton = (CButton*)GetDlgItem(IDC_BUTTON_RECHARGE_RECHARGE);
	pCButton->EnableWindow(FALSE);

	CString cstrEditUserName;
	CString cstrEditCardPwd;
	CString cstrEditReCommendUser;

	GetDlgItem(IDC_EDIT_RECHARGE_USERNAME)->GetWindowText(cstrEditUserName);
	GetDlgItem(IDC_EDIT_RECHARGE_RECOMMENDUSERNAME)->GetWindowText(cstrEditReCommendUser);
	GetDlgItem(IDC_EDIT_RECHARGE_CARDPWD)->GetWindowText(cstrEditCardPwd);
	
	if (0x00 == cstrEditUserName.GetLength()) {
		MessageBox(_T("ÇëÊäÈëÄúÓÃ»§Ãû£¡"));
		pCButton->EnableWindow(TRUE);
		return;
	}
	if (0x00 == cstrEditCardPwd.GetLength()) {
		MessageBox(_T("ÇëÊäÈëÄú³äÖµ¿¨ÃÜÂë£¡"));
		pCButton->EnableWindow(TRUE);
		return;
	}
	MessageBox(AidPlugLoginIF::Instance()->API_CardReCharge(cstrEditUserName, cstrEditCardPwd, cstrEditReCommendUser));
	pCButton->EnableWindow(TRUE);
}

BOOL ReChargeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
