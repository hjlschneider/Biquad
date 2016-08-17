/*
This code shows how to implement a filter made with ASN filter designer. 
By using this filter it is important to measure the output of a function 
or sensor with a certain frequency, which is shown in this code. It is 
also important to be able to analyze the output in programs like matlab.
This can be done by using putty to save the log as a csv file and import 
this file in matlab.
*/

#include "Biquad.h"

/*
  ASN Filter Designer Demo v3.1.0
  Fri, 08 Jul 2016 14:36:12 GMT

  ** Primary Filter (H1)**
  Filter Arithmetic = Floating Point (Double Precision)
  Architecture = IIR
  Structure = Direct Form II Transposed
  Response = Lowpass
  Method = Butterworth
  Biquad = Yes
  Stable = Yes
  Sampling Frequency = 100Hz
  Filter Order = 6

  Band  Frequencies (Hz)    Att/Ripple (dB)
  1     0, 2                0.001       
  2     5, 50               80.000      

  Biquad #1
  Gain = 0.006264
  B = [ 1.00000000000,  2.00000000000,  1.00000000000]
  A = [ 1.00000000000, -1.69260283681,  0.71765695723]

  Biquad #2
  Gain = 0.006510
  B = [ 1.00000000000,  2.00000000000,  1.00000000000]
  A = [ 1.00000000000, -1.75914568009,  0.78518477606]

  Biquad #3
  Gain = 0.006985
  B = [ 1.00000000000,  2.00000000000,  1.00000000000]
  A = [ 1.00000000000, -1.88768514092,  0.91562689418] 
*/

// make biquads
Biquad biquad1(-1.69260283681, 0.71765695723, 0.006264);	// biquad(a1, a2, gain)
Biquad biquad2(-1.75914568009, 0.78518477606, 0.006510);	// biquad(a1, a2, gain)
Biquad biquad3(-1.88768514092, 0.91562689418, 0.006985); 	// biquad(a1, a2, gain)

// time variables
#define DELTA_T 10 // 10 ms
unsigned long _oldtime;		// this is the last time that the loop started
unsigned int _printTimer;	// this timer counts how many times delta_T went by

// Measured values
int Measurement;			// This are the measurements that need to be filtered
int filteredMeasurement		// This are the filtered measurements

void setup(){
	Serial.begin(115200);
	// it is important to print time and filtered information so it can be analyzed with the help of programs like matlab
	// by using putty it is possible to save the printed values
	_oldtime = millis();
}

void loop(){
	// every 10 ms we want to perform some actions, this is important because the measurements need to be done with a certain frequency, in this example is the frequency 100Hz
	if (millis() - _oldtime >= DELTA_T) {
		old_time = millis();
		// run programs that will give you the values that need to be filtered
		int y1 = biquad1.filter(Measurement);
		int y2 = biquad2.filter(y1);
		int y3 = biquad3.filter(y2);
		filteredMeasurement = y3;
		
		// we also want to print the values, but by doing this with a lower frequency it won't slow down the program too much, in this example the printing is done with a frequency of 10Hz
		if (printTimer >= 10) {
			Serial.print(_oldtime); Serial.print(", "); Serial.println(filteredMeasurement);
		} else {printTimer++;}
	}
}
