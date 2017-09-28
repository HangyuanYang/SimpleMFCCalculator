// TESTDlg.h : header file
//

#if !defined(AFX_TESTDLG_H__C9A5E745_ADE2_4B8E_9D58_2DCB6B68F14C__INCLUDED_)
#define AFX_TESTDLG_H__C9A5E745_ADE2_4B8E_9D58_2DCB6B68F14C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTESTDlg dialog

class CTESTDlg : public CDialog
{
// Construction
public:
	CTESTDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTESTDlg)
	enum { IDD = IDD_TEST_DIALOG };
	CString	m_sShow;
	CString Backup;
	int		m_radio;
	int     tag;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTESTDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTESTDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPress1();
	afx_msg void OnPress2();
	afx_msg void OnPress3();
	afx_msg void OnPress4();
	afx_msg void OnPress5();
	afx_msg void OnPress6();
	afx_msg void OnPress7();
	afx_msg void OnPress8();
	afx_msg void OnPress9();
	afx_msg void OnPress10();
	afx_msg void OnPress11();
	afx_msg void OnPress12();
	afx_msg void OnPress13();
	afx_msg void OnPress14();
	afx_msg void OnPress15();
	afx_msg void OnPress16();
	afx_msg void OnPress17();
	afx_msg void OnPress18();
	afx_msg void OnPress19();
	afx_msg void OnPress20();
	afx_msg void OnPress21();
	afx_msg void OnPress22();
	afx_msg void OnPress23();
	afx_msg void OnPress24();
	afx_msg void OnPress25();
	afx_msg void OnPress26();
	afx_msg void OnPress27();
	afx_msg void OnPress28();
	afx_msg void OnPress29();
	afx_msg void OnPress30();
	afx_msg void OnPress31();
	afx_msg void OnRadio1();
	afx_msg void OnPress32();
	afx_msg void OnPress33();
	afx_msg void OnPress34();
	afx_msg void OnPress35();
	afx_msg void OnPress36();
	afx_msg void OnPress37();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDLG_H__C9A5E745_ADE2_4B8E_9D58_2DCB6B68F14C__INCLUDED_)
