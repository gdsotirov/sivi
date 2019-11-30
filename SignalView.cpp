// SignalView.cpp : implementation of the CSignalView class
//

#include "stdafx.h"
#include "sivi.h"

#include "MainFrm.h"
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
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_VIEW_ZOOM_ZOOMIN, OnViewZoomIn)
	ON_COMMAND(ID_VIEW_ZOOM_ZOOMOUT, OnViewZoomOut)
	ON_COMMAND(ID_VIEW_ZOOM_ORIGINALSIZE, OnViewOriginalSize)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOM_ZOOMOUT, OnUpdateViewZoomOut)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOM_ORIGINALSIZE, OnUpdateViewOriginalSize)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSignalView construction/destruction

CSignalView::CSignalView() {
	m_iZoomFactor = 1;
	m_ClRect = { 0, 0, 0, 0 };
	m_lFontHeight = 0;
	m_dPixPerUnitX = 1.0;
	m_dPixPerUnitY = 1.0;
	m_iCenterX = 0;
	m_iCenterY = 0;
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
	m_lFontHeight = tm.tmHeight;

	// Draw coordinate system
	GetClientRect(&m_ClRect);

	m_iCenterX = m_ClRect.right / 2;
	m_iCenterY = m_ClRect.bottom / 2;

	pDC->MoveTo(m_ClRect.left, m_iCenterY);
	pDC->LineTo(m_ClRect.right, m_iCenterY);
	pDC->MoveTo(m_iCenterX, m_ClRect.top);
	pDC->LineTo(m_iCenterX, m_ClRect.bottom);

	double amp_sum = pDoc->CalcAmplitude();
	if ( amp_sum != 0 ) {
		m_dPixPerUnitY = ((double)m_iCenterY - (double)m_lFontHeight - (double)(TEXT_OFFSET * 2)) / amp_sum;
		m_dPixPerUnitX = m_dPixPerUnitY;

		double start_x_units = - m_iCenterX / m_dPixPerUnitX;

		if ( m_iZoomFactor != 1 ) {
			m_dPixPerUnitX *= m_iZoomFactor;
			start_x_units /= m_iZoomFactor;
		}

		CString number;

		// Draw numbers on the y axis
		double y_unit = -amp_sum;
		while ( y_unit <= amp_sum ) {
			if ( y_unit != 0 ) {
				int y_pix = (y_unit > 0) ? m_iCenterY - (int)(fabs(y_unit) * m_dPixPerUnitY) : m_iCenterY + (int)(fabs(y_unit) * m_dPixPerUnitY);

				pDC->MoveTo(m_iCenterX - 2, y_pix);
				pDC->LineTo(m_iCenterX + 2, y_pix);
				number.Format("%.2f", y_unit);
				pDC->TextOut(m_iCenterX + 5, y_pix - (m_lFontHeight / 2), number);
			}

			y_unit += 1.0;
		}

		// Draw numbers on the x axis
		double x_unit = 0.0;
		while ( x_unit > start_x_units ) {
			if ( x_unit < 0.0 ) {
				int x_pix = m_iCenterX - (int)(fabs(x_unit) * m_dPixPerUnitX);

				pDC->MoveTo(x_pix, m_iCenterY - 2);
				pDC->LineTo(x_pix, m_iCenterY + 2);
				number.Format("%.3f", x_unit);
				pDC->TextOut(x_pix - (m_lFontHeight / 2), m_iCenterY + 5, number);
			}

			x_unit -= 1.0 / m_iZoomFactor;
		}
		while ( x_unit < -start_x_units ) {
			if ( x_unit > 0 ) {
				int x_pix = m_iCenterX + (int)(fabs(x_unit) * m_dPixPerUnitX);

				pDC->MoveTo(x_pix, m_iCenterY - 2);
				pDC->LineTo(x_pix, m_iCenterY + 2);
				number.Format("%.3f", x_unit);
				pDC->TextOut(x_pix - (m_lFontHeight / 2), m_iCenterY + 5, number);
			}

			x_unit += 1.0 / m_iZoomFactor;
		}
				
		CPen signal_pen(PS_SOLID, 1, RGB(255, 0, 0));
		pDC->SelectObject(&signal_pen);

		double x = start_x_units;
		while ( x <= -start_x_units ) {
			double y = pDoc->Calc(x);
			int x_pix = (int)floor(x * m_dPixPerUnitX + m_iCenterX);
			int y_pix = (int)floor(y * m_dPixPerUnitY + m_iCenterY);

			if ( x == start_x_units )
				pDC->MoveTo(x_pix, y_pix);
			pDC->LineTo(x_pix, y_pix);

			x += 1 / m_dPixPerUnitX;
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
	CSignalDoc * pDoc = GetDocument();
	CSigPrmsDlg sig_params;

	for ( int i = 0; i < pDoc->SignalsCount(); ++i ) {
		sig_params.m_stype = pDoc->GetType(i);
		CSignal * pSig = pDoc->GetSignal(i);
		sig_params.m_samp  = pSig->getAmplitude();
		sig_params.m_sfreq = pSig->getFrequency();

		if ( sig_params.DoModal() == IDOK ) {
			CString new_type = sig_params.m_stype.Mid(0, 3);
			new_type.MakeLower();
			pDoc->ChangeType(i, new_type);
			pSig->setAmplitude(sig_params.m_samp);
			pSig->setFrequency(sig_params.m_sfreq);
			pDoc->SetModifiedFlag();
			pDoc->UpdateAllViews(NULL);
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

void CSignalView::OnMouseMove(UINT nFlags, CPoint point) {
	CString buf;
	CSignalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CMainFrame * pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	ASSERT_VALID(pFrame);
	CStatusBar * pStatus = pFrame->GetStatusBar();
	ASSERT_VALID(pStatus);

	double amp_sum = pDoc->CalcAmplitude();
	if ( amp_sum > 0 ) {
		double x_unit = ((double)point.x - (double)m_iCenterX) / m_dPixPerUnitX;
		double y_unit = - (point.y - m_iCenterY) / m_dPixPerUnitY;
		buf.Format(IDS_COORDINATES, x_unit, y_unit);
		pStatus->SetPaneText(0, buf);
	}

	CView::OnMouseMove(nFlags, point);
}

void CSignalView::OnViewZoomIn() {
	CSignalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	m_iZoomFactor *= 2;

	pDoc->UpdateAllViews(NULL);
}

void CSignalView::OnViewZoomOut() {
	CSignalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if ( m_iZoomFactor > 1 )
		m_iZoomFactor /= 2;

	pDoc->UpdateAllViews(NULL);
}

void CSignalView::OnViewOriginalSize() {
	CSignalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	m_iZoomFactor = 1;

	pDoc->UpdateAllViews(NULL);
}

void CSignalView::OnUpdateViewZoomOut(CCmdUI* pCmdUI) {
	pCmdUI->Enable(m_iZoomFactor != 1);
}

void CSignalView::OnUpdateViewOriginalSize(CCmdUI* pCmdUI) {
	pCmdUI->Enable(m_iZoomFactor != 1);	
}
