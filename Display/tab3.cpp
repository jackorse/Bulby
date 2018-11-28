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
	switch (ris)
	{
	case SINISTRA_BUTTON:
		if (slider->getIndex() - 3 >= 0)
			slider->setIndex(slider->getIndex() - 3);
		else
			slider->setIndex(0);
		draw();
		return -1;
	case  DESTRA_BUTTON:
		if (slider->getIndex() + 3 < NUMCOLORI)
			slider->setIndex(slider->getIndex() + 3);
		else
			slider->setIndex(NUMCOLORI - 1);
		draw();
		return -1;
	case -1:
		return GenericTab::checkBottoni();
	default:
		return ris;
	}
}

int tab3::getSliderIndex()
{
	return slider->getIndex();
}
