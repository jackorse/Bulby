#include "tab3.h"

tab3::tab3(Adafruit_GFX * gfx, TouchScreen * ts, Colors* vettColori, bool *acceso)
	:GenericTab(gfx, ts)
{
	GenericTab::disableTabButton(2);
	attivo = nullptr;
	slider = new colorButtonsSlider(gfx, ts, vettColori);
	this->acceso = acceso;
}
tab3::~tab3()
{
	if (slider) delete slider;
	if (attivo) delete attivo;
}

void tab3::draw()
{
	GenericTab::draw();
	gfx->setCursor(30, 50);
	gfx->setTextColor(BLACK);
	gfx->println("COLORE ATTUALE:");
	slider->draw();
	reDrawSelectedColorButton();
}

int tab3::checkBottoni()
{
	int ris = slider->checkTouch();
	switch (ris)
	{
	case SINISTRA_BUTTON:
		restartTimer();
		if (slider->getIndex() - 3 >= 0)
		{
			Serial.println("index: " + (String)(slider->getIndex() - 3));
			slider->setIndex(slider->getIndex() - 3);
		}
		else
		{
			slider->setIndex(0);
		}
		slider->draw();
		return -1;
	case  DESTRA_BUTTON:
		restartTimer();
		if (slider->getIndex() + 3 < NUMCOLORI)
		{
			Serial.println("index: " + (String)(slider->getIndex() + 3));
			slider->setIndex(slider->getIndex() + 3);
		}
		slider->draw();
		return -1;
	case -1:
		return GenericTab::checkBottoni();
	default:
		restartTimer();
		if (*acceso)
		{
			Serial.println("si");
			return ris;
		}
		else
		{
			Serial.println("no");
			return -1;
		}
	}
}

int tab3::getSliderIndex()
{
	return slider->getIndex();
}

void tab3::reDrawSelectedColorButton()
{
	if (attivo)
	{
		delete attivo;
	}
	Serial.println("Index colore attivo: " + (String)(slider->getVettColor()->getAttivo()->getIndex()));
	if (slider->getVettColor()->getAttivo()->getIndex() == 16)
	{
		attivo = new button(gfx, 210, 35, 50, 50, Colors::getColore(slider->getVettColor()->getAttivo()->getColore()), WHITE, "L", ts);
	}
	else if (slider->getVettColor()->getAttivo()->getIndex() == 17)
	{
		attivo = new button(gfx, 210, 35, 50, 50, Colors::getColore(slider->getVettColor()->getAttivo()->getColore()), WHITE, "V", ts);
	}
	else
	{
		attivo = new button(gfx, 210, 35, 50, 50, Colors::getColore(slider->getVettColor()->getAttivo()->getColore()), WHITE, "", ts);
	}
	attivo->drawButton();
}