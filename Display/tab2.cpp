// 
// 
// 

#include "tab2.h"



tab2::tab2(Adafruit_GFX * gfx, TouchScreen * ts, CColore* colore)
	:GenericTab(gfx, ts)
{
	this->colore = colore;
	piu = new button(gfx, 200, 100, 50, 50, WHITE, BLACK, "+", ts);
	meno = NULL;// new button(gfx, 100, 100, 50, 50, WHITE, BLACK, "-", ts);
	tabs[1]->setDisabled();
}

tab2::~tab2()
{
	delete piu;
	//delete meno;
}


void tab2::draw()
{
	GenericTab::draw();
	gfx->setCursor(50, 50);
	gfx->setTextColor(BLACK);
	gfx->println("INTENSITA'");
	//gfx->println("\n  altre impostazioni.....");
	//gfx->println("\n  Coming soon...");
	piu->drawButton();
	//meno->drawButton();
}

int tab2::checkBottoni()
{
	if (piu->checkTouch())
	{
		restartTimer();
		colore->setIntensita(colore->getIntensita() + 5);
		printIntensita();
		return 30;
	}
	//else if (meno->checkTouch())
	//{
	//	restartTimer();
	//	colore->setIntensita(colore->getIntensita() - 5);
	//	printIntensita();
	//	return 20;
	//}
	return GenericTab::checkBottoni();
}

void tab2::printIntensita()
{
	gfx->fillRect(140, 80, 50, 50, WHITE);	//cancello 
	gfx->setCursor(150, 100);
	gfx->print(colore->getIntensita());
}
