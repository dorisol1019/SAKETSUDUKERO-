#pragma once

#include<Siv3D.hpp>
#include"TaskSystem/rnfs.h"

class TitleText :public Task
{
private:
	TaskCall update;
public:
	TitleText():update(this,&TitleText::Update)
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

