#pragma once

#include<Siv3D.hpp>
#include"TaskSystem/rnfs.h"

#include"Subject.h"

class OpeningGraph :public Task
{
private:
	TaskCall update;
	Texture texture;

	Subject*subject;
public:
	OpeningGraph(const FilePath&path, Subject*subject) :
		update(this, &OpeningGraph::UpdateFadein), texture(path)
		, subject(subject)
	{
	}

	~OpeningGraph()
	{
	}

	void UpdateFadein() {
		static int t = 0;
		if (t >= 120)
		{
			update.SetCall(&OpeningGraph::UpdateFadeout);
		}
		texture.drawAt(Window::Center(), AlphaF((double)t++ / 120));
	}
	void UpdateFadeout() {
		static int t = 120;
		if (t <= 0)
		{
			this->Destroy();
			subject->onNotify(Event::createTitleGraph, subject);
		}
		texture.drawAt(Window::Center(), AlphaF((double)t-- / 120));
	}


private:

};
