#pragma once


// UserInfoDlg dialog

class UserInfoDlg : public CDialog
{
	DECLARE_DYNAMIC(UserInfoDlg)

public:
	UserInfoDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~UserInfoDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_USERINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
