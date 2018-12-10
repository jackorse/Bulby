#pragma once
#include"abstractTab.h"
#include"RGBColors.h"
class homeTab : public abstractTab
{
public:
	homeTab(Adafruit_GFX* gfx, TouchScreen* ts);
	virtual ~homeTab();
	virtual void draw();
	virtual int checkBottoni() override;
};