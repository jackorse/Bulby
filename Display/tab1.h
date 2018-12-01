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
#define LUCE_BUTTON 10
class tab1 : public GenericTab
{
private:
	luceButton* luce;
	bool accesa;
 public:
	tab1(Adafruit_GFX* gfx, TouchScreen* ts, bool *accesa);
	virtual ~tab1();
	virtual void draw() override;
	virtual int checkBottoni() override;
};

#endif

