#ifndef _TAB2_h
#define _TAB2_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include"GenericTab.h"
#include"CLuce.h"
#define MENO_BUTTON 20
#define PIU_BUTTON 30

class tab2:public GenericTab
{
private:
	button *piu;
	button *meno;
	CLuce *colore;

 public:
	tab2(Adafruit_GFX* gfx, TouchScreen* ts, CLuce* luce);
	virtual ~tab2();
	virtual void draw() override;
	virtual int checkBottoni() override;
	void printIntensita();
};

#endif