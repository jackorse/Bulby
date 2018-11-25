#include "CBulby.h"



CBulby::CBulby()
{
	frame = new finestra(luce.isAccesa(),luce.getAttivo());
	//luce = CLuce("bianco", 100);
}


CBulby::~CBulby()
{
	delete frame;
}

void CBulby::initBluetooth()
{
	pinMode(9, OUTPUT);  // questo pin è connesso al relativo pin 34 (pin KEY) del HC-05 che portato a HIGH permette di passare alla modalità AT
	digitalWrite(9, HIGH);
	Serial.println("Inserire i comandi AT:");
	bt.begin(38400);  // Velocità di default del modulo HC-05
}


void CBulby::checkBluetooth()
{
	bool isColore = true;
	String letto = bt.leggi();
	if (letto != "")
	{
		for (int i = 0; i < letto.length(); i++)
			if (letto[i] >= '0'&&letto[i] <= '9')
				isColore = false;
		if (isColore)
			if (letto == "on")
				luce.accendi();
			else if (letto == "off")
				luce.spegni();
			else
				luce.setColore(letto);
		else
			luce.setIntensita(letto.toInt());
	}
	//if (letto != "")
	//{
	//	setColore(letto);
	//	setIntensita(intens);
	//}

}

void CBulby::checkDisplay()
{
	int ris = frame->getTab()->checkBottoni();
	if (ris >= 0 && ris <= 3)
		frame->setTab(ris);
	else if (ris == 10)	//pulsante luce premuto
		if (luce.isAccesa()) {
			luce.spegni();
			bt.invia("spegni");
		}
		else {
			luce.accendi();
			bt.invia("accendi");
		}
	else if (ris == 20)
	{
		luce.setIntensita(luce.getIntensita() - 5);
		bt.invia((String)luce.getIntensita());
	}
	else if (ris == 30)
	{
		//setIntensita(getIntensita() + 5);
		//bt.invia((String)getIntensita());
	}
}

void CBulby::resetDisplay()
{
	delete frame;
	frame = new finestra(luce.isAccesa(), luce.getAttivo());
}
