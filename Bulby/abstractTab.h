#pragma once
class abstractTab
{
public:
	abstractTab();
	virtual ~abstractTab();
	virtual void draw() = 0;
	virtual int checkBottoni() = 0;
};

