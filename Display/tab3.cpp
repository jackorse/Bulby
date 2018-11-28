// 
// 
// 

#include "tab3.h"

tab3::tab3(Adafruit_GFX * gfx, TouchScreen * ts, Colors* vettColori)
	:GenericTab(gfx, ts)
{
	slider = new colorButtonsSlider(gfx, ts, vettColori);
	tabs[2]->setDisabled();
}

tab3::~tab3()
{
	delete slider;
}

void tab3::draw()
{
	GenericTab::draw();
	gfx->setCursor(50, 50);
	gfx->setTextColor(BLACK);
	gfx->println("COLORE");
	slider->draw();
	//gfx->println("\n  altre impostazioni.....");
	//gfx->println("\n  Coming soon...");
}

int tab3::checkBottoni()
{
	int ris = slider->checkTouch();
	if (ris != -1)
		return ris;
	else
		return GenericTab::checkBottoni();
}
