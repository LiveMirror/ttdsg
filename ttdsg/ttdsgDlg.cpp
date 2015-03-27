
// ttdsgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ttdsg.h"
#include "ttdsgDlg.h"
#include "LoginDlg.h"

#ifndef AIDPLUGLOGINIF_H
#include "AidPlugLoginIF.h"
#endif

#ifndef CXX_SETTINGIF_H
#include "SettingIF.h"
#endif

#ifndef CXX_AIDPLUGIDENTIFYIF_H
#include "AidPlugIdentifyIF.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//TIMER
#define TIMER_KEEP_ONLINE		1
#define TIMER_KEEP_ONLINE_TIEM	2//*60*1000 //2 Minutes

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CttdsgDlg dialog




CttdsgDlg::CttdsgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CttdsgDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CttdsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CttdsgDlg, CDialog)
	ON_MESSAGE(WM_HOTKEY,OnHotKey)

	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_DESTROY()

	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CttdsgDlg message handlers

BOOL CttdsgDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	if (FALSE == UserLogin()) {
		OnCancel();
		return FALSE;
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CttdsgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CttdsgDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CttdsgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

bool 
CttdsgDlg::UserLogin()
{
	LoginDlg cLoginDlg;
	cLoginDlg.DoModal();
	CString cstrCheck;
	if (0x00 == AidPlugLoginIF::Instance()->API_CheckUserStatus(cstrCheck)){
		return false;
	}
	//登陆成功
	//设置定时在线更新
	SetTimer(TIMER_KEEP_ONLINE, TIMER_KEEP_ONLINE_TIEM, 0);
	return true;
}
BOOL 
CttdsgDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message==WM_KEYDOWN && (pMsg->wParam==VK_ESCAPE || pMsg->wParam==VK_RETURN)) return TRUE;
	else
		return CDialog::PreTranslateMessage(pMsg);
}

int CttdsgDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	WORD virtualcode = MOD_SHIFT;
	WORD modifiers = VK_F11;
	SettingIF::Hotkey sHotkey = SettingIF::Instance()->GetHotKey(SettingIF::HOTKEY_HIDE);
	if(FALSE == RegisterHotKey(m_hWnd, sHotkey.eHotKey, 0, sHotkey.uiHotKey)){  //函数请参考MSDN
		MessageBox(_T("热键冲突"));
	}
	
	// 设置寻找标记
	::SetProp(m_hWnd, AfxGetApp()->m_pszExeName, (HANDLE)1);
	return 0;
}

LRESULT CttdsgDlg::OnHotKey(WPARAM     wParam,LPARAM     lParam)
{
	switch (wParam) {
		case SettingIF::HOTKEY_HIDE:
			if (TRUE == IsWindowVisible()) {
				::ShowWindow(GetSafeHwnd(), SW_HIDE);
			}
			else {
				::ShowWindow(GetSafeHwnd(), SW_SHOW);
			}
			break;
		default:
			break;
	}
	return 0;
}

void CttdsgDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent){
		case TIMER_KEEP_ONLINE:
			break;
			{
				static long lAbnormal = 0x00; 
				CString cstrCheck;
				long lRet = AidPlugLoginIF::Instance()->API_CheckUserStatus(cstrCheck);
				if (0x01 != lRet) {
					//异常
					lAbnormal++;
					if (-112 == lRet) {
						lAbnormal = 15;
					}
				}
				else {
					lAbnormal = 0x00;
				}
				if (15 <= lAbnormal) {
					KillTimer(TIMER_KEEP_ONLINE);
					MessageBox(cstrCheck);
					OnCancel();
				}
			}
			break;
		default:
			break;
	}

	CDialog::OnTimer(nIDEvent);

}

void CttdsgDlg::OnDestroy()
{
	CDialog::OnDestroy();
	// TODO: Add your message handler code here
	UnregisterHotKey(m_hWnd, SettingIF::HOTKEY_HIDE);	//解除热键登记,释放系统资源.

	// 删除寻找标记
	::RemoveProp(m_hWnd, AfxGetApp()->m_pszExeName);
	KillTimer(TIMER_KEEP_ONLINE);

	//插件相关
	CString cstrCheck;
	if (0x01 == AidPlugLoginIF::Instance()->API_CheckUserStatus(cstrCheck)) {
		AidPlugIdentifyIF::Instance()->UnBindWindow();		//解绑
		AidPlugIdentifyIF::Instance()->SetWindowState(7);	//显示窗口
	}
}