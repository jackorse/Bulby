#pragma once
#include<SoftwareSerial.h>
#include<HardwareSerial.h>
/**
* Classe che gestisce la comunicazione Bluetooth
*/
class MyBluetooth :public SoftwareSerial
{
public:
	MyBluetooth();
	~MyBluetooth();
	String leggiColore();
};

