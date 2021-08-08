#include "DungeonMaster.h"
#include <KGLGE/Window.h>
#include <KGLGE/Sprite.h>
#include "Square.h"

int main() {
	KGLGE::initializeGLFW();
	KGLGE::Window* win = new KGLGE::Window("DungeonMaster");
	win->display();
	DungeonMaster master(win);

	Square r(-1, -1, 1, 1, 1, 0, 0, 1);
	master.addGameObject(&r,0);

	Square b(-1, 0, 1, 1, 0, 1, 0, 1);
	master.addGameObject(&b, 0);

	Square g(0, -1, 1, 1, 0, 0, 1, 1);
	master.addGameObject(&g, 0);

	Square y(0, 0, 1, 1, 1, 1, 0, 1);
	master.addGameObject(&y, 0);
	for (int i = 0; i < 4; i++) {
		Square *t = new Square(0, 0, 0, 0, 0, 0, 0, 0);
		master.addGameObject(t,1);
	}


	master.startLoop();
	
	delete win;
}