#pragma once
#include"finestra.h"
#include"CLuce.h"

class CBulby
{
private:
	finestra *frame;
	MyBluetooth bt;
	CLuce luce = CLuce("bianco", 100);
	//unsigned long connectedTime;
	bool oldBtState;
public:
	CBulby();
	~CBulby();
	void checkBluetooth();
	void runDisplay();
	void resetDisplay();
};