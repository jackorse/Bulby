// 
// 
// 

#include "tab3.h"

tab3::tab3(Adafruit_GFX * gfx, TouchScreen * ts)
	:GenericTab(gfx, ts)
{
	tabs[2]->setDisabled();
}

void tab3::draw()
{
	GenericTab::draw();
	gfx->setCursor(50, 50);
	gfx->setTextColor(BLACK);
	gfx->println("TAB3");
	gfx->println("\n  altre impostazioni.....");
	gfx->println("\n  Coming soon...");
}
