// 
// 
// 

#include "tab2.h"



tab2::tab2(Adafruit_GFX * gfx, TouchScreen * ts)
	:GenericTab(gfx, ts)
{
	//piu = new button(gfx, 100, 100, 50, 50, WHITE, BLACK, "+", ts);
	//meno = new button(gfx, 200, 100, 50, 50, WHITE, BLACK, "-", ts);
	//intensita = 100;
	tabs[1]->setDisabled();
}

tab2::~tab2()
{
	//delete piu;
	//delete meno;
}


void tab2::draw()
{
	GenericTab::draw();
	gfx->setCursor(50,50);
	gfx->setTextColor(BLACK);
	gfx->println("INTENSITA'");
	//gfx->println("\n  altre impostazioni.....");
	//gfx->println("\n  Coming soon...");
	//gfx->setCursor(150, 100);
	//gfx->print(intensita);
	//piu->drawButton();
	//meno->drawButton();
}

int tab2::checkBottoni()
{
	/*if (piu->checkTouch())
	{
		Serial.println("piuuuuu");
		intensita += 5;
		return 20;
	}
	else if (meno->checkTouch())
	{
		Serial.println("meno");
		intensita -= 5;
		return 30;
	}*/
	 return GenericTab::checkBottoni();
}
