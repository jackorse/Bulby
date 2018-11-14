// luceButton.h

#ifndef _LUCEBUTTON_h
#define _LUCEBUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#include "toggleButton.h"
class luceButton : public toggleButton
{
public:
	luceButton(Adafruit_GFX *gfx, int x, int y, TouchScreen* ts);
	virtual void drawButton() override;
};
#endif

