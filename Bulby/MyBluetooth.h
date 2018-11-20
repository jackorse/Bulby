#pragma once
#include<SoftwareSerial.h>
class MyBluetooth :public SoftwareSerial
{
public:
	MyBluetooth();
	~MyBluetooth();
	String leggiColore();
};

