#include "DungeonMaster.h"

DungeonMaster::DungeonMaster(KGLGE::Window* win) : GameLoop(win)
{
	///1-4 are for enemies
	//0 is for fullscreen stuff
}

void DungeonMaster::addImg(std::string name, unsigned int num) {

}

void DungeonMaster::update()
{
	if (this->getWin()->getKey(GLFW_KEY_1)) {
		std::string x;
		std::cout << "Please Insert the name of the file:\n";
		std::cin >> x;
		addImg(x, 1);
	}
	else if(this->getWin()->getKey(GLFW_KEY_2)){
		std::string x;
		std::cout << "Please Insert the name of the file:\n";
		std::cin >> x;
		addImg(x, 2);
	}
	else if (this->getWin()->getKey(GLFW_KEY_3)) {
		std::string x;
		std::cout << "Please Insert the name of the file:\n";
		std::cin >> x;
		addImg(x, 3);
	}
	else if (this->getWin()->getKey(GLFW_KEY_4)) {
		std::string x;
		std::cout << "Please Insert the name of the file:\n";
		std::cin >> x;
		addImg(x, 4);
	}
}
