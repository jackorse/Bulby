// tab2.h

#ifndef _TAB2_h
#define _TAB2_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include"GenericTab.h"

class tab2:public GenericTab
{
 public:
	tab2(Adafruit_GFX* gfx, TouchScreen* ts);
	virtual void draw() override;
};


#endif

