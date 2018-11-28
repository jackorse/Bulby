#pragma once
#include<WString.h>
#include<HardwareSerial.h>
class CColore
{
private:
	String colore;
	int index;
	int intensita;
	bool attivo;
public:
	CColore();
	CColore(String colore,int index, int intensita=100);
	~CColore();
	void setIntensita(int intensita);
	int getIntensita();
	String getColore();
	int getIndex();
	void attiva();
	void disattiva();
	bool isAttiva();
};