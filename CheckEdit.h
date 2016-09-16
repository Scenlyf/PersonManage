#if !defined(AFX_CHECKEDIT_H__04948F21_EF81_487E_9BEC_2E6DDCA09AF9__INCLUDED_)
#define AFX_CHECKEDIT_H__04948F21_EF81_487E_9BEC_2E6DDCA09AF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CheckEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCheckEdit dialog

class CCheckEdit : public CDialog
{
// Construction
public:
	CCheckEdit(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCheckEdit)
	enum { IDD = IDD_DLGCHECKEDIT };
	CComboBox	m_BoxName;
	CComboBox	m_BoxLeave;
	CString	m_leave;
	CString	m_name;
	CTime	m_datecheck;
	CString	m_memo;
	CTime	m_timeoff;
	CTime	m_timeoffduty;
	CTime	m_timeoffleave;
	CTime	m_timeon;
	CTime	m_timeonduty;
	CTime	m_timeonleave;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckEdit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCheckEdit)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKEDIT_H__04948F21_EF81_487E_9BEC_2E6DDCA09AF9__INCLUDED_)
