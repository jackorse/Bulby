#include "tab3.h"

tab3::tab3(Adafruit_GFX * gfx, TouchScreen * ts, Colors* vettColori)
	:GenericTab(gfx, ts)
{
	slider = new colorButtonsSlider(gfx, ts, vettColori);
	attivo = new button(gfx, 140,35, 50, 50, colorButtonsSlider::getColore(vettColori->getAttivo()->getColore()), WHITE, "", ts);
	tabs[2]->setDisabled();
	this->ts = ts;
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
	attivo->drawButton();
	slider->draw();
}

int tab3::checkBottoni()
{
	int ris = slider->checkTouch();
	switch (ris)
	{
	case SINISTRA_BUTTON:
		restartTimer();
		if (slider->getIndex() - 3 >= 0)
			slider->setIndex(slider->getIndex() - 3);
		else
			slider->setIndex(0);
		slider->draw();
		return -1;
	case  DESTRA_BUTTON:
		restartTimer();
		if (slider->getIndex() + 3 < NUMCOLORI)
			slider->setIndex(slider->getIndex() + 3);
		slider->draw();
		return -1;
	case -1:
		return GenericTab::checkBottoni();
	default:
		restartTimer();
		return ris;
	}
}

int tab3::getSliderIndex()
{
	return slider->getIndex();
}

void tab3::reDrawSelectedColorButton()
{
	delete attivo;
	if (slider->getVettColor()->getAttivo()->getIndex() == 16)
	{
		attivo = new button(gfx, 140, 35, 50, 50, colorButtonsSlider::getColore(slider->getVettColor()->getAttivo()->getColore()), WHITE, "L", ts);
	}
	else if (slider->getVettColor()->getAttivo()->getIndex() == 17)
	{
		attivo = new button(gfx, 140, 35, 50, 50, colorButtonsSlider::getColore(slider->getVettColor()->getAttivo()->getColore()), WHITE, "V", ts);
	}
	else
	{
		attivo = new button(gfx, 140, 35, 50, 50, colorButtonsSlider::getColore(slider->getVettColor()->getAttivo()->getColore()), WHITE, "", ts);
	}
	attivo->drawButton();
}