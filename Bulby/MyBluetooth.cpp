#include "MyBluetooth.h"



MyBluetooth::MyBluetooth()
{
	//Serial1.begin(38400);
	//Serial.println("starting bluetooth...");
}


MyBluetooth::~MyBluetooth()
{
}

String MyBluetooth::leggi()
{
	//String ris;
	//if (Serial1.available() > 0)
	//	ris = Serial1.readString();// readString();
	//if (ris != "")
	//	Serial.println("letto: " + ris);
	////if (colore.startsWith == "rosso" || colore == "giallo" || colore == "verde" || colore == "blu" || colore == "arancione" || colore == "azzurro" || colore == "bianco" || colore == "giallancione" || colore == "rosa" || colore == "rgbLento" || colore == "rgbVeloce")
	//return ris;
	////else return "";
}

void MyBluetooth::invia(String colore)
{
	///Serial1.write(colore.c_str());
}
