// DeptEdit.cpp : implementation file
//

#include "stdafx.h"
#include "Personal.h"
#include "DeptEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeptEdit dialog


CDeptEdit::CDeptEdit(CWnd* pParent /*=NULL*/)
	: CDialog(CDeptEdit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeptEdit)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDeptEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeptEdit)
	DDX_Control(pDX, IDC_EDIT_DEPTNAME, m_name);
	DDX_Control(pDX, IDC_EDIT_DEPTMEMO, m_memo);
	DDX_Control(pDX, IDC_CHECK_ROOT, m_root);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeptEdit, CDialog)
	//{{AFX_MSG_MAP(CDeptEdit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeptEdit message handlers

BOOL CDeptEdit::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if (!visible)
		m_root.ShowWindow(SW_HIDE);
	m_name.SetWindowText(name);
	m_memo.SetWindowText(memo);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDeptEdit::OnOK() 
{
	// TODO: Add extra validation here
	m_name.GetWindowText(name);
	m_memo.GetWindowText(memo);
	isroot = m_root.GetCheck();
	CDialog::OnOK();
}
