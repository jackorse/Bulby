#ifndef _TAB3_h
#define _TAB3_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include"GenericTab.h"
#include"colorButtonsSlider.h"

class tab3 :public GenericTab
{
private:
	colorButtonsSlider *slider;
	button *attivo;
	bool *acceso;

public:
	tab3(Adafruit_GFX* gfx, TouchScreen* ts, Colors* vettColori, bool* acceso);
	virtual ~tab3();
	virtual void draw() override;
	virtual int checkBottoni() override;
	int getSliderIndex();
	void reDrawSelectedColorButton();
};
#endif