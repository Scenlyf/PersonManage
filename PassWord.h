#if !defined(AFX_PASSWORD_H__ED2A2F6C_7BAA_44FD_955C_E8700C582E23__INCLUDED_)
#define AFX_PASSWORD_H__ED2A2F6C_7BAA_44FD_955C_E8700C582E23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PassWord.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPassWord dialog

class CPassWord : public CDialog
{
// Construction
public:
	CADODataSet m_DataSet;
	CString password;
	CPassWord(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CPassWord)
	enum { IDD = IDD_DLGPASSWORD };
	CEdit	m_PassWord;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPassWord)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPassWord)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PASSWORD_H__ED2A2F6C_7BAA_44FD_955C_E8700C582E23__INCLUDED_)
