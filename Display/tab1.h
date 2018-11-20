// tab1.h

#ifndef _TAB1_h
#define _TAB1_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include"GenericTab.h"
#include"luceButton.h"

class tab1 : public GenericTab
{
private:
	luceButton* luce;
 public:
	tab1(Adafruit_GFX* gfx, TouchScreen* ts);
	virtual ~tab1();
	virtual void draw() override;
	virtual int checkBottoni() override;
};

#endif
