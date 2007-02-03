// SignalDoc.h : interface of the CSignalDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIGNALDOC_H__D9F7BA07_F444_48AF_85E0_DA27C1B21B94__INCLUDED_)
#define AFX_SIGNALDOC_H__D9F7BA07_F444_48AF_85E0_DA27C1B21B94__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "signal.h"
#include "signalsin.h"
#include "signaltri.h"

using sivi::CSignal;
using sivi::CSignalSin;
using sivi::CSignalTri;

class CSignalDoc : public CDocument {
protected: // create from serialization only
	CSignalDoc();
	DECLARE_DYNCREATE(CSignalDoc)

// Attributes
private:
	CObArray m_aSignals;

// Attributes
public:
	CSignal * GetSignal(int number) const;
	int SignalsCount(void) const;
	CString GetType(int number) const;

// Operations
public:
	int ChangeType(int number, CString type);
	int AddSignal(CString type, double amp, double freq);
	double CalcAmplitude(void);
	double Calc(double x);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSignalDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSignalDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSignalDoc)
	afx_msg void OnUpdateFileSave(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIGNALDOC_H__D9F7BA07_F444_48AF_85E0_DA27C1B21B94__INCLUDED_)
