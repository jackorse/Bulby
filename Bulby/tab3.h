// tab3.h

#ifndef _TAB3_h
#define _TAB3_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include"GenericTab.h"

class tab3 :public GenericTab
{
public:
	tab3(Adafruit_GFX* gfx, TouchScreen* ts);
	virtual void draw() override;
};


#endif

