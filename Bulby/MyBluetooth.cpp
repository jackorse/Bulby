#include "MyBluetooth.h"



MyBluetooth::MyBluetooth()
	:SoftwareSerial(10, 11)
{
	Serial.println("starting bluetooth...");
}


MyBluetooth::~MyBluetooth()
{
}

String MyBluetooth::leggi()
{
	String ris;
	if (available() > 0)
		ris = readString();
	//if (colore.startsWith == "rosso" || colore == "giallo" || colore == "verde" || colore == "blu" || colore == "arancione" || colore == "azzurro" || colore == "bianco" || colore == "giallancione" || colore == "rosa" || colore == "rgbLento" || colore == "rgbVeloce")
	return ris;
	//else return "";
}

void MyBluetooth::invia(String colore)
{
	SoftwareSerial::write(colore.c_str());
}
