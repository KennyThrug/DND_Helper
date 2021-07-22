#pragma once
#include "KGLGE/Sprite.h"
class Tile : public KGLGE::Sprite {
public:
	Tile(KGLGE::TextureAtlas* atlas, float x, float y, float width, float height, std::string fileName, int numRotations = 0);
	void update() override;
	bool respondToKey(unsigned int key) override;
};