// LoginDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Personal.h"
#include "LoginDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDialog dialog


CLoginDialog::CLoginDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDialog)
	//}}AFX_DATA_INIT
}


void CLoginDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDialog)
    DDX_Control(pDX, IDC_EDIT_PASSWORD, m_UserPassword);
	DDX_Control(pDX, IDC_COMUSERLIST, m_UserList);
	
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDialog, CDialog)
	//{{AFX_MSG_MAP(CLoginDialog)
	ON_BN_CLICKED(IDOK, OnLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDialog message handlers



void CLoginDialog::OnLogin() 
{
	// TODO: Add your control notification handler code here
	CString sql,user,pass;
	m_UserList.GetWindowText(user); //获取用户名
	m_UserPassword.GetWindowText(pass);//获取密码
	sql.Format("Select * From tab_User Where UserName = '%s' and PassWord = '%s'",user,pass);//生成SQL查询语句
	m_DataSet.Open(sql); //打开数据库
	if(m_DataSet.GetRecordCount() == 1)
	{
		::SetUserName(user); //设置当前用户
		m_user = _T(user);
		this->OnOK();
	}
	else
		AfxMessageBox("用户名或密码不正确！");
}

CString GetUser()
{
	return m_user;
}

BOOL CLoginDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_DataSet.SetConnection(GetConnection());//设置数据集连接的数据库连接对象
	m_DataSet.Open("select * from Tab_User");//打开用户表
	int count = m_DataSet.GetRecordCount();//获取用户数量
	for(int i=0; i<count; i++)
	{   //将用户名添加到列表控件中
		m_UserList.AddString((_bstr_t)m_DataSet.GetFields()->Item["UserName"]->Value);
		m_DataSet.Next();
	}
	m_UserList.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
