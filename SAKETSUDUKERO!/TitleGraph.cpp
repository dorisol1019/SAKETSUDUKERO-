#include "TitleGraph.h"

#include"TitleText.h"

TitleGraph::~TitleGraph()
{
}

void TitleGraph::Stopping()
{
	texture.drawAt(pos);
}

void TitleGraph::Move()
{
	pos.y -= 5;
	if (pos.y <= 110 || Input::AnyKeyClicked())
	{
		pos.y = 110;
		update.SetCall(&TitleGraph::Stopping);
		Create<TitleText>();
	}
	texture.drawAt(pos);

}

void TitleGraph::Appear()
{
	static const int countStart = System::FrameCount();
	const int countNow = System::FrameCount();
	const int t = (countNow - countStart);
	if (Input::AnyKeyClicked() || t % (60 * 2) + 1 >= 60 * 2)
	{
		update.SetCall(&TitleGraph::Move);
	}

	texture.drawAt(pos, AlphaF((double)(t) / (2 * 60)));
}

void TitleGraph::Draw()
{

}
