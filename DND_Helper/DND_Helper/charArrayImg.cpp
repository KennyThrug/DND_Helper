#include "charArrayImg.h"

void loadImageFromCharArray(unsigned char* pixels, int bpp, int pixel_width, int pixel_height, unsigned int texSlot) {
	glActiveTexture(GL_TEXTURE0 + texSlot);
	GLuint textureID;
	glCreateTextures(GL_TEXTURE_2D, 1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, pixel_width, pixel_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

	glActiveTexture(GL_TEXTURE0 + texSlot);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glBindTextureUnit(texSlot, textureID);
}

charArrayImg::charArrayImg(unsigned char* pixels, int bpp, int pixel_width, int pixel_height, float x, float y, float width, float height, unsigned int texSlot)
	:m_Height(height),m_Width(width),m_x(x),m_y(y),GameObject()
{
	loadImageFromCharArray(pixels, bpp, pixel_width, pixel_height, texSlot);
	m_vertex[0].texPos = { 0,0 };
	m_vertex[1].texPos = { 1,0 };
	m_vertex[2].texPos = { 1,1 };
	m_vertex[3].texPos = { 0,1 };

	m_vertex[0].texID = texSlot;
	m_vertex[1].texID = texSlot;
	m_vertex[2].texID = texSlot;
	m_vertex[3].texID = texSlot;
}

void charArrayImg::update()
{

}

KGLGE::Vertex* charArrayImg::getVertexes()
{
	resetTextures();
	return m_vertex;
}

unsigned int charArrayImg::getNumVertex()
{
	return 4;
}

KGLGE::Triangle* charArrayImg::getIndicies(unsigned int offset)
{
	m_Triangles[0].index1 = 0 + offset;
	m_Triangles[0].index2 = 1 + offset;
	m_Triangles[0].index3 = 2 + offset;
	m_Triangles[1].index1 = 2 + offset;
	m_Triangles[1].index2 = 3 + offset;
	m_Triangles[1].index3 = 0 + offset;
	return m_Triangles;
}

bool charArrayImg::respondToKey(unsigned int key)
{
	return false;
}

unsigned int charArrayImg::getNumTriangles()
{
	return 2;
}

void charArrayImg::resetTextures()
{
	m_vertex[0].position = { m_x,m_y };
	m_vertex[1].position = { m_x + m_Width,m_y };
	m_vertex[2].position = { m_x + m_Width, m_y + m_Height };
	m_vertex[3].position = { m_x,m_y + m_Height };
}
