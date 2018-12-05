#include"Colors.h"

Colors::Colors()
{
	char* colorsname[] = { "giallancione", "viola", "azzurrochiaro", "azzurroverde2", "giallo", "azzurroverde", "gialloverde", "bluviola", "rosa", "azzurro", "blu", "rosso", "bianco", "verde", "arancione", "fucsia", "rgbLento", "rgbVeloce" };
	for (int i = 0; i < NUMCOLORI; i++)
		colori[i] = CColore(colorsname[i], i);
}

CColore * Colors::get(int index)
{
	if (index >= 0 && index < NUMCOLORI)
		return &colori[index];
}

CColore * Colors::get(String colorName)
{
	for (int i = 0; i < NUMCOLORI; i++)
		if (colori[i].getColore() == colorName)
			return &colori[i];
	return nullptr;
}

CColore * Colors::getAttivo()
{
	for (int i = 0; i < NUMCOLORI; i++)
	{
		if (colori[i].isAttiva())
		{
			return &colori[i];
		}
	}
	return nullptr;
}
uint16_t Colors::getColore(String colore)
{
	if (colore == "rosso")
		return RED;
	else if (colore == "giallo")
		return YELLOW;
	else if (colore == "verde")
		return GREEN;
	else if (colore == "blu")
		return BLUE;
	else if (colore == "arancione")
		return ORANGE;
	else if (colore == "azzurro")
		return CYAN;
	else if (colore == "bianco")
		return WHITE;
	else if (colore == "giallancione")
		return GIALLO_ARANCIO;
	else if (colore == "rosa")
		return PINK;
	else if (colore == "viola")
		return VIOLA;
	else if (colore == "azzurrochiaro")
		return AZZURRO_CHIARO;
	else if (colore == "azzurroverde2")
		return AZZURRO_VERDE2;
	else if (colore == "azzurroverde")
		return AZZURRO_VERDE;
	else if (colore == "gialloverde")
		return GIALLO_VERDE;
	else if (colore == "bluviola")
		return BLU_VIOLA;
	else if (colore == "fucsia")
		return FUCSIA;
}