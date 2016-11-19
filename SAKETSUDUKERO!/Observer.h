#pragma once


class Observer
{
public:
	Observer() {};
	virtual~Observer() {};

	virtual void onNotify() = 0;

};