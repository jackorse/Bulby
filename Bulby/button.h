#pragma once
#include"Adafruit_GFX.h"
#include"TouchScreen.h"
// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF


#define TS_MINX 122
#define TS_MAXX 916

#define TS_MINY 107
#define TS_MAXY 915
class button :public Adafruit_GFX_Button
{
protected:
	TouchScreen* ts;
private:
	int x1, y1, w, h;
public:
	button(Adafruit_GFX *gfx, int x, int y, int w, int h, uint16_t colore, uint16_t coloreTesto, char *label, TouchScreen* ts);
	~button();
	virtual void drawButton();
	bool contains(int16_t x, int16_t y); //quello della libreria non va bene con lo schermo routato in orizzontale
	virtual bool checkTouch();
};

