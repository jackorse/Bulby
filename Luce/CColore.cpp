#include "CColore.h"

CColore::CColore()
{
}

CColore::CColore(char colore[], int index, int intensita = 20)
{
	strcpy(this->colore, colore);
	this->index = index;
	setIntensita(intensita);
	attivo = false;
}

CColore::~CColore()
{
}

void CColore::setIntensita(int intensita)
{
	if (intensita >= 1 && intensita <= 20)
		this->intensita = intensita;
	Serial.println("Nuova intensita: " + (String)this->intensita);
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

String CColore::toString()
{
	String ris = " Attivo";
	if (!attivo)
		ris = " Non attivo";
	return "Colore: " + String(colore) + " index: " + (String)index + ris;
}
