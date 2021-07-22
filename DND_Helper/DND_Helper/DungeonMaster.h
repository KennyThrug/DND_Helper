#pragma once
#include <KGLGE/GameLoop.h>
class DungeonMaster : public KGLGE::GameLoop {
public:
	DungeonMaster(KGLGE::Window* win);
	void update() override;
};