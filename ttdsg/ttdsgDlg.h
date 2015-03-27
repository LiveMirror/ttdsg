
// ttdsgDlg.h : header file
//

#pragma once


// CttdsgDlg dialog
class CttdsgDlg : public CDialog
{
// Construction
public:
	CttdsgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TTDSG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	afx_msg void OnTcnSelchangeTabSetting(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
	
private:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	LRESULT     OnHotKey(WPARAM     wParam,LPARAM     lParam);

private:
	bool UserLogin();	//ÓÃ»§µÇÂ½
};
