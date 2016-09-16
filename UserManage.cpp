// UserManage.cpp : implementation file
//

#include "stdafx.h"
#include "Personal.h"
#include "UserManage.h"
#include "UserEdit.h"
#include "LoginDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserManage dialog


CUserManage::CUserManage(CWnd* pParent /*=NULL*/)
	: CDialog(CUserManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserManage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CUserManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserManage)
	DDX_Control(pDX, IDC_LISTGRID, m_grid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserManage, CDialog)
	//{{AFX_MSG_MAP(CUserManage)
	ON_BN_CLICKED(IDC_APPEND, OnAppend)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserManage message handlers


BOOL CUserManage::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_grid.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES); //列表控制样式
	m_grid.InsertColumn(0,"用户名");  //添加列
	m_grid.SetColumnWidth(0,150);     //设置宽度
	m_DataSet.SetConnection(::GetConnection());   //设置数据集的数据库连接对象
	UpdateGrid();      //向列表视图控件中添加数据
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void CUserManage::UpdateGrid() 
{
	// TODO: Add your control notification handler code here
	m_DataSet.Open("Select * From tab_User");//打开用户表
	m_grid.DeleteAllItems(); //清空列表视图中的全部记录
	for(int i=0; i<m_DataSet.GetRecordCount(); i++)
	{
		//向列表视图中插入用户信息
		m_grid.InsertItem(i, (_bstr_t)m_DataSet.GetFields()->Item[L"UserName"]->Value);
		int no = m_DataSet.GetRecordNo(); //获取当前记录集行号
		m_grid.SetItemData(i, no);        //存储列表视图中的项对应的行号
		m_DataSet.Next();                 //行下移
	}
}

void CUserManage::OnAppend() 
{
	// TODO: Add your control notification handler code here
	CUserEdit useredit;    //定义用户编译窗体
	if(useredit.DoModal() == IDOK)   //显示用户编译窗体
	{
		if(Find(useredit.name) == 1)
		{
			return;
		}
		m_DataSet.AddNew();          //数据集添加行
		m_DataSet.SetFieldValue("UserName", (_bstr_t)useredit.name);//设置用户字段的值为新用户
		m_DataSet.SetFieldValue("PassWord", (_bstr_t)useredit.password);
		m_DataSet.Save();            //保存数据集
		UpdateGrid();
	}
}

int CUserManage::Find(CString name)
{
	for(int i=0;i<m_DataSet.GetRecordCount();i++)
	{
		CString str = m_grid.GetItemText(i,0);
		if(str.Compare(name)==0)
		{
			MessageBox("该用户已存在！");
			return 1;
		}
	}
	return 0;
}


void CUserManage::OnEdit() 
{
	// TODO: Add your control notification handler code here
	// 获取被选择的列表项索引号
    int pos = m_grid.GetSelectionMark();
	if (pos == -1)
	{
		MessageBox("你还没有选中列表项！");	
		return;
	}
	if(MessageBox("是否修改记录！","提示",
		MB_YESNO|MB_ICONWARNING) == IDYES)
	{
		CUserEdit useredit;
		int no = m_grid.GetItemData(m_grid.GetSelectionMark());
		m_DataSet.move(no-1);
		useredit.name = (char*)(_bstr_t)m_DataSet.GetFields()->Item[L"UserName"]->Value;
		useredit.password = (char*)(_bstr_t)m_DataSet.GetFields()->Item[L"PassWord"]->Value;
		if(useredit.DoModal() == IDOK)
		{
			m_DataSet.SetFieldValue("UserName",(_bstr_t)useredit.name);
			m_DataSet.SetFieldValue("PassWord",(_bstr_t)useredit.password);
			m_DataSet.Save();
			UpdateGrid();
		}
	}
}

void CUserManage::OnDelete() 
{
	// TODO: Add your control notification handler code here

	CString user = GetUser();
	if (user.Compare("mr") != 0)
	{
		MessageBox("非管理员，无法进行用户删除！");
		return;
	}

	int pos = m_grid.GetSelectionMark();
	if(pos != -1)
	{	
		CString name = m_grid.GetItemText(pos, 0);
		if(name != "mr")
		{	
			if(MessageBox("是否删除记录！","提示",
				MB_YESNO|MB_ICONWARNING) == IDYES)
			{
				int no = m_grid.GetItemData(m_grid.GetSelectionMark());
				m_DataSet.move(no-1);
				m_DataSet.Delete();
				m_DataSet.Save();
				UpdateGrid();
			}
		}
		else
		{
			MessageBox("该用户不能删除！");
			return;
		}
	}
	else
	{	
		MessageBox("你还没有选中列表项！");	
		return;
	}
}
