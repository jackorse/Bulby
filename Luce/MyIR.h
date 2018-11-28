#pragma once
#include<IRremote.h>

#define ON 0xFFB04F
#define OFF 0xFFF807
#define FADE 0xFF00FF
#define multicolorRGB 0xFF30CF
#define multicolorVeloce 0xFFB24D
#define multicolorLento 0xFF58A7

#define AU_INT 0xFF906F //20 volte
#define DIM_INT 0xFFB847 //20 volte

#define GIALLO_ARANCIO 0xFF02FD
#define VIOLA 0xFF20DF
#define AZZURROCHIARO 0xFF28D7
#define AZZURRO_VERDE2 0xFF32CD
#define GIALLO 0xFF38C7
#define AZZURRO_VERDE 0xFF48B7
#define GIALLO_VERDE 0xFF50AF
#define BLU_VIOLA 0xFF6897
#define ROSA 0xFF708F
#define AZZURRO 0xFF7887
#define BLU 0xFF8877
#define ROSSO 0xFF9867
#define BIANCO 0xFFA857
#define VERDE 0xFFD827
#define ARANCIONE 0xFFE817
#define ARANCIONESCURO 0xFFF00F

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
	void rosso();
	void verde();
	void blu();
	void arancione();
	void bianco();
	void giallo();
	void azzurro();
	void rosa();
	void giallancione();
	void RGBveloce();
	void RGBlento();
	void aumentaIntensita();
	void diminuisciIntensita();
};

