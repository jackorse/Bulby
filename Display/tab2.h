// tab2.h

#ifndef _TAB2_h
#define _TAB2_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include"GenericTab.h"
#include"CColore.h"

class tab2:public GenericTab
{
private:
	button *piu;
	button *meno;
	CColore *colore;
 public:
	tab2(Adafruit_GFX* gfx, TouchScreen* ts, CColore* colore);
	virtual ~tab2();
	virtual void draw() override;
	virtual int checkBottoni() override;
	void printIntensita();
};


#endif

