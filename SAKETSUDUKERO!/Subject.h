#pragma once

#include "Observer.h"
#include <Siv3D.hpp>

class Subject
{
public:
	Subject() {};
	virtual~Subject() {};

	void addObserver(Observer*obs) {
		observers.emplace_back(obs);
	}

	void removeObserver(Observer*obs) {
		s3d::Erase(observers, obs);
	}

	void onNotify(Event e,Subject*sub) {
		for (auto& i : observers)
		{
			i->onNotify(e,sub);
		}
	}

private:
	Array<Observer*> observers;

};