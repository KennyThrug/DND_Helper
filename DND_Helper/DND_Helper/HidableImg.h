#pragma once
#include <KGLGE/Image.h>
class HidableImg : public KGLGE::Image {
public:
	HidableImg(float x, float y, float width, float height, std::string fileName, unsigned int texSlot)
		: KGLGE::Image(x, y, width, height, fileName, texSlot), maxWidth(width), maxHeight(height)	{

	}
	void hideImg() {
		m_Height = 0;
		m_Width = 0;
		shouldUpdate = true;
	}
	bool isHidden() {
		return m_Height == 0;
	}
	void showImg() {
		m_Height = maxHeight;
		m_Width = maxWidth;
		shouldUpdate = true;
	}
private:
	unsigned int maxWidth;
	unsigned int maxHeight;
};