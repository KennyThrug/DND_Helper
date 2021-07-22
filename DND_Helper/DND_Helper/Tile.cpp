#include "Tile.h"

Tile::Tile(KGLGE::TextureAtlas* atlas, float x, float y, float width, float height,std::string fileName, int numRotations) 
	: Sprite(atlas,x,y,width,height,fileName,numRotations)
{

}

void Tile::update()
{

}

bool Tile::respondToKey(unsigned int key)
{
	return false;
}
