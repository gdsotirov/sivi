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

#include "signaltri.h"

namespace sivi {

#ifdef _MSC_VER
IMPLEMENT_SERIAL(CSignalTri, CObject, 0)
#endif

CSignalTri::CSignalTri(void) : CSignal() {
}

CSignalTri::CSignalTri(double amp = 0.0, double freq =  0.0) : CSignal(amp, freq) {
}

CSignalTri::CSignalTri(const CSignal& sig) : CSignal(sig)
{
}

CSignalTri::~CSignalTri(void) {
}

double CSignalTri::Calc(double t) {
  return amplitude * (2 / M_PI) * asin(sin(2 * M_PI * frequency * t));
}

} // namespace sivi

