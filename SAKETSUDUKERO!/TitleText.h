#pragma once

#include<Siv3D.hpp>
#include"TaskSystem/rnfs.h"

#include"Subject.h"

class TitleText :public Task
{
private:
	TaskCall update;

	Subject*subject;
public:
	TitleText(Subject*sub):update(this,&TitleText::Update)
		,subject(sub)
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

		FontAsset(L"font").drawCenter(L"Press Start", { Window::Center().x, Window::Center().y + 40 });
	}

private:

};

