// SignalDoc.cpp : implementation of the CSignalDoc class
//

#include "stdafx.h"
#include "sivi.h"

#include "SignalDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSignalDoc

IMPLEMENT_DYNCREATE(CSignalDoc, CDocument)

BEGIN_MESSAGE_MAP(CSignalDoc, CDocument)
	//{{AFX_MSG_MAP(CSignalDoc)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSignalDoc construction/destruction

CSignalDoc::CSignalDoc() {
}

CSignalDoc::~CSignalDoc() {
	for ( int i = 0; i < m_aSignals.GetCount(); ++i )
		delete m_aSignals.GetAt(i);

	m_aSignals.RemoveAll();
}

BOOL CSignalDoc::OnNewDocument() {
	if (!CDocument::OnNewDocument())
		return FALSE;

	CSignal * new_sig = new CSignalSin();
	m_aSignals.Add(new_sig);

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSignalDoc serialization

void CSignalDoc::Serialize(CArchive& ar) {
	m_aSignals.Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CSignalDoc diagnostics

#ifdef _DEBUG
void CSignalDoc::AssertValid() const {
	CDocument::AssertValid();
}

void CSignalDoc::Dump(CDumpContext& dc) const {
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSignalDoc commands

void CSignalDoc::OnUpdateFileSave(CCmdUI* pCmdUI) {
	pCmdUI->Enable(IsModified());
}

CSignal * CSignalDoc::GetSignal(int number) const {
	return (CSignal *)m_aSignals.GetAt(number);
}

int CSignalDoc::SignalsCount(void) const {
	return (int)m_aSignals.GetSize();
}

CString CSignalDoc::GetType(int number) const {
	CSignal * obj = (CSignal *)m_aSignals.GetAt(number);

	if ( CSignalSin * sig = dynamic_cast<CSignalSin *>(obj) ) {
		return _T("sin");
	}

	if ( CSignalTri * sig = dynamic_cast<CSignalTri *>(obj) ) {
		return _T("tri");
	}

	return _T("unknown");
}

int CSignalDoc::ChangeType(int number, CString new_type) {
	if ( GetType(number) != new_type ) {
		CSignal * sig = (CSignal *)m_aSignals.GetAt(number);
		delete sig;
		sig = NULL;
		if ( new_type == _T("tri") )
			sig = new CSignalTri;
		else
			sig = new CSignalSin;
		m_aSignals.SetAt(number, sig);
	}
	return 0;
}

int CSignalDoc::AddSignal(CString type, double amp, double freq) {
	CSignal * new_sig = NULL;

	if ( type == _T("sin") ) {
		new_sig = new CSignalSin(amp, freq);
		m_aSignals.Add(new_sig);
		return 0;
	}
	else if ( type = _T("tri") ) {
		new_sig = new CSignalTri(amp, freq);
		m_aSignals.Add(new_sig);
		return 0;
	}

	return -1;
}

double CSignalDoc::CalcAmplitude(void) {
	double sum = 0.0;

	for ( int i = 0; i < m_aSignals.GetSize(); ++i ) {
		sum += ((CSignal *)m_aSignals.GetAt(i))->getAmplitude();
	}

	return sum;
}

double CSignalDoc::Calc(double x) {
	double y = 0.0;

	for ( int i = 0; i < m_aSignals.GetSize(); ++i ) {
		y += -((CSignal *)m_aSignals.GetAt(i))->Calc(x);
	}

	return y;
}
