#include "MyIR.h"



MyIR::MyIR()
{
}


MyIR::~MyIR()
{
}

void MyIR::accendi()
{
	sendNEC(IR_ON, 32);
}

void MyIR::spegni()
{
	sendNEC(IR_OFF, 32);
}

void MyIR::inviaColore(unsigned long irCode)
{
	sendNEC(irCode, 32);
}
//
//void MyIR::rosso()
//{
//	sendNEC(ROSSO, 32);
//}
//
//void MyIR::verde()
//{
//	sendNEC(VERDE, 32);
//}
//
//void MyIR::blu()
//{
//	sendNEC(BLU, 32);
//}
//
//void MyIR::arancione()
//{
//	sendNEC(ARANCIONE, 32);
//}
//
//void MyIR::bianco()
//{
//	sendNEC(BIANCO, 32);
//}
//
//void MyIR::giallo()
//{
//	sendNEC(GIALLO, 32);
//}
//
//void MyIR::azzurro()
//{
//	sendNEC(AZZURRO, 32);
//}
//
//void MyIR::rosa()
//{
//	sendNEC(ROSA, 32);
//}
//
//void MyIR::giallancione()
//{
//	sendNEC(GIALLO_ARANCIO, 32);
//}

void MyIR::RGBveloce()
{
	sendNEC(IR_multicolorVeloce, 32);
}

void MyIR::RGBlento()
{
	sendNEC(IR_multicolorLento, 32);
}

void MyIR::aumentaIntensita()
{
	sendNEC(IR_AU_INT, 32);
}

void MyIR::diminuisciIntensita()
{
	sendNEC(IR_DIM_INT, 32);
}
