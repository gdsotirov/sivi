#include "stdafx.h"
#include "CNumericEdit.h"

BEGIN_MESSAGE_MAP(CNumericEdit, CEdit)
  //{{AFX_MSG_MAP(CNumEdit)
  ON_WM_CHAR()
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

CNumericEdit::CNumericEdit()
{
  // TODO: Get decimal separator from locale
  m_strMask.Append(m_strDecSep);
}

CNumericEdit::~CNumericEdit()
{
}

/**
 * Do not accept other characters than number or decimal separator
 */
void CNumericEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
  switch (nChar) {
    // Ignore backspace, enter, escape and tab keys
    case VK_BACK:
    case VK_RETURN:
    case VK_ESCAPE:
    case VK_TAB:
      break;
    default:
    {
      if (m_strMask.Find(nChar) < 0)
        return;
    }
  }

  CEdit::OnChar(nChar, nRepCnt, nFlags);
}
