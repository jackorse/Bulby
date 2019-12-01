#pragma once
#include"button.h"
class homeButton :public button
{
public:
	homeButton(Adafruit_GFX *gfx, TouchScreen*ts, int x, int y);
	~homeButton();
	virtual void drawButton()override;
};

