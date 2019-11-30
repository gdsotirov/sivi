// sivi.h : main header file for the SIVI application
//

#if !defined(AFX_SIVI_H__C3549897_182F_4C75_9DA0_9BD2302679C3__INCLUDED_)
#define AFX_SIVI_H__C3549897_182F_4C75_9DA0_9BD2302679C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
  #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSiviApp:
// See sivi.cpp for the implementation of this class
//

class CSiviApp : public CWinApp
{
public:
  CSiviApp();

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CSiviApp)
public:
  virtual BOOL InitInstance();
  //}}AFX_VIRTUAL

// Implementation
  //{{AFX_MSG(CSiviApp)
  afx_msg void OnAppAbout();
    // NOTE - the ClassWizard will add and remove member functions here.
    //    DO NOT EDIT what you see in these blocks of generated code !
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIVI_H__C3549897_182F_4C75_9DA0_9BD2302679C3__INCLUDED_)
