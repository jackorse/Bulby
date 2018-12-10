#include "CBulby.h"



CBulby::CBulby()
{
	frame = new finestra(luce.getAccesa(), &luce);
}


CBulby::~CBulby()
{
	delete frame;
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
			if (letto == "ON")
				luce.accendi();
			else if (letto == "OFF")
				luce.spegni();
			else
			{
				luce.setColore(letto);
			}
		else
			luce.setIntensita(letto.toInt());
	}
}

void CBulby::runDisplay()
{
	int ris = frame->getTab()->checkBottoni();
	tab3 *tab;
	int index;

	if (ris >= 0 && ris <= 3)
		frame->setTab(ris);
	else switch (ris)
	{
	case LUCE_BUTTON:	//pulsante luce premuto
		if (luce.isAccesa()) {
			luce.spegni();
			bt.invia("off");
		}
		else {
			luce.accendi();
			bt.invia("on");
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
		Serial.println("Colore premuto: 1");
		tab = (tab3*)frame->getTab();
		index = tab->getSliderIndex();
		luce.setColore(index);
		Serial.println("Index premuto:" + (String)index);
		tab->reDrawSelectedColorButton();
		bt.invia(luce.getColore());
		break;
	case COLORE2_BUTTON:
		Serial.println("Colore premuto: 2");
		tab = (tab3*)frame->getTab();
		index = tab->getSliderIndex();
		luce.setColore(index + 1);
		Serial.println("Index premuto:" + (String)(index + 1));
		tab->reDrawSelectedColorButton();
		bt.invia(luce.getColore());
		break;
	case COLORE3_BUTTON:
		Serial.println("Colore premuto: 3");
		tab = (tab3*)frame->getTab();
		index = tab->getSliderIndex();
		Serial.println("Index premuto:" + (String)(index + 2));
		luce.setColore(index + 2);
		tab->reDrawSelectedColorButton();
		bt.invia(luce.getColore());
		break;
	}
}

void CBulby::resetDisplay()
{
	if (frame)
		delete frame;
	frame = new finestra(luce.getAccesa(), &luce);
}
