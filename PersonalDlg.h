// PersonalDlg.h : header file
//

#if !defined(AFX_PERSONALDLG_H__34956B48_E08D_40D4_8DB8_B30B58693782__INCLUDED_)
#define AFX_PERSONALDLG_H__34956B48_E08D_40D4_8DB8_B30B58693782__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPersonalDlg dialog

class CPersonalDlg : public CDialog
{
// Construction
public:
	CPersonalDlg(CWnd* pParent = NULL);	// standard constructor
    CMenu m_menu;//主菜单
// Dialog Data
	//{{AFX_DATA(CPersonalDlg)
	enum { IDD = IDD_PERSONAL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPersonalDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPersonalDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMenuuser();
	afx_msg void OnMenupassword();
	afx_msg void OnMenuexit();
	afx_msg void OnMenuperson();
	afx_msg void OnMenucheck();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMenuchecksum();
	afx_msg void OnMenudept();
	afx_msg void OnMenuhelp();
	afx_msg void OnMenuconnect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void OnCancel();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PERSONALDLG_H__34956B48_E08D_40D4_8DB8_B30B58693782__INCLUDED_)
