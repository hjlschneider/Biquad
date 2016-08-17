#include "Biquad.h"

Biquad::Biquad(const double a1_, const double a2_, const double gain_) :
	a1(a1_), a2(a2_), b0(gain_), b1(2*gain_), b2(gain_), v1(0), v2(0) {};
	
int Biquad::filter(int u) {
	double v = u - a1*v1 - a2*v2;
	int y = b0*v + b1*v1 + b2*v2;
	v2 = v1;
	v1 = v;
	return y;
};