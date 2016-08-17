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
  
  This code is written for Arduino
*/  
  

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
