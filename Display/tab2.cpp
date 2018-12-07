#include "tab2.h"



tab2::tab2(Adafruit_GFX * gfx, TouchScreen * ts, CLuce* colore)
	:GenericTab(gfx, ts)
{
	this->colore = colore;
	piu = new button(gfx, 185, 100, 50, 50, WHITE, BLACK, "+", ts);
	meno = new button(gfx, 85, 100, 50, 50, WHITE, BLACK, "-", ts);
	tabs[1]->setDisabled();
}

tab2::~tab2()
{
	delete piu;
	delete meno;
}


void tab2::draw()
{
	GenericTab::draw();
	gfx->setCursor(100, 50);
	gfx->setTextColor(BLACK);
	gfx->println("INTENSITA'");
	piu->drawButton();
	meno->drawButton();
	printIntensita();
}

int tab2::checkBottoni()
{
	if (piu->checkTouch())
	{
		restartTimer();
		colore->setIntensita(colore->getIntensita() + 5);
		printIntensita();
		return PIU_BUTTON;
	}
	else if (meno->checkTouch())
	{
		restartTimer();
		colore->setIntensita(colore->getIntensita() - 5);
		printIntensita();
		return MENO_BUTTON;
	}
	return GenericTab::checkBottoni();
}

void tab2::printIntensita()
{
	gfx->fillRect(145, 100, 35, 35, WHITE);	//cancello 
	gfx->setCursor(145, 120);
	gfx->print(colore->getIntensita());
}
