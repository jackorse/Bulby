#pragma once
#include<WString.h>
#include<HardwareSerial.h>
//colors index
#define GIALLO_ARANCIO 0
#define VIOLA 1
#define AZZURRO 2
#define AZZURROCHIARO 3
#define GIALLO 4
#define AZZURRO_VERDE 5
#define GIALLO_VERDE 6
#define BLU_VIOLA 7
#define ROSA 8
#define AZZURRO 9
#define BLU 10
#define ROSSO 11
#define BIANCO 12
#define VERDE 13
#define ARANCIONE 14
class CColore
{
private:
	int colore;
	int intensita;
	bool attivo;
public:
	CColore();
	CColore(int colore, int intensita=100);
	~CColore();
	void setIntensita(int intensita);
	int getIntensita();
	int getColore();
	void attiva();
	void disattiva();
	bool isAttiva();
};

