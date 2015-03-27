#pragma once


// ResetPwdDlg dialog

class ResetPwdDlg : public CDialog
{
	DECLARE_DYNAMIC(ResetPwdDlg)

public:
	ResetPwdDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~ResetPwdDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_RESETPWD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	BOOL PreTranslateMessage(MSG* pMsg);
	void OnInitCtrl();
public:
	afx_msg void OnBnClickedButtonUserResetpwdOk();
	virtual BOOL OnInitDialog();
};
