#include "MyBluetooth.h"



MyBluetooth::MyBluetooth()
	:SoftwareSerial(10, 11)
{
	Serial.println("starting bluetooth...");
}


MyBluetooth::~MyBluetooth()
{
}

String MyBluetooth::leggiColore()
{
	String colore;
	if (available() > 0)
		colore = readString();
	if (colore != "")Serial.println(colore);
	if (colore.startsWith == "rosso" || colore == "giallo" || colore == "verde" || colore == "blu" || colore == "arancione" || colore == "azzurro" || colore == "bianco" || colore == "giallancione" || colore == "rosa" || colore == "rgbLento" || colore == "rgbVeloce")
		return colore;
	else return "";
}

void MyBluetooth::inviaColore(String colore)
{
	SoftwareSerial::write(colore.c_str());
}
