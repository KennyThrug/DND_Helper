#pragma once
#include <KGLGE/GameLoop.h>
#include "HidableImg.h"
#include <FreeImage.h>
#include "charArrayImg.h"
class DungeonMaster : public KGLGE::GameLoop {
public:
	DungeonMaster(KGLGE::Window* win);
	void addImg(unsigned int num,float x, float y);
	void displayFullscreenIMG(std::string fileName);
	void update() override;
	void saveImg();
};