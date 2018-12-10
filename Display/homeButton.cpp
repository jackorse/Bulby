#include "homeButton.h"



homeButton::homeButton(Adafruit_GFX *gfx, TouchScreen*ts, int x, int y)
	:button(gfx, x, y, 80, 30, WHITE, BLACK, "HOME", ts)
{
}


homeButton::~homeButton()
{
}

void homeButton::drawButton()
{
	Adafruit_GFX_Button::drawButtonSquadrato(true);
	while (ts->isTouching());
	Adafruit_GFX_Button::drawButtonSquadrato();
}
