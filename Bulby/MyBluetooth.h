#pragma once
#include<HardwareSerial.h>
#include<Arduino.h>
#define STATE_PIN 0			//TODO		<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

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
	bool isConnesso();
};

