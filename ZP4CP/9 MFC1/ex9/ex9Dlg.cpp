
// ex9Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "ex9.h"
#include "ex9Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cex9Dlg dialog
int base = 16;
CStringA input;
char* str = new char();

Cex9Dlg::Cex9Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_EX9_DIALOG, pParent)
	, rb(2)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cex9Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, rb);

	DDX_Control(pDX, IDC_EDIT2, input_right);
	DDX_Control(pDX, IDC_EDIT1, input_left);
}

BEGIN_MESSAGE_MAP(Cex9Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &Cex9Dlg::OnBnClickedRadio) //set all radio buttons on one event change function
	ON_EN_CHANGE(IDC_EDIT1, &Cex9Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_RADIO2, &Cex9Dlg::OnBnClickedRadio)
	ON_BN_CLICKED(IDC_RADIO3, &Cex9Dlg::OnBnClickedRadio)
	ON_BN_CLICKED(IDC_BUTTON1, &Cex9Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &Cex9Dlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// Cex9Dlg message handlers

BOOL Cex9Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cex9Dlg::OnPaint()
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
HCURSOR Cex9Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void Cex9Dlg::OnEnChangeEdit1()
{
	
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}





void Cex9Dlg::OnBnClickedRadio()
{
	UpdateData();
	if (rb == 0) {
		base = 2;
	}
	else if (rb == 1) {
		base = 8;
	}
	else if (rb == 2) {
		base = 16;
	}
	OnBnClickedButton1();
}


void Cex9Dlg::OnBnClickedButton1()
{
	UpdateData();
	int x = atoi(input);
	itoa(x, str, base);
	input_left.SetWindowTextA(str);
	input_right.SetFocus();
}


void Cex9Dlg::OnEnChangeEdit2()
{
	input_right.GetWindowTextA(input);
}
