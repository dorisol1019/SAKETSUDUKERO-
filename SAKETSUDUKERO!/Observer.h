#pragma once

enum class Event;
class Subject;

class Observer
{
public:
	Observer() {};
	virtual~Observer() {};

	virtual void onNotify(Event e,Subject*sub) = 0;

};