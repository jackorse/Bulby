// 
// 
// 

#include "tab2.h"



tab2::tab2(Adafruit_GFX * gfx, TouchScreen * ts)
	:GenericTab(gfx, ts)
{
	tabs[1]->setDisabled();
}


void tab2::draw()
{
	GenericTab::draw();
	gfx->setCursor(50,50);
	gfx->setTextColor(BLACK);
	gfx->println("TAB2");
	gfx->println("\n  altre impostazioni.....");
	gfx->println("\n  Coming soon...");
}
