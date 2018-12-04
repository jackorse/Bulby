#pragma once
#include"MyIR.h"
#include<WString.h>
#include"CColore.h"
#include"Colors.h"


/*
* Classe che gestisce la luce
*/
class CLuce
{
private:
	MyIR ir;
	Colors colori;
	bool accesa;
	unsigned short intensita;
public:
	CLuce();
	CLuce(String colore, int intensita);
	CLuce(String colore);
	~CLuce();
	void accendi();
	void spegni();
	void setLuce(String colore, int intensita);
	void setColore(String colore);
	void setColore(int index);
	void setIntensita(int intensita);
	String getColore();
	int getIntensita();
	CColore* getAttivo();
	bool isAccesa();
	bool* getAccesa();
	Colors* getColori();
};

