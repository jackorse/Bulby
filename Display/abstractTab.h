#pragma once
#include<Adafruit_GFX.h>
#include<TouchScreen.h>
class abstractTab
{
protected:
	Adafruit_GFX* gfx;
	TouchScreen* ts;
public:
	abstractTab(Adafruit_GFX *gfx, TouchScreen* ts);
	virtual ~abstractTab();
	virtual void draw() = 0;
	virtual int checkBottoni() = 0;
};

