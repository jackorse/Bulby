#include "toggleButton.h"



toggleButton::toggleButton(Adafruit_GFX *gfx, int x, int y, int w, int h, uint16_t colore, uint16_t coloreTesto, char* label, TouchScreen* ts)
	: button(gfx, x, y, w, h, colore, coloreTesto, label, ts)
	//:GFXcanvas16(w, h), Adafruit_GFX_Button()
{
}


toggleButton::~toggleButton()
{
}

void toggleButton::drawButton()
{
	while (ts->isTouching());
	if (isPressed()) {
		Adafruit_GFX_Button::drawButton(false);
		Serial.println("acceso");
	}
	else if (!isPressed()) {
		Serial.println("spento");
		Adafruit_GFX_Button::drawButton(true);
	}
}


