#include "DungeonMaster.h"
#include <KGLGE/Window.h>
#include "Tile.h"

int main() {
	KGLGE::initializeGLFW();
	KGLGE::Window* win = new KGLGE::Window(500,500,"DungeonMaster");
	win->display();
	DungeonMaster master(win);

	std::string s = "res/sprites/GrassLand/";
	KGLGE::TextureAtlas grass(s,KGLGE_BACKGROUND);

	Tile tile = Tile(&grass, 0, 0, 0.5f, 0.5f, "Grass.png");
	KGLGE::Sprite water = KGLGE::Sprite(&grass, -1, -1, 0.25f, 0.25f, "Water.png");

	master.addGameObject(&tile,0);
	master.addGameObject(&water, 0);
	master.startLoop();
	
	delete win;
}