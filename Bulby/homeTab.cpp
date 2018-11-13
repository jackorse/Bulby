#include "homeTab.h"





homeTab::homeTab(Adafruit_GFX * gfx, TouchScreen * ts)
{
	this->gfx = gfx;
	this->b = new button(gfx, 110, 150, 100, 50, WHITE, BLACK,"OPZIONI", ts);
}

homeTab::~homeTab()
{
	Serial.println("deleting hometab");
	delete b;
}

void homeTab::draw()
{
	Serial.println("disegno la home");
	gfx->fillScreen(BLACK);
	gfx->setTextSize(7);
	gfx->setCursor(60, 60);
	gfx->setTextColor(YELLOW);
	gfx->print("Bulby");
	b->drawButton();
}

int homeTab::checkBottoni()
{
	if (b->checkTouch())
		return 1;
	else return -1;
}
