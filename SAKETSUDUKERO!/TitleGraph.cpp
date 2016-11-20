#include "TitleGraph.h"

#include "Event.h"

TitleGraph::~TitleGraph()
{
}

void TitleGraph::Stopping()
{}

void TitleGraph::Move()
{
	pos.y -= 5;
	if (pos.y <= 110 || Input::AnyKeyClicked())
	{
		pos.y = 110;
		update.SetCall(&TitleGraph::Stopping);
		subject->onNotify(Event::createTitleText,subject);
	}

}

void TitleGraph::Appear()
{
	if (Input::AnyKeyClicked() || frameCount % (60 * 2) + 1 >= 60 * 2)
	{
		update.SetCall(&TitleGraph::Move);
		frameCount = 120;
	}
	frameCount++;
}

void TitleGraph::Draw()
{
	texture.drawAt(pos, AlphaF((double)(frameCount) / (2 * 60)));
}
