#include "tab1.h"

tab1::tab1(Adafruit_GFX* gfx, TouchScreen* ts, bool *accesa)
	:GenericTab(gfx, ts)
{
	GenericTab::disableTabButton(0);
	this->accesa = *accesa;
	luce = new luceButton(gfx, 85, 70, ts);	//(gfx, 50, 50, 100, 50, 5, YELLOW, BLACK, "LUCE", 10);

	if (this->accesa)
	{
		luce->press(true);
	}
	else
	{
		luce->press(false);
	}
}

tab1::~tab1()
{
	Serial.println("deleting tab1");
	if(luce) delete luce;
}

void tab1::draw()
{
	GenericTab::draw();
	luce->drawButton();
	Serial.println("tab1 disegnata");
}

int tab1::checkBottoni()
{
	if (luce->checkTouch()) 
	{
		restartTimer();
		return LUCE_BUTTON;
	}
	return GenericTab::checkBottoni();
}