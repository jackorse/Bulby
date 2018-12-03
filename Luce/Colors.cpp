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
