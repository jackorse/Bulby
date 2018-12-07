#include "MyBluetooth.h"



MyBluetooth::MyBluetooth()
{
	Serial1.begin(38400);
	Serial.println("starting bluetooth...");
}


MyBluetooth::~MyBluetooth()
{
}

String MyBluetooth::leggi()
{
	String ris;
	if (Serial1.available() > 0)
	{
		ris = Serial1.readString();// readString();
	}
	if (ris != "")
	{
		Serial.println("letto: " + ris);
	}
	return ris;
}

void MyBluetooth::invia(String colore)
{
	Serial1.print(colore);
}
