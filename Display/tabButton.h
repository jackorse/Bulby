#pragma once
#include"button.h"
class tabButton : public button
{
private: 
	int numTab;
public:
	tabButton();
	tabButton(Adafruit_GFX* gfx, int x,int y,int numTab, TouchScreen* ts);
	int getNumTab();
	~tabButton();
	//virtual void draw();//override;
	String toString();
	void setDisabled();
};

