#pragma once
#include"MyIR.h"
#include<WString.h>
#include"MyBluetooth.h"
class CLuce
{
private:
	MyIR ir;
	MyBluetooth bt;
	String colore;
	int intensita;
	bool accesa;
public:
	CLuce();
	CLuce(String colore, int intensita);
	CLuce(String colore);
	~CLuce();
	void accendi();
	void spegni();
	void initBluetooth();
	void setLuce(String colore, int intensita);
	void setColore(String colore);
	void setIntensita(int intensita);
	String getColore();
	int getIntensita();
	void checkBluetooth();
};

