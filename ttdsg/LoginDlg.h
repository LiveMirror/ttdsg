#pragma once


// LoginDlg dialog

class LoginDlg : public CDialog
{
	DECLARE_DYNAMIC(LoginDlg)

public:
	LoginDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~LoginDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonUserLoginRegister();
	afx_msg void OnBnClickedButtonUserLoginLogin();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
private:
	BOOL PreTranslateMessage(MSG* pMsg);
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonUserLoginForgetpwd();
	afx_msg void OnBnClickedButtonUserLoginRecharge();
};
