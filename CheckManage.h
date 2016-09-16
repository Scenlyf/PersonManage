#if !defined(AFX_CHECKMANAGE_H__3EF3F5D1_D78E_4092_B165_08865649C255__INCLUDED_)
#define AFX_CHECKMANAGE_H__3EF3F5D1_D78E_4092_B165_08865649C255__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CheckManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCheckManage dialog

class CCheckManage : public CDialog
{
// Construction
public:
	CCheckManage(CWnd* pParent = NULL);   // standard constructor
   
// Dialog Data
	//{{AFX_DATA(CCheckManage)
	enum { IDD = IDD_DLGCHECK };
	CListCtrl	m_list;
	CComboBox	m_cyy;
	CComboBox	m_cmm;
	CComboBox	m_cemp;
	CString	m_emp;
	CString	m_mm;
	CString	m_yy;
	BOOL	m_check;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCheckManage)
	virtual BOOL OnInitDialog();
	afx_msg void OnCheck1();
	afx_msg void OnCloseupComboemp();
	afx_msg void OnCloseupCombomm();
	afx_msg void OnCloseupComboyy();
	afx_msg void OnAppend();
	afx_msg void OnEdit();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
protected:
	CTime GetDateForStr(CString datestr);
	CTime GetTimeForStr(CString timestr);
	CTime DecTime(CTime one,CTime two);
	void UpdateList();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKMANAGE_H__3EF3F5D1_D78E_4092_B165_08865649C255__INCLUDED_)
