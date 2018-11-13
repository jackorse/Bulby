#pragma once

// finestra.h
// Define User Types below here or use a .h file
//

#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin
/*
#define TS_MINX 50
#define TS_MAXX 920
#define TS_MINY 100
#define TS_MAXY 940
*/
//Touch For New ILI9341 TP
#define TS_MINX 122
#define TS_MAXX 916

#define TS_MINY 107
#define TS_MAXY 915
//minx = 122 | miny = 107
//maxx = 916 | maxy = 915
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
// optional
#define LCD_RESET A4



#ifndef _FINESTRA_h
#define _FINESTRA_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include"homeTab.h"
#include"tab1.h"
#include"tab2.h"
#include"tab3.h"
#include"GenericTab.h"
#include"Adafruit_TFTLCD.h"
class finestra : public Adafruit_TFTLCD
{
private:
	TouchScreen* ts;
	abstractTab* tab;
	int index;
 public:
	finestra();
	~finestra();
	void setTab(int index);
	abstractTab* getTab();
};


#endif

