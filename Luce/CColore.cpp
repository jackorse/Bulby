#include "CColore.h"

CColore::CColore()
{
}

CColore::CColore(String colore, int index, int intensita)
{
	this->colore = colore;
	this->index = index;
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
	Serial.print("sto disattivando: " ); Serial.println(colore);
	attivo = false;
}

bool CColore::isAttiva()
{
	return attivo;
}
