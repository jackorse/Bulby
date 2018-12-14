#include "homeTab.h"



homeTab::homeTab(Adafruit_GFX * gfx, TouchScreen * ts, MyBluetooth* bt)
	:abstractTab(gfx, ts)
{
	this->bt = bt;
	Serial.println("hometab inizializzata");
}

homeTab::~homeTab()
{
	Serial.println("deleting hometab");
}

void homeTab::draw()
{
	Serial.println("disegno la home");
	gfx->fillScreen(BLACK);
	gfx->setTextSize(7);
	gfx->setCursor(60, 60);
	gfx->setTextColor(YELLOW);
	gfx->print("Bulby");
	gfx->setCursor(50, 150);
	if (bt->isConnesso())
		gfx->print("connesso");
	else
		gfx->print("non connesso");
}

int homeTab::checkBottoni()
{
	TSPoint p = ts->getPoint();
	//Serial.println("x: " + (String)p.x + " y: " +(String) p.y);
	if (p.x >= 0 && p.x <= 1023 && p.y >= 0 && p.y <= 1023 && p.z >= 100)
	{
		return 1;
	}
	return -1;
}
