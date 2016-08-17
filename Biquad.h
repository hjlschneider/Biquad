/*
  Biquad library code is place under the MIT License
  Copyright (c) 2016 H.J.L. Schneider

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.  
  
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
