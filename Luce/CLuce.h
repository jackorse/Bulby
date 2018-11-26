#pragma once
#include"MyIR.h"
#include<WString.h>
#include"CColore.h"
#define NUMCOLORI 16


/*
* Classe che gestisce la luce
*/
class CLuce
{
private:
	MyIR ir;
	CColore colori[NUMCOLORI];
	bool accesa;
	const String colors[17] = { "giallancione","viola","azzurro","azzurrochiaro","giallo","azzurroverde","gialloverde","bluviola","rosa","azzurro","blu","rosso","bianco","verde","arancione","rgbLento","rgbVeloce" };
public:
	CLuce();
	CLuce(String colore, int intensita);
	CLuce(String colore);
	~CLuce();
	void accendi();
	void spegni();
	void setLuce(String colore, int intensita);
	void setColore(String colore);
	void setIntensita(int intensita);
	String getColore();
	int getIntensita();
	CColore* getAttivo();
	bool isAccesa();
};

