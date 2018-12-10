#include "GenericTab.h"



GenericTab::GenericTab(Adafruit_GFX* gfx, TouchScreen* ts)
	:abstractTab(gfx, ts)
{
	home = new button(gfx, 0, 0, 80, 30, WHITE, BLACK, "HOME", ts);
	Serial.println("inizializzo");
	delay(10);
	tabs[0] = new tabButton(gfx, 0, 180, 1, ts);
	tabs[1] = new tabButton(gfx, 107, 180, 2, ts);
	tabs[2] = new tabButton(gfx, 214, 180, 3, ts);
	restartTimer();
}


GenericTab::~GenericTab()
{
	Serial.println("deleting genericTab");
	for (int i = 0; i < 3; i++)
		if (tabs[i])
			delete tabs[i];
	if (home) delete home;
}

tabButton* GenericTab::getTabButton(int index)
{
	return tabs[index];
}

void GenericTab::draw()
{
	gfx->fillScreen(WHITE);

	Serial.println("drawing tabs...");
	home->drawButtonSquadrato();
	for (int i = 0; i < 3; i++)
	{
		tabs[i]->drawButton();
	}
	Serial.println("tabs disegnate");
}

int GenericTab::checkBottoni()
{
	unsigned long time2 = millis();
	if (time2 - startTime > 8000)
	{
		return HOME_BUTTON;
	}
	if (home->checkTouch())
	{
		return HOME_BUTTON;
	}
	for (int i = 0; i < 3; i++)
	{
		if (tabs[i]->checkTouch())
		{
			return i + 1;
		}
	}
	return -1;
}

void GenericTab::restartTimer()
{
	startTime = millis();
}

void GenericTab::disableTabButton(int index)
{
	if (index >= 0 && index <= 2)
		tabs[index]->setDisabled();
}
