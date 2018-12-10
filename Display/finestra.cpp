// 
// 
// 

#include "finestra.h"

/**
<summary>text</summary>
*/
finestra::finestra(bool *accesa, CLuce * luce)
	:Adafruit_TFTLCD(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET)
{
	this->luce = luce;
	this->accesa = accesa;
	reset();
	begin(0x9341);
	ts = new TouchScreen(XP, YP, XM, YM, 300);
	setRotation(3);
	tab = new homeTab(this, ts);
	tab->draw();
	index = 0;
}


finestra::~finestra()
{
	if (ts) delete ts;
	if (tab) delete tab;
}

void finestra::setTab(int index)
{
	if (this->index == index || index == -1)
		return;
	else
	{
		if (tab) {
			delete tab;
			Serial.println("tab deletato");
		}
		switch (index)
		{
		case 0:
			tab = new homeTab(this, ts);
			break;
		case 1:
			tab = new tab1(this, ts, accesa);
			break;
		case 2:
			tab = new tab2(this, ts, luce);
			break;
		case 3:
			tab = new tab3(this, ts, luce->getColori(), accesa);
			break;
		default:
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
