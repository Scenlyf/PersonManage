#if !defined(AFX_USEREDIT_H__3E381867_C361_4FFE_92BB_C86F8632AE06__INCLUDED_)
#define AFX_USEREDIT_H__3E381867_C361_4FFE_92BB_C86F8632AE06__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserEdit dialog

class CUserEdit : public CDialog
{
// Construction
public:
	CString name;
	CString password;
	CUserEdit(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CUserEdit)
	enum { IDD = IDD_DLGUSEREDIT };
	CEdit	m_PassWord;
	CEdit	m_UserName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserEdit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserEdit)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEREDIT_H__3E381867_C361_4FFE_92BB_C86F8632AE06__INCLUDED_)
