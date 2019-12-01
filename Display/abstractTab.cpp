#include "abstractTab.h"
#include"RGBColors.h"


abstractTab::abstractTab(Adafruit_GFX *gfx, TouchScreen* ts,String ID)
{
	this->gfx = gfx;
	this->ts = ts;
	this->id = ID;
}


abstractTab::~abstractTab()
{
}

String abstractTab::toString()
{
	return id;
}
