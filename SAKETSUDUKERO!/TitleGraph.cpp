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
		update.SetCall(&TitleGraph::StopingHalfTime);
		frameCount = 120;
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

void TitleGraph::StopingHalfTime()
{
	static int t = 0;
	if (t / 20 >= 1 || Input::AnyKeyClicked())
	{
		update.SetCall(&TitleGraph::SceleExclamation);
		draw.SetCall(&TitleGraph::DrawTitle);
	}
	t++;
}

void TitleGraph::SceleExclamation()
{
	constexpr double scaleSpeed = 0.5;
	constexpr int speed = 2;
	pos.x -= speed;
	scale -= scaleSpeed;

	if (pos.x <= Window::Center().x - 40 || Input::AnyKeyClicked())
	{
		pos.x = Window::Center().x - 40;
		if (scale <= 1.0 || Input::AnyKeyClicked())
		{
			scale = 1.0;
			update.SetCall(&TitleGraph::Stopping);
			subject->onNotify(Event::createTitleText, subject);
		}

	}
}

void TitleGraph::Draw()
{
	texture.drawAt(pos, AlphaF(Clamp((double)(frameCount) / (2 * 60), 0.0, 1.0)));
}

void TitleGraph::DrawTitle()
{
	texture.drawAt(pos);
	texture2.scale(scale).drawAt(pos2);
}
