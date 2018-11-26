#include "CColore.h"

CColore::CColore()
{
}

CColore::CColore(int colore, int intensita)
{
	this->colore = colore;
	setIntensita(intensita);
}

CColore::~CColore()
{
}

void CColore::setIntensita(int intensita)
{
	if (intensita >= 0 && intensita <= 20)
		this->intensita = intensita;
}

int CColore::getIntensita()
{
	return intensita;
}

int CColore::getColore()
{
	return colore;
}

void CColore::attiva()
{
	Serial.print("sto attivando: "); Serial.println(colore);
	attivo = true;
}

void CColore::disattiva()
{
	Serial.print("sto disattivando: " ); Serial.println(colore);
	attivo = false;
}

bool CColore::isAttiva()
{
	return attivo;
}
