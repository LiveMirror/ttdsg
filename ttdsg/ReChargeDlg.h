#pragma once


// ReChargeDlg dialog

class ReChargeDlg : public CDialog
{
	DECLARE_DYNAMIC(ReChargeDlg)

public:
	ReChargeDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~ReChargeDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_RECHARGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	BOOL PreTranslateMessage(MSG* pMsg);
public:
	afx_msg void OnBnClickedButtonRechargeRecharge();
	virtual BOOL OnInitDialog();
};
