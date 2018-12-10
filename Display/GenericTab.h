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
private:
	unsigned long  startTime;
	button* home;
	tabButton* tabs[3];
public:
	GenericTab(Adafruit_GFX *gfx, TouchScreen* ts);
	virtual ~GenericTab();
	tabButton* getTabButton(int index);
	virtual void draw();
	virtual int checkBottoni() override;
	void restartTimer();
	void disableTabButton(int index);
};


