#include "button.h"



button::button(Adafruit_GFX *gfx, int x, int y, int w, int h, uint16_t colore, uint16_t coloreTesto, char* label, TouchScreen* ts)
{
	x1 = y;	//invertite per lo schermo orizzontale
	y1 = x;
	this->w = w;
	this->h = h;
	this->ts = ts;
	this->initButtonUL(gfx, x, y, w, h, 5, colore, coloreTesto, label, 2);
}


button::~button()
{
}

void button::drawButton()
{
	Adafruit_GFX_Button::drawButton(true);
	while (ts->isTouching()) { Serial.println("aspetto..."); }
	Adafruit_GFX_Button::drawButton();
}

bool button::contains(int16_t x, int16_t y)
{
	return ((x >= x1) && (x < (int16_t)(x1 + h)) &&
		(y >= y1) && (y < (int16_t)(y1 + w)));
}

bool button::checkTouch()
{
	digitalWrite(13, HIGH);
	TSPoint p = ts->getPoint();
	digitalWrite(13, LOW);
	int x = p.x, y = p.y;
	x = map(x, TS_MINX, TS_MAXX, 0, 240);
	y = map(y, TS_MINY, TS_MAXY, 0, 320);

	//Serial.println((String)x + "    |      " + (String)y);
	if (p.z > 200 && contains(x, y))
	{
		Serial.println("pigiatooo");
		//press(!isPressed()) <<<< per qualche strano motivo non gli piace
		if (isPressed())
			press(false);
		else
			press(true);
		drawButton();
		return true;
	}
	return false;
}
