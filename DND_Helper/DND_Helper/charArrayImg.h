#pragma once
#include <KGLGE/GameObject.h>
#include <KGLGE/TextureAtlas.h>

class charArrayImg : public KGLGE::GameObject {
public:
	charArrayImg(unsigned char* pixels, int bpp, int pixel_width, int pixel_height, float x, float y, float width, float height,unsigned int texSlot);
	// Inherited via GameObject
	virtual void update() override;
	virtual KGLGE::Vertex* getVertexes() override;
	virtual unsigned int getNumVertex() override;
	virtual KGLGE::Triangle* getIndicies(unsigned int offset) override;
	virtual bool respondToKey(unsigned int key) override;
	virtual unsigned int getNumTriangles() override;
protected:
	void resetTextures();
	float m_x;
	float m_y;
	float m_Width;
	float m_Height;

private:
	KGLGE::Vertex m_vertex[4];
	KGLGE::Triangle m_Triangles[2];
};