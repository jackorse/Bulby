#pragma once
#include"button.h"
class tabButton : public button
{
private: 
	unsigned short numTab;
	Adafruit_GFX *gfx;
public:
	tabButton();
	tabButton(Adafruit_GFX* gfx, int x,int y,int numTab, TouchScreen* ts);
	int getNumTab();
	~tabButton();
	String toString();
	void setDisabled();
	virtual void drawButton() override;
};

