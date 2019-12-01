#pragma once
#include <afxwin.h>

/**
 * A CEdit control that accepts only numbers (including decimal)
 */
class CNumericEdit : public CEdit
{
private:
  CString m_strMask = "0123456789";
  CString m_strDecSep = _T("."); // decimal separator

public:
  CNumericEdit();
  virtual ~CNumericEdit();

protected:
  //{{AFX_MSG(CNumEdit
  afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
  //}}AFX_MSG

  DECLARE_MESSAGE_MAP()
};

