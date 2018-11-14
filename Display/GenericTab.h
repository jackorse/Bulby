#pragma once
#include"button.h"
#include"tabButton.h"
#include"abstractTab.h"
using namespace std;
class GenericTab : public abstractTab
{
protected:
	Adafruit_GFX* gfx;
	button* home;
	tabButton* tabs[3];
private:
	unsigned long  startTime;
public:
	GenericTab(Adafruit_GFX *gfx, TouchScreen* ts);
	virtual ~GenericTab();
	tabButton* getTabButton(int index);
	virtual void draw();
	virtual int checkBottoni() override;
	void restartTimer();
};


