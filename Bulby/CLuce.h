#pragma once
#include<WString.h>
class CLuce
{
private:
	String colore;
	int intensita;
public:
	CLuce();
	CLuce(String colore, int intensita);
	CLuce(String colore);
	~CLuce();
	void setLuce(String colore, int intensita);
	void setColore(String colore);
	void setIntensita(int intensita);
	String getColore();
	int getIntensita();
};

