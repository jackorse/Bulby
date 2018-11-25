#include "MyBluetooth.h"



MyBluetooth::MyBluetooth()
{
	Serial2.begin(9600);
	Serial.println("starting bluetooth...");
}


MyBluetooth::~MyBluetooth()
{
}

String MyBluetooth::leggi()
{
	String ris;
	if (Serial2.available() > 0)
		ris = Serial2.readString();// readString();
	if (ris != "")
		Serial.println("letto: " + ris);
	//if (colore.startsWith == "rosso" || colore == "giallo" || colore == "verde" || colore == "blu" || colore == "arancione" || colore == "azzurro" || colore == "bianco" || colore == "giallancione" || colore == "rosa" || colore == "rgbLento" || colore == "rgbVeloce")
	return ris;
	//else return "";
}

void MyBluetooth::invia(String colore)
{
	Serial2.write(colore.c_str());
}
