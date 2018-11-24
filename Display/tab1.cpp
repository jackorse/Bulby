// 
// 
// 

#include "tab1.h"

tab1::tab1(Adafruit_GFX* gfx, TouchScreen* ts, bool *accesa)
	:GenericTab(gfx, ts)
{
	this->accesa = accesa;
	luce = new luceButton(gfx, 50, 70, ts);	//(gfx, 50, 50, 100, 50, 5, YELLOW, BLACK, "LUCE", 10);
	tabs[0]->setDisabled();
	if (accesa)
		luce->press(true);
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
		restartTimer();
		return 10;
	}
	return GenericTab::checkBottoni();
}

