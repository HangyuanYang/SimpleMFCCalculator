// TEST.h : main header file for the TEST application
//

#if !defined(AFX_TEST_H__99E469B9_CD60_47A8_8336_229A99A228B9__INCLUDED_)
#define AFX_TEST_H__99E469B9_CD60_47A8_8336_229A99A228B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTESTApp:
// See TEST.cpp for the implementation of this class
//

class CTESTApp : public CWinApp
{
public:
	CTESTApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTESTApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTESTApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_H__99E469B9_CD60_47A8_8336_229A99A228B9__INCLUDED_)
