#pragma once

#include<Siv3D.hpp>
#include"TaskSystem/rnfs.h"
#include"TaskCallGroup.h"

#include"Subject.h"

class OpeningGraph :public Task
{
private:
	TaskCall update, draw;
	Texture texture;

	Subject*subject;

	int frameCount = 0;
public:
	OpeningGraph(const FilePath&path, Subject*subject) :
		update(this, &OpeningGraph::UpdateFadein, TaskCallGroup::Update),
		draw(this, &OpeningGraph::Draw, TaskCallGroup::Draw)
		, texture(path)
		, subject(subject)
		, frameCount(0)
	{
	}

	~OpeningGraph()
	{
	}

	void UpdateFadein() {
		if (frameCount >= 120)
		{
			update.SetCall(&OpeningGraph::UpdateFadeout);
			frameCount = 120;
		}
		frameCount++;
	}
	void UpdateFadeout() {
		if (frameCount <= 0)
		{
			this->Destroy();
			subject->onNotify(Event::createTitleGraph, subject);
		}
		frameCount--;
	}

	void Draw()
	{
		texture.drawAt(Window::Center(), AlphaF((double)frameCount / 120));
	}
};
