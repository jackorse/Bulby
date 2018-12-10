// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
	Name:       Bulby.ino
	Created:	07/11/2018 17:27:20
	Author:     Giacomo Orsenigo
*/
#include<spi.h>
#include"CBulby.h"
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
CBulby *bulby;
// The setup() function runs once each time the micro-controller starts
void setup()
{
	Serial.begin(9600);
	Serial.println("START");
	delay(10);
	Serial.println("sto per disegnare");
	//frame->getAttiva()->draw();
	//pinMode(13, OUTPUT);
	//frame = new finestra();
	bulby = new CBulby();
	Serial.println("fine setup");
	delay(10);
}
// Add the main program code into the continuous loop() function
void loop()
{
	bulby->runDisplay();
	//bulby->checkBluetooth();
}
