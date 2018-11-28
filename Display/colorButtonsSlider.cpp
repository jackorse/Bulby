#include "colorButtonsSlider.h"



colorButtonsSlider::colorButtonsSlider(Adafruit_GFX* gfx, TouchScreen* ts, Colors *vettColori)
{
	this->gfx = gfx;
	this->ts = ts;
	setIndex(0);
}


colorButtonsSlider::~colorButtonsSlider()
{
}

int colorButtonsSlider::checkTouch()
{
	if (sinistra->checkTouch())
		return SINISTRA_BUTTON;
	else if (destra->checkTouch())
		return DESTRA_BUTTON;
	else for (int i = 0; i < 3; i++)
		if (buttons[i]->checkTouch())
			return COLORE1_BUTTON + i * 10;
	return -1;
}

uint16_t colorButtonsSlider::getColore(String colore)
{
	if (colore == "rosso")
		return RED;
	else if (colore == "giallo")
		return YELLOW;
	else if (colore == "verde")
		return GREEN;
	else if (colore == "blu")
		return BLUE;
	else if (colore == "arancione")
		return ORANGE;
	else if (colore == "azzurro")
		return AZZURRO;
	else if (colore == "bianco")
		return WHITE;
	else if (colore == "giallancione")
		return GIALLO_ARANCIO;
	else if (colore == "rosa")
		return PINK;
}

void colorButtonsSlider::setIndex(int i )
{
	index = i;
	for (int i = 0; i < 3; i++)
	{
		buttons[i] = new button(gfx, i * 70, 100, 50, 50, getColore((vettColori->get(index) + i)->getColore()), WHITE, "", ts);
	}
	sinistra = new button(gfx, 5, 100, 50, 50, WHITE, BLACK, "<", ts);
	destra = new button(gfx, 270, 100, 50, 50, WHITE, BLACK, ">", ts);
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
