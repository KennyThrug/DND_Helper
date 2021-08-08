#include "DungeonMaster.h"
DungeonMaster::DungeonMaster(KGLGE::Window* win) : GameLoop(win)
{
	///1-4 are for enemies
	//0 is for fullscreen stuff
}

void DungeonMaster::addImg(unsigned int num,float x,float y) {
	delete gameObjects[1][num];
	std::string p;
	std::cout << "Please Insert the name of the file:\n";
	std::cin >> p;
	HidableImg* img = new HidableImg(x, y, 0.8f, 0.8f, p, num);
	gameObjects[1][num] = img;
}
bool xa = true;
void DungeonMaster::update()
{
	if (this->getWin()->getKey(GLFW_KEY_1)) {
		addImg(1,-0.9f,-0.9f);
	}
	else if(this->getWin()->getKey(GLFW_KEY_2)){
		addImg(2,0.1f,-0.9f);
	}
	else if (this->getWin()->getKey(GLFW_KEY_3)) {
		addImg(3,0.1f,0.1f);
	}
	else if (this->getWin()->getKey(GLFW_KEY_4)) {
		addImg(4,-0.9f,0.1f);
	}
	else if (this->getWin()->getKey(GLFW_KEY_Q)) {
		std::string x;
		std::cout << "Please Insert the name of the file:\n";
		std::cin >> x;
		displayFullscreenIMG(x);
	}
	else if (this->getWin()->getKey(GLFW_KEY_W)) {
		if (((HidableImg*)gameObjects[2][0])->isHidden()) {
			((HidableImg*)gameObjects[2][0])->showImg();
		}
		else {
			((HidableImg*)gameObjects[2][0])->hideImg();
		}
	}
	else if (this->getWin()->getKey(GLFW_KEY_SPACE) && xa) {
		saveImg();
		xa = false;
	}
}

void DungeonMaster::displayFullscreenIMG(std::string fileName)
{
	HidableImg* img = new HidableImg(-1, -1, 2, 2, fileName, 0);
	gameObjects[2][0] = img;
	m_numGameObjects[2] = 1;
}

void DungeonMaster::saveImg() {
	int width = 0;
	int height = 0;
	getWin()->getSize(&width, &height);
	unsigned char* pixels = new unsigned char[4 * width * height];
	
	glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
	

	charArrayImg* go = new charArrayImg(pixels,4,width,height,0,0,1,1,7);
	addGameObject(go, 2);
	//delete[] pixels;
}