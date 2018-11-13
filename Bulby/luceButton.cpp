// 
// 
// 

#include "luceButton.h"

luceButton::luceButton(Adafruit_GFX * gfx, int x, int y, TouchScreen * ts)
	:toggleButton(gfx, x, y, 150, 50, YELLOW, BLUE, "LUCE", ts)
{
}

void luceButton::drawButton()
{
	if (isPressed())
		setLabel("LUCE: ON");
	else
		setLabel("LUCE: OFF");
	toggleButton::drawButton();
}
