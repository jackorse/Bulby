#pragma once
#include"button.h"
#include"tabButton.h"
#include"abstractTab.h"
#define HOME_BUTTON 0
#define TAB1_BUTTON 1
#define TAB2_BUTTON 2
#define TAB3_BUTTON 3
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


