#if !defined(AFX_DEPTMANAGE_H__F86E4EC9_829E_4D90_AB11_9575BD9ED544__INCLUDED_)
#define AFX_DEPTMANAGE_H__F86E4EC9_829E_4D90_AB11_9575BD9ED544__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeptManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeptManage dialog

class CDeptManage : public CDialog
{
// Construction
public:
	CDeptManage(CWnd* pParent = NULL);   // standard constructor
	CADODataSet m_DataSet;
// Dialog Data
	//{{AFX_DATA(CDeptManage)
	enum { IDD = IDD_DLGDEPT };
	CTreeCtrl	m_tree;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeptManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDeptManage)
	virtual BOOL OnInitDialog();
	afx_msg void OnAppend();
	afx_msg void OnDelete();
	afx_msg void OnEdit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
protected:
	void GetNode(HTREEITEM pNode, int npid);
	void UpdateDept();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEPTMANAGE_H__F86E4EC9_829E_4D90_AB11_9575BD9ED544__INCLUDED_)
