#pragma once
#include<WString.h>
#include<HardwareSerial.h>

class CColore
{
private:
	char colore[15];
	unsigned short index;
	unsigned short intensita;
	bool attivo;

public:
	CColore();
	CColore(char colore[], int index, int intensita = 20);
	~CColore();
	void setIntensita(int intensita);
	int getIntensita();
	String getColore();
	int getIndex();
	void attiva();
	void disattiva();
	bool isAttiva();
	String toString();
};