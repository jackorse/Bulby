#include "CLuce.h"


CLuce::CLuce()
{
	setLuce("bianco", 100);
}

CLuce::CLuce(String colore, int intensita)
{
	setLuce(colore, intensita);
}

CLuce::CLuce(String colore)
{
	setLuce(colore, 100);
}


CLuce::~CLuce()
{
}

void CLuce::accendi()
{
	ir.accendi();
	accesa = true;
}

void CLuce::spegni()
{
	ir.spegni();
	accesa = false;
}


void CLuce::setLuce(String colore, int intensita)
{
	accendi();
	setColore(colore);
	this->getAttivo()->setIntensita(20);
	setIntensita(intensita);
}

void CLuce::setColore(String colore)
{
	Serial.println("colore: " + colore);
	this->getAttivo()->disattiva();
	this->colori.get(colore)->attiva();
	if (colore == ("rosso")) {
		ir.inviaColore(IR_ROSSO);
	}
	else if (colore == ("giallo")) {
		ir.inviaColore(IR_GIALLO);
	}
	else if (colore == "gialloverde") {
		ir.inviaColore(IR_GIALLO_VERDE);
	}
	else if (colore == "verde") {
		ir.inviaColore(IR_VERDE);
	}
	else if (colore == "blu") {
		ir.inviaColore(IR_BLU);
	}
	else if (colore == "bluviola") {
		ir.inviaColore(IR_BLU_VIOLA);
	}
	else if (colore == "arancione") {
		ir.inviaColore(IR_ARANCIONE);
	}
	else if (colore == "giallancione") {
		ir.inviaColore(IR_GIALLO_ARANCIO);
	}
	else if (colore == "azzurro") {
		ir.inviaColore(IR_AZZURRO);
	}
	else if (colore == "azzurrochiaro") {
		ir.inviaColore(IR_AZZURROCHIARO);
	}
	else if (colore == "bianco") {
		ir.inviaColore(IR_BIANCO);
	}
	else if (colore == "rosa") {
		ir.inviaColore(IR_ROSA);
	}
	else if (colore == "viola") {
		ir.inviaColore(IR_VIOLA);
	}
	else if (colore == "azzurroverde") {
		ir.inviaColore(IR_AZZURRO_VERDE);
	}
	else if (colore == "azzurroverde2") {
		ir.inviaColore(IR_AZZURRO_VERDE2);
	}
	else if (colore == "rgbLento") {
		ir.RGBlento();
	}
	else if (colore == "rgbVeloce") {
		ir.RGBveloce();
	}
	else return;
	Serial.println(colore);
}

void CLuce::setColore(int index)
{
	setColore(colori.get(index)->getColore());
	Serial.println(colori.get(index)->getColore());
}

void CLuce::setIntensita(int intensita)
{
	intensita /= 5;			//trasforma da % a 1-20
	Serial.println("Intensita: " + String(intensita));
	if (intensita >= 5 && intensita <= 100)
	{
		int diff = this->getAttivo()->getIntensita() - intensita;
		if (diff >= 0)
			for (int i = 0; i < diff; i++) {
				Serial.println("diminuisco");
				ir.diminuisciIntensita();
				delay(50);
			}
		else
		{
			for (int i = diff; i < 0; i++) {
				Serial.println("aumento");
				ir.aumentaIntensita();
				delay(50);
			}
		}
		this->getAttivo()->setIntensita(intensita);
	}
}

String CLuce::getColore()
{
	return getAttivo()->getColore();
}

int CLuce::getIntensita()
{
	return getAttivo()->getIntensita() * 5; //trasforma in %
}

CColore* CLuce::getAttivo()
{
	return colori.getAttivo();
}

bool CLuce::isAccesa()
{
	return accesa;
}

Colors * CLuce::getColori()
{
	return &colori;
}
