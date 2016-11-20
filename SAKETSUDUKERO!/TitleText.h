#pragma once

#include<Siv3D.hpp>
#include"TaskSystem/rnfs.h"
#include"TaskCallGroup.h"

#include"Subject.h"

class TitleText :public Task
{
private:
	TaskCall update;
	TaskCall draw;

	Subject*subject;
public:
	TitleText(Subject*sub):
		update(this,&TitleText::Update,TaskCallGroup::Update),
		draw(this,&TitleText::Draw,TaskCallGroup::Draw),
		subject(sub)
	{
	}

	~TitleText()
	{
	}

	void Update() {

		if (Input::AnyKeyClicked())
		{
			this->Destroy();
		}

	}

	void Draw()
	{
		FontAsset(L"font").drawCenter(L"Press Start", { Window::Center().x, Window::Center().y + 40 });
	}

private:

};

