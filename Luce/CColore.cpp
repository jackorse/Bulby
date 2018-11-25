#include "CColore.h"

CColore::CColore()
{
}

CColore::CColore(String colore, int intensita)
{
	this->colore = colore;
	this->intensita = intensita;
}

CColore::~CColore()
{
}

void CColore::setIntensita(int intensita)
{
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

void CColore::attiva()
{
	attivo = true;
}

void CColore::disattiva()
{
	attivo = false;
}

bool CColore::isAttiva()
{
	return attivo;
}
