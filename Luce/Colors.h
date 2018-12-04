#pragma once
#define NUMCOLORI 16+2
#include"CColore.h"
#include"RGBColors.h"
class Colors {
private:
	CColore colori[NUMCOLORI];
public:
	Colors();
	CColore* get(int index);
	CColore* get(String colorName);
	CColore* getAttivo();
	static uint16_t getColore(String colore);
};


//enum colors {
//	GIALLO_ARANCIO,
//	VIOLA,
//	AZZURRO,
//	AZZURROCHIARO,
//	GIALLO,
//	AZZURRO_VERDE,
//	GIALLO_VERDE,
//	BLU_VIOLA,
//	ROSA,
//	AZZURRO,
//	BLU,
//	ROSSO,
//	BIANCO,
//	VERDE,
//	ARANCIONE
//};