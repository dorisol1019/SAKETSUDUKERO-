#pragma once
#include<Siv3D.hpp>
#include"TaskSystem/rnfs.h"

#include"Subject.h"

class TitleGraph :
	public Task
{
private:
	Vec2 pos;
	Texture texture;

	Subject*subject;

	TaskCall update;
public:
	TitleGraph(Subject*subject) :
		pos(Window::Center()), texture(L"Data/System/Title.png"),
		update(this, &TitleGraph::Appear),subject(subject)
	{}
	
	~TitleGraph();

private:
	
	void Stopping();
	void Move();
	void Appear();
	void Draw();


};

