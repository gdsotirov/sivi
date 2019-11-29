#include "stdafx.h"
#ifdef _MSC_VER
#define _USE_MATH_DEFINES // for math constants
#endif
#include <cmath>

/* It looks like that math defines are not allways availiable in Microsoft
 * include files, so we will define what we need just in case.
 */
#ifndef M_PI
#define M_PI 3.14159265358979323846 /* pi */
#endif

#include "signalsin.h"

namespace sivi {

#ifdef _MSC_VER
IMPLEMENT_SERIAL(CSignalSin, CObject, 0)
#endif

CSignalSin::CSignalSin() : CSignal() {
}

CSignalSin::CSignalSin(double amp, double freq) : CSignal(amp, freq) {
}

CSignalSin::~CSignalSin(void) {
}

double CSignalSin::Calc(double t) {
	return amplitude * sin(2 * M_PI * frequency * t);
}

} // namespace sivi
