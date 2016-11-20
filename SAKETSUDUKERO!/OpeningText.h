#pragma once

#include<Siv3D.hpp>
#include"TaskSystem/rnfs.h"
#include"TaskCallGroup.h"

#include"Subject.h"
#include"Event.h"

class OpeningText :public Task
{
private:
	TaskCall update;
	TaskCall draw;
	String text;

	Subject*subject;

	int frameCount = 0;
public:
	OpeningText(const String&text, Subject*subject) :
		update(this, &OpeningText::UpdateFadein, TaskCallGroup::Update),
		draw(this, &OpeningText::Draw, TaskCallGroup::Draw),
		text(text), subject(subject), frameCount(0)
	{
	}

	~OpeningText()
	{
	}

	void UpdateFadein() {
		if (frameCount % (60 * 2) + 1 >= 60 * 2)
		{
			frameCount = 120;
			update.SetCall(&OpeningText::UpdateFadeout);
		}
		frameCount++;
	}
	void UpdateFadeout() {
		if (frameCount <= 0)
		{
			this->Destroy();
			subject->onNotify(Event::createOpeningGraph, subject);
		}
		frameCount--;
	}

	void Draw()
	{
		FontAsset(L"font").drawCenter(text, Window::Center(), AlphaF((double)frameCount / 120));
	}
};
