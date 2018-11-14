#include "tabButton.h"

tabButton::tabButton()
	:button(NULL, 0, 0, 0, 0, WHITE, BLACK, "", NULL)
{
	this->numTab = -1;
}

tabButton::tabButton(Adafruit_GFX* gfx, int x, int y, int numTab, TouchScreen* ts)
	: button(gfx, x, y, 50, 50, WHITE, BLACK, itoa(numTab, NULL, 10), ts)
{
	this->numTab = numTab;
	delay(1);
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
	setColor(BLACK);
	setTextColor(WHITE);
}

//void tabButton::draw()
//{
//	button::drawButton();
//	//this->drawChar(5, 5, 'c', BLACK, 10, 10);;
//	Serial.println("tabButton disegnato");
//}

