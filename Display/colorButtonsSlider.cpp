#include "colorButtonsSlider.h"



void colorButtonsSlider::elimina()
{
	for (int i = 0; i < 3; i++)
		if (buttons[i])
			delete buttons[i];
}

colorButtonsSlider::colorButtonsSlider(Adafruit_GFX* gfx, TouchScreen* ts, Colors *vettColori)
{
	this->gfx = gfx;
	this->ts = ts;
	this->vettColori = vettColori;
	setIndex(0);
	sinistra = new button(gfx, 5, 100, 50, 50, WHITE, BLACK, "<", ts);
	destra = new button(gfx, 270, 100, 50, 50, WHITE, BLACK, ">", ts);
}


colorButtonsSlider::~colorButtonsSlider()
{
	delete destra;
	delete sinistra;
	elimina();
}

int colorButtonsSlider::checkTouch()
{
	if (sinistra->checkTouch())
	{
		return SINISTRA_BUTTON;
	}
	else if (destra->checkTouch())
	{
		return DESTRA_BUTTON;
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			if (buttons[i]->checkTouch())
			{
				return COLORE1_BUTTON + i * 10;
			}
		}
		return -1;
	}
}



void colorButtonsSlider::setIndex(int i)
{
	index = i;
	elimina();
	for (int i = 0; i < 3; i++)
	{
		if (index + i  == 16 )
		{
			buttons[i] = new button(gfx, (i + 1) * 70, 100, 50, 50, Colors::getColore((vettColori->get(index) + i)->getColore()), WHITE, "L", ts);
		}
		else if (index + i == 17)
		{
			buttons[i] = new button(gfx, (i + 1) * 70, 100, 50, 50, Colors::getColore((vettColori->get(index) + i)->getColore()), WHITE, "V", ts);
		}
		else
		{
			buttons[i] = new button(gfx, (i + 1) * 70, 100, 50, 50, Colors::getColore((vettColori->get(index) + i)->getColore()), WHITE, "", ts);
		}
	}
}

void colorButtonsSlider::draw()
{
	sinistra->drawButton();
	destra->drawButton();
	for (int i = 0; i < 3; i++)
		buttons[i]->drawButton();
}

int colorButtonsSlider::getIndex()
{
	return index;
}

Colors * colorButtonsSlider::getVettColor()
{
	return vettColori;
}
