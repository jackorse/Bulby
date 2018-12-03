#include "MyBluetooth.h"



MyBluetooth::MyBluetooth()
	:SoftwarSerial(10,11)
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
	{
		ris = readString();// readString();
	}
	if (ris != "")
	{
		Serial.println("letto: " + ris);
	}
	return ris;
}

void MyBluetooth::invia(String colore)
{
	write(colore.c_str());
}
