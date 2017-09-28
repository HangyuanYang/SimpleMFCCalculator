// TEST.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "TEST.h"
#include "TESTDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTESTApp

BEGIN_MESSAGE_MAP(CTESTApp, CWinApp)
	//{{AFX_MSG_MAP(CTESTApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTESTApp construction

CTESTApp::CTESTApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTESTApp object

CTESTApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTESTApp initialization

BOOL CTESTApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CTESTDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

//	//SetDialogBkColor  只能放到*App.h中的InitInstance()函数中
//  //在afxwin.h 中(包含在了stdafx.h中)    经过验证并不能改变对话框背景
    SetDialogBkColor(RGB(0, 0, 0), RGB(0, 0, 0));

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
