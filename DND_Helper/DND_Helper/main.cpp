#include "DungeonMaster.h"
#include <KGLGE/Window.h>
#include <KGLGE/Sprite.h>
#include "Square.h"

int main() {
	KGLGE::initializeGLFW();
	KGLGE::Window* win = new KGLGE::Window("DungeonMaster");
	win->display();
	DungeonMaster master(win);

	Square r(-1, -1, 0.5f, 0.5f, 1, 0, 0, 1);
	master.addGameObject(&r,1);

	Square b(-1, 0, 0.5f, 0.5f, 0, 1, 0, 1);
	master.addGameObject(&b, 1);

	Square g(0, -1, 0.5f, 0.5f, 0, 0, 1, 1);
	master.addGameObject(&g, 1);

	Square y(0, 0, 0.5f, 0.5f, 1, 1, 0, 1);
	master.addGameObject(&y, 1);



	master.startLoop();
	
	delete win;
}