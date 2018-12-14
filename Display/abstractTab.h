#pragma once
#include<Adafruit_GFX.h>
#include<TouchScreen.h>
class abstractTab
{
protected:
	Adafruit_GFX* gfx;
	TouchScreen* ts;
private:
	String id;
public:
	abstractTab(Adafruit_GFX *gfx, TouchScreen* ts,String ID);
	virtual ~abstractTab();
	virtual void draw() = 0;
	virtual int checkBottoni() = 0;
	String toString();
};

