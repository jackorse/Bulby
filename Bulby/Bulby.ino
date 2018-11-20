// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
	Name:       Bulby.ino
	Created:	07/11/2018 17:27:20
	Author:     Giacomo Orsenigo
*/
#include "tab3.h"
#include "tab2.h"
#include "tab1.h"
#include "finestra.h"
#include<spi.h>
#include"CLuce.h"
// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//



// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
//TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
CLuce luce("bianco");
finestra* frame;// = finestra();
// The setup() function runs once each time the micro-controller starts
void setup()
{
	Serial.begin(9600);
	Serial.println("START");
	delay(10);
	Serial.println("sto per disegnareeee");
	//frame->getAttiva()->draw();
	pinMode(13, OUTPUT);
	frame = new finestra();
	Serial.println("fine setup");
	delay(10);
}
// Add the main program code into the continuous loop() function
void loop()
{
	int tab = frame->getTab()->checkBottoni();
	frame->setTab(tab);
	luce.checkBluetooth();
}