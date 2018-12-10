#pragma once
#include"button.h"

class toggleButton :public button
	//, public GFXcanvas16
{
public:
	toggleButton(Adafruit_GFX *gfx, int x, int y, int w, int h, uint16_t colore, uint16_t coloreTesto, char* label, TouchScreen* ts);
	~toggleButton();
	virtual void drawButton() override;
};

