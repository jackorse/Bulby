#include "tabButton.h"

tabButton::tabButton()
	:button(NULL, 0, 0, 0, 0, WHITE, BLACK, "", NULL)
{
	this->numTab = -1;
}

tabButton::tabButton(Adafruit_GFX* gfx, int x, int y, int numTab, TouchScreen* ts)
	: button(gfx, x, y, 107, 60, BLACK, WHITE, itoa(numTab, NULL, 10), ts)
{
	this->numTab = numTab;
	this->gfx = gfx;
}

int tabButton::getNumTab()
{
	return numTab;
}


tabButton::~tabButton()
{
}

String tabButton::toString()
{
	return String(this->numTab);
}

void tabButton::setDisabled()
{
	setColor(WHITE);
	setTextColor(BLACK);
}

void tabButton::drawButton()
{
	Adafruit_GFX_Button::drawButtonConSpigoli(true);
	while (ts->isTouching());
	Adafruit_GFX_Button::drawButtonConSpigoli();
}

