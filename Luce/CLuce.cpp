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
	colori.get(colore)->attiva();
	setIntensita(intensita);
	setColore(colore);
	//this->getAttivo()->setIntensita(20);
}

void CLuce::setColore(String colore)
{
	Serial.println("SET COLORE");
	Serial.println("colore selezionato: " + colore);
	//colori.printColoriAttivi();
	//colori.disattivaTutti();
	this->getAttivo()->disattiva();
	this->colori.get(colore)->attiva();
	Serial.println("colore attivato:" + colori.getAttivo()->toString());
	int index = Colors::getColore(colore);
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

	//dopo aver cambiato il colore sistemo l'intensità
	changeIntensita();
}

void CLuce::setColore(int index)
{
	setColore(colori.get(index)->getColore());
}

void CLuce::setIntensita(int intensita)
{
	if (intensita >= 1 && intensita <= 100)
		this->intensita = intensita / 5;
	Serial.println("Intensita: " + String(this->intensita));
	changeIntensita();
}

String CLuce::getColore()
{
	return getAttivo()->getColore();
}

int CLuce::getIntensita()
{
	//return getAttivo()->getIntensita() * 5; //trasforma in %
	return intensita * 5;
}

CColore* CLuce::getAttivo()
{
	return colori.getAttivo();
}

bool CLuce::isAccesa()
{
	return accesa;
}

bool * CLuce::getAccesa()
{
	return &accesa;
}

Colors * CLuce::getColori()
{
	return &colori;
}

void CLuce::changeIntensita()
{
	int diff = this->getAttivo()->getIntensita() - intensita;
	Serial.println(this->getAttivo()->toString());
	Serial.println("Intensità colore attivo: " + (String)getAttivo()->getIntensita());
	if (diff >= 0)
	{
		for (int i = 0; i < diff; i++)
		{
			Serial.println("diminuisco intensità");
			ir.diminuisciIntensita();
			delay(50);
		}
	}
	else
	{
		for (int i = diff; i < 0; i++)
		{
			Serial.println("aumento intensità");
			ir.aumentaIntensita();
			delay(50);
		}
	}
	this->getAttivo()->setIntensita(intensita);
}
