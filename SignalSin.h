#ifdef _MSC_VER
#pragma once
#endif

#ifndef __SIVI_CSIGNALSIN_H__
#define __SIVI_CSIGNALSIN_H__

#include "signal.h"

namespace sivi {

class CSignalSin : public CSignal {
#ifdef _MSC_VER
  DECLARE_SERIAL(CSignalSin)
#endif
public:
  // Constructors/destructors
  CSignalSin(void);
  CSignalSin(double amp, double freq);
  CSignalSin(const CSignal& sig);
  virtual ~CSignalSin(void);

  // General methods
  virtual double Calc(double t);
};

} // namespace sivi

#endif // __SIVI_CSIGNALSIN_H__

