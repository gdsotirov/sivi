#include "Stdafx.h"
#include "signal.h"

namespace sivi {

// Constructors/Destructors
CSignal::CSignal() : amplitude(0.0), frequency(0.0) {
}

CSignal::CSignal(double amp, double freq) : amplitude(amp), frequency(freq) {
}

CSignal::CSignal(const CSignal& sig) {
	amplitude = sig.getAmplitude();
	frequency = sig.getFrequency();
}

CSignal::~CSignal(void) {
}

#ifdef _MSC_VER
// Serialization
void CSignal::Serialize(CArchive &ar) {
	if ( ar.IsStoring() ) {
		ar << amplitude << frequency;
	}
	else {
		ar >> amplitude >> frequency;
	}
}
#endif

} // namespace sivi
