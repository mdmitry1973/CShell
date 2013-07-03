
// SimpleDialog2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "SimpleDialog2.h"
#include "SimpleDialog2Dlg.h"
//??#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSimpleDialog2Dlg dialog




CSimpleDialog2Dlg::CSimpleDialog2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSimpleDialog2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CSimpleDialog2Dlg::~CSimpleDialog2Dlg()
{


}

void CSimpleDialog2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

    DDX_Control(pDX, IDC_COMBO1, m_cob_test);
    DDX_CBIndex(pDX, IDC_COMBO1, indexComboBox);
    DDX_Check(pDX, IDC_CHECK1, indexCheckBox);

    DDX_Control(pDX, IDC_SPIN_LEFT_MARGIN, m_spin_Data);
    DDX_Control(pDX, IDC_EDIT_LEFT_MARGIN, m_edit_Data);

    DDX_Control(pDX, IDC_SLIDER1, m_slider);
    DDX_Control(pDX, IDC_PROGRESS1, m_progress);

    DDX_Control(pDX, IDC_LIST1, m_listBox);
}


BEGIN_MESSAGE_MAP(CSimpleDialog2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, OnBnClickedCheck1)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_RADIO1, OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnBnClickedRadio2)
	ON_EN_CHANGE(IDC_EDIT1, OnEnChangeEdit1)
    ON_LBN_SELCHANGE(IDC_LIST1, OnLbnSelchangeList1)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()

// CSimpleDialog2Dlg message handlers

BOOL CSimpleDialog2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
/*
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
*/
	CString itemStr;

	itemStr.LoadString(IDS_STRING102);
	m_cob_test.AddString(itemStr);

	itemStr.LoadString(IDS_STRING103);
	m_cob_test.AddString(itemStr);

	itemStr.LoadString(IDS_STRING104);
	m_cob_test.AddString(itemStr);

	indexComboBox = 0;
	indexCheckBox =TRUE;

	m_spin_Data.SetBuddy(&m_edit_Data);
	m_edit_Data.Verbose(TRUE);
	m_edit_Data.SetNumberOfNumberAfterPoint(1);
	m_spin_Data.SetRange(0.0, 10.0);
	m_spin_Data.SetDelta(0.1);
	m_spin_Data.SetPos(2.2);

	m_progress.SetRange(0, 100);
	m_slider.SetRange(0, 100);

    m_progress.SetPos(50);
    m_slider.SetPos(20);

	m_listBox.AddString(_T("hello1"));
	m_listBox.AddString(_T("hello2"));
	m_listBox.AddString(_T("hello3"));

	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSimpleDialog2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSimpleDialog2Dlg::OnPaint()
{
//??	if (IsIconic())
//??	{
//??		CPaintDC dc(this); // device context for painting
//??
//??		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
//??//??		int cxIcon = GetSystemMetrics(SM_CXICON);
//??		int cyIcon = GetSystemMetrics(SM_CYICON);
//??		CRect rect;
//??		GetClientRect(&rect);
//??		int x = (rect.Width() - cxIcon + 1) / 2;
//??		int y = (rect.Height() - cyIcon + 1) / 2;
//??
		// Draw the icon
//??		dc.DrawIcon(x, y, m_hIcon);
//??	}
//??	else
//??	{
//??		CDialogEx::OnPaint();
//??	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSimpleDialog2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSimpleDialog2Dlg::OnBnClickedButton1()
{
	UpdateData();

	if (indexCheckBox)
	{
		CButton *radio = (CButton *)GetDlgItem(IDC_RADIO1);
		
		if (radio)
		{
			radio->SetCheck(1);
		}
		
	}
	else
	{
		if (GetDlgItem(IDC_RADIO2))
		{
			((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(1);
		}
    }
}


void CSimpleDialog2Dlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
}


void CSimpleDialog2Dlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}


void CSimpleDialog2Dlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
}


void CSimpleDialog2Dlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
}


void CSimpleDialog2Dlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CSimpleDialog2Dlg::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
}


void CSimpleDialog2Dlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;

    m_progress.SetPos(m_slider.GetPos());
}

void CSimpleDialog2Dlg::OnHScroll(UINT /*nSBCode*/, UINT /*nPos*/, CScrollBar* /*pScrollBar*/)
{
	m_progress.SetPos(m_slider.GetPos());
}

