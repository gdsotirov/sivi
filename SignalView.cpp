// SignalView.cpp : implementation of the CSignalView class
//

#include "stdafx.h"
#include "sivi.h"

#include "SignalDoc.h"
#include "SignalView.h"
#include "SigPrmsDlg.h"

#include <cmath>

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
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_FILE_ADDSIGNAL, OnFileAddsignal)
	ON_UPDATE_COMMAND_UI(ID_FILE_ADDSIGNAL, OnUpdateFileAddsignal)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSignalView construction/destruction

CSignalView::CSignalView() {
}

CSignalView::~CSignalView() {
}

BOOL CSignalView::PreCreateWindow(CREATESTRUCT& cs) {
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSignalView drawing

void CSignalView::OnDraw(CDC* pDC) {
	CSignalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CString buf;
	RECT cl_rect;
	CString type;
	TEXTMETRIC tm;

	if ( pDoc->SignalsCount() > 1 )
		type = "Combined";
	else {
		if ( pDoc->GetType(0) == _T("sin") ) 
			type = "Sinusoidal";
		else if ( pDoc->GetType(0) == _T("tri") )
			type = "Triangular";
		else
			type = "Unknown";
	}

#define TEXT_OFFSET 5 // pixels

	if ( pDoc->SignalsCount() == 1 ) {
		CSignal * sig = pDoc->GetSignal(0);
		buf.Format(IDS_VIEW_INFO, type, sig->getAmplitude(), sig->getFrequency());
	}
	else
		buf.Format(IDS_VIEW_INFO_CMB, type);

	pDC->TextOut(TEXT_OFFSET, TEXT_OFFSET, buf);
	pDC->GetTextMetrics(&tm);

	// Draw coordinate system
	GetClientRect(&cl_rect);

	int center_x = cl_rect.right / 2;
	int center_y = cl_rect.bottom / 2;

	pDC->MoveTo(cl_rect.left, center_y);
	pDC->LineTo(cl_rect.right, center_y);
	pDC->MoveTo(center_x, cl_rect.top);
	pDC->LineTo(center_x, cl_rect.bottom);

	double amp_sum = pDoc->CalcAmplitude();
	if ( amp_sum != 0 ) {
		double unit_in_pixels = (center_y - tm.tmHeight - TEXT_OFFSET * 2) / amp_sum;
		double start_x_units = - (center_x - 5) / unit_in_pixels;

		CPen signal_pen(PS_SOLID, 1, RGB(255, 0, 0));
		pDC->SelectObject(&signal_pen);

		double x = start_x_units;
		while ( x < -start_x_units ) {
			double y = pDoc->Calc(x);
			int x_pix = (int)floor(x * unit_in_pixels + center_x);
			int y_pix = (int)floor(y * unit_in_pixels + center_y);

			if ( x == start_x_units )
				pDC->MoveTo(x_pix, y_pix);
			pDC->LineTo(x_pix, y_pix);

			x += 0.001;
		}
	}

	pDC->SelectStockObject(BLACK_PEN);
}

/////////////////////////////////////////////////////////////////////////////
// CSignalView printing

BOOL CSignalView::OnPreparePrinting(CPrintInfo* pInfo) {
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSignalView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/) {
	// TODO: add extra initialization before printing
}

void CSignalView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/) {
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSignalView diagnostics

#ifdef _DEBUG
void CSignalView::AssertValid() const {
	CView::AssertValid();
}

void CSignalView::Dump(CDumpContext& dc) const {
	CView::Dump(dc);
}

CSignalDoc* CSignalView::GetDocument() const { // non-debug version is inline
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSignalDoc)));
	return (CSignalDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSignalView message handlers

void CSignalView::OnLButtonDblClk(UINT nFlags, CPoint point) {
	CSignalDoc * doc = GetDocument();
	CSigPrmsDlg sig_params;

	for ( int i = 0; i < doc->SignalsCount(); ++i ) {
		sig_params.m_stype = doc->GetType(i);
		CSignal * sig = doc->GetSignal(i);
		sig_params.m_samp  = sig->getAmplitude();
		sig_params.m_sfreq = sig->getFrequency();

		if ( sig_params.DoModal() == IDOK ) {
			CString new_type = sig_params.m_stype.Mid(0, 3);
			new_type.MakeLower();
			doc->ChangeType(i, new_type);
			sig->setAmplitude(sig_params.m_samp);
			sig->setFrequency(sig_params.m_sfreq);
			doc->SetModifiedFlag();
			doc->UpdateAllViews(NULL);
		}
	}

	CView::OnLButtonDblClk(nFlags, point);
}

void CSignalView::OnFileAddsignal() {
	CSignalDoc * pDoc = GetDocument();
	CSigPrmsDlg sig_params;

	if ( sig_params.DoModal() == IDOK ) {
		CString type = sig_params.m_stype.Mid(0, 3);
		type.MakeLower();

		if ( pDoc->AddSignal(type, sig_params.m_samp, sig_params.m_sfreq) )
			AfxMessageBox(IDS_SIGNAL_ADDERR, MB_ICONERROR | MB_OK, 0);
		
		pDoc->SetModifiedFlag();
		pDoc->UpdateAllViews(NULL);
	}
}

void CSignalView::OnUpdateFileAddsignal(CCmdUI* pCmdUI) {
	pCmdUI->Enable(GetDocument()->SignalsCount() < 2);
}
