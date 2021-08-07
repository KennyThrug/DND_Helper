#pragma once
#include <KGLGE/GameLoop.h>
#include "HidableImg.h"
class DungeonMaster : public KGLGE::GameLoop {
public:
	DungeonMaster(KGLGE::Window* win);
	void addImg(std::string fileName, unsigned int num);
	void displayFullscreenIMG(std::string fileName);
	void update() override;
};