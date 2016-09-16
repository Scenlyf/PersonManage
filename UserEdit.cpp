// UserEdit.cpp : implementation file
//

#include "stdafx.h"
#include "Personal.h"
#include "UserEdit.h"
#include "LoginDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserEdit dialog


CUserEdit::CUserEdit(CWnd* pParent /*=NULL*/)
	: CDialog(CUserEdit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserEdit)
	//}}AFX_DATA_INIT
}


void CUserEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserEdit)
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_PassWord);
	DDX_Control(pDX, IDC_EDIT_USERNAME, m_UserName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserEdit, CDialog)
	//{{AFX_MSG_MAP(CUserEdit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserEdit message handlers


void CUserEdit::OnOK() 
{
	m_UserName.GetWindowText(name);
	m_PassWord.GetWindowText(password);
	if (name.IsEmpty())
		AfxMessageBox("用户名不能为空！");
	else
		CDialog::OnOK();
}

BOOL CUserEdit::OnInitDialog() 
{
	CDialog::OnInitDialog();
    CString user = GetUser();	
	if (user.Compare("mr") == 0)//设置权限，mr是管理员
	{
		m_UserName.EnableWindow(true);
		m_PassWord.EnableWindow(false);
	}
	else
	{
		m_PassWord.EnableWindow(false);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
}
