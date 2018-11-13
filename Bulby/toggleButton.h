#pragma once
#include"button.h"
// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
class toggleButton :public button
	//, public GFXcanvas16
{
public:
	toggleButton(Adafruit_GFX *gfx, int x, int y, int w, int h, uint16_t colore, uint16_t coloreTesto, char* label, TouchScreen* ts);
	~toggleButton();
	virtual void drawButton() override;
};

