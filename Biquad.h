/*
  Adapted from the mbed library: https://developer.mbed.org/users/tomlankhorst/code/biquadFilter/
  Original code written by Tom Lankhorst
  
  Biquad.h - Library for applying biquad filters
  Created by H.J.L. Schneider, July 8, 2016
  Designed for Arduino
*/

#ifndef BIQUAD_H
#define BIQUAD_H

class Biquad {
		// constants of the filter
		const double a1, a2, b0, b1, b2;
		// storage values of the filter
		double v1, v2;
	public:
		/*
				b0 + b1 z^-1 + b2 z^-2
		H(z) = -----------------------
				a0 + a1 z^-1 + a2 z^-2
				
		a0 = 1, b0 = 1*gain, b1 = 2*gain, and b2 = 1*gain when filter is designed with ASN filter designer
		
		@param const float a1
		@param const float a2
		@param const float gain
		*/
		Biquad(const double, const double, const double);
		/*
		@param int u: input
		@return int y: output
		*/
		int filter(int);
};

#endif
