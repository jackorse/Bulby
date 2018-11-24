#include "homeTab.h"





homeTab::homeTab(Adafruit_GFX * gfx, TouchScreen * ts)
{
	this->ts = ts;
	this->gfx = gfx;
	//this->b = new button(gfx, 110, 150, 100, 50, WHITE, BLACK,"OPZIONI", ts);
}

homeTab::~homeTab()
{
	Serial.println("deleting hometab");
	//delete b;
}

void homeTab::draw()
{
	Serial.println("disegno la home");
	gfx->fillScreen(BLACK);
	gfx->setTextSize(7);
	gfx->setCursor(60, 60);
	gfx->setTextColor(YELLOW);
	gfx->print("Bulby");
	//b->drawButton();
}

int homeTab::checkBottoni()
{
	TSPoint p = ts->getPoint();
	Serial.println("x: " + (String)p.x + " y: " +(String) p.y);
	if (p.x >= 0 && p.x <= 1023 && p.y >= 0 && p.y <= 1023 && p.z >= 100)
		return 1;
	return -1;
	//if (b->checkTouch())
	//	return 1;
	//else return -1;
}
