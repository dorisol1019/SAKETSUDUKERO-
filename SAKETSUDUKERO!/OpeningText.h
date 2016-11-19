#pragma once

#include<Siv3D.hpp>
#include"TaskSystem/rnfs.h"

#include"Subject.h"
#include"Event.h"

class OpeningText :public Task
{
private:
	TaskCall update;
	String text;

	Subject*subject;
public:
	OpeningText(const String&text,Subject*subject) :update(this, &OpeningText::UpdateFadein), text(text)
		,subject(subject)
	{
	}

	~OpeningText()
	{
	}

	void UpdateFadein() {

		static const int countStart = System::FrameCount();
		const int countNow = System::FrameCount();
		const int t = (countNow - countStart);
		if (t % (60 * 2) + 1 >= 60 * 2)
		{
			update.SetCall(&OpeningText::UpdateFadeout);
		}
		FontAsset(L"font").drawCenter(text, Window::Center(), AlphaF((double)t / 120));
	}
	void UpdateFadeout() {
		static int t = 120;
		if (t <= 0)
		{
			this->Destroy();
			subject->onNotify(Event::createOpeningGraph,subject);
		}
		FontAsset(L"font").drawCenter(text, Window::Center(), AlphaF((double)t-- / 120));
	}


private:

};
