#if !defined(AFX_LOGINDIALOG_H__6E209C78_1962_43C3_9764_50001B6D7F73__INCLUDED_)
#define AFX_LOGINDIALOG_H__6E209C78_1962_43C3_9764_50001B6D7F73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginDialog dialog

CString GetUser();
static CString m_user;

class CLoginDialog : public CDialog
{
// Construction
public:
    CADODataSet m_DataSet;
	CLoginDialog(CWnd* pParent = NULL);   // standard constructor
    
// Dialog Data
	//{{AFX_DATA(CLoginDialog)
	enum { IDD = IDD_DLGLOGIN };
	CEdit	m_UserPassword;
	CComboBox	m_UserList;

	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoginDialog)

	afx_msg void OnLogin();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDIALOG_H__6E209C78_1962_43C3_9764_50001B6D7F73__INCLUDED_)
