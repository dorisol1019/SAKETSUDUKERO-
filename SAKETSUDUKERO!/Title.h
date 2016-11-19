#pragma once

#include"MySceneMgr.h"

class Title :
	public MySceneMgr::Scene
{
public:
	Title();
	~Title();

	void update()override;
	void draw()const override;


};

