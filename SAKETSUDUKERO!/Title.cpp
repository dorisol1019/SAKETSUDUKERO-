#include "Title.h"
#include"TaskSystem/rnfs.h"
#include"TaskCallGroup.h"

#include"Event.h"

Title::Title()
{
	subject = std::make_unique<Subject>();
	subject->addObserver(&createObject);
	subject->onNotify(Event::createOpeningText, subject.get());
}


Title::~Title()
{
	subject->removeObserver(&createObject);
	Task::All::Clear();
}

void Title::update()
{
	TaskCall::All::Update(TaskCallGroup::Update);
}

void Title::draw() const
{
	TaskCall::All::Update(TaskCallGroup::Draw);
}
