#pragma once
#include<Siv3D.hpp>
#include"TaskSystem/rnfs.h"
class TitleGraph :
	public Task
{
private:
	Vec2 pos;
	Texture texture;

	TaskCall update;
public:
	TitleGraph() :pos(Window::Center()), texture(L"Data/System/Title.png"),
		update(this, &TitleGraph::Appear)
	{}
	
	~TitleGraph();

private:
	
	void Stopping();
	void Move();
	void Appear();
	void Draw();


};

