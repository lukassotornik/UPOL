
// ex 10Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "ex 10.h"
#include "ex 10Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cex10Dlg dialog

const char *Jmena[] =
{ "Marie","Jan","Jana","Petr","Josef","Pavel","Jaroslav","Martin","Miroslav","Eva",
"Anna","Hana","Karel","Lenka","Milan","Michal","Alena","Petra","Lucie","Jaroslava" };


Cex10Dlg::Cex10Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_EX10_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cex10Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, list1);
	DDX_Control(pDX, IDC_LIST2, list2);
}

BEGIN_MESSAGE_MAP(Cex10Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cex10Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cex10Dlg::OnBnClickedButton2)
	ON_LBN_DBLCLK(IDC_LIST1, &Cex10Dlg::OnLbnDblclkList1)
	ON_LBN_DBLCLK(IDC_LIST2, &Cex10Dlg::OnLbnDblclkList2)
END_MESSAGE_MAP()


// Cex10Dlg message handlers

BOOL Cex10Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	for (auto x : Jmena) {
		list1.AddString(x);
	}

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

void Cex10Dlg::OnPaint()
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
HCURSOR Cex10Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void Cex10Dlg::OnBnClickedButton1()
{
	moveName(list1, list2);
}

void Cex10Dlg::moveName(CListBox & list1, CListBox & list2)
{
	for (int i = 0, m = list1.GetSelCount(); m > 0, i < list1.GetCount(); ++i) {
				if (list1.GetSel(i) > 0) {
					char name[21];
					list1.GetText(i, name);
					list1.DeleteString(i);
					list2.AddString(name);
					--i;
					--m;
					
				}
			}
}

void Cex10Dlg::OnBnClickedButton2()
{
	moveName(list2, list1);
}


void Cex10Dlg::OnLbnDblclkList1()
{
	moveName(list1, list2);
}


void Cex10Dlg::OnLbnDblclkList2()
{
	moveName(list2, list1);
}
