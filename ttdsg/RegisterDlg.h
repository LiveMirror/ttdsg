#pragma once


// RegisterDlg dialog

class RegisterDlg : public CDialog
{
	DECLARE_DYNAMIC(RegisterDlg)

public:
	RegisterDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~RegisterDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_REGISTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonUserRegisterResetinfo();
	afx_msg void OnBnClickedButtonUserRegisterRegister();
private:
	BOOL PreTranslateMessage(MSG* pMsg);

public:
	virtual BOOL OnInitDialog();
};
