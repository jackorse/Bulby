#include "CLuce.h"

/**
 * @brief costruttore
 *
 * @see #setLuce(String,int)
 */
CLuce::CLuce()
{
	setLuce("bianco", 100);
}

/**
 * @brief costruttore *
 * @param colore
 * @param intensità
 * @see #setLuce(String,int)
 */
CLuce::CLuce(String colore, int intensita)
{
	setLuce(colore, intensita);
}

/**
 * @brief costruttore
 *
 * @param colore
 * @see #setLuce(String,int)
 */
CLuce::CLuce(String colore)
{
	setLuce(colore, 100);
}


/**
 * @brief distruttore
 */
CLuce::~CLuce()
{
}

/**
 * @brief accendi
 *
 * accende la luce tramite IR e modifica {@link #accesa}
 * @see MyIR#accendi()
 */
void CLuce::accendi()
{
	ir.accendi();
	accesa = true;
}

/**
 * @brief spegni
 *
 * spegne la luce tramite IR e modifica {@link #accesa}
 * @see MyIR#spegni()
 */
void CLuce::spegni()
{
	ir.spegni();
	accesa = false;
}

/**
 * @brief set luce
 *
 * accende e inizializza la luce
 * @param colore
 * @param intensità
 * @see #accendi()
 * @see #setInntensita()
 * @see #setColore()
 */
void CLuce::setLuce(String colore, int intensita)
{
	accendi();
	colori.get(colore)->attiva();
	setIntensita(intensita);
	setColore(colore);
	//this->getAttivo()->setIntensita(20);
}

/**
 * @brief set colore
 *
 * imposta il colore dalle luce tramite IR e setta il colore attivo
 * @param colore da attivare
 * @see MyIR#inviaColore(String)
 */
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

/**
 * @brief set intensità
 *
 * modifica l'intensità {@link #intensita}
 * @see #changeIntensita()
 */
void CLuce::setIntensita(int intensita)
{
	if (intensita >= 1 && intensita <= 100)
		this->intensita = intensita / 5;
	Serial.println("Intensita: " + String(this->intensita));
	changeIntensita();
}

/**
 * @brief get colore
 *
 * @return colore attivo
 * @see #getAttivo()
 */
String CLuce::getColore()
{
	return getAttivo()->getColore();
}

/**
 * @brief get intensità
 *
 * @return intensità {@link #intensita}
 */
int CLuce::getIntensita()
{
	//return getAttivo()->getIntensita() * 5; //trasforma in %
	return intensita * 5;
}

/**
 * @brief get colore attivo
 *
 * @return colore attivo
 * @see CColore#getAttivo()
 */
CColore* CLuce::getAttivo()
{
	return colori.getAttivo();
}

/**
 * @brief is accesa
 *
 * @return true se la luce è accesa, false se è spenta
 */
bool CLuce::isAccesa()
{
	return accesa;
}

/**
 * @brief get accesa
 *
 * @return puntatore a {@link #accesa}
 */
bool * CLuce::getAccesa()
{
	return &accesa;
}

/**
 * @brief get colore
 *
 * @return puntatore al vettore dei colori {@link #colori}
 */
Colors * CLuce::getColori()
{
	return &colori;
}

/**
 * @brief change intensità
 *
 * Imposta tramite IR l'intensità attuale alla luce, in base all'intensità di ogni colore
 * @see MyIR#diminuisciIntensita()
 * @see MyIR#aumentaIntensita()
 */
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
