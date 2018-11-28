#include "CBulby.h"



CBulby::CBulby()
{
	frame = new finestra(luce.isAccesa(), &luce);
	//luce = CLuce("bianco", 100);
}


CBulby::~CBulby()
{
	delete frame;
}

void CBulby::initBluetooth()
{
	//pinMode(9, OUTPUT);  // questo pin è connesso al relativo pin 34 (pin KEY) del HC-05 che portato a HIGH permette di passare alla modalità AT
	//digitalWrite(9, HIGH);
	//Serial.println("Inserire i comandi AT:");
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
	else switch (ris)
	{
	case LUCE_BUTTON:	//pulsante luce premuto
		if (luce.isAccesa()) {
			luce.spegni();
			bt.invia("spegni");
		}
		else {
			luce.accendi();
			bt.invia("accendi");
		}
		break;
	case MENO_BUTTON:
		//luce.setIntensita(luce.getIntensita()/* - 5*/);
		bt.invia((String)luce.getIntensita());
		break;
	case PIU_BUTTON:
		//luce.setIntensita(luce.getIntensita() /*+ 5*/);
		bt.invia((String)luce.getIntensita());
		break;
	case COLORE1_BUTTON:
		tab3 *tabA = (tab3*)frame->getTab();
		int indexA = tabA->getSliderIndex();
		luce.setColore(indexA);
		bt.invia(luce.getColore());
		break;
	case COLORE2_BUTTON:
		tab3 *tabB = (tab3*)frame->getTab();
		int indexB = tabB->getSliderIndex();
		luce.setColore(indexB + 1);
		bt.invia(luce.getColore());
		break;
	case COLORE3_BUTTON:
		tab3 *tabC = (tab3*)frame->getTab();
		int indexC = tabC->getSliderIndex();
		luce.setColore(indexC + 2);
		bt.invia(luce.getColore());
		break;
	}
}

void CBulby::resetDisplay()
{
	delete frame;
	frame = new finestra(luce.isAccesa(), &luce);
}
