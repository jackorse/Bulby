#include "MyBluetooth.h"


/**
 * @brief costruttore
 *
 * inizializza la comunicazione seriale sulla {@link #Serial1}
 */
MyBluetooth::MyBluetooth()
{
	Serial1.begin(38400);
	Serial.println("starting bluetooth...");
}

/**
 * @brief distruttore
 */
MyBluetooth::~MyBluetooth()
{
}

/**
 * @brief leggi
 *
 * legge un valore dal bluetooth
 * @return stringa letta
 */
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

/**
 * @brief invia
 *
 * Invia un valore tramite bluetooth
 * @param stringa da inviare
 */
void MyBluetooth::invia(String colore)
{
	Serial1.print(colore);
}

bool MyBluetooth::isConnesso()
{
	return digitalRead(STATE_PIN) == HIGH;
}
