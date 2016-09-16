// DeptManage.cpp : implementation file
//

#include "stdafx.h"
#include "Personal.h"
#include "DeptManage.h"
#include "DeptEdit.h"
#include "LoginDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeptManage dialog


CDeptManage::CDeptManage(CWnd* pParent /*=NULL*/)
	: CDialog(CDeptManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeptManage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDeptManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeptManage)
	DDX_Control(pDX, IDC_TREE, m_tree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeptManage, CDialog)
	//{{AFX_MSG_MAP(CDeptManage)
	ON_BN_CLICKED(IDC_APPEND, OnAppend)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeptManage message handlers

void CDeptManage::GetNode(HTREEITEM pNode, int npid)
{
	HTREEITEM node;
	CADODataSet DataSet;
	DataSet.SetConnection(::GetConnection());
	CString str;
	str.Format("Select * From tab_Dept where pid = %d", npid);
	DataSet.Open(str);
	int count = DataSet.GetRecordCount();
	int ID;
	_variant_t value;
	for(int i=0; i<count; i++)
	{
		node = m_tree.InsertItem((_bstr_t)DataSet.GetFields()->Item["DeptName"]->Value, pNode);
		value = (_variant_t)DataSet.GetFields()->Item["ID"]->Value;
		ID = value.intVal;
		m_tree.SetItemData(node, ID);
		GetNode(node, ID);
		DataSet.Next();
	}
}

void CDeptManage::UpdateDept()
{
	m_tree.DeleteAllItems();  //清空
	GetNode(TVI_ROOT,0);     //生成树列表
}


BOOL CDeptManage::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_DataSet.SetConnection(::GetConnection());
	UpdateDept();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CDeptManage::OnAppend() 
{
	// TODO: Add your control notification handler code here
	CString user = GetUser();	
	if (user.Compare("mr") != 0)//设置权限，mr是管理员
	{
		MessageBox("非管理员，无法进行部门的添加！");
		return;
	}
	CDeptEdit deptedit;
	if(deptedit.DoModal() == IDOK)
	{
		HTREEITEM pNode = m_tree.GetSelectedItem();
		int pID;
		if (deptedit.isroot)
			pID = 0;
		else
			pID = m_tree.GetItemData(pNode);
		CADODataSet dataset;

		 /*
		if(m_tree.GetChildItem(pNode) != 0)
		{
			while(m_tree.GetNextSiblingItem(pNode) != 0)
			{	
				//CString str = m_tree.GetChildItem(pNode);
				if(m_tree.Compare(deptedit.name)==0)
				{
					MessageBox("该部门已存在！");
					return;
				}
			}
        }
		*/
		dataset.SetConnection(::GetConnection());
		dataset.Open("Select top 1 * From tab_Dept");
		dataset.AddNew();
		dataset.SetFieldValue("DeptName",(_variant_t)deptedit.name);
		dataset.SetFieldValue("memo",(_variant_t)deptedit.memo);
		dataset.SetFieldValue("PID",(long)pID);
		dataset.Save();
		UpdateDept();
	}
}

void CDeptManage::OnEdit() 
{
	// TODO: Add your control notification handler code here
	CString user = GetUser();	
	if (user.Compare("mr") != 0)//设置权限，mr是管理员
	{
		MessageBox("非管理员，无法进行部门的修改！");
		return;
	}
	
	CDeptEdit deptedit;
	deptedit.visible = false;

	HTREEITEM pNode = m_tree.GetSelectedItem();
	if (pNode == 0)
	{	
		MessageBox("你还没有选中列表项！");	
    	return;
	}
	int pID = m_tree.GetItemData(pNode);
	CADODataSet dataset;
	dataset.SetConnection(::GetConnection());
	CString str;
	str.Format("Select * From tab_Dept where id = %d",pID);
	dataset.Open(str);
	deptedit.name = (char *)(_bstr_t)dataset.GetFields()->Item[L"DeptName"]->Value;
	deptedit.memo = (char *)(_bstr_t)dataset.GetFields()->Item["memo"]->Value;
	if (deptedit.DoModal() == IDOK)
	{
		dataset.SetFieldValue("DeptName",(_variant_t)deptedit.name);
		dataset.SetFieldValue("memo",(_variant_t)deptedit.memo);
		dataset.Save();
		UpdateDept();
	}
}

void CDeptManage::OnDelete() 
{
	// TODO: Add your control notification handler code here
	CString user = GetUser();	
	if (user.Compare("mr") != 0)//设置权限，mr是管理员
	{
		MessageBox("非管理员，无法进行部门的删除！");
		return;
	}
	HTREEITEM pNode = m_tree.GetSelectedItem();
	if (pNode == 0)
	{	
		MessageBox("你还没有选中列表项！");	
    	return;
	}
	
	if (MessageBox("是否删除此记录！","提示",
		MB_YESNO|MB_ICONWARNING) == IDYES)
	{
		int pID = m_tree.GetItemData(pNode);
		CADODataSet dataset;
		dataset.SetConnection(::GetConnection());
		CString str;
		str.Format("Select * From tab_Dept where id = %d",pID);
		dataset.Open(str);	
		dataset.Delete();
		dataset.Save();
		UpdateDept();
	}
}
