#include "Title.h"
#include"TaskSystem/rnfs.h"

//#include"TitleGraph.h"
#include"OpeningText.h"

Title::Title()
{
	Create<OpeningText>(L"2016  @dorisol1019");
}


Title::~Title()
{
	Task::All::Clear();
}

void Title::update()
{
	TaskCall::All::Update();
	Task::All::Update();
}

void Title::draw() const
{

}
