#pragma once
#include"Adafruit_GFX.h"
#include"TouchScreen.h"
#include"RGBColors.h"


#define TS_MINX 122
#define TS_MAXX 916

#define TS_MINY 107
#define TS_MAXY 915
class button :public Adafruit_GFX_Button
{
protected:
	TouchScreen* ts;
	short x1, y1, w, h;
public:
	button(Adafruit_GFX *gfx, int x, int y, int w, int h, uint16_t colore, uint16_t coloreTesto, char *label, TouchScreen* ts);
	~button();
	virtual void drawButton();
	bool contains(int16_t x, int16_t y); //quello della libreria non va bene con lo schermo routato in orizzontale
	virtual bool checkTouch();
};

