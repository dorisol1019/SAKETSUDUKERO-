
# include <Siv3D.hpp>
# include <HamFramework.hpp>
# include "TaskSystem\rnfs.h"

# include "MySceneMgr.h"
# include "Title.h"

void Main()
{

	Window::Resize(960, 540);

	Window::SetTitle(L"避け続けろ！");

	FontAsset::Register(L"font", 15);


	MySceneMgr sceneMgr{};

	// シーン追加処理
	sceneMgr.add<Title>(L"Title");

	//メインループ
	while (System::Update())
	{
		sceneMgr.updateAndDraw();

		Task::All::Update();
	}
}
