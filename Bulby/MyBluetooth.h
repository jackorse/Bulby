#pragma once
#include<HardwareSerial.h>
/**
* Classe che gestisce la comunicazione Bluetooth
*/
class MyBluetooth //:public SoftwareSerial
{
public:
	MyBluetooth();
	~MyBluetooth();
	String leggi();
	void invia(String text);
};

