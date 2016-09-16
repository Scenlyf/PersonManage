// PassWord.cpp : implementation file
//

#include "stdafx.h"
#include "Personal.h"
#include "PassWord.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPassWord dialog


CPassWord::CPassWord(CWnd* pParent /*=NULL*/)
	: CDialog(CPassWord::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPassWord)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPassWord::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPassWord)
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_PassWord);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPassWord, CDialog)
	//{{AFX_MSG_MAP(CPassWord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPassWord message handlers

void CPassWord::OnOK() 
{
	// TODO: Add extra validation here
	m_PassWord.GetWindowText(password);	
    CString str;
	str.Format("Select * From tab_User where UserName = '%s'",::GetUserName());
	m_DataSet.Open(str);
	m_DataSet.SetFieldValue("PassWord",(_bstr_t)password);
	m_DataSet.Save();
	CDialog::OnOK();
}
