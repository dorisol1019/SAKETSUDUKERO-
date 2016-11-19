#pragma once

#include"MySceneMgr.h"

#include"CreateObject.h"
#include"Subject.h"

class Title :
	public MySceneMgr::Scene
{
public:
	Title();
	~Title();

	void update()override;
	void draw()const override;

private:
	CreateObject createObject;

	std::unique_ptr<Subject>subject;
	
};

