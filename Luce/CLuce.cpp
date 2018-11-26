#include "CLuce.h"


CLuce::CLuce()
{
	for (int i = 0; i < 14; i++)
		colori[i] = CColore(i);
	setLuce("bianco", 100);
}

CLuce::CLuce(String colore, int intensita)
{
	for (int i = 0; i < 14; i++)
		colori[i] = CColore(i);
	setLuce(colore, intensita);
}

CLuce::CLuce(String colore)
{
	for (int i = 0; i < 14; i++)
		colori[i] = CColore(i);
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
	//if (this->getAttivo()->getColore() == colore)
	//	return;
	this->getAttivo()->disattiva();
	if (colore.startsWith("rosso")) {
		this->colori[ROSSO].attiva();
		ir.rosso();
	}
	else if (colore.startsWith("giallo")) {
		this->colori[GIALLO].attiva();
		ir.giallo();
	}
	else if (colore == "verde") {
		ir.verde();
		this->colori[VERDE].attiva();
	}
	else if (colore == "blu") {
		ir.blu();
		this->colori[BLU].attiva();
	}
	else if (colore == "arancione") {

		ir.arancione();
		this->colori[ARANCIONE].attiva();
	}
	else if (colore == "azzurro") {

		ir.azzurro();
		this->colori[AZZURRO].attiva();
	}
	else if (colore == "bianco") {

		ir.bianco();
		this->colori[BIANCO].attiva();
	}
	else if (colore == "giallancione") {

		ir.giallancione();
		this->colori[GIALLO_ARANCIO].attiva();
	}
	else if (colore == "rosa") {

		ir.rosa();
		this->colori[ROSA].attiva();
	}
	else if (colore == "rgbLento") {

		ir.RGBlento();
		this->colori[multicolorLento].attiva();
	}
	else if (colore == "rgbVeloce") {

		ir.RGBveloce();
		this->colori[multicolorVeloce].attiva();
	}
	else return;
	Serial.println(colore);
}

void CLuce::setIntensita(int intensita)
{
	intensita /= 5;			//trasforma da % a 1-20
	Serial.println("Intensita: " + String(intensita));
	if (intensita >= 0 && intensita <= 100)
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
	return colors[getAttivo()->getColore()];
}

int CLuce::getIntensita()
{
	return getAttivo()->getIntensita() * 5; //trasforma in %
}

CColore* CLuce::getAttivo()
{
	for (int i = 0; i < NUMCOLORI;i++) {
		if (colori[i].isAttiva())
		{
			Serial.println("attivo: "+colors[i]);
			return &colori[i];
		}
	}
	return nullptr;
}

bool CLuce::isAccesa()
{
	return accesa;
}
