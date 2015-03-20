#pragma once

#ifndef CXX_SETTINGIF_H
#include "SettingIF.h"
#endif

// BindWindowDxDlg dialog

class BindWindowDxDlg : public CDialog
{
	DECLARE_DYNAMIC(BindWindowDxDlg)

public:
	enum BINDWINDOWINFO_TYPE
	{
		BINDWINDOWINFO_NON = 0,
		BINDWINDOWINFO_DISPLAY,
		BINDWINDOWINFO_MOUSE,
		BINDWINDOWINFO_KEYBOARD,
		BINDWINDOWINFO_PUBLIC,

		BINDWINDOWINFO_ALL,
		BINDWINDOWINFO_INVALID = -1,
	};

	BindWindowDxDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~BindWindowDxDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_BINDWINDOW_DX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheckBindwindowDxDisplayDx2d();
	afx_msg void OnBnClickedCheckBindwindowDxDisplayDx2d2();
	afx_msg void OnBnClickedCheckBindwindowDxDisplayDx3d();
	afx_msg void OnBnClickedCheckBindwindowDxDisplayDx3d8();
	afx_msg void OnBnClickedCheckBindwindowDxDisplayDxOpengl();
	afx_msg void OnBnClickedCheckBindwindowDxMouseDxPositionLockApi();
	afx_msg void OnBnClickedCheckBindwindowDxMouseDxPositionLockMessage();
	afx_msg void OnBnClickedCheckBindwindowDxMouseDxFocusInputApi();
	afx_msg void OnBnClickedCheckBindwindowDxMouseDxFocusInputMessage();
	afx_msg void OnBnClickedCheckBindwindowDxMouseDxClipLockApi();
	afx_msg void OnBnClickedCheckBindwindowDxMouseDxInputLockApi();
	afx_msg void OnBnClickedCheckBindwindowDxMouseDxStateApi();
	afx_msg void OnBnClickedCheckBindwindowDxMouseDxStateMessage();
	afx_msg void OnBnClickedCheckBindwindowDxMouseDxApi();
	afx_msg void OnBnClickedCheckBindwindowDxMouseDxCursor();
	afx_msg void OnBnClickedCheckBindwindowDxMouseDxRawInput();
	afx_msg void OnBnClickedCheckBindwindowDxMouseDxInputLockApi2();
	afx_msg void OnBnClickedCheckBindwindowDxMouseDxInputLockApi3();
	afx_msg void OnBnClickedCheckBindwindowDxKeyboardDxInputLockApi();
	afx_msg void OnBnClickedCheckBindwindowDxKeyboardDxStateApi();
	afx_msg void OnBnClickedCheckBindwindowDxKeyboardDxApi();
	afx_msg void OnBnClickedCheckBindwindowDxKeyboardDxRawInput();
	afx_msg void OnBnClickedCheckBindwindowDxPublicDxActiveApi();
	afx_msg void OnBnClickedCheckBindwindowDxPublicDxActiveMessage();
	afx_msg void OnBnClickedCheckBindwindowDxPublicDxDisableWindowPosition();
	afx_msg void OnBnClickedCheckBindwindowDxPublicDxDisableWindowSize();
	afx_msg void OnBnClickedCheckBindwindowDxPublicDxDisableWindowMinmax();
	afx_msg void OnBnClickedCheckBindwindowDxPublicDxFakeWindowMin();
	afx_msg void OnBnClickedCheckBindwindowDxPublicDxHideDll();
	afx_msg void OnBnClickedCheckBindwindowDxPublicDxActiveApi2();
	afx_msg void OnBnClickedCheckBindwindowDxPublicDxInputIme();
	afx_msg void OnBnClickedCheckBindwindowDxPublicDxGraphicProtect();
	afx_msg void OnBnClickedCheckBindwindowDxPublicDxDisableWindowShow();
	afx_msg void OnBnClickedCheckBindwindowDxPublicDxAntiApi();
	afx_msg void OnBnClickedCheckBindwindowDxPublicDxMemory();
	afx_msg void OnBnClickedCheckBindwindowDxPublicDxKmProtect();
	afx_msg void OnBnClickedCheckBindwindowDxPublicDxPreventBlock();
	afx_msg void OnBnClickedCheckBindwindowDxPublicDxOriProc();
	afx_msg void OnBnClickedCheckBindwindowDxPublicDxDownCpu();
	afx_msg void OnBnClickedCheckBindwindowDxPublicDxFocusMessage();
	virtual BOOL OnInitDialog();

	void UpdateCtrl();
	void SetBindWindow(BINDWINDOWINFO_TYPE eBindWindow) {m_eBindWindow = eBindWindow;}
private:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
private:
	BINDWINDOWINFO_TYPE m_eBindWindow;
};
