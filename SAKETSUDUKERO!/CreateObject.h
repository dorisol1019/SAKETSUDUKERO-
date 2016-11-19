#pragma once

#include"Observer.h"
#include"Event.h"

#include"TaskSystem\rnfs.h"
#include"OpeningText.h"
#include"OpeningGraph.h"
#include"TitleText.h"
#include"TitleGraph.h"
class CreateObject:public Observer
{
public:
	CreateObject(){}

	~CreateObject(){}

	void onNotify(Event e,Subject*sub)override
	{
		switch (e)
		{
			case Event::createOpeningText:
				rnfs::Create<OpeningText>(L"2016  @dorisol1019",sub);
				break;
			case Event::createOpeningGraph:
				rnfs::Create<OpeningGraph>(L"Data/System/SRDG_Logo.png",sub);
				break;
			case Event::createTitleText:
				rnfs::Create<TitleText>(sub);
				break;
			case Event::createTitleGraph:
				rnfs::Create<TitleGraph>(sub);
				break;
			default:
				break;
		}
	}

private:

};
