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
	bool spegnimentoAutomatico;
public:
	CLuce();
	CLuce(String colore, int intensita = 100, bool spegnimentoAutomatico = false);
	CLuce(String colore, bool spegnimentoAutomatico = false);
	~CLuce();
	void accendi();
	void spegni();
	void setLuce(String colore, int intensita, bool spegnimentoAutomatico);
	void setColore(String colore);
	void setColore(int index);
	void setIntensita(int intensita);
	String getColore();
	int getIntensita();
	CColore* getAttivo();
	bool isAccesa();
	bool* getAccesa();
	Colors* getColori();
	void changeIntensita();
	String getColoreSimile();
	void setSpegnimentoAutomatico(bool s);
	bool isSpegnimentoAutomatico();
};

