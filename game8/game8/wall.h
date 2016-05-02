#pragma once


/////////////////////////////////////
// Include
#include "gameObject.h"
#include "level.h"


/////////////////////////////////////
// Class Tank
class Wall
	: public GameObject
{
public:
	Wall();

	virtual void render( RenderSystem* rs );

	void setImage( unsigned char symbol, ConsoleColor symbolColor, ConsoleColor bgColor );

private:
	ConsoleSymbolData m_image;
};
