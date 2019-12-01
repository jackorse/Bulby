#include "CBulby.h"


/**
 * @brief costruttore
 *
 * inizializza {@link #frame}
 */
CBulby::CBulby()
{
	frame = new finestra(luce.getAccesa(), &luce, &bt);
	//connectedTime = -1;
	oldBtState = false;
}

/**
 * @brief distruttore
 *
 * elimina {@link #frame}
 */
CBulby::~CBulby()
{
	delete frame;
}

/**
 * @brief controlla il bluetooth.
 *
 * Modifica lo stato della {@link #luce} in base a quello che legge dal bluetooth {@link #bt}
 * @see MyBluetooth#leggi()
 */
void CBulby::checkBluetooth()
{
	if (oldBtState != bt.isConnesso())
	{
		Serial.println("cambio stato bluetooth");
		oldBtState = !oldBtState;
		if (frame->getTab()->toString() == "HOME")
			((homeTab*)frame->getTab())->update();
		if (oldBtState)
		{
			if (luce.isAccesa())
			{
				bt.invia("F;ON");
			}
			else
			{
				bt.invia("F;OFF");
			}
			delay(1000);
			bt.invia("F;"+luce.getColoreSimile());
			delay(1000);
			bt.invia("F;"+(String)luce.getIntensita());
		}
	}
	if (bt.isConnesso())
	{
		//if (connectedTime == -1)
		//	connectedTime = millis();

		bool isIntensita = true;
		String letto = bt.leggi();
		if (letto != "")
		{
			for (int i = 0; i < letto.length(); i++)
				if (letto[i] < '0' || letto[i] > '9')
					isIntensita = false;
			if (isIntensita)
				luce.setIntensita(letto.toInt());
			else
				if (letto == "ON")
					luce.accendi();
				else if (letto == "OFF")
					luce.spegni();
			//else if (letto == "ferlin")
			//	luce.setSpegnimentoAutomatico(true);
			//else if (letto == "ferrareis")
			//	luce.setSpegnimentoAutomatico(false);
				else
					luce.setColore(letto);
		}
	}
	else
	{
		//if (connectedTime != -1)
		//	connectedTime = -1;
		//SPEGNIMENTO AUTOMATICO QUANDO BLUETOOTH SI DISCONNETTE
		//if (luce.isSpegnimentoAutomatico() && millis() > 20000)		//se è acceso da più di 20 sec. (tempo di connettersi)
		//	luce.spegni();
	}
}

/**
 * @brief run display
 *
 * cambia lo stato della {@link #luce} in base ai pulsanti premuti sul display
 */
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
			//bt.invia("off");
		}
		else {
			luce.accendi();
			//bt.invia("on");
		}
		break;
	case MENO_BUTTON:
		//luce.setIntensita(luce.getIntensita()/* - 5*/);
		//bt.invia((String)luce.getIntensita());
		break;
	case PIU_BUTTON:
		//luce.setIntensita(luce.getIntensita() /*+ 5*/);
		//bt.invia((String)luce.getIntensita());
		break;
	case COLORE1_BUTTON:
		Serial.println("Colore premuto: 1");
		tab = (tab3*)frame->getTab();
		index = tab->getSliderIndex();
		luce.setColore(index);
		Serial.println("Index premuto:" + (String)index);
		tab->reDrawSelectedColorButton();
		//bt.invia(luce.getColoreSimile());
		break;
	case COLORE2_BUTTON:
		Serial.println("Colore premuto: 2");
		tab = (tab3*)frame->getTab();
		index = tab->getSliderIndex();
		luce.setColore(index + 1);
		Serial.println("Index premuto:" + (String)(index + 1));
		tab->reDrawSelectedColorButton();
		//bt.invia(luce.getColoreSimile());
		break;
	case COLORE3_BUTTON:
		Serial.println("Colore premuto: 3");
		tab = (tab3*)frame->getTab();
		index = tab->getSliderIndex();
		Serial.println("Index premuto:" + (String)(index + 2));
		luce.setColore(index + 2);
		tab->reDrawSelectedColorButton();
		//bt.invia(luce.getColoreSimile());
		break;
	}
}

/**
 * @brief reset diaplay
 *
 * elimina e reinizializza {@link #frame}
 */
void CBulby::resetDisplay()
{
	if (frame)
		delete frame;
	frame = new finestra(luce.getAccesa(), &luce, &bt);
}
