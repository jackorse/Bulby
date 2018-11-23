#pragma once
class CColore
{
private:
	 String colore;
	int intensita;
	bool attivo;
public:
	CColore();
	CColore(String colore, int intensita=100);
	~CColore();
	void setIntensita(int intensita);
	int getIntensita();
	String getColore();
	void attiva();
	void disattiva();
	bool isAttiva();
};

