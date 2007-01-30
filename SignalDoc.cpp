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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSignalDoc construction/destruction

CSignalDoc::CSignalDoc()
{
	// TODO: add one-time construction code here

}

CSignalDoc::~CSignalDoc()
{
}

BOOL CSignalDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSignalDoc serialization

void CSignalDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSignalDoc diagnostics

#ifdef _DEBUG
void CSignalDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSignalDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSignalDoc commands
