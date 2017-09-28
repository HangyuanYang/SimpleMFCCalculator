// TESTDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TEST.h"
#include "TESTDlg.h"
#include "calculator.h"
#include<string>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTESTDlg dialog

CTESTDlg::CTESTDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTESTDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTESTDlg)
	m_sShow = _T("");
	m_radio = 2;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTESTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTESTDlg)
	DDX_Text(pDX, IDC_EDIT1, m_sShow);
	DDX_Radio(pDX, IDC_RADIO1, m_radio);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTESTDlg, CDialog)
	//{{AFX_MSG_MAP(CTESTDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnPress1)
	ON_BN_CLICKED(IDC_BUTTON2, OnPress2)
	ON_BN_CLICKED(IDC_BUTTON3, OnPress3)
	ON_BN_CLICKED(IDC_BUTTON4, OnPress4)
	ON_BN_CLICKED(IDC_BUTTON5, OnPress5)
	ON_BN_CLICKED(IDC_BUTTON6, OnPress6)
	ON_BN_CLICKED(IDC_BUTTON7, OnPress7)
	ON_BN_CLICKED(IDC_BUTTON8, OnPress8)
	ON_BN_CLICKED(IDC_BUTTON9, OnPress9)
	ON_BN_CLICKED(IDC_BUTTON10, OnPress10)
	ON_BN_CLICKED(IDC_BUTTON11, OnPress11)
	ON_BN_CLICKED(IDC_BUTTON12, OnPress12)
	ON_BN_CLICKED(IDC_BUTTON13, OnPress13)
	ON_BN_CLICKED(IDC_BUTTON14, OnPress14)
	ON_BN_CLICKED(IDC_BUTTON15, OnPress15)
	ON_BN_CLICKED(IDC_BUTTON16, OnPress16)
	ON_BN_CLICKED(IDC_BUTTON17, OnPress17)
	ON_BN_CLICKED(IDC_BUTTON18, OnPress18)
	ON_BN_CLICKED(IDC_BUTTON19, OnPress19)
	ON_BN_CLICKED(IDC_BUTTON20, OnPress20)
	ON_BN_CLICKED(IDC_BUTTON21, OnPress21)
	ON_BN_CLICKED(IDC_BUTTON22, OnPress22)
	ON_BN_CLICKED(IDC_BUTTON23, OnPress23)
	ON_BN_CLICKED(IDC_BUTTON24, OnPress24)
	ON_BN_CLICKED(IDC_BUTTON25, OnPress25)
	ON_BN_CLICKED(IDC_BUTTON26, OnPress26)
	ON_BN_CLICKED(IDC_BUTTON27, OnPress27)
	ON_BN_CLICKED(IDC_BUTTON28, OnPress28)
	ON_BN_CLICKED(IDC_BUTTON29, OnPress29)
	ON_BN_CLICKED(IDC_BUTTON30, OnPress30)
	ON_BN_CLICKED(IDC_BUTTON31, OnPress31)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_BUTTON32, OnPress32)
	ON_BN_CLICKED(IDC_BUTTON33, OnPress33)
	ON_BN_CLICKED(IDC_BUTTON34, OnPress34)
	ON_BN_CLICKED(IDC_BUTTON35, OnPress35)
	ON_BN_CLICKED(IDC_BUTTON36, OnPress36)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio1)
	ON_BN_CLICKED(IDC_BUTTON37, OnPress37)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTESTDlg message handlers

BOOL CTESTDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	m_sShow="";
	Backup="";
	tag=0;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTESTDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTESTDlg::OnPaint() 
{
	//设置背景颜色
	CRect   rect;  
    CPaintDC   dc(this);  
    GetClientRect(rect);  
    dc.FillSolidRect(rect,RGB(23,200,255));   


	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTESTDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTESTDlg::OnPress1()  // 7
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"7";
	UpdateData(false);
}

void CTESTDlg::OnPress2()  // 8
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"8";
	UpdateData(false);
}

void CTESTDlg::OnPress3()  // 9
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"9";
	UpdateData(false);
}

void CTESTDlg::OnPress4()  // 4
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"4";
	UpdateData(false);
}

void CTESTDlg::OnPress5()  // 5
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"5";
	UpdateData(false);
}

void CTESTDlg::OnPress6()  // 6
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"6";
	UpdateData(false);
}

void CTESTDlg::OnPress7()  // 1
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"1";
	UpdateData(false);
}

void CTESTDlg::OnPress8()  // 2
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"2";
	UpdateData(false);
}


void CTESTDlg::OnPress9()  // 3
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"3";
	UpdateData(false);
}


void CTESTDlg::OnPress10() // 0
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"0";
	UpdateData(false);
}

void CTESTDlg::OnPress11() // .
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+".";
	UpdateData(false);
}


void CTESTDlg::OnPress12() // =
{
	Backup=m_sShow; // 备份
	// TODO: Add your control notification handler code here
	//CString转换成字符串char*  GetBuffer(长度)转换成字符串char*   再转换成string
	
	/*string s=m_sShow.GetBuffer(m_sShow.GetLength());
	calculator t_calculator(s,m_radio);
	t_calculator.operate();
	int flag=t_calculator.getisexception();
	if(!flag)m_sShow.Format("%lf",t_calculator.getanswer());//将double转换成CString
	else m_sShow.Format("%s",calculator::iexcept[flag].c_str());//输出异常信息*/
	
	//以下直接将CString 放进计算器中 并直接取出结果  减少程序耦合
	calculator t_calculator(m_sShow,m_radio);
	t_calculator.operate();
	m_sShow=t_calculator.getanswer();
	if(tag&&m_sShow[0]=='N')m_sShow="";
	UpdateData(false);
}

void CTESTDlg::OnPress13() // +
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"+";
	UpdateData(false);
}

void CTESTDlg::OnPress14() // -
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"-";
	UpdateData(false);
}

void CTESTDlg::OnPress15() // *
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"*";
	UpdateData(false);
}


void CTESTDlg::OnPress16() // /
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"/";
	UpdateData(false);
}

void CTESTDlg::OnPress17() // AC
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_EDIT1,"");
	GetDlgItemText(IDC_EDIT1,m_sShow);//UpdataData(true);
}

void CTESTDlg::OnPress18() // (
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"(";
	UpdateData(false);
}

void CTESTDlg::OnPress19() // )
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+")";
	UpdateData(false);
}

void CTESTDlg::OnPress20() // Del
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow.Left(m_sShow.GetLength()-1);
	UpdateData(false);
}

void CTESTDlg::OnPress21() // &
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"&";
	UpdateData(false);
}

void CTESTDlg::OnPress22() // ^
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"^";
	UpdateData(false);
}

void CTESTDlg::OnPress23() // |
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"|";
	UpdateData(false);
}

void CTESTDlg::OnPress24() // Return
{
	// TODO: Add your control notification handler code here
	m_sShow=Backup;
	UpdateData(false);
}

void CTESTDlg::OnPress25() // TEXT UPDATE 
{
	// TODO: Add your control notification handler code here
	Backup=m_sShow;
	GetDlgItemText(IDC_EDIT1,m_sShow);
}

void CTESTDlg::OnPress26() // sin
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"sin(";
	UpdateData(false);
}

void CTESTDlg::OnPress27() //cos
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"cos(";
	UpdateData(false);
}

void CTESTDlg::OnPress28() //tan
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"tan(";
	UpdateData(false);
}

void CTESTDlg::OnPress29() //asin
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"asin(";
	UpdateData(false);
}

void CTESTDlg::OnPress30() //acos
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"acos(";
	UpdateData(false);
}

void CTESTDlg::OnPress31() //atan
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"atan(";
	UpdateData(false);
}

void CTESTDlg::OnRadio1() //进制选择
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	tag=1;
	OnPress12();
	tag=0;
}

void CTESTDlg::OnPress32() // 'A'
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"A";
	UpdateData(false);
}

void CTESTDlg::OnPress33() // 'B'
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"B";
	UpdateData(false);
}

void CTESTDlg::OnPress34() // 'C'
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"C";
	UpdateData(false);
}


void CTESTDlg::OnPress35() // 'D'
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"D";
	UpdateData(false);
}

void CTESTDlg::OnPress36() // 'E'
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"E";
	UpdateData(false);
}

void CTESTDlg::OnPress37()// 'F'
{
	// TODO: Add your control notification handler code here
	m_sShow=m_sShow+"F";
	UpdateData(false);
}
