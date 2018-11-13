#pragma once
#include "GenericTab.h"
#include"abstractTab.h"
class homeTab : public abstractTab
{
private:
	Adafruit_GFX* gfx;
	button* b;
public:
	homeTab(Adafruit_GFX* gfx, TouchScreen* ts);
	virtual ~homeTab();
	virtual void draw();
	virtual int checkBottoni() override;
};

