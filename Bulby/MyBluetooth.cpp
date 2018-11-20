#include "MyBluetooth.h"



MyBluetooth::MyBluetooth()
	:SoftwareSerial(10, 11)
{
}


MyBluetooth::~MyBluetooth()
{
}

String MyBluetooth::leggiColore()
{
	String colore;
	if (available() > 0)
		colore = readString();
	if (colore == "rosso" || colore == "giallo" || colore == "verde" || colore == "blu" || colore == "arancione" || colore == "azzurro" || colore == "bianco" || colore == "giallancione" || colore == "rosa" || colore == "rgbLento" || colore == "rgbVeloce")
		return colore;
	else return "";
}
