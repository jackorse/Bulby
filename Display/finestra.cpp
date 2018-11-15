// 
// 
// 

#include "finestra.h"

finestra::finestra()
	:Adafruit_TFTLCD(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET)
{
	reset();
	begin(0x9341);
	ts = new TouchScreen(XP, YP, XM, YM, 300);
	fillScreen(RED);
	setRotation(3);
	tab = new homeTab(this, ts);
	tab->draw();
	index = 0;
}

finestra::~finestra()
{
	delete ts;
	delete tab;
}

void finestra::setTab(int index)
{
	if (this->index == index || index == -1)
		return;
	else
	{
		delete tab;
		Serial.println("tab deletato");
		Serial.println(index);
		Serial.println(this->index);
		switch (index)
		{
		case 0:
			tab = new homeTab(this, ts);
			break;
		case 1:
			tab = new tab1(this, ts);
			break;
		case 2:
			tab = new tab2(this, ts);
			break;
		case 3:
			tab = new tab3(this, ts);
			break;
		default:
			Serial.println("come sei arrivato qui????");
			break;
		}
	}
	this->index = index;
	tab->draw();
}

abstractTab * finestra::getTab()
{
	return tab;
}
