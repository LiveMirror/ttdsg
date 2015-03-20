// BindWindowDxDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ttdsg.h"
#include "BindWindowDxDlg.h"


// BindWindowDxDlg dialog

IMPLEMENT_DYNAMIC(BindWindowDxDlg, CDialog)

BindWindowDxDlg::BindWindowDxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(BindWindowDxDlg::IDD, pParent),
	m_eBindWindow(BINDWINDOWINFO_NON)
{

}

BindWindowDxDlg::~BindWindowDxDlg()
{
}

void BindWindowDxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BindWindowDxDlg, CDialog)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_DISPLAY_DX_2D, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxDisplayDx2d)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_DISPLAY_DX_2D_2, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxDisplayDx2d2)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_DISPLAY_DX_3D, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxDisplayDx3d)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_DISPLAY_DX_3D_8, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxDisplayDx3d8)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_DISPLAY_DX_OPENGL, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxDisplayDxOpengl)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_POSITION_LOCK_API, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxPositionLockApi)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_POSITION_LOCK_MESSAGE, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxPositionLockMessage)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_FOCUS_INPUT_API, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxFocusInputApi)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_FOCUS_INPUT_MESSAGE, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxFocusInputMessage)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_CLIP_LOCK_API, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxClipLockApi)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_INPUT_LOCK_API, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxInputLockApi)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_STATE_API, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxStateApi)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_STATE_MESSAGE, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxStateMessage)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_API, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxApi)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_CURSOR, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxCursor)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_RAW_INPUT, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxRawInput)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_INPUT_LOCK_API2, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxInputLockApi2)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_INPUT_LOCK_API3, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxInputLockApi3)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_KEYBOARD_DX_INPUT_LOCK_API, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxKeyboardDxInputLockApi)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_KEYBOARD_DX_STATE_API, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxKeyboardDxStateApi)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_KEYBOARD_DX_API, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxKeyboardDxApi)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_KEYBOARD_DX_RAW_INPUT, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxKeyboardDxRawInput)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_ACTIVE_API, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxActiveApi)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_ACTIVE_MESSAGE, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxActiveMessage)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_DISABLE_WINDOW_POSITION, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxDisableWindowPosition)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_DISABLE_WINDOW_SIZE, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxDisableWindowSize)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_DISABLE_WINDOW_MINMAX, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxDisableWindowMinmax)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_FAKE_WINDOW_MIN, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxFakeWindowMin)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_HIDE_DLL, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxHideDll)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_ACTIVE_API2, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxActiveApi2)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_INPUT_IME, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxInputIme)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_GRAPHIC_PROTECT, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxGraphicProtect)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_DISABLE_WINDOW_SHOW, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxDisableWindowShow)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_ANTI_API, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxAntiApi)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_MEMORY, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxMemory)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_KM_PROTECT, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxKmProtect)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_PREVENT_BLOCK, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxPreventBlock)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_ORI_PROC, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxOriProc)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_DOWN_CPU, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxDownCpu)
	ON_BN_CLICKED(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_FOCUS_MESSAGE, &BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxFocusMessage)
END_MESSAGE_MAP()


// BindWindowDxDlg message handlers

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxDisplayDx2d()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_DISPLAY_DX_2D);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lDisplayDx |=  SettingIF::BINDWINDOWINFO_DISPLAY_DX_2D;
	}
	else {
		sBindWindowInfo.lDisplayDx &=  ~SettingIF::BINDWINDOWINFO_DISPLAY_DX_2D;
	}
	
	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxDisplayDx2d2()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_DISPLAY_DX_2D_2);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lDisplayDx |=  SettingIF::BINDWINDOWINFO_DISPLAY_DX_2D_2;
	}
	else {
		sBindWindowInfo.lDisplayDx &=  ~SettingIF::BINDWINDOWINFO_DISPLAY_DX_2D_2;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxDisplayDx3d()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_DISPLAY_DX_3D);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lDisplayDx |=  SettingIF::BINDWINDOWINFO_DISPLAY_DX_3D;
	}
	else {
		sBindWindowInfo.lDisplayDx &=  ~SettingIF::BINDWINDOWINFO_DISPLAY_DX_3D;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxDisplayDx3d8()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_DISPLAY_DX_3D_8);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lDisplayDx |=  SettingIF::BINDWINDOWINFO_DISPLAY_DX_3D_8;
	}
	else {
		sBindWindowInfo.lDisplayDx &=  ~SettingIF::BINDWINDOWINFO_DISPLAY_DX_3D_8;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxDisplayDxOpengl()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_DISPLAY_DX_OPENGL);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lDisplayDx |=  SettingIF::BINDWINDOWINFO_DISPLAY_DX_OPENGL;
	}
	else {
		sBindWindowInfo.lDisplayDx &=  ~SettingIF::BINDWINDOWINFO_DISPLAY_DX_OPENGL;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxPositionLockApi()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_POSITION_LOCK_API);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lMouseDx |=  SettingIF::BINDWINDOWINFO_MOUSE_DX_POSITION_LOCK_API;
	}
	else {
		sBindWindowInfo.lMouseDx &=  ~SettingIF::BINDWINDOWINFO_MOUSE_DX_POSITION_LOCK_API;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxPositionLockMessage()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_POSITION_LOCK_MESSAGE);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lMouseDx |=  SettingIF::BINDWINDOWINFO_MOUSE_DX_POSITION_LOCK_MESSAGE;
	}
	else {
		sBindWindowInfo.lMouseDx &=  ~SettingIF::BINDWINDOWINFO_MOUSE_DX_POSITION_LOCK_MESSAGE;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxFocusInputApi()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_FOCUS_INPUT_API);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lMouseDx |=  SettingIF::BINDWINDOWINFO_MOUSE_DX_FOCUS_INPUT_API;
	}
	else {
		sBindWindowInfo.lMouseDx &=  ~SettingIF::BINDWINDOWINFO_MOUSE_DX_FOCUS_INPUT_API;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxFocusInputMessage()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_FOCUS_INPUT_MESSAGE);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lMouseDx |=  SettingIF::BINDWINDOWINFO_MOUSE_DX_FOCUS_INPUT_MESSAGE;
	}
	else {
		sBindWindowInfo.lMouseDx &=  ~SettingIF::BINDWINDOWINFO_MOUSE_DX_FOCUS_INPUT_MESSAGE;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxClipLockApi()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_CLIP_LOCK_API);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lMouseDx |=  SettingIF::BINDWINDOWINFO_MOUSE_DX_CLIP_LOCK_API;
	}
	else {
		sBindWindowInfo.lMouseDx &=  ~SettingIF::BINDWINDOWINFO_MOUSE_DX_CLIP_LOCK_API;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxInputLockApi()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_INPUT_LOCK_API);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lMouseDx |=  SettingIF::BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API;
	}
	else {
		sBindWindowInfo.lMouseDx &=  ~SettingIF::BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxStateApi()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_STATE_API);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lMouseDx |=  SettingIF::BINDWINDOWINFO_MOUSE_DX_STATE_API;
	}
	else {
		sBindWindowInfo.lMouseDx &=  ~SettingIF::BINDWINDOWINFO_MOUSE_DX_STATE_API;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxStateMessage()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_STATE_MESSAGE);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lMouseDx |=  SettingIF::BINDWINDOWINFO_MOUSE_DX_STATE_MESSAGE;
	}
	else {
		sBindWindowInfo.lMouseDx &=  ~SettingIF::BINDWINDOWINFO_MOUSE_DX_STATE_MESSAGE;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxApi()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_API);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lMouseDx |=  SettingIF::BINDWINDOWINFO_MOUSE_DX_API;
	}
	else {
		sBindWindowInfo.lMouseDx &=  ~SettingIF::BINDWINDOWINFO_MOUSE_DX_API;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxCursor()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_CURSOR);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lMouseDx |=  SettingIF::BINDWINDOWINFO_MOUSE_DX_CURSOR;
	}
	else {
		sBindWindowInfo.lMouseDx &=  ~SettingIF::BINDWINDOWINFO_MOUSE_DX_CURSOR;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxRawInput()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_RAW_INPUT);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lMouseDx |=  SettingIF::BINDWINDOWINFO_MOUSE_DX_RAW_INPUT;
	}
	else {
		sBindWindowInfo.lMouseDx &=  ~SettingIF::BINDWINDOWINFO_MOUSE_DX_RAW_INPUT;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxInputLockApi2()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_INPUT_LOCK_API2);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lMouseDx |=  SettingIF::BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API2;
	}
	else {
		sBindWindowInfo.lMouseDx &=  ~SettingIF::BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API2;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxMouseDxInputLockApi3()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_INPUT_LOCK_API3);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lMouseDx |=  SettingIF::BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API3;
	}
	else {
		sBindWindowInfo.lMouseDx &=  ~SettingIF::BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API3;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxKeyboardDxInputLockApi()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_KEYBOARD_DX_INPUT_LOCK_API);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lKeyboardDx |=  SettingIF::BINDWINDOWINFO_KEYBOARD_DX_INPUT_LOCK_API;
	}
	else {
		sBindWindowInfo.lKeyboardDx &=  ~SettingIF::BINDWINDOWINFO_KEYBOARD_DX_INPUT_LOCK_API;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxKeyboardDxStateApi()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_KEYBOARD_DX_STATE_API);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lKeyboardDx |=  SettingIF::BINDWINDOWINFO_KEYBOARD_DX_STATE_API;
	}
	else {
		sBindWindowInfo.lKeyboardDx &=  ~SettingIF::BINDWINDOWINFO_KEYBOARD_DX_STATE_API;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxKeyboardDxApi()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_KEYBOARD_DX_API);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lKeyboardDx |=  SettingIF::BINDWINDOWINFO_KEYBOARD_DX_API;
	}
	else {
		sBindWindowInfo.lKeyboardDx &=  ~SettingIF::BINDWINDOWINFO_KEYBOARD_DX_API;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxKeyboardDxRawInput()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_KEYBOARD_DX_RAW_INPUT);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lKeyboardDx |=  SettingIF::BINDWINDOWINFO_KEYBOARD_DX_RAW_INPUT;
	}
	else {
		sBindWindowInfo.lKeyboardDx &=  ~SettingIF::BINDWINDOWINFO_KEYBOARD_DX_RAW_INPUT;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxActiveApi()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_ACTIVE_API);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lPublicDx |=  SettingIF::BINDWINDOWINFO_PUBLIC_DX_ACTIVE_API;
	}
	else {
		sBindWindowInfo.lPublicDx &=  ~SettingIF::BINDWINDOWINFO_PUBLIC_DX_ACTIVE_API;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxActiveMessage()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_ACTIVE_MESSAGE);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lPublicDx |=  SettingIF::BINDWINDOWINFO_PUBLIC_DX_ACTIVE_MESSAGE;
	}
	else {
		sBindWindowInfo.lPublicDx &=  ~SettingIF::BINDWINDOWINFO_PUBLIC_DX_ACTIVE_MESSAGE;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxDisableWindowPosition()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_DISABLE_WINDOW_POSITION);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();

	//mutex judge
	if (BST_CHECKED==pCButtonCheck->GetCheck()&&SettingIF::BINDWINDOWINFO_PUBLIC_DX_FAKE_WINDOW_MIN==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_FAKE_WINDOW_MIN&sBindWindowInfo.lPublicDx)) {
		MessageBox(_T("\"dx.public.disable.window.position\" 此模式将锁定绑定窗口位置.\r\n 不可与\"dx.public.fake.window.min\"共用"),_T("公共属性dx模式互斥"),MB_OK);
		pCButtonCheck->SetCheck(BST_UNCHECKED);
		return;
	}

	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lPublicDx |=  SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_POSITION;
	}
	else {
		sBindWindowInfo.lPublicDx &=  ~SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_POSITION;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxDisableWindowSize()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_DISABLE_WINDOW_SIZE);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();

	//mutex judge
	if (BST_CHECKED==pCButtonCheck->GetCheck()&&SettingIF::BINDWINDOWINFO_PUBLIC_DX_FAKE_WINDOW_MIN==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_FAKE_WINDOW_MIN&sBindWindowInfo.lPublicDx)) {
		MessageBox(_T("\"dx.public.disable.window.size\" 此模式将锁定绑定窗口,禁止改变大小.\r\n 不可与\"dx.public.fake.window.min\"共用"),_T("公共属性dx模式互斥"),MB_OK);
		pCButtonCheck->SetCheck(BST_UNCHECKED);
		return;
	}

	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lPublicDx |=  SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_SIZE;
	}
	else {
		sBindWindowInfo.lPublicDx &=  ~SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_SIZE;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxDisableWindowMinmax()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_DISABLE_WINDOW_MINMAX);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();

	//mutex judge
	if (BST_CHECKED==pCButtonCheck->GetCheck()&&SettingIF::BINDWINDOWINFO_PUBLIC_DX_FAKE_WINDOW_MIN==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_FAKE_WINDOW_MIN&sBindWindowInfo.lPublicDx)) {
		MessageBox(_T("\"dx.public.disable.window.minmax\" 此模式将禁止窗口最大化和最小化,但是付出的代价是窗口同时也会被置顶. \r\n 不可与\"dx.public.fake.window.min\"共用"),_T("公共属性dx模式互斥"),MB_OK);
		pCButtonCheck->SetCheck(BST_UNCHECKED);
		return;
	}

	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lPublicDx |=  SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_MINMAX;
	}
	else {
		sBindWindowInfo.lPublicDx &=  ~SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_MINMAX;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxFakeWindowMin()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_FAKE_WINDOW_MIN);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();

	//mutex judge
	if (BST_CHECKED==pCButtonCheck->GetCheck()&&(SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_POSITION==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_POSITION&sBindWindowInfo.lPublicDx)
		||SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_SIZE==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_SIZE&sBindWindowInfo.lPublicDx)
		||SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_MINMAX==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_MINMAX&sBindWindowInfo.lPublicDx))) {
		MessageBox(_T("\"dx.public.fake.window.min\" 此模式将允许目标窗口在最小化状态时，仍然能够像非最小化一样操作.. \r\n 另注意，此模式会导致任务栏顺序重排，所以如果是多开模式下，会看起来比较混乱，建议单开使用，多开不建议使用. \r\n 同时此模式不是万能的,有些情况下最小化以后图色会不刷新或者黑屏.\r\n 不可与\"dx.public.disable.window.position\"共用 \r\n 不可与\"dx.public.disable.window.size\"共用 \r\n 不可与\"dx.public.disable.window.minmax\"共用"),_T("公共属性dx模式互斥"),MB_OK);
		pCButtonCheck->SetCheck(BST_UNCHECKED);
		return;
	}

	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lPublicDx |=  SettingIF::BINDWINDOWINFO_PUBLIC_DX_FAKE_WINDOW_MIN;
	}
	else {
		sBindWindowInfo.lPublicDx &=  ~SettingIF::BINDWINDOWINFO_PUBLIC_DX_FAKE_WINDOW_MIN;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxHideDll()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_HIDE_DLL);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lPublicDx |=  SettingIF::BINDWINDOWINFO_PUBLIC_DX_HIDE_DLL;
	}
	else {
		sBindWindowInfo.lPublicDx &=  ~SettingIF::BINDWINDOWINFO_PUBLIC_DX_HIDE_DLL;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxActiveApi2()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_ACTIVE_API2);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lPublicDx |=  SettingIF::BINDWINDOWINFO_PUBLIC_DX_ACTIVE_API2;
	}
	else {
		sBindWindowInfo.lPublicDx &=  ~SettingIF::BINDWINDOWINFO_PUBLIC_DX_ACTIVE_API2;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxInputIme()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_INPUT_IME);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lPublicDx |=  SettingIF::BINDWINDOWINFO_PUBLIC_DX_INPUT_IME;
	}
	else {
		sBindWindowInfo.lPublicDx &=  ~SettingIF::BINDWINDOWINFO_PUBLIC_DX_INPUT_IME;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxGraphicProtect()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_GRAPHIC_PROTECT);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lPublicDx |=  SettingIF::BINDWINDOWINFO_PUBLIC_DX_GRAPHIC_PROTECT;
	}
	else {
		sBindWindowInfo.lPublicDx &=  ~SettingIF::BINDWINDOWINFO_PUBLIC_DX_GRAPHIC_PROTECT;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxDisableWindowShow()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_DISABLE_WINDOW_SHOW);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lPublicDx |=  SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_SHOW;
	}
	else {
		sBindWindowInfo.lPublicDx &=  ~SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_SHOW;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxAntiApi()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_ANTI_API);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lPublicDx |=  SettingIF::BINDWINDOWINFO_PUBLIC_DX_ANTI_API;
	}
	else {
		sBindWindowInfo.lPublicDx &=  ~SettingIF::BINDWINDOWINFO_PUBLIC_DX_ANTI_API;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxMemory()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_MEMORY);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lPublicDx |=  SettingIF::BINDWINDOWINFO_PUBLIC_DX_MEMORY;
	}
	else {
		sBindWindowInfo.lPublicDx &=  ~SettingIF::BINDWINDOWINFO_PUBLIC_DX_MEMORY;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxKmProtect()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_KM_PROTECT);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lPublicDx |=  SettingIF::BINDWINDOWINFO_PUBLIC_DX_KM_PROTECT;
	}
	else {
		sBindWindowInfo.lPublicDx &=  ~SettingIF::BINDWINDOWINFO_PUBLIC_DX_KM_PROTECT;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxPreventBlock()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_PREVENT_BLOCK);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lPublicDx |=  SettingIF::BINDWINDOWINFO_PUBLIC_DX_PREVENT_BLOCK;
	}
	else {
		sBindWindowInfo.lPublicDx &=  ~SettingIF::BINDWINDOWINFO_PUBLIC_DX_PREVENT_BLOCK;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxOriProc()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_ORI_PROC);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lPublicDx |=  SettingIF::BINDWINDOWINFO_PUBLIC_DX_ORI_PROC;
	}
	else {
		sBindWindowInfo.lPublicDx &=  ~SettingIF::BINDWINDOWINFO_PUBLIC_DX_ORI_PROC;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxDownCpu()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_DOWN_CPU);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lPublicDx |=  SettingIF::BINDWINDOWINFO_PUBLIC_DX_DOWN_CPU;
	}
	else {
		sBindWindowInfo.lPublicDx &=  ~SettingIF::BINDWINDOWINFO_PUBLIC_DX_DOWN_CPU;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

void BindWindowDxDlg::OnBnClickedCheckBindwindowDxPublicDxFocusMessage()
{
	// TODO: Add your control notification handler code here
	CButton* pCButtonCheck = NULL;
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_FOCUS_MESSAGE);
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	if (BST_CHECKED==pCButtonCheck->GetCheck()) {
		sBindWindowInfo.lPublicDx |=  SettingIF::BINDWINDOWINFO_PUBLIC_DX_FOCUS_MESSAGE;
	}
	else {
		sBindWindowInfo.lPublicDx &=  ~SettingIF::BINDWINDOWINFO_PUBLIC_DX_FOCUS_MESSAGE;
	}

	SettingIF::Instance()->SetBindWindowInfo(sBindWindowInfo);
}

BOOL BindWindowDxDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	UpdateCtrl();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void 
BindWindowDxDlg::UpdateCtrl()
{
	SettingIF::BindWindowInfo sBindWindowInfo = SettingIF::Instance()->GetBindWindowInfo();
	CButton* pCButtonCheck = NULL;

	//Display	
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_DISPLAY_DX_2D);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_DISPLAY_DX_2D==(SettingIF::BINDWINDOWINFO_DISPLAY_DX_2D&sBindWindowInfo.lDisplayDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_DISPLAY==m_eBindWindow&&SettingIF::BINDWINDOWINFO_DISPLAY_DX == sBindWindowInfo.eDisplay);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_DISPLAY_DX_2D_2);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_DISPLAY_DX_2D_2==(SettingIF::BINDWINDOWINFO_DISPLAY_DX_2D_2&sBindWindowInfo.lDisplayDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_DISPLAY==m_eBindWindow&&SettingIF::BINDWINDOWINFO_DISPLAY_DX == sBindWindowInfo.eDisplay);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_DISPLAY_DX_3D);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_DISPLAY_DX_3D==(SettingIF::BINDWINDOWINFO_DISPLAY_DX_3D&sBindWindowInfo.lDisplayDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_DISPLAY==m_eBindWindow&&SettingIF::BINDWINDOWINFO_DISPLAY_DX == sBindWindowInfo.eDisplay);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_DISPLAY_DX_3D_8);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_DISPLAY_DX_3D_8==(SettingIF::BINDWINDOWINFO_DISPLAY_DX_3D_8&sBindWindowInfo.lDisplayDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_DISPLAY==m_eBindWindow&&SettingIF::BINDWINDOWINFO_DISPLAY_DX == sBindWindowInfo.eDisplay);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_DISPLAY_DX_OPENGL);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_DISPLAY_DX_OPENGL==(SettingIF::BINDWINDOWINFO_DISPLAY_DX_OPENGL&sBindWindowInfo.lDisplayDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_DISPLAY==m_eBindWindow&&SettingIF::BINDWINDOWINFO_DISPLAY_DX == sBindWindowInfo.eDisplay);

	//Mousse
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_POSITION_LOCK_API);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_MOUSE_DX_POSITION_LOCK_API==(SettingIF::BINDWINDOWINFO_MOUSE_DX_POSITION_LOCK_API&sBindWindowInfo.lMouseDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_MOUSE==m_eBindWindow&&SettingIF::BINDWINDOWINFO_MOUSE_DX == sBindWindowInfo.eMouse);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_POSITION_LOCK_MESSAGE);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_MOUSE_DX_POSITION_LOCK_MESSAGE==(SettingIF::BINDWINDOWINFO_MOUSE_DX_POSITION_LOCK_MESSAGE&sBindWindowInfo.lMouseDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_MOUSE==m_eBindWindow&&SettingIF::BINDWINDOWINFO_MOUSE_DX == sBindWindowInfo.eMouse);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_FOCUS_INPUT_API);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_MOUSE_DX_FOCUS_INPUT_API==(SettingIF::BINDWINDOWINFO_MOUSE_DX_FOCUS_INPUT_API&sBindWindowInfo.lMouseDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_MOUSE==m_eBindWindow&&SettingIF::BINDWINDOWINFO_MOUSE_DX == sBindWindowInfo.eMouse);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_FOCUS_INPUT_MESSAGE);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_MOUSE_DX_FOCUS_INPUT_MESSAGE==(SettingIF::BINDWINDOWINFO_MOUSE_DX_FOCUS_INPUT_MESSAGE&sBindWindowInfo.lMouseDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_MOUSE==m_eBindWindow&&SettingIF::BINDWINDOWINFO_MOUSE_DX == sBindWindowInfo.eMouse);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_CLIP_LOCK_API);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_MOUSE_DX_CLIP_LOCK_API==(SettingIF::BINDWINDOWINFO_MOUSE_DX_CLIP_LOCK_API&sBindWindowInfo.lMouseDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_MOUSE==m_eBindWindow&&SettingIF::BINDWINDOWINFO_MOUSE_DX == sBindWindowInfo.eMouse);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_INPUT_LOCK_API);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API==(SettingIF::BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API&sBindWindowInfo.lMouseDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_MOUSE==m_eBindWindow&&SettingIF::BINDWINDOWINFO_MOUSE_DX == sBindWindowInfo.eMouse);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_STATE_API);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_MOUSE_DX_STATE_API==(SettingIF::BINDWINDOWINFO_MOUSE_DX_STATE_API&sBindWindowInfo.lMouseDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_MOUSE==m_eBindWindow&&SettingIF::BINDWINDOWINFO_MOUSE_DX == sBindWindowInfo.eMouse);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_STATE_MESSAGE);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_MOUSE_DX_STATE_MESSAGE==(SettingIF::BINDWINDOWINFO_MOUSE_DX_STATE_MESSAGE&sBindWindowInfo.lMouseDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_MOUSE==m_eBindWindow&&SettingIF::BINDWINDOWINFO_MOUSE_DX == sBindWindowInfo.eMouse);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_API);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_MOUSE_DX_API==(SettingIF::BINDWINDOWINFO_MOUSE_DX_API&sBindWindowInfo.lMouseDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_MOUSE==m_eBindWindow&&SettingIF::BINDWINDOWINFO_MOUSE_DX == sBindWindowInfo.eMouse);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_CURSOR);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_MOUSE_DX_CURSOR==(SettingIF::BINDWINDOWINFO_MOUSE_DX_CURSOR&sBindWindowInfo.lMouseDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_MOUSE==m_eBindWindow&&SettingIF::BINDWINDOWINFO_MOUSE_DX == sBindWindowInfo.eMouse);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_RAW_INPUT);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_MOUSE_DX_RAW_INPUT==(SettingIF::BINDWINDOWINFO_MOUSE_DX_RAW_INPUT&sBindWindowInfo.lMouseDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_MOUSE==m_eBindWindow&&SettingIF::BINDWINDOWINFO_MOUSE_DX == sBindWindowInfo.eMouse);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_INPUT_LOCK_API2);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API2==(SettingIF::BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API2&sBindWindowInfo.lMouseDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_MOUSE==m_eBindWindow&&SettingIF::BINDWINDOWINFO_MOUSE_DX == sBindWindowInfo.eMouse);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_MOUSE_DX_INPUT_LOCK_API3);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API3==(SettingIF::BINDWINDOWINFO_MOUSE_DX_INPUT_LOCK_API3&sBindWindowInfo.lMouseDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_MOUSE==m_eBindWindow&&SettingIF::BINDWINDOWINFO_MOUSE_DX == sBindWindowInfo.eMouse);

	//Keyboard
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_KEYBOARD_DX_INPUT_LOCK_API);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_KEYBOARD_DX_INPUT_LOCK_API==(SettingIF::BINDWINDOWINFO_KEYBOARD_DX_INPUT_LOCK_API&sBindWindowInfo.lKeyboardDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_KEYBOARD==m_eBindWindow&&SettingIF::BINDWINDOWINFO_KEYBOARD_DX == sBindWindowInfo.eKeyboard);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_KEYBOARD_DX_STATE_API);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_KEYBOARD_DX_STATE_API==(SettingIF::BINDWINDOWINFO_KEYBOARD_DX_STATE_API&sBindWindowInfo.lKeyboardDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_KEYBOARD==m_eBindWindow&&SettingIF::BINDWINDOWINFO_KEYBOARD_DX == sBindWindowInfo.eKeyboard);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_KEYBOARD_DX_API);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_KEYBOARD_DX_API==(SettingIF::BINDWINDOWINFO_KEYBOARD_DX_API&sBindWindowInfo.lKeyboardDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_KEYBOARD==m_eBindWindow&&SettingIF::BINDWINDOWINFO_KEYBOARD_DX == sBindWindowInfo.eKeyboard);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_KEYBOARD_DX_RAW_INPUT);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_KEYBOARD_DX_RAW_INPUT==(SettingIF::BINDWINDOWINFO_KEYBOARD_DX_RAW_INPUT&sBindWindowInfo.lKeyboardDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_KEYBOARD==m_eBindWindow&&SettingIF::BINDWINDOWINFO_KEYBOARD_DX == sBindWindowInfo.eKeyboard);

	//Public
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_ACTIVE_API);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_PUBLIC_DX_ACTIVE_API==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_ACTIVE_API&sBindWindowInfo.lPublicDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_PUBLIC==m_eBindWindow&&sBindWindowInfo.bPublic);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_ACTIVE_MESSAGE);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_PUBLIC_DX_ACTIVE_MESSAGE==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_ACTIVE_MESSAGE&sBindWindowInfo.lPublicDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_PUBLIC==m_eBindWindow&&sBindWindowInfo.bPublic);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_DISABLE_WINDOW_POSITION);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_POSITION==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_POSITION&sBindWindowInfo.lPublicDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_PUBLIC==m_eBindWindow&&sBindWindowInfo.bPublic);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_DISABLE_WINDOW_SIZE);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_SIZE==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_SIZE&sBindWindowInfo.lPublicDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_PUBLIC==m_eBindWindow&&sBindWindowInfo.bPublic);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_DISABLE_WINDOW_MINMAX);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_MINMAX==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_MINMAX&sBindWindowInfo.lPublicDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_PUBLIC==m_eBindWindow&&sBindWindowInfo.bPublic);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_FAKE_WINDOW_MIN);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_PUBLIC_DX_FAKE_WINDOW_MIN==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_FAKE_WINDOW_MIN&sBindWindowInfo.lPublicDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_PUBLIC==m_eBindWindow&&sBindWindowInfo.bPublic);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_HIDE_DLL);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_PUBLIC_DX_HIDE_DLL==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_HIDE_DLL&sBindWindowInfo.lPublicDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_PUBLIC==m_eBindWindow&&sBindWindowInfo.bPublic);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_ACTIVE_API2);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_PUBLIC_DX_ACTIVE_API2==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_ACTIVE_API2&sBindWindowInfo.lPublicDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_PUBLIC==m_eBindWindow&&sBindWindowInfo.bPublic);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_INPUT_IME);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_PUBLIC_DX_INPUT_IME==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_INPUT_IME&sBindWindowInfo.lPublicDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_PUBLIC==m_eBindWindow&&sBindWindowInfo.bPublic);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_GRAPHIC_PROTECT);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_PUBLIC_DX_GRAPHIC_PROTECT==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_GRAPHIC_PROTECT&sBindWindowInfo.lPublicDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_PUBLIC==m_eBindWindow&&sBindWindowInfo.bPublic);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_DISABLE_WINDOW_SHOW);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_SHOW==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_DISABLE_WINDOW_SHOW&sBindWindowInfo.lPublicDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_PUBLIC==m_eBindWindow&&sBindWindowInfo.bPublic);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_ANTI_API);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_PUBLIC_DX_ANTI_API==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_ANTI_API&sBindWindowInfo.lPublicDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_PUBLIC==m_eBindWindow&&sBindWindowInfo.bPublic);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_MEMORY);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_PUBLIC_DX_MEMORY==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_MEMORY&sBindWindowInfo.lPublicDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_PUBLIC==m_eBindWindow&&sBindWindowInfo.bPublic);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_KM_PROTECT);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_PUBLIC_DX_KM_PROTECT==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_KM_PROTECT&sBindWindowInfo.lPublicDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_PUBLIC==m_eBindWindow&&sBindWindowInfo.bPublic);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_PREVENT_BLOCK);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_PUBLIC_DX_PREVENT_BLOCK==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_PREVENT_BLOCK&sBindWindowInfo.lPublicDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_PUBLIC==m_eBindWindow&&sBindWindowInfo.bPublic);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_ORI_PROC);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_PUBLIC_DX_ORI_PROC==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_ORI_PROC&sBindWindowInfo.lPublicDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_PUBLIC==m_eBindWindow&&sBindWindowInfo.bPublic);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_DOWN_CPU);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_PUBLIC_DX_DOWN_CPU==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_DOWN_CPU&sBindWindowInfo.lPublicDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_PUBLIC==m_eBindWindow&&sBindWindowInfo.bPublic);
	pCButtonCheck = (CButton*)GetDlgItem(IDC_CHECK_BINDWINDOW_DX_PUBLIC_DX_FOCUS_MESSAGE);
	pCButtonCheck->SetCheck(SettingIF::BINDWINDOWINFO_PUBLIC_DX_FOCUS_MESSAGE==(SettingIF::BINDWINDOWINFO_PUBLIC_DX_FOCUS_MESSAGE&sBindWindowInfo.lPublicDx));
	pCButtonCheck->EnableWindow(BINDWINDOWINFO_PUBLIC==m_eBindWindow&&sBindWindowInfo.bPublic);
}

BOOL 
BindWindowDxDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message==WM_KEYDOWN && (pMsg->wParam==VK_ESCAPE || pMsg->wParam==VK_RETURN)) return TRUE;
	else
		return CDialog::PreTranslateMessage(pMsg);
}