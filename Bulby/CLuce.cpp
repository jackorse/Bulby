#include "CLuce.h"


CLuce::CLuce()
{
	initBluetooth();
	setLuce("bianco", 100);
}

CLuce::CLuce(String colore, int intensita)
{
	initBluetooth();
	setLuce(colore, intensita);
}

CLuce::CLuce(String colore)
{
	initBluetooth();
	setLuce(colore, 100);
}


CLuce::~CLuce()
{
}

void CLuce::accendi()
{
	ir.accendi();
	accesa = true;
	Serial.println("accesa");
}

void CLuce::spegni()
{
	ir.spegni();
	accesa = false;
}

void CLuce::initBluetooth()
{
	pinMode(9, OUTPUT);  // questo pin è connesso al relativo pin 34 (pin KEY) del HC-05 che portato a HIGH permette di passare alla modalità AT
	digitalWrite(9, HIGH);
	Serial.println("Inserire i comandi AT:");
	bt.begin(38400);  // Velocità di default del modulo HC-05
}

void CLuce::setLuce(String colore, int intensita)
{
	accendi();
	setColore(colore);
	this->intensita = 20;
	setIntensita(intensita);
}

void CLuce::setColore(String colore)
{
	Serial.println(colore);
	if (this->colore == colore)
		return;
	else if (colore == "rosso")
		ir.rosso();
	else if (colore == "giallo")
		ir.giallo();
	else if (colore == "verde")
		ir.verde();
	else if (colore == "blu")
		ir.blu();
	else if (colore == "arancione")
		ir.arancione();
	else if (colore == "azzurro")
		ir.azzurro();
	else if (colore == "bianco")
		ir.bianco();
	else if (colore == "giallancione")
		ir.giallancione();
	else if (colore == "rosa")
		ir.rosa();
	else if (colore == "rgbLento")
		ir.RGBlento();
	else if (colore == "rgbVeloce")
		ir.RGBveloce();
	else return;
	this->colore = colore;
	Serial.println(colore);
}

void CLuce::setIntensita(int intensita)
{
	if (intensita >= 0 && intensita <= 100)
	{
		int diff = this->intensita - intensita;
		if (diff >= 0)
			for (int i = 0; i < diff; i++)
				ir.aumentaIntensita();
		else
		{
			for (int i = diff; i < 0; i++)
				ir.diminuisciIntensita();
		}
		this->intensita = intensita / 5;	//trasforma da % a 1-20
	}
}

String CLuce::getColore()
{
	return colore;
}

int CLuce::getIntensita()
{
	return intensita * 5; //trasforma in %
}

void CLuce::checkBluetooth()
{
	String letto = bt.leggi();
	int intens = letto.toInt();
	if (letto != "")
	{
		setColore(letto);
		setIntensita(intens);
	}

}

void CLuce::checkDisplay()
{

}
