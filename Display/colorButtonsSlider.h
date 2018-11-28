#pragma once
#include"button.h"
#include"Colors.h"
#define SINISTRA_BUTTON 80
#define DESTRA_BUTTON 90
#define COLORE1_BUTTON 100
#define COLORE2_BUTTON 110
#define COLORE3_BUTTON 120

class colorButtonsSlider
{
private:
	button* buttons[3];
	button *sinistra, *destra;
	int index;
	Colors* vettColori;
	Adafruit_GFX* gfx;
	TouchScreen* ts;
public:
	colorButtonsSlider(Adafruit_GFX* gfx, TouchScreen* ts, Colors *vettColori);
	~colorButtonsSlider();
	int checkTouch();
	uint16_t getColore(String colore);
	void setIndex(int i);
	void draw();
	int getIndex();
};

