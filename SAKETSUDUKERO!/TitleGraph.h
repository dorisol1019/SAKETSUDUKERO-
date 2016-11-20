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

	Subject*subject;

	TaskCall update;
	TaskCall draw;

	int frameCount = 0;
public:
	TitleGraph(Subject*subject) :
		update(this, &TitleGraph::Appear,TaskCallGroup::Update),
		draw(this,&TitleGraph::Draw,TaskCallGroup::Draw),
		pos(Window::Center()), texture(L"Data/System/Title.png"),
		subject(subject)
	{}
	
	~TitleGraph();

private:
	
	void Stopping();
	void Move();
	void Appear();
	void Draw();


};

