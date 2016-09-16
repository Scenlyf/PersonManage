#if !defined(AFX_PERSONMANAGE_H__62C4C63C_E3A1_403B_8F4E_5D3B0989D308__INCLUDED_)
#define AFX_PERSONMANAGE_H__62C4C63C_E3A1_403B_8F4E_5D3B0989D308__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PersonManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPersonManage dialog

class CPersonManage : public CDialog
{
// Construction
public:
	CPersonManage(CWnd* pParent = NULL);   // standard constructor
 	int m_DeptID;
// Dialog Data
	//{{AFX_DATA(CPersonManage)
	enum { IDD = IDD_DLGPERSON };
	CTreeCtrl	m_tree;
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPersonManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPersonManage)
	afx_msg void OnAppend();
	afx_msg void OnEdit();
	afx_msg void OnDelete();
	afx_msg void OnSelchangedTreedept(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void UpdatePerson();
	void GetNode(HTREEITEM pNode,int nPid);
	void UpdateDept();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PERSONMANAGE_H__62C4C63C_E3A1_403B_8F4E_5D3B0989D308__INCLUDED_)
