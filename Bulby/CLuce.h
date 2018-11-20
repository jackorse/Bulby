// CLuce.h

#ifndef _CLUCE_h
#define _CLUCE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class CLuceClass
{
 protected:


 public:
	void init();
};

extern CLuceClass CLuce;

#endif

