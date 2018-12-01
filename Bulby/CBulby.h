#pragma once
#include"finestra.h"
#include"CLuce.h"
#include"MyBluetooth.h"

class CBulby
{
private:
	finestra *frame;
	MyBluetooth bt;
	CLuce luce = CLuce("bianco", 100);

public:
	CBulby();
	~CBulby();
	void checkBluetooth();
	void checkDisplay();
	void resetDisplay();
};