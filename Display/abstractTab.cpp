#include "abstractTab.h"
#include"RGBColors.h"


abstractTab::abstractTab(Adafruit_GFX *gfx, TouchScreen* ts)
{
	this->gfx = gfx;
	this->ts = ts;
}


abstractTab::~abstractTab()
{
}
