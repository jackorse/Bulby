#pragma once
#include"IRremote.h"

#define IR_ON 0xFFB04F
#define IR_OFF 0xFFF807
#define IR_FADE 0xFF00FF
#define IR_multicolorRGB 0xFF30CF
#define IR_multicolorVeloce 0xFFB24D
#define IR_multicolorLento 0xFF58A7

#define IR_AU_INT 0xFF906F //20 volte
#define IR_DIM_INT 0xFFB847 //20 volte

#define IR_GIALLO_ARANCIO 0xFF02FD
#define IR_VIOLA 0xFF20DF
#define IR_AZZURROCHIARO 0xFF28D7
#define IR_AZZURRO_VERDE2 0xFF32CD
#define IR_GIALLO 0xFF38C7
#define IR_AZZURRO_VERDE 0xFF48B7
#define IR_GIALLO_VERDE 0xFF50AF
#define IR_BLU_VIOLA 0xFF6897
#define IR_ROSA 0xFF708F
#define IR_AZZURRO 0xFF7887
#define IR_BLU 0xFF8877
#define IR_ROSSO 0xFF9867
#define IR_BIANCO 0xFFA857
#define IR_VERDE 0xFFD827
#define IR_ARANCIONE 0xFFE817
#define IR_FUCSIA 0xFFF00F

/**
* Classe che gestisce il LED IR
*/
class MyIR :public IRsend
{
public:
	MyIR();
	~MyIR();
	void accendi();
	void spegni();
	void inviaColore(unsigned long irCode);
	//void rosso();
	//void verde();
	//void blu();
	//void arancione();
	//void bianco();
	//void giallo();
	//void azzurro();
	//void rosa();
	//void giallancione();
	void RGBveloce();
	void RGBlento();
	void aumentaIntensita();
	void diminuisciIntensita();
};

