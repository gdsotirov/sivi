#ifdef _MSC_VER
#pragma once
#endif

#ifndef __SIVI_CSIGNAL_H__
#define __SIVI_CSIGNAL_H__

#ifdef _MSC_VER
#include "stdafx.h"
#endif

namespace sivi {

#ifdef _MSC_VER
class CSignal : public CObject {
#else
class CSignal
#endif

public:
	// Constructors/destructors
	CSignal(void);
	CSignal(double amp, double freq);
	CSignal(const CSignal& sig);
	~CSignal(void);

	// Get/Set methods
	double getAmplitude (void) const;
	void   setAmplitude (double amp);
	double getPeriode   (void) const;
	void   setPeriode   (double per);
	double getFrequency (void) const;
	void   setFrequency (double freq);

#ifdef _MSC_VER
	// Serialization only when used with MFC
	virtual void Serialize(CArchive &ar);
#endif

	// Operators
	const CSignal& operator =(const CSignal& sig);
	BOOL operator ==(const CSignal& sig) const;
	BOOL operator !=(const CSignal& sig) const;

	// General methods
	virtual double Calc(double x) = 0;
protected:
	double amplitude;
	double frequency;
};

// Get/Set
inline double CSignal::getAmplitude(void) const {
	return amplitude;
}

inline void CSignal::setAmplitude(double amp) {
	amplitude = amp;
}

inline double CSignal::getPeriode(void) const {
	return 1 / frequency;
}

inline void CSignal::setPeriode(double per) {
	frequency = 1 / per;
}

inline double CSignal::getFrequency(void) const {
	return frequency;
}

inline void CSignal::setFrequency(double freq) {
	frequency = freq;
}

// Operators
inline const CSignal& CSignal::operator =(const CSignal& sig) {
	amplitude = sig.getAmplitude();
	frequency = sig.getFrequency();

	return *this;
}

inline BOOL CSignal::operator ==(const CSignal& sig) const {
	return (amplitude == sig.amplitude && frequency == sig.frequency);
}

inline BOOL CSignal::operator !=(const CSignal& sig) const {
	return !(*this == sig);
}

} // namespace sivi

#endif // __SIVI_CSIGNAL_H__
