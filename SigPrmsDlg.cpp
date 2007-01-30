// SigPrmsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "sivi.h"
#include "SigPrmsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSigPrmsDlg dialog


CSigPrmsDlg::CSigPrmsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSigPrmsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSigPrmsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSigPrmsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSigPrmsDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSigPrmsDlg, CDialog)
	//{{AFX_MSG_MAP(CSigPrmsDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSigPrmsDlg message handlers
