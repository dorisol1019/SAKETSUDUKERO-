#pragma once

#include<Siv3D.hpp>
#include"TaskSystem/rnfs.h"

#include"TitleGraph.h"

class OpeningGraph :public Task
{
private:
	TaskCall update;
	Texture texture;
public:
	OpeningGraph(const FilePath&path) :update(this, &OpeningGraph::UpdateFadein), texture(path)
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
			Create<TitleGraph>();
		}
		texture.drawAt(Window::Center(), AlphaF((double)t-- / 120));
	}


private:

};
