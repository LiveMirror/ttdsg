// UserInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ttdsg.h"
#include "UserInfoDlg.h"


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
END_MESSAGE_MAP()


// UserInfoDlg message handlers
