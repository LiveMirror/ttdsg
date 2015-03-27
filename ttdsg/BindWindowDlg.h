#pragma once


// BindWindowDlg dialog

class BindWindowDlg : public CDialog
{
	DECLARE_DYNAMIC(BindWindowDlg)

public:
	BindWindowDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~BindWindowDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_BINDWINDOW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadioHighinfoBindwindow();
	afx_msg void OnBnClickedRadioHighinfoBindmouse();
	afx_msg void OnBnClickedRadioHighinfoBindkeyboard();
	afx_msg void OnBnClickedCheckHighinfoBindpubicDx();
	afx_msg void OnBnClickedRadioHighinfoBindmodel();
	virtual BOOL OnInitDialog();
	void UpdateCtrl();
	
private:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
