#include "CColore.h"

CColore::CColore()
{
}

CColore::CColore(char colore[], int index, int intensita = 20)
{
	Serial.println("initialing colore...");
	strcpy(this->colore, colore);
	Serial.println(colore);
	Serial.println(this->colore);
	this->index = index;
	Serial.println(intensita);
	setIntensita(intensita);
	Serial.println(this->intensita);
	Serial.println("colore inizializzato");
}

CColore::~CColore()
{
}

void CColore::setIntensita(int intensita)
{
	if (intensita >= 1 && intensita <= 20)
		this->intensita = intensita;
}

int CColore::getIntensita()
{
	return intensita;
}

String CColore::getColore()
{
	return colore;
}

int CColore::getIndex()
{
	return index;
}

void CColore::attiva()
{
	Serial.print("sto attivando: "); Serial.println(colore);
	attivo = true;
}

void CColore::disattiva()
{
	Serial.print("sto disattivando: "); Serial.println(colore);
	attivo = false;
}

bool CColore::isAttiva()
{
	return attivo;
}
