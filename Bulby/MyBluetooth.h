#pragma once
#include<SoftwareSerial.h>
#include<HardwareSerial.h>
class MyBluetooth :public SoftwareSerial
{
public:
	MyBluetooth();
	~MyBluetooth();
	String leggiColore();
};

