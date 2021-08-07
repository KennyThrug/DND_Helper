#pragma once
#include <KGLGE/GameLoop.h>
#include <KGLGE/Sprite.h>
class DungeonMaster : public KGLGE::GameLoop {
public:
	DungeonMaster(KGLGE::Window* win);
	void addImg(std::string name, unsigned int num);
	void update() override;
};