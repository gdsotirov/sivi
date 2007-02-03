#if !defined(AFX_SIGPRMSDLG_H__29859502_9E66_4D6B_BE75_77D99905BD6F__INCLUDED_)
#define AFX_SIGPRMSDLG_H__29859502_9E66_4D6B_BE75_77D99905BD6F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SigPrmsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSigPrmsDlg dialog

class CSigPrmsDlg : public CDialog {
// Construction
public:
	CSigPrmsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSigPrmsDlg)
	enum { IDD = IDD_SIGPARAMS };
	CString m_stype;
	double  m_samp;
	double  m_sfreq;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSigPrmsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSigPrmsDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIGPRMSDLG_H__29859502_9E66_4D6B_BE75_77D99905BD6F__INCLUDED_)
