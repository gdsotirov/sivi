// SignalView.h : interface of the CSignalView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIGNALVIEW_H__D5F66EEA_AB7B_45C1_B010_34774F54BDF4__INCLUDED_)
#define AFX_SIGNALVIEW_H__D5F66EEA_AB7B_45C1_B010_34774F54BDF4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSignalView : public CView {
protected: // create from serialization only
	CSignalView();
	DECLARE_DYNCREATE(CSignalView)

// Attributes
public:
	CSignalDoc* GetDocument() const;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSignalView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSignalView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

private:
	RECT m_ClRect;
	long m_lFontHeight;

// Generated message map functions
protected:
	//{{AFX_MSG(CSignalView)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnFileAddsignal();
	afx_msg void OnUpdateFileAddsignal(CCmdUI* pCmdUI);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SignalView.cpp
inline CSignalDoc* CSignalView::GetDocument() const {
	return (CSignalDoc*)m_pDocument;
}
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIGNALVIEW_H__D5F66EEA_AB7B_45C1_B010_34774F54BDF4__INCLUDED_)
