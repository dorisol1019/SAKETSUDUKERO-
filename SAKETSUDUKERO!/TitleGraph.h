#pragma once
#include<Siv3D.hpp>
#include"TaskSystem/rnfs.h"
#include"TaskCallGroup.h"

#include"Subject.h"

class TitleGraph :
	public Task
{
private:
	Vec2 pos;
	Texture texture;
	Vec2 pos2;
	Texture texture2;

	Subject*subject;

	TaskCall update;
	TaskCall draw;

	int frameCount = 0;
	double scale;
public:
	TitleGraph(Subject*subject) :
		update(this, &TitleGraph::Appear, TaskCallGroup::Update),
		draw(this, &TitleGraph::Draw, TaskCallGroup::Draw),
		pos({ Window::Center().x,Window::Center().y }), texture(L"Data/System/Title.png"),
		pos2({ 800,107 }), texture2(L"Data/System/Title2.png"), scale(10),
		subject(subject)
	{}

	~TitleGraph();

private:

	void Stopping();
	void Move();
	void Appear();
	void StopingHalfTime();
	void SceleExclamation();

	void Draw();
	void DrawTitle();


};

