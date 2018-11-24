#include "CLuce.h"


CLuce::CLuce()
{
	frame = new finestra();
	initBluetooth();
	setLuce("bianco", 100);
}

CLuce::CLuce(String colore, int intensita)
{
	frame = new finestra();
	initBluetooth();
	setLuce(colore, intensita);
}

CLuce::CLuce(String colore)
{
	frame = new finestra();
	initBluetooth();
	setLuce(colore, 100);
}


CLuce::~CLuce()
{
	delete frame;
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
	this->getAttivo()->setIntensita(20);
	setIntensita(intensita);
}

void CLuce::setColore(String colore)
{
	Serial.println("colore: " + colore);
	if (this->getAttivo()->getColore() == colore)
		return;
	else if (colore.startsWith("rosso")) {
		this->colore[ROSSO].attiva();
		ir.rosso();
	}
	else if (colore.startsWith("giallo")) {
		this->colore[GIALLO].attiva();
		ir.giallo();
	}
	else if (colore == "verde") {
		ir.verde();
		this->colore[VERDE].attiva();
	}
	else if (colore == "blu") {
		ir.blu();
		this->colore[BLU].attiva();
	}
	else if (colore == "arancione") {

		ir.arancione();
		this->colore[ARANCIONE].attiva();
	}
	else if (colore == "azzurro") {

		ir.azzurro();
		this->colore[AZZURRO].attiva();
	}
	else if (colore == "bianco") {

		ir.bianco();
		this->colore[BIANCO].attiva();
	}
	else if (colore == "giallancione") {

		ir.giallancione();
		this->colore[GIALLO_ARANCIO].attiva();
	}
	else if (colore == "rosa") {

		ir.rosa();
		this->colore[ROSA].attiva();
	}
	else if (colore == "rgbLento") {

		ir.RGBlento();
		this->colore[multicolorLento].attiva();
	}
	else if (colore == "rgbVeloce") {

		ir.RGBveloce();
		this->colore[multicolorVeloce].attiva();
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
				ir.diminuisciIntensita();
				delay(50);
			}
		else
		{
			for (int i = diff; i < 0; i++) {
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
	for (int i = 0; i < NUMCOLORI;i++) {
		if (colore[i].isAttiva())
			return colore;
	}
	return nullptr;
}

void CLuce::checkBluetooth()
{
	bool isColore = true;
	String letto = bt.leggi();
	if (letto != "")
	{
		for (int i = 0; i < letto.length(); i++)
			if (letto[i] >= '0'&&letto[i] <= '9')
				isColore = false;
		if (isColore)
			setColore(letto);
		else
			setIntensita(letto.toInt());
	}
	//if (letto != "")
	//{
	//	setColore(letto);
	//	setIntensita(intens);
	//}

}

void CLuce::checkDisplay()
{
	int ris = frame->getTab()->checkBottoni();
	if (ris >= 0 && ris <= 3)
		frame->setTab(ris);
	else if (ris == 10)	//pulsante luce premuto
		if (accesa) {
			spegni();
			bt.invia("spegni");
		}
		else {
			accendi();
			bt.invia("accendi");
		}
}
