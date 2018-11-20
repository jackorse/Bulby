// 
// 
// 

#include "tab1.h"

tab1::tab1(Adafruit_GFX* gfx, TouchScreen* ts)
	:GenericTab(gfx, ts)
{
	luce = new luceButton(gfx, 50, 70, ts);	//(gfx, 50, 50, 100, 50, 5, YELLOW, BLACK, "LUCE", 10);
	tabs[0]->setDisabled();
}

tab1::~tab1()
{
	Serial.println("deleting tab1");
	delete luce;
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
		Serial.println("luceeeee");
		restartTimer();
	}
	return GenericTab::checkBottoni();
}
