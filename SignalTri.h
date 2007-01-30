#ifdef _MSC_VER
#pragma once
#endif

#ifndef __SIVI_CSIGNALTRI_H__
#define __SIVI_CSIGNALTRI_H__

#include "signal.h"

namespace sivi {

class CSignalTri : public CSignal {
#ifdef _MSC_VER
	DECLARE_SERIAL(CSignalTri)
#endif
public:
	// Constructors/destructors
	CSignalTri(void);
	CSignalTri(double amp, double freq);
	virtual ~CSignalTri(void);

	// General methods
	virtual double Calc(double t);
};

} // namespace sivi

#endif // __SIVI_CSIGNALTRI_H__
