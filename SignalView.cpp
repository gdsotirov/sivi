// SignalView.cpp : implementation of the CSignalView class
//

#include "stdafx.h"
#include "sivi.h"

#include "SignalDoc.h"
#include "SignalView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSignalView

IMPLEMENT_DYNCREATE(CSignalView, CView)

BEGIN_MESSAGE_MAP(CSignalView, CView)
	//{{AFX_MSG_MAP(CSignalView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSignalView construction/destruction

CSignalView::CSignalView()
{
	// TODO: add construction code here

}

CSignalView::~CSignalView()
{
}

BOOL CSignalView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSignalView drawing

void CSignalView::OnDraw(CDC* pDC)
{
	CSignalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSignalView printing

BOOL CSignalView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSignalView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSignalView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSignalView diagnostics

#ifdef _DEBUG
void CSignalView::AssertValid() const
{
	CView::AssertValid();
}

void CSignalView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSignalDoc* CSignalView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSignalDoc)));
	return (CSignalDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSignalView message handlers
